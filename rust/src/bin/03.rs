//! Advanced

fn main() {
    let war = 10;

    println!("war is {}", war);
    // war = 20;
    // 03.rs:7:5: 7:13 error: re-assignment of immutable variable `war`
    // 03.rs:7     war = 20;
    //
    // 고칠수없는 변수의 값을 고쳤다는뜻.
    // Rust는 변수선언을 하면 기본적으로 immutable임
    println!("war never changes");
    println!("");

    let mut p = 10;
    println!("p was {}", p);
    p = 20;
    println!("But now p is {}", p);
}
