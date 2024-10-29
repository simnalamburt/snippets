use std::borrow::Cow;
use std::collections::HashMap;

fn main() {
    let a = "Hello, World!";
    let b = "Hello, World!".to_string();

    let a = Cow::from(a);
    let b = Cow::from(b);

    dbg!(a == b);

    let mut map = HashMap::new();
    map.insert(a, 100);
    map.insert(b, 200);
    dbg!(map);
}
