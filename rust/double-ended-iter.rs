fn main () {
    let a = [1, 2, 3, 4, 5, 6, 7, 8, 9];
    let mut iter = a.iter();

    println!("{:?}", iter.next()); // Some(1)
    println!("{:?}", iter.next()); // Some(2)

    let mut iter = iter.rev();

    println!("{:?}", iter.next()); // Some(9)
    println!("{:?}", iter.next()); // Some(8)
    println!("{:?}", iter.next()); // Some(7)

    let mut iter = iter.rev();

    println!("{:?}", iter.next()); // Some(3)
    println!("{:?}", iter.next()); // Some(4)

    let mut iter = iter.rev();

    println!("{:?}", iter.next()); // Some(6)
    println!("{:?}", iter.next()); // Some(5)
    println!("{:?}", iter.next()); // None
}
