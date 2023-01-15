use sliding_puzzle::*;

fn main() -> Result<(), PuzzleError> {
    let puzzle = Puzzle::from_id(410325678)?;
    // TODO: Check if solvable
    dbg!(bfs(puzzle));
    Ok(())
}

mod sliding_puzzle {
    use std::fmt::{Debug, Formatter};
    use std::hash::{Hash, Hasher};

    #[derive(Clone, Copy, Eq, PartialEq)]
    pub struct Puzzle {
        /// The state of the puzzle. `4` represents the empty tile.
        board: [[u8; 3]; 3],

        /// The position of the empty tile. `pos / 3` is the row, and
        /// `pos % 3` is the column.
        pos: u8,
    }

    #[derive(Clone, Copy, Debug, Eq, PartialEq)]
    pub enum PuzzleError {
        InvalidPuzzle,
    }

    impl Puzzle {
        /// Creates a new puzzle from an ID.
        pub fn from_id(mut id: u32) -> Result<Puzzle, PuzzleError> {
            let mut check = 0u16;
            let mut board = [[0; 3]; 3];
            let mut pos = 0u8;

            for row in (0u8..3).rev() {
                for col in (0..3).rev() {
                    let val = (id % 10) as u8;
                    id /= 10;

                    check |= 1 << val;
                    board[row as usize][col as usize] = val;
                    if val == 4 {
                        pos = row * 3 + col;
                    }
                }
            }

            if check == 0b111111111 {
                Ok(Puzzle { board, pos })
            } else {
                Err(PuzzleError::InvalidPuzzle)
            }
        }

        /// Check if the puzzle is solved.
        fn is_solved(&self) -> bool {
            self.board == [[0, 1, 2], [3, 4, 5], [6, 7, 8]]
        }

        /// Check if the puzzle object is valid.
        fn is_valid(&self) -> bool {
            let mut check = 0u16;
            let mut pos = 0u8;
            for row in 0u8..3 {
                for col in 0..3 {
                    let val = self.board[row as usize][col as usize];

                    check |= 1 << val;
                    if val == 4 {
                        pos = row * 3 + col;
                    }
                }
            }
            check == 0b111111111 && pos == self.pos
        }

        /// Returns the indices of row and column of the empty tile.
        fn rowcol(&self) -> (usize, usize) {
            ((self.pos / 3) as usize, (self.pos % 3) as usize)
        }

        /// Returns the unique ID of the puzzle.
        fn id(&self) -> u32 {
            let mut sum = 0u32;
            for row in self.board {
                for val in row {
                    sum = sum * 10 + val as u32;
                }
            }
            sum
        }

        /// Returns the possible moves of the puzzle.
        fn next_moves(&self) -> NextMoves {
            let state = match self.pos {
                0 => 0b01010000,
                1 => 0b01110000,
                2 => 0b01100000,
                3 => 0b11010000,
                4 => 0b11110000,
                5 => 0b11100000,
                6 => 0b10010000,
                7 => 0b10110000,
                8 => 0b10100000,
                _ => unreachable!(),
            };
            NextMoves {
                state,
                puzzle: self,
            }
        }

        /// Returns the next puzzle by moving the empty tile to upper row.
        fn up(&self) -> Puzzle {
            let (row, col) = self.rowcol();

            debug_assert!(self.is_valid());
            debug_assert!(row > 0);

            let mut ret = *self;
            ret.board[row][col] = ret.board[row - 1][col];
            ret.board[row - 1][col] = 4;
            ret.pos -= 3;
            ret
        }

        /// Returns the next puzzle by moving the empty tile to lower row.
        fn down(&self) -> Puzzle {
            let (row, col) = self.rowcol();

            debug_assert!(self.is_valid());
            debug_assert!(row < 2);

            let mut ret = *self;
            ret.board[row][col] = ret.board[row + 1][col];
            ret.board[row + 1][col] = 4;
            ret.pos += 3;
            ret
        }

        /// Returns the next puzzle by moving the empty tile to left column.
        fn left(&self) -> Puzzle {
            let (row, col) = self.rowcol();

            debug_assert!(self.is_valid());
            debug_assert!(col > 0);

            let mut ret = *self;
            ret.board[row][col] = ret.board[row][col - 1];
            ret.board[row][col - 1] = 4;
            ret.pos -= 1;
            ret
        }

        /// Returns the next puzzle by moving the empty tile to right column.
        fn right(&self) -> Puzzle {
            let (row, col) = self.rowcol();

            debug_assert!(self.is_valid());
            debug_assert!(col < 2);

            let mut ret = *self;
            ret.board[row][col] = ret.board[row][col + 1];
            ret.board[row][col + 1] = 4;
            ret.pos += 1;
            ret
        }
    }

    impl Debug for Puzzle {
        fn fmt(&self, f: &mut Formatter) -> std::fmt::Result {
            write!(f, "Puzzle({:09})", self.id())?;
            Ok(())
        }
    }

    impl Hash for Puzzle {
        fn hash<H: Hasher>(&self, state: &mut H) {
            self.id().hash(state)
        }
    }

    #[derive(Clone, Copy, Debug)]
    pub enum Direction {
        Up,
        Down,
        Left,
        Right,
    }

    struct NextMoves<'a> {
        /// 8bits unsigned integer `0bUDLRNNNN` which represents possible next moves of empty tile.
        /// `U` is up, `D` is down, `L` is left, and `R` is right. `NNNN` is the number of current
        /// iteration.
        state: u8,
        puzzle: &'a Puzzle,
    }

    impl Iterator for NextMoves<'_> {
        type Item = (Puzzle, Direction);

        fn next(&mut self) -> Option<Self::Item> {
            let moves = self.state & 0b11110000;
            for n in (self.state & 0b00001111)..4 {
                self.state += 1;

                if moves & (0b10000000 >> n) != 0 {
                    return match n {
                        0 => Some((self.puzzle.up(), Direction::Up)),
                        1 => Some((self.puzzle.down(), Direction::Down)),
                        2 => Some((self.puzzle.left(), Direction::Left)),
                        3 => Some((self.puzzle.right(), Direction::Right)),
                        _ => unreachable!(),
                    };
                }
            }
            None
        }
    }

    pub fn bfs(puzzle: Puzzle) -> Option<Vec<Direction>> {
        use std::collections::hash_map::{Entry, HashMap};
        use std::collections::VecDeque;

        let mut visited: HashMap<Puzzle, Option<(Puzzle, Direction)>> = HashMap::new();
        let mut q: VecDeque<(Puzzle, Option<(Puzzle, Direction)>)> = VecDeque::from([(puzzle, None)]);
        while let Some((puzzle, previous)) = q.pop_front() {
            // Check if the puzzle is already visited.
            match visited.entry(puzzle) {
                Entry::Occupied(_) => continue,
                Entry::Vacant(e) => e.insert(previous),
            };

            // Check if the puzzle is solved.
            if puzzle.is_solved() {
                let mut cursor = puzzle;
                let mut path = Vec::new();

                while let Some((prev, direction)) = visited[&cursor] {
                    path.push(direction);
                    cursor = prev;
                }
                path.reverse();
                return Some(path);
            }

            // Push next states to the q.
            for (next, direction) in puzzle.next_moves() {
                q.push_back((next, Some((puzzle, direction))));
            }
        }
        None
    }
}
