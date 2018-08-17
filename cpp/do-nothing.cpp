// See 'no-libc.cpp' to see how to compile this source code

extern "C" void _start() {
  asm volatile(R"(
    movq $60,   %rax; # syscall number: SYS_exit
    xorq %rsi,  %rdi; # first parameter: 0
    syscall;          # Go
  )");
}
