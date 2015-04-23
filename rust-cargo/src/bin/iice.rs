#![allow(unreachable_code)]

use std::io::{stdout, Write};

/// Immediately-invoked closure expression
fn main() {
    fn println(msg: &str) { stdout().write_all(msg.as_bytes()).unwrap() }

    println("First");
    (|| {
        println("Second");
        return;
        println("Unreachable!");
    })();
    println("Third");
}
