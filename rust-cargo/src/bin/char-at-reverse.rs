#![feature(core, old_io)]

extern crate core;

use std::old_io as io;

fn main() {
    print!("Type any string: ");

    let input = io::stdin().read_line().ok().expect("Failed to read line");
    let input = input[].trim();

    let count = {
        use core::str::StrExt;

        input.char_len()
    };

    print!("{:>30} :", "input.char_at()");
    for x in range(0us, count) {
        print!(" {}", input.char_at(x));
    }
    println!("");

    print!("{:>30} :", "input.char_at_reverse()");
    for x in range(0us, count) {
        print!(" {}", input.char_at_reverse(x));
    }
    println!("");
}
