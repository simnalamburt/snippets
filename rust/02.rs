//! Basic

/// 여러분들은 프로니까 한번 따라치고 알아서 이해하세요
fn main() {
    // 변수 선언
    let a: i32 = 10;

    // 조건문
    if a > 5 {
        println!("{} > 5", a);
        println!("");
    }

    // 반복문. 파이썬의 그것과 유사
    for i in 2..10 {
        println!("{} * 2 = {}", i, i*2);
    }

    // 타입이 생략된 변수선언
    // 함수 호출
    let b = foo();
    println!("b is {}\n", b);

    // Nested function
    // 리턴문과 세미콜론없는 expression
}

fn foo() -> i32 {
    10 + 20
}
