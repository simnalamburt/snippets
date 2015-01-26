use std::io;
use std::rand;
use std::rand::distributions::{IndependentSample, Range};

fn main() {
    println!("Guess the number!");

    let secret = Range::new(0us, 10000).ind_sample(&mut rand::thread_rng());
    loop {
        println!("");
        print!("Please input your guess: ");

        let line = io::stdin().read_line().ok().expect("Failed to read line");
        let input: usize = match line[].trim().parse() {
            Some(num) => num,
            None      => {
                println!("Please input a number!");
                continue;
            }
        };

        match cmp(input, secret) {
            Ordering::Less    => println!("It's too small"),
            Ordering::Greater => println!("It's too big"),
            Ordering::Equal   => {
                println!("You WIN");
                return;
            }
        }
    }
}

enum Ordering { Less, Equal, Greater }

fn cmp(left: usize, right: usize) -> Ordering {
    if left < right { Ordering::Less }
    else if left > right { Ordering::Greater }
    else { Ordering::Equal }
}
