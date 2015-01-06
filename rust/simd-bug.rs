#![feature(simd, slicing_syntax)]

#[simd]
#[deriving(Show)]
struct f32x3(f32, f32, f32);

fn main() {
    let mut points = Vec::new();

    for _ in 0i..10 {
        points.push(f32x3(1.0, 1.0, 1.0));
    }

    for point in points.iter() {
        println!("{}", point);
    }
}
