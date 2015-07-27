use std::io::stdin;

fn main() {
    print!("Type any string: ");

    let mut line = String::new();
    stdin().read_line(&mut line).unwrap();
    let input = line[..].trim();

    println!("{}", input.chars().next_back().unwrap());
}
