extern crate libc;

use std::ffi::CString;
use libc::types::os::arch::posix01::utimbuf;
use libc::funcs::posix88::unistd::utime;

fn main() {
    let buf = utimbuf {
        actime: 0,
        modtime: 0,
    };

    let name = CString::new("utime").unwrap();

    let ret = unsafe { utime(name.as_ptr(), &buf) };
    if ret != 0 {
        println!("utime: 실패!");
        std::process::exit(1);
    }
}
