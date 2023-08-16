use blake3::{hash, Hash};
use std::io::{stdin, BufRead, Result};
use std::time::Instant;

const TOTAL_LINE_COUNT: usize = 46366321;

fn main() -> Result<()> {
    let mut f = stdin().lock();
    let mut buf = Vec::new();
    let begin = Instant::now();
    let mut i = 1;
    let mut accum = (0u128, 0u128);

    while let Ok(bytes) = f.read_until(b'\n', &mut buf) {
        if bytes == 0 {
            break;
        }

        let h: [u8; 32] = hash(&buf).into();
        let h: [[u8; 16]; 2] = unsafe { std::mem::transmute(h) };
        accum.0 ^= u128::from_ne_bytes(h[0]);
        accum.1 ^= u128::from_ne_bytes(h[1]);

        // Logging
        if i % 100000 == 0 {
            let permyriad = i * 10000 / TOTAL_LINE_COUNT;
            let eta = begin
                .elapsed()
                .mul_f64(TOTAL_LINE_COUNT as f64 / i as f64 - 1.0f64);
            eprintln!(
                "{i:8}/46366321\t{:2}.{:02}%\tETA: {:.02?}",
                permyriad / 100,
                permyriad % 100,
                eta
            );
        }

        i += 1;
        buf.clear();
    }

    let accum: [u8; 32] =
        unsafe { std::mem::transmute([accum.0.to_ne_bytes(), accum.1.to_ne_bytes()]) };
    println!("{}", Hash::from_bytes(accum));
    Ok(())
}
