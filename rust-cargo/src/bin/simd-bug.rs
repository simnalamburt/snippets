#![feature(simd, slicing_syntax)]

#[simd]
#[derive(Debug)]
#[allow(non_camel_case_types)]
struct f32x3(f32, f32, f32);

fn main() {
    let mut points = Vec::new();

    for _ in 0is..10 {
        points.push(f32x3(1.0, 1.0, 1.0));
    }

    for point in points.iter() {
        println!("{:?}", point);
    }
}
