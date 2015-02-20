#![allow(unreachable_code)]

/// Immediately-invoked closure expression
fn main() {
    println!("ok");
    (|| {
        println!("ok");
        return;
        panic!();
    })();
    println!("ok");
}
