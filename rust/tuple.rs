use std::fmt::Show;

trait ValuePrelude<T> {
    fn equal(&self, T);
    fn typename(&self) -> &'static str;
}

impl<T: PartialEq + Show> ValuePrelude<T> for T {
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

impl<'a, T: PartialEq + Show> RefPrelude<T> for &'a T {
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
    let a:(int, int) = (1i, 1i);

    println!("{}", a);
    println!("{}", a.typename()); //=> (int, int)
}
