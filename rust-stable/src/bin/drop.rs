#[derive(Debug)]
struct Bass;

impl Bass {
    fn drop_it(&self) {
        println!("Drop da bass");
    }
}

fn main() {
    let bass = Bass;
    bass.drop_it();
    drop(bass);
    // bass.drop_it(); <- Error
}
