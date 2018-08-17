/*

g++ \
  -std=c++11 -W -Wall -Wextra -Wpedantic -s -Os \
  -nostartfiles -nodefaultlibs -nostdlib -static \
  -fno-exceptions -fno-rtti -fno-stack-protector -fomit-frame-pointer \
  -ffunction-sections -fdata-sections -fno-math-errno -fmerge-all-constants \
  -fno-ident -fno-asynchronous-unwind-tables -fno-unwind-tables \
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
  // size_t, ssize_t definition
  using ssize_t = long int;
  using size_t = unsigned long int;
  static_assert(sizeof(ssize_t) == 8 && sizeof(size_t) == 8,
    "This program targets only x86_64 GNU/Linux environment.");

  // 64-bit system call numbers
  //
  // Reference:
  //   https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/arch/x86/entry/syscalls/syscall_64.tbl
  constexpr auto SYS_write = 1;
  constexpr auto SYS_exit = 60;

  // The file descriptors associated with the standard I/O streams
  //
  // Reference:
  //   STDIN(3), http://man7.org/linux/man-pages/man3/stdin.3.html
  constexpr auto STDIN_FILENO = 0;
  constexpr auto STDOUT_FILENO = 1;
  constexpr auto STDERR_FILENO = 2;

  // SYSCALL(2) - indirect system call
  //
  // Reference:
  //   148 page of AMD64 ABI Draft 1.0, https://github.com/hjl-tools/x86-psABI/wiki/X86-psABI
  //   glibc's syscall() function implementation, https://sourceware.org/git/?p=glibc.git;a=blob;f=sysdeps/unix/sysv/linux/x86_64/syscall.S
  //   SYSCALL(2), http://man7.org/linux/man-pages/man2/syscall.2.html
  extern "C" [[gnu::naked]] long syscall(long number, ...);
  asm volatile(R"(
  syscall:
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

  // WRITE(2) - write to a file descriptor
  ssize_t write(int fd, const void *buf, size_t count) {
    return syscall(SYS_write, fd, buf, count);
  }

  // _EXIT(2) - terminate the calling process
  [[noreturn]] void _exit(int status) {
    syscall(SYS_exit, status);

    __builtin_unreachable();
  }
}

extern "C" void _start() {
  constexpr char message[] { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\n' };

  write(STDOUT_FILENO, message, sizeof message);
  _exit(0);
}
