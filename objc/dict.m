// Dictionary
// ========
// Compile with the command below:
//
//     clang -fobjc-arc -fmodules -Wall -Wextra -O3 dict.m
//     ./a.out
//
// ###### References
// - https://developer.apple.com/reference/foundation/nsdictionary
// - https://developer.apple.com/reference/foundation/nsmutabledictionary

@import Foundation;

static void vwrite(const NSFileHandle *fd, NSString *format, va_list arguments);
static void vprint(NSString *format, va_list arguments);
static void vprintln(NSString *format, va_list arguments);
static void println(NSString *format, ...);

int main() {
  @autoreleasepool {
    const NSMutableDictionary * const map = [NSMutableDictionary dictionary];

    map[@"a"] = @10;
    map[@"b"] = @YES;
    map[@"c"] = @3.141592;
    map[@"d"] = @"YOLO";

    for (id key in map) { println(@"%@ : %@", key, map[key]); }
    println(@"");

    map[@"a"] = @300;
    map[@"b"] = @NO;
    map[@"c"] = @2.414;
    map[@"e"] = @"THOUSAND SUN";

    for (id key in map) { println(@"%@ : %@", key, map[key]); }
  }
}

static void vwrite(const NSFileHandle *fd, NSString *format, va_list arguments) {
  const NSString * const string = [[NSString alloc] initWithFormat: format arguments: arguments];
  NSData *const strData = [string dataUsingEncoding: NSUTF8StringEncoding];
  [fd writeData: strData];
}

static void vprint(NSString *format, va_list arguments) {
  vwrite([NSFileHandle fileHandleWithStandardOutput], format, arguments);
}

static void vprintln(NSString *format, va_list arguments) {
  vprint([format stringByAppendingString:@"\n"], arguments);
}

static void println(NSString *format, ...) {
  va_list arguments;
  va_start(arguments, format);
  vprintln(format, arguments);
  va_end(arguments);
}
