//! Match

fn main() {
    // 패턴매칭은 존나 강려크합니다

    let a = 30;
    match a {
        10 => println!("붸에에"),
        30 => println!("ㅇㅅㅇ"),
        _ => println!("Otherwise")
    };

    // match문 역시 값을 반환하는 블록 역할을 함
    let a = match a {
        10 => "십",
        30 => "삼십",
        _ => "아더왕",
    };
    println!("a is {}", a);
}
