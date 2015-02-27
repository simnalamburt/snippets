fn foo<T>(param: T) -> T { param }

fn main() {
    println!("{}", foo(foo)(2));
    println!("{}", foo(1));
    println!("{}", foo("a"));
}
