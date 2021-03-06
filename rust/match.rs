#![feature(plugin, custom_derive)]
#![plugin(rand_macros)]

extern crate rand;

use std::io::{stdout, Write};
use rand::random;

#[derive_Rand]
enum Name { Hyeon, Newnyang, P, Sgkim, Sgm, Gallen }

fn main() {
    use self::Name::*;
    fn println(msg: &str) { stdout().write_all(msg.as_bytes()).unwrap() }

    println(match random() {
        Hyeon => "김젼",
        Newnyang => "뉴냥",
        P => "포비아",
        Sgkim => "심규김",
        Sgm => "심규민",
        Gallen => "갈렌"
    });

    println(match 1000i32 {
        0...9 => "한자리수",
        10...99 => "두자리수",
        100...999 => "세자리수",
        1000...9999 => "네자리수",
        _ => "다섯자리 이상"
    });
}
