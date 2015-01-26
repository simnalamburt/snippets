macro_rules! m {
    { $($exp:expr);* } => ({
        $(
            println!("{}", $exp);
        )+
    })
}

fn main() {
    m! {
        3.14f32;
        "Hello";
        false
    };
}
