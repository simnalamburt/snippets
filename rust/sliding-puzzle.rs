use sliding_puzzle::*;

fn main() -> Result<(), PuzzleError> {
    let puzzle = Puzzle::from_id(410325678)?;
    dbg!(dfs(puzzle));
    dbg!(bfs(puzzle));
    Ok(())
}

mod sliding_puzzle {
    use std::collections::{HashSet, VecDeque};
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

        /// Returns the 4bits unsigned integer `0bUDLR` which represents possible next moves of empty
        /// tile. `U` is up, `D` is down, `L` is left, and `R` is right.
        fn next_moves(&self) -> u8 {
            match self.pos {
                0 => 0b0101,
                1 => 0b0111,
                2 => 0b0110,
                3 => 0b1101,
                4 => 0b1111,
                5 => 0b1110,
                6 => 0b1001,
                7 => 0b1011,
                8 => 0b1010,
                _ => unreachable!(),
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
            write!(f, "Puzzle({})", self.id())?;
            Ok(())
        }
    }

    impl Hash for Puzzle {
        fn hash<H: Hasher>(&self, state: &mut H) {
            self.id().hash(state)
        }
    }

    pub fn dfs(puzzle: Puzzle) -> Option<u64> {
        let mut visited = HashSet::new();
        let mut stack = Vec::new();
        stack.push((puzzle, 0));

        while let Some((puzzle, dist)) = stack.pop() {
            // Check if the puzzle is solved.
            if puzzle.is_solved() {
                return Some(dist);
            }

            // Check if the puzzle is already visited.
            if visited.contains(&puzzle) {
                continue;
            }
            visited.insert(puzzle);

            // Push next states to the stack.
            let moves = puzzle.next_moves();
            if moves & 0b1000 != 0 {
                stack.push((puzzle.up(), dist + 1));
            }
            if moves & 0b0100 != 0 {
                stack.push((puzzle.down(), dist + 1));
            }
            if moves & 0b0010 != 0 {
                stack.push((puzzle.left(), dist + 1));
            }
            if moves & 0b0001 != 0 {
                stack.push((puzzle.right(), dist + 1));
            }
        }
        None
    }

    pub fn bfs(puzzle: Puzzle) -> Option<u64> {
        let mut visited = HashSet::new();
        let mut queue = VecDeque::new();
        queue.push_back((puzzle, 0));

        while let Some((puzzle, dist)) = queue.pop_front() {
            // Check if the puzzle is solved.
            if puzzle.is_solved() {
                return Some(dist);
            }

            // Check if the puzzle is already visited.
            if visited.contains(&puzzle) {
                continue;
            }
            visited.insert(puzzle);

            // Push next states to the queue.
            let moves = puzzle.next_moves();
            if moves & 0b1000 != 0 {
                queue.push_back((puzzle.up(), dist + 1));
            }
            if moves & 0b0100 != 0 {
                queue.push_back((puzzle.down(), dist + 1));
            }
            if moves & 0b0010 != 0 {
                queue.push_back((puzzle.left(), dist + 1));
            }
            if moves & 0b0001 != 0 {
                queue.push_back((puzzle.right(), dist + 1));
            }
        }
        None
    }
}
