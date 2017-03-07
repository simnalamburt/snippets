#![feature(core, str_char)]

extern crate core;

use std::io::stdin;

fn main() {
    print!("Type any string: ");

    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    let input = line[..].trim();

    let count = core::str::StrExt::char_len(input);

    print!("{:>30} :", "input.char_at()");
    for x in 0..count {
        print!(" {}", input.char_at(x));
    }
    println!("");

    print!("{:>30} :", "input.char_at_reverse()");
    for x in 0..count {
        print!(" {}", input.char_at_reverse(x));
    }
    println!("");
}
