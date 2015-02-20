#![feature(core)]

trait Typename { fn typename(&self) -> &'static str; }

impl<T> Typename for T {
    fn typename(&self) -> &'static str {
        unsafe { *std::intrinsics::get_tydesc::<T>() } .name
    }
}

fn main() {
    let mut obj = Group;

    let a = (1, "Hello, world!");
    let b = [1, 2, 3, 4, 5];
    let c = "Good world";
    let d = &mut obj;

    println!("{}", a.typename());
    println!("{}", b.typename());
    println!("{}", c.typename());
    println!("{}", d.typename());
}

struct Group;
