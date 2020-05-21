use std::error::Error;
use std::io::{stdin, BufRead};

fn main() -> Result<(), Box<dyn Error>> {
    let numbers = stdin()
        .lock()
        .lines()
        .map(|maybe_line| { Ok(maybe_line?.parse()?) })
        .collect::<Result<Vec<i32>, Box<dyn Error>>>()?;

    dbg!(numbers);

    Ok(())
}
