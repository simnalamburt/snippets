//! infinite.rs
//! ========
//!
//! This example shows how to terminate infinite loop within finite time.
//!
//!     $ rustc -O infinite.rs
//!     boom!
//!
//! ##### Tested with
//! - rustc 1.2.0 (082e47636 2015-08-03)
//! - rustc 1.3.0 (9a92aaf19 2015-09-15)
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

// Same with https://github.com/simnalamburt/snippets/blob/master/rust/infinite.rs
// Maintained for https://github.com/rust-lang/rust/issues/28728
