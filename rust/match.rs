#![feature(globs)]

use self::User::*;

enum User {
    Hyeon,
    Newnyang,
    P,
    Sgkim,
    Sgm,
    Gallen,
}

fn main() {
    let a = Newnyang;

    println!("{}", match a {
        Hyeon => "김젼",
        Newnyang => "뉴냥",
        P => "포비아",
        Sgkim => "심규김",
        Sgm => "심규민",
        Gallen => "갈렌"
    });
}
