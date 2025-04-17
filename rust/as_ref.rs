use std::borrow::Cow;

fn foo1(param: &str) {
    println!("{param}");
}

fn foo2(param: impl AsRef<str>) {
    let param: &str = param.as_ref();
    println!("{param}");
}

fn main() {
    let s1 = "hello";
    let s2 = String::from("hello");
    let s3 = Cow::Borrowed("hello");
    let s4 = Cow::Owned(String::from("hello"));

    foo1(&s1);
    foo1(&s2);
    foo1(&s3);
    foo1(&s4);

    foo1(s1);
    // foo1(s2); // error[E0308]: mismatched types, expected `&str`, found `String`
    // foo1(s3); // error[E0308]: mismatched types, expected `&str`, found `Cow<'_, str>`
    // foo1(s4); // error[E0308]: mismatched types, expected `&str`, found `Cow<'_, str>`

    foo2(s1);
    foo2(s2);
    foo2(s3);
    foo2(s4);

    foo2(s1);
    // foo2(s2); // error[E0382]: use of moved value
    // foo2(s3); // error[E0382]: use of moved value
    // foo2(s4); // error[E0382]: use of moved value
}
