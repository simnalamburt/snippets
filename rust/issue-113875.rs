//! ###### References
//! - https://github.com/rust-lang/rust/issues/113875

#![allow(unreachable_code)]

// Following function will not compile with the error:
//
//     error[E0277]: `!` is not an iterator
//
// fn neveriter() -> impl Iterator<Item = i32> {
//     loop {}
// }

// Workaround:

enum Never {}
impl Iterator for Never {
    type Item = (); // Or `!` if you're using Rust nightly with #![feature(never_type)]
    fn next(&mut self) -> Option<Self::Item> {
        unreachable!()
    }
}

fn neveriter() -> Never {
    loop {}
}

fn main() {
    for item in neveriter() {
        println!("{item:?}");
    }
}
