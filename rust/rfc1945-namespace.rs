macro_rules! define {
    { $($key:tt = $value:expr;)+ } => {
        $(
            macro_rules! $key (() => ($value));
        )+
    }
}

define! { ACCESS_SYSTEM_SECURITY = 16777216; }

fn foo() {
    define! { WM_CHAR = 258; }
}

fn main() {
    // OK
    println!("{}", ACCESS_SYSTEM_SECURITY!());

    // ERROR!
    println!("{}", WM_CHAR!());
}
