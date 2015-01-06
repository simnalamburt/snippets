#![feature(simd, globs, macro_rules)]
#![allow(non_camel_case_types)]

use std::mem::*;

#[simd] #[repr(C)] struct f32x3(f32, f32, f32);
#[simd] struct f32x3_no_c(f32, f32, f32);
struct f32x3_no_simd(f32, f32, f32);
struct OneByte(u8);
struct TwoByte(u16);
struct ThreeByte(u8, u16);
struct FiveByte(u32, u8);

macro_rules! inspect {
    ($($T:ty);*;) => ({
        println!(" {:19} | size_of | min_align_of | align_of | size_of >= min_align_of", "");
        println!("-{:-<19}-+-{:-<7}-+-{:-<12}-+-{:-<8}-+-{:-<23}-", "", "", "", "", "");
        $(
            println!(" {:19} | {:7} | {:12} | {:8} | {}", stringify!($T),
                size_of::<$T>(), min_align_of::<$T>(), align_of::<$T>(),
                size_of::<$T>() >= min_align_of::<$T>());
        )*
        println!("");
    })
}

fn main() {
    inspect! {
        f32x3;
        f32x3_no_c;
        f32x3_no_simd;
    };
    
    inspect! {
        u8;
        OneByte;
        u16;
        TwoByte;
        (u8, u16);
        (u16, u8);
        ThreeByte;
        (u32, u8);
        FiveByte;
        (f32x3, u8);
        (f32x3_no_simd, u8);
    };
}