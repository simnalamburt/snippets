#![feature(collections)]

use std::collections::*;

struct Group;

/// Custom trait to interface `HashMap` and `VecMap`.
trait Map<K, Q: ?Sized, V> {
    /// Interface of `HashMap` and `VecMap`'s `insert` function.
    fn insert(&mut self, K, V) -> Option<V>;
    /// Interface of `HashMap` and `VecMap`'s `get_mut` function.
    fn get_mut(&mut self, k: &Q) -> Option<&mut V>;
}

impl<V> Map<String, str, V> for HashMap<String, V> {
    fn insert(&mut self, k: String, v: V) -> Option<V> {
        self.insert(k, v)
    }

    fn get_mut(&mut self, k: &str) -> Option<&mut V> {
        self.get_mut(k)
    }
}

impl<V> Map<usize, usize, V> for VecMap<V> {
    fn insert(&mut self, k: usize, v: V) -> Option<V> {
        self.insert(k, v)
    }

    fn get_mut(&mut self, k: &usize) -> Option<&mut V> {
        self.get_mut(k)
    }
}

// ------------------------ >8 ------------------------

fn foo<T, V, Q: ?Sized>(map: &mut T, value: V, q1: &Q, q2: &Q) where
    T: Map<V, Q, Group>
{
    map.insert(value, Group);
    assert!(map.get_mut(q1).is_some());
    assert!(map.get_mut(q2).is_none());
}


fn main() {
    foo(&mut HashMap::new(), "a".to_string(), "a", "b");
    foo(&mut VecMap::new(), 100, &100, &200);
}
