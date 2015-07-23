//! 제네릭, 타입추론

fn main() {
    // ::<i32> 생략가능. 이것이 바로 타입 추론
    let mut list = Vec::<i32>::new();

    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);

    for i in list.into_iter() {
        println!("{}", i);
    }
}
