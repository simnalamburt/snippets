use std::env::args;

fn main() {
    for arg in args() {
        println!("{:?}", arg);
    }
}
