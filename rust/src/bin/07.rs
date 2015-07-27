#![allow(unused_variables)]

//! Basic (2)
//!
//! - Name hiding
//! - Statements as an expression
//! - Underscore

fn main() {
    // 1. Name hiding
    let a = 10;
    let a = "하티하티하티호";
    let a = 3.14;

    // 변수의 값을 고친것이 아님.
    // 이름이 같은 새 변수를 선언하고, 앞의 변수는 이름이 '가려진것'
    // 변수의 이름이 가려졌다고 변수가 일찍 죽거나 하진 않는다.


    // 2. Statements as an expression
    let a = {
        let b = 10;
        let c = 20;
        b + c
    };
    println!("a is {}", a);
    println!("");
    // 마치 함수가 반환한 값을 caller가 받아서 사용하듯, 블록이 반환한 값을 a가 받아서 사용했음

    println!("Braces can go anywhere: {}", {
        // 블록은 아무데나 펼쳐질 수 있음
        let a = 3.14;
        let b = 2.141;
        a * b
    });
    println!("");

    let a = if 10 > 5 {
        "10은 5보다 크다"
    } else {
        "10은 5보다 작돠?"
    };
    // 단순 블록뿐만 아니라, 이런 문장들에도 적용됨
    println!("{}", a);
    println!("");


    // 3. Underscore
    for _ in 0..10 {
        // 사용하지 않을 변수는 이름을 _ 로 선언하면, unused variable 경고가 사라짐
        println!("비둘기야 먹자");
    }
    println!("");
}
