//! ```bash
//! rustc --edition=2024 organic-never.rs
//! ```

#![allow(unused_variables, unreachable_code)]

enum OrganicNever {}

fn main() {
    let never = todo!();

    // ! -> OrganicNever
    let organic_never: OrganicNever = never;

    // OrganicNever -> !
    let never = match organic_never {};
}
