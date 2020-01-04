/*

Boilerplate for lightweight C++ binary
========
Welcome to the libc-free world! Your binary will be super lightweight and
easy to deploy. Don't bother with shared objects anymore!

    # Both clang++ and g++ are supported
    # You are free to remove the '-m32' option below if you want
    clang++ -m32 \
      -std=c++11 -Wall -Wextra -Wpedantic -s -Oz -nostartfiles -nodefaultlibs -nostdlib -static \
      -fno-exceptions -fno-asynchronous-unwind-tables -fno-unwind-tables -fno-stack-protector \
      -Wl,--build-id=none,--gc-sections,--omagic no-libc.cpp
    strip -S --strip-unneeded \
      --remove-section=.note.gnu.gold-version \
      --remove-section=.comment \
      --remove-section=.note \
      --remove-section=.note.gnu.build-id \
      --remove-section=.note.ABI-tag \
      a.out

    stat '-c%s' ./a.out
    # The size of the compiled binary will be around 500 bytes

See Also:
  https://github.com/dfouhey/caffe64

*/

#if !defined(__x86_64__) && !defined(__i386__)
static_assert(false, "Unsupported build target");
#endif

namespace {
  // size_t, ssize_t definition
  using ssize_t = long;
  using size_t = unsigned long;
  static_assert(
      sizeof(ssize_t) == sizeof(void *) && sizeof(size_t) == sizeof(void *),
      "This program targets only x86 and x86-64 GNU/Linux environment");

  // System call numbers
  //
  // Reference:
  //   https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/arch/x86/entry/syscalls/syscall_64.tbl
  //   https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/arch/x86/entry/syscalls/syscall_32.tbl
#ifdef __x86_64__
  constexpr auto SYS_write  = 1;
  constexpr auto SYS_exit   = 60;
#else
  constexpr auto SYS_write  = 4;
  constexpr auto SYS_exit   = 1;
#endif

  // The file descriptors associated with the standard I/O streams
  //
  // Reference:
  //   http://man7.org/linux/man-pages/man3/stdin.3.html
  constexpr auto STDOUT_FILENO = 1;

  // SYSCALL(2) - indirect system call
  //
  // Reference:
  //   148 page of AMD64 ABI Draft 1.0, https://github.com/hjl-tools/x86-psABI/wiki/X86-psABI
  //   http://man7.org/linux/man-pages/man2/syscall.2.html
  //   https://sourceware.org/git/?p=glibc.git;a=blob;f=sysdeps/unix/sysv/linux/x86_64/syscall.S
  //   https://sourceware.org/git/?p=glibc.git;a=blob;f=sysdeps/unix/sysv/linux/i386/syscall.S
  extern "C" [[gnu::naked]] long syscall(long number, ...);
#ifdef __x86_64__
  asm(R"(
    .text
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
#else
  asm(R"(
    .text
  syscall:
    # save register contents
    pushl %ebp;
    pushl %edi;
    pushl %esi;
    pushl %ebx;

    # load arguments
    movl 44(%esp), %ebp;
    movl 40(%esp), %edi;
    movl 36(%esp), %esi;
    movl 32(%esp), %edx;
    movl 28(%esp), %ecx;
    movl 24(%esp), %ebx;

    # load syscall number into %eax
    movl 20(%esp), %eax;

    # do the system call
    int $0x80;

    # restore register contents
    popl %ebx;
    popl %esi;
    popl %edi;
    popl %ebp;

    # return to caller
    ret;
  )");
#endif

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
