#![allow(unreachable_code, unconditional_recursion)]
extern crate rand;

fn main() {
    diverge();
    func(0);
    bar(0);
}

fn diverge() -> ! {
    if rand::random() {
        diverge()
    } else {
        panic!()
    }
}

fn func (a: i32) -> ! {
    if a > 0 {
        func(a + 1)
    } else if a < 0 {
        func(a - 1)
    } else {
        panic!()
    }
}

fn foo (a: i32) -> ! { if a > 0 { bar(a + 1) } else if a < 0 { bar(a - 1) } else { panic!() } }
fn bar (a: i32) -> ! { if a > 0 { foo(a + 1) } else if a < 0 { foo(a - 1) } else { panic!() } }
