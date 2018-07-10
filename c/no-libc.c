// gcc -nostdlib no-libc.c

#include <unistd.h>
#include <sys/syscall.h>

static long mini_syscall() {
  asm(
    "movq %rdi,    %rax;" // syscall number -> rax
    "movq %rsi,    %rdi;" // shift arg1 - arg5
    "movq %rdx,    %rsi;"
    "movq %rcx,    %rdx;"
    "movq %r8,     %r10;"
    "movq %r9,     %r8;"
    "movq 8(%rsp), %r9;"  // arg6 is on the stack.
    "syscall;"            // do the system call
    "ret;"                // return to caller
  );
}

ssize_t write(int fd, const void *buf, size_t count) {
  return mini_syscall(SYS_write, fd, buf, count);
}

void _exit(int status) {
  mini_syscall(SYS_exit, status);
  while (1) { } // NOTE: 워닝 제거용
}

void _start() {
  const char message[] = "Hello, world!\n";
  write(STDOUT_FILENO, message, sizeof message);
  _exit(0);
}
