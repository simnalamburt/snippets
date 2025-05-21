//! ```bash
//! rustc +nightly --edition=2024 issue-113875-nightly.rs
//! ```
//!
//! ###### References
//! - https://github.com/rust-lang/rust/issues/113875
#![feature(never_type)]
#![allow(unreachable_code)]

// Following function will not compile with the error:
//
//     error[E0277]: `!` is not an iterator
//
// fn neveriter() -> impl Iterator<Item = i32> {
//     loop {}
// }

// Workaround:

#[derive(Eq, PartialEq, Ord, PartialOrd, Clone, Copy, Hash, Debug)]
enum Never {}

impl Iterator for Never {
    type Item = !;
    fn next(&mut self) -> Option<Self::Item> {
        match *self {}
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
