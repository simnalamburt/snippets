#![feature(macro_rules)]

use std::io;

fn main() {
    print!("Type any string: ");

    let line = io::stdin().read_line().ok().expect("Failed to read line");
    let input = line.as_slice().trim();

    println!("{}", input.chars().next_back().unwrap());
}
