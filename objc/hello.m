// Hello, world!
// ========
//
// Compile with the command below:
//
//     clang -fobjc-arc -fmodules -mmacosx-version-min=10.6 hello.m
//
// - `-fobjc-arc`: Enable ARC
// - `-fmodules`: Enable module
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
