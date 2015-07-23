fn main() {
    let list = Vec::<i32>::new();
    // 05.rs:2:9: 2:13 warning: unused variable: `list`, #[warn(unused_variables)] on by default
    // 05.rs:2     let list = Vec::<i32>::new();
    //                 ^~~~

    // 아래것들 다 가능
    // 이를 Parametric Polymorphism
    let list2 = Vec::<f64>::new();
    let list3 = Vec::<String>::new();
    let list4 = Vec::<Vec<i32>>::new();
}
