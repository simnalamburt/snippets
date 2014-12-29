#![feature(simd)]

#[simd]
#[deriving(Copy, Show)]
#[repr(C)]
struct i32x2(i32, i32);

fn main() {
    let a = i32x2(10, 20);
    let b = i32x2(05, 05);

    let c = a > b;

    println!("{}", c);
}
