//! Boilerplate for lightweight Rust binary
//! ========
//! Welcome to the libc-free world! Your binary will be super lightweight and
//! easy to deploy. Don't bother with shared objects anymore!
//!
//!     # With rustc 1.40.0
//!     RUSTC_BOOTSTRAP=1 rustc --target=i686-unknown-linux-gnu \
//!       -C opt-level=s \
//!       -C panic=abort \
//!       -C link-args='-nostartfiles -nodefaultlibs -nostdlib -static
//!         -fno-exceptions -fno-asynchronous-unwind-tables -fno-unwind-tables -fno-stack-protector
//!         -Wl,--build-id=none,--gc-sections,--omagic' \
//!       -C relocation-model=static \
//!       no-libc.rs
//!     strip -s \
//!       -R .comment \
//!       -R .note \
//!       -R .note.ABI-tag \
//!       -R .note.gnu.build-id \
//!       -R .note.gnu.gold-version \
//!       no-libc
//!
//!     readelf -e no-libc
//!     stat '-c%s' no-libc
//!     # 308

#![feature(core_intrinsics, asm)]
#![no_std]
#![no_main]

const SYS_WRITE: i32 = 4;
const SYS_EXIT: i32 = 1;
const STDOUT_FILENO: i32 = 1;

/// WRITE(2) - write to a file descriptor
fn write(fd: i32, buf: *const u8, count: usize) -> isize {
    let ret: isize;
    unsafe {
        asm!("int $$0x80"
            : "={eax}"(ret)
            : "{eax}"(SYS_WRITE), "{ebx}"(fd), "{ecx}"(buf), "{edx}"(count)
            : "memory" "cc"
            : "volatile"
        );
    }
    ret
}

/// _EXIT(2) - terminate the calling process
fn _exit(status: i32) -> ! {
    unsafe {
        asm!("int $$0x80"
            :
            : "{eax}"(SYS_EXIT), "{ebx}"(status)
            : "memory" "cc"
            : "volatile"
        );
        core::hint::unreachable_unchecked();
    }
}

/// Entrypoint
#[no_mangle]
extern "C" fn _start() -> ! {
    // rustc will generate '.rodata' section if you use string literals
    let message = [b'H', b'e', b'l', b'l', b'o', b',', b' ', b'w', b'o', b'r', b'l', b'd', b'!', b'\n'];

    write(STDOUT_FILENO, message.as_ptr(), message.len());
    _exit(0);
}

/// Abort on panic
#[panic_handler]
#[no_mangle]
extern "C" fn panic(_info: &core::panic::PanicInfo) -> ! {
    unsafe { core::intrinsics::abort() }
}
