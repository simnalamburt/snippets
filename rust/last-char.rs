use std::io;

fn main() {
    print!("Type any string: ");

    let line = io::stdin().read_line().ok().expect("Failed to read line");
    let input = line[].trim();

    println!("{}", input.chars().next_back().unwrap());
}
