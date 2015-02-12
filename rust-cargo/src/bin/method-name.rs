// http://is.gd/3wQvvV

struct Dinosaur;

impl Dinosaur {
    // 아래문장이 있어도, 없어도 컴파일됨
    fn say(&self, _: isize) { println!("yee"); }
}

trait Yee {
    fn say(&self, count: isize);
}

impl Yee for Dinosaur {
    fn say(&self, count: isize) {
        if count <= 0 { return; }
        for _ in 0..(count) { print!("봙"); } println!("");
        self.say(count - 1);
    }
}

fn yee<T: Yee>(yee: &T) {
    yee.say(5);
}

fn main() {
    let y = &Dinosaur;

    yee(y);
    println!("");
    y.say(5);
}
