use std::mem::zeroed;

#[derive(Debug)]
struct Data<T = i32> { data: T }

fn new<T>() -> Data<T> { Data { data: unsafe { zeroed() } } }

fn main() {
    let a: Data = new();
    println!("{:?}", a);
}
