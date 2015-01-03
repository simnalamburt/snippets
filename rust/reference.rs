use std::io::stdin;

fn main() {
    let res_a = '가';
    let res_b = 'b';
    let res_c = '@';
    let mut current: &char = &res_a;

    for line in stdin().lock().lines() {
        current = match line.unwrap().as_slice().trim_right() {
            "a" => &res_a,
            "b" => &res_b,
            "c" => &res_c,
            _ => continue,
        };

        println!("      a : {} \t({})", res_a, &res_a as *const char);
        println!("      b : {} \t({})", res_b, &res_b as *const char);
        println!("      c : {} \t({})", res_c, &res_c as *const char);
        println!("current : {} \t({})", *current, current as *const char);
        println!("");
    }
}
