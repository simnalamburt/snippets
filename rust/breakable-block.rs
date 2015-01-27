#![allow(unreachable_code)]

fn main() {
    println!("ok");

    (|:| {
        println!("ok");

        return;

        panic!();
    })();

    println!("ok");
}
