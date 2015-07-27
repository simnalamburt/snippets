fn main() {
    'a: for i in 0i32..100 {
        for j in 0..100 {
            for k in 0..100 {
                println!("{}, {}, {}", i, j, k);

                if i > 10 {
                    break 'a;
                }
            }
        }
    }
}
