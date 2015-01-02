#![feature(simd)]

#[simd]
#[deriving(Copy, Show)]
#[allow(non_camel_case_types)]
struct f32x3(f32, f32, f32);

fn main() {
    let a = f32x3(1.0, 2.0, 3.0);
    let b = f32x3(0.5, 1.5, 2.5);

    let c = a - b;

    println!("{}", c);
}
