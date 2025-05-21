// Assume Axiom of Choice

trait VectorSpace {
    const DIMENSION: usize;
}

fn dim<T: VectorSpace>() -> usize {
    T::DIMENSION
}

struct R3(f64, f64, f64);
struct R0;

impl VectorSpace for R3 {
    const DIMENSION: usize = 42;
}

impl VectorSpace for R0 {
    const DIMENSION: usize = 0;
}

pub fn main() {
    println!("{}", dim::<R3>());
    println!("{}", dim::<R0>());
    // println!("{}", dim::<!>()); // What value should be returned?
}
