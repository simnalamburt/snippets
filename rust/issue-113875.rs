//! ```bash
//! rustc --edition=2024 issue-113875.rs
//! ```
//!
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
fn neveriter() -> impl Iterator<Item = i32> {
    (loop {} as Vec<i32>).into_iter()
}

fn main() {
    for item in neveriter() {
        println!("{item:?}");
    }
}
