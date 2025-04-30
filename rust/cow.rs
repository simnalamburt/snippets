use std::borrow::Cow;
use std::collections::HashMap;

fn main() {
    let a = Cow::Borrowed("foo");
    let b = Cow::Owned(String::from("foo"));

    dbg!(a == b);

    let mut map = HashMap::new();
    map.insert(a, 100);
    map.insert(b, 200);
    dbg!(map);
}
