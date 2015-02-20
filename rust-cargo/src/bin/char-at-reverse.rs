#![feature(core, old_io)]

extern crate core;

use std::old_io::stdin;

fn main() {
    print!("Type any string: ");

    let input = &stdin().read_line().unwrap()[..];
    let input = input.trim();

    let count = core::str::StrExt::char_len(input);

    print!("{:>30} :", "input.char_at()");
    for x in range(0, count) {
        print!(" {}", input.char_at(x));
    }
    println!("");

    print!("{:>30} :", "input.char_at_reverse()");
    for x in range(0, count) {
        print!(" {}", input.char_at_reverse(x));
    }
    println!("");
}
