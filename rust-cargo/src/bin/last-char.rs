#![feature(old_io)]

use std::old_io::stdin;

fn main() {
    print!("Type any string: ");

    let line = stdin().read_line().ok().expect("Failed to read line");
    let input = line[..].trim();

    println!("{}", input.chars().next_back().unwrap());
}
