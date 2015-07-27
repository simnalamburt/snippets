extern crate num;

fn main() {
    let a: Option<u16> = num::cast(0x1000000);
    let b: Option<u16> = num::cast(0x10000);
    let c: Option<u16> = num::cast(0x100);

    println!("{:?}", a);
    println!("{:?}", b);
    println!("{:?}", c);
}
