//! infinite.rs
//! ========
//!
//! This example shows how to terminate infinite loop within finite time.
//!
//!     $ cargo run --bin infinite --release
//!     boom!
//!
//! ##### Tested with
//! - rustc 1.2.0 (082e47636 2015-08-03)
//!
//! ##### Reference:
//! - http://rosaec.snu.ac.kr/publish/2014/techmemo/ROSAEC-2014-002.pdf

fn foo() { loop { } }

fn bar() {
    foo();

    let mut i = 0;
    while i < 100 { i += 1; }
}

fn main() {
    bar();
    println!("boom!\n");
}
