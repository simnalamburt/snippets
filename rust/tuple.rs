use std::fmt::Debug;

trait ValuePrelude<T> {
    fn equal(&self, T);
    fn typename(&self) -> &'static str;
}

impl<T: PartialEq + Debug> ValuePrelude<T> for T {
    fn equal(&self, rhs: T) {
        assert_eq!(*self, rhs)
    }

    fn typename(&self) -> &'static str {
        unsafe {
            (*std::intrinsics::get_tydesc::<T>()).name
        }
    }
}

trait RefPrelude<T> {
    fn equal(&self, &T);
    fn typename(&self) -> &'static str;
}

impl<'a, T: PartialEq + Debug> RefPrelude<T> for &'a T {
    fn equal(&self, rhs: &T) {
        assert_eq!(*self, rhs)
    }

    fn typename(&self) -> &'static str {
        unsafe {
            (*std::intrinsics::get_tydesc::<*const T>()).name
        }
    }
}

fn main() {
    let a = (1is, 1is);

    println!("{:?}", a);
    println!("{:?}", a.typename()); //=> (int, int)
}
