// NSURL
// ========
//
//     clang -fobjc-arc -fmodules -Wall -Wextra -O3 url.m
//     ./a.out

@import Foundation;

void vwrite(const NSFileHandle *fd, NSString *format, va_list arguments) {
  const NSString * const string = [[NSString alloc] initWithFormat: format arguments: arguments];
  NSData *const strData = [string dataUsingEncoding: NSUTF8StringEncoding];
  [fd writeData: strData];
}

void vprint(NSString *format, va_list arguments) {
  vwrite([NSFileHandle fileHandleWithStandardOutput], format, arguments);
}

void vprintln(NSString *format, va_list arguments) {
  vprint([format stringByAppendingString:@"\n"], arguments);
}

void print(NSString *format, ...) {
  va_list arguments;
  va_start(arguments, format);
  vprint(format, arguments);
  va_end(arguments);
}

void println(NSString *format, ...) {
  va_list arguments;
  va_start(arguments, format);
  vprintln(format, arguments);
  va_end(arguments);
}

// WIP
static BOOL compareURL(
  const NSURL * const _Nonnull left,
  const NSURL * const _Nonnull right
) {
  if ([left isEqual:right]) { return YES; }
  if ([left.scheme caseInsensitiveCompare:right.scheme] != NSOrderedSame) { return NO; }
  if ([left.host caseInsensitiveCompare:right.host] != NSOrderedSame) { return NO; }

  // NSURL path is smart about trimming trailing slashes. Note case-sensitivty here
  if ([left.path compare:right.path] != NSOrderedSame) { return NO; }

  // At this point, we've established that the urls are equivalent according to
  // the RFC1808 insofar as scheme, host, and paths match

  // TODO: According to RFC2616, port's can weakly match if one is missing and
  // the other is default for the scheme.

  // Compare port numbers
  if (left.port || right.port) {
    if (![left.port isEqual:right.port]) { return NO; }
    if (![left.query isEqual:right.query]) { return NO; }
  }

  return YES;

  // References:
  //   https://www.ietf.org/rfc/rfc1808.txt
  //   https://www.ietf.org/rfc/rfc2616.txt
  //   http://stackoverflow.com/a/12332091
}

int main() {
  @autoreleasepool {
    const NSURL * const url = [NSURL URLWithString:@"http://google.com"];
    println(@"url = %@", url);
    println(@"");

    NSString *str1 = [NSString stringWithFormat:@"%@", url];
    NSString *str2 = url.absoluteString;
    println(@"[NSString stringWithFormat:@\"%%@\", url] = %@", str1);
    println(@"                    url.absoluteString = %@", str2);
    println(@"");

    println(@"Is it same? = %@", [str1 isEqualToString:str2] ? @"Same" : @"Differenct");
    println(@"");

    [str2 substringFromIndex:str2.length - 4];
    println(@"(Just called substringFromIndex method)");
    println(@"Is it still same? = %@", [str1 isEqualToString:str2] ? @"Same" : @"Differenct");
    println(@"");

    println(@"Comparing '%@' to other strings...", url);
    println(@"");
    println(@"isEqual | compareURL | operand");
    println(@"--------|------------|--------");

    void (^const compare)(NSString * _Nonnull) = ^void(NSString * _Nonnull const input) {
      NSURL * const operand = [NSURL URLWithString:input];
      println(
          @" %-6s | %-10s | %@",
          [url isEqual:operand] ? "YES" : "NO",
          compareURL(url, operand) ? "YES" : "NO",
          operand);
    };

    compare(@"http://google.com");
    println(@"        |            |");
    compare(@"HTTP://google.com");
    compare(@"http://GOOGLE.COM");
    compare(@"http://google.com?");
    compare(@"http://google.com?a");
    compare(@"http://google.com#");
    compare(@"http://google.com#a");
    println(@"        |            |");
    compare(@"http://google.com:80");
    compare(@"http://google.com/");
  }
}
