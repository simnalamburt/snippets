// Hello, world!
// ========
// Compile with the command below:
//
//     clang -fobjc-arc -fmodules -Wall -Wextra -O3 hello.m
//     ./a.out
//
// - `-fobjc-arc`: Enable ARC
// - `-fmodules`: Enable module
// - `-mmacosx-version-min=10.6`: Use it if you want compatibility for legacy platforms
//
// ###### References
// - https://clang.llvm.org/docs/AutomaticReferenceCounting.html
// - https://clang.llvm.org/docs/Modules.html

@import Foundation;

int main() {
  @autoreleasepool {
    NSLog(@"Hello, World! \n");
  }
}
