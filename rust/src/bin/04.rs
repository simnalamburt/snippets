#![allow(unused_variables)]

//! 제네릭 (1)

/// ### 에러메세지
///
///     03.rs:2:16: 2:24 error: unable to infer enough type information about `_`;
///       type annotations or generic parameter binding required [E0282]
///     03.rs:2     let list = Vec::new();
///                            ^~~~~~~~
///     03.rs:2:16: 2:24 help: run `rustc --explain E0282` to see a detailed explanation
///     error: aborting due to previous error
///
/// ### 설명
///
/// Vec은 구조체의 이름. vector의 약자, 동적배열의 다른이름. Vec 선언을 보면 이렇게 되어있음
///
///     struct Vec<T> { /* ... */ }
///
/// C++의 템플릿에 해당하는놈. Vec은 int 자료형을 담고있는 벡터가 될수도 있고, String 자료형을
/// 담고있는 벡터가 될수도 있다. 임의의 자료형을 담을 수 있음.
///
/// 그래서 Vec::new() 라고 쓰면, T에 해당하는애가 무엇이 될 지 모르기 때문에 컴파일에러가 난것.
fn main() {
    // 아래 문장은 컴파일에러
    // let list = Vec::new();

    let list = Vec::<i32>::new();
}
