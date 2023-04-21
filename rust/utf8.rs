use std::time::Instant;

mod stdlib {
    pub fn get_tokens(input: &str) -> Vec<&str> {
        let mut ret = Vec::new();

        let mut fsm = None;
        for (idx, ch) in input.char_indices() {
            if ch.is_ascii_punctuation() || ch.is_ascii_whitespace() {
                if let Some(start) = fsm {
                    ret.push(&input[start..idx]);
                }
                fsm = None;
            } else {
                if fsm.is_none() {
                    fsm = Some(idx);
                }
            }
        }
        if let Some(start) = fsm {
            ret.push(&input[start..]);
        }

        ret
    }
}

mod manual {
    pub fn get_tokens(input: &str) -> Vec<&str> {
        let mut ret = Vec::new();

        let mut fsm = None;

        let bytes = input.as_bytes();
        let mut idx = 0;
        while let Some((ch, width)) = next_char_and_width(bytes, idx) {
            if ch.is_ascii_punctuation() || ch.is_ascii_whitespace() {
                if let Some(start) = fsm {
                    ret.push(&input[start..idx]);
                }
                fsm = None;
            } else {
                if fsm.is_none() {
                    fsm = Some(idx);
                }
            }

            idx += width;
        }
        if let Some(start) = fsm {
            ret.push(&input[start..]);
        }

        ret
    }

    fn next_char_and_width(bytes: &[u8], idx: usize) -> Option<(char, usize)> {
        const CONT_MASK: u8 = 0b0011_1111;

        #[inline]
        const fn utf8_acc_cont_byte(ch: u32, byte: u8) -> u32 {
            (ch << 6) | (byte & CONT_MASK) as u32
        }

        let x = *bytes.get(idx)?;
        if x < 128 {
            let c = unsafe { char::from_u32_unchecked(x as u32) };
            return Some((c, 1));
        }

        let init = (x & (0x7F >> 2)) as u32;
        let y = bytes[idx + 1];
        let mut ch = utf8_acc_cont_byte(init, y);
        let mut width = 2;
        if x >= 0xE0 {
            let z = bytes[idx + 2];
            let y_z = utf8_acc_cont_byte((y & CONT_MASK) as u32, z);
            ch = init << 12 | y_z;
            width = 3;
            if x >= 0xF0 {
                let w = bytes[idx + 3];
                ch = (init & 7) << 18 | utf8_acc_cont_byte(y_z, w);
                width = 4;
            }
        }

        let c = unsafe { char::from_u32_unchecked(ch) };
        Some((c, width))
    }
}

fn main() {
    let data = "(hello)   (  blank  ) 한글+🐸🐼 end";
    println!("{:?}", stdlib::get_tokens(data));
    println!("{:?}", manual::get_tokens(data));

    let now = Instant::now();
    for _ in 0..50_000_000 {
        stdlib::get_tokens(data);
    }
    println!("stdlib: {:?}", now.elapsed());

    let now = Instant::now();
    for _ in 0..50_000_000 {
        manual::get_tokens(data);
    }
    println!("manual: {:?}", now.elapsed());
}
