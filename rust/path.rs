use std::env::current_exe;

fn main() {
    if let Ok(path) = current_exe() {
        let mut a = path.clone();
        a.push("..");
        println!("{:?}", a);
        println!("{:?}", (&*path).parent().unwrap());
    }
}
