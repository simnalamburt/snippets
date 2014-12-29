use std::mem::transmute;

fn main() {
    let lhs: f64 =  0.498633;
    let rhs: f64 = "0.498633".parse().unwrap();
    println!("{} != {}", lhs, rhs);

    let lhs: [u8; 8] = unsafe { transmute(lhs) };
    let rhs: [u8; 8] = unsafe { transmute(rhs) };
    println!("{} != {}", lhs, rhs);
}
