/*

g++ \
  -std=c++11 -W -Wall -Wextra -Wpedantic -s -Os \
  -nostartfiles -nodefaultlibs -nostdlib -static \
  -fno-exceptions -fno-rtti -fno-stack-protector -fomit-frame-pointer \
  -ffunction-sections -fdata-sections -fno-math-errno -fmerge-all-constants \
  -fno-ident \
  -Wl,--build-id=none,--gc-sections,-z,norelro \
  no-libc.cpp &&\
  \
  strip -S --strip-unneeded \
  --remove-section=.note.gnu.gold-version \
  --remove-section=.comment \
  --remove-section=.note \
  --remove-section=.note.gnu.build-id \
  --remove-section=.note.ABI-tag \
  a.out

*/

namespace {
  using i8 = signed char;
  using i16 = signed short int;
  using i32 = signed int;
  using i64 = signed long int;

  using u8 = unsigned char;
  using u16 = unsigned short int;
  using u32 = unsigned int;
  using u64 = unsigned long int;

  static_assert(
    sizeof(i8) == 1 && sizeof(i16) == 2 && sizeof(i32) == 4 && sizeof(i64) == 8 &&
    sizeof(u8) == 1 && sizeof(u16) == 2 && sizeof(u32) == 4 && sizeof(u64) == 8,
    "This program targets only x86_64 GNU/Linux environment.");

  // Reference: https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/arch/x86/entry/syscalls/syscall_64.tbl
  constexpr auto SYS_write = 1;
  constexpr auto SYS_exit = 60;

  // Reference: http://man7.org/linux/man-pages/man3/stdin.3.html
  constexpr auto STDIN_FILENO = 0;
  constexpr auto STDOUT_FILENO = 1;
  constexpr auto STDERR_FILENO = 2;

  // References:
  // - 148 page of AMD64 ABI Draft 1.0, https://github.com/hjl-tools/x86-psABI/wiki/X86-psABI
  // - glibc's syscall() function implementation, https://sourceware.org/git/?p=glibc.git;a=blob;f=sysdeps/unix/sysv/linux/x86_64/syscall.S
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
  i64 syscall(...) {
    asm(R"(
      movq %rdi,    %rax; # syscall number -> rax
      movq %rsi,    %rdi; # shift arg1 - arg5
      movq %rdx,    %rsi;
      movq %rcx,    %rdx;
      movq %r8,     %r10;
      movq %r9,     %r8;
      movq 8(%rsp), %r9;  # arg6 is on the stack.
      syscall;            # do the system call
      ret;                # return to caller
    )");
  }
#pragma GCC diagnostic pop

  i64 write(int fd, const void *buf, u64 count) {
    return syscall(SYS_write, fd, buf, count);
  }

  [[noreturn]] void _exit(int status) {
    syscall(SYS_exit, status);
    while (true) { }
  }
}

extern "C"
void _start() {
  constexpr u8 message[] = "Hello, world!\n";

  write(STDOUT_FILENO, message, sizeof message);
  _exit(0);
}
