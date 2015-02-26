#![feature(old_io)]
#![allow(unreachable_code)]

use std::old_io::stdio::println;

/// Immediately-invoked closure expression
fn main() {
    println("First");
    (|| {
        println("Second");
        return;
        println("Unreachable!");
    })();
    println("Third");
}
