// Sieve of Eratosthenes
// ========
//
// This is my own practice for `NSMutableArray` type. It performs unboxing so it
// is slower than using plain C array.

@import Foundation;

NSArray *sieve(const NSUInteger max) {
  // Make an array instance filled with @YES
  const NSMutableArray * const sieve = [NSMutableArray arrayWithCapacity:max];
  for (NSUInteger i = 0; i < max; ++i) { [sieve addObject:@YES]; }

  // 0 and 1 are not a prime number
  for (NSUInteger i = 0; i < 2 && i < max; ++i) {
    sieve[i] = @NO;
  }

  // Sieve of Eratosthenes
  for (NSUInteger i = 2; i*i <= max; ++i) {
    if ([sieve[i] boolValue]) {
      for (NSUInteger a = i*i; a < max; a += i) { sieve[a] = @NO; }
    }
  }

  // Result array
  const NSMutableArray *const result = NSMutableArray.array;
  [sieve enumerateObjectsUsingBlock:^(NSNumber *elem, NSUInteger idx, BOOL *_) {
    if (!elem.boolValue) { return; }
    [result addObject:[NSNumber numberWithUnsignedInteger:idx]];
  }];
  return result.copy;
}

int main() {
  @autoreleasepool {
    NSArray *primes = sieve(70);

    NSMutableArray *temporal = NSMutableArray.array;
    for (NSNumber *num in primes) {
      [temporal addObject:num.stringValue];
    }

    NSLog(@"%@, ...", [temporal componentsJoinedByString:@", "]);
  }
}
