use std::fmt::Debug;

fn foo1<T: Debug>(val: T) {
    println!("foo1: {val:?}");
}

fn foo2(val: impl Debug) {
    println!("foo2: {val:?}");
}

fn main() {
    let v = Vec::new();
    foo1::<Vec<i32>>(v);

    let v = Vec::new();
    foo2(v as Vec<i32>);
}
