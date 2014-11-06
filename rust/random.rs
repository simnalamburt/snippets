use std::rand;
use std::rand::distributions::{IndependentSample, Range};

fn main() {
    let range = Range::new(0i, 100i);
    let mut rng = rand::task_rng();
    let mut counter = 0u;

    loop {
        counter += 1;
        print!("{:>2} ", range.ind_sample(&mut rng));

        if counter % 30 == 0 { println!(""); }
    }
}
