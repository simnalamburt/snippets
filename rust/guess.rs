use std::io;
use std::rand;
use std::rand::distributions::{IndependentSample, Range};

fn main() {
    println!("Guess the number!");

    let secret = Range::new(0u, 10000u).ind_sample(&mut rand::task_rng());
    loop {
        println!("");
        print!("Please input your guess: ");

        let line = io::stdin().read_line().ok().expect("Failed to read line");
        let input = match from_str::<uint>(line.as_slice().trim()) {
            Some(num) => num,
            None      => {
                println!("Please input a number!");
                continue;
            }
        };

        match cmp(input, secret) {
            Less    => println!("It's too small"),
            Greater => println!("It's too big"),
            Equal   => {
                println!("You WIN");
                return;
            }
        }
    }
}

enum Ordering { Less, Equal, Greater }

fn cmp(left: uint, right: uint) -> Ordering {
    if left < right { Less }
    else if left > right { Greater }
    else { Equal }
}
