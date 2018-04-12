enum Void {}

fn main() {
    let mut x: (Void, usize);
    let y = 1;
    x.1 = 0;
    println!("{}", y)
}
