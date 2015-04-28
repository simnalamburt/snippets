use std::io::{stdin, BufRead};

fn main() {
    let res_a = '가';
    let res_b = 'b';
    let res_c = '@';

    println!("a = {:?} ... {:?}", res_a, &res_a as *const char);
    println!("b = {:?} ... {:?}", res_b, &res_b as *const char);
    println!("c = {:?} ... {:?}", res_c, &res_c as *const char);
    println!("");
    println!("a, b, c 셋 중 하나를 입력하세요.");
    print!("ptr: ");
    let mut ptr: &char;

    let stdin = stdin();
    for line in stdin.lock().lines() {
        ptr = match line.unwrap()[..].trim_right() {
            "a" => &res_a,
            "b" => &res_b,
            "c" => &res_c,
            _ => continue,
        };

        println!("ptr = {:?} ... {:?}", ptr, ptr as *const char);
        println!("");
        print!("ptr: ");
    }
}
