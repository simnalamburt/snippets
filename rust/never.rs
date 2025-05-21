//! ```bash
//! rustc --edition=2024 never.rs
//! ```
//!
//! ###### References
//! - https://github.com/rust-lang/rust/issues/113875

#![allow(unreachable_code)]

use std::fmt::Display;

fn ret() -> impl Display {
    todo!()
}

// Following code will not compile
// fn ret2() -> impl Iterator<Item = u8> {
//     todo!()
// }

fn param(a: impl Display) {
    println!("{a}");
}

fn main() {
    println!("{}", ret());

    param(todo!());
}
