#![feature(core)]

extern crate rand;

use rand::distributions::{IndependentSample, Range};

fn main() {
    let range = Range::new(0is, 100);
    let mut rng = rand::thread_rng();
    let mut counter = 0us;

    loop {
        counter += 1;
        print!("{:>2} ", range.ind_sample(&mut rng));

        if counter % 30 == 0 { println!(""); }
    }
}
