trait Typename<T> { fn typename(&self) -> &'static str; }

impl<T> Typename<T> for T {
    #[allow(unstable)]
    fn typename(&self) -> &'static str {
        unsafe { *std::intrinsics::get_tydesc::<T>() } .name
    }
}

fn main() {
    let mut obj = Group;

    let a = (1i32, "Hello, world!");
    let b = [1us, 2, 3, 4, 5];
    let c = "Good world";
    let d = &mut obj;

    println!("{}", a.typename());
    println!("{}", b.typename());
    println!("{}", c.typename());
    println!("{}", d.typename());
}

struct Group;
