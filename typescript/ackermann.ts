import assert from 'node:assert/strict';

// naive implementation
function ackermann0(m: bigint, n: bigint): bigint {
  if (m < 0n) { return 0n; }
  if (m === 0n) { return n + 1n; }
  if (n < 0n) { return 0n; }
  if (n === 0n) { return ackermann0(m - 1n, 1n); }
  return ackermann0(m - 1n, ackermann0(m, n - 1n));
}

// partial tail recursion, handle low m
function ackermann1(m: bigint, n: bigint): bigint {
  for (;;) {
    if (m < 0n) { return 0n; }
    if (m === 0n) { return n + 1n; }
    if (m === 1n) { return n + 2n; }
    if (m === 2n) { return 2n * n + 3n; }
    if (m === 3n) { return 2n ** (n + 3n) - 3n; }
    if (n < 0n) { return 0n; }
    if (n === 0n) { m = m - 1n; n = 1n; continue; }
    const temp = ackermann1(m, n - 1n);
    m = m - 1n; n = temp;
  }
}

// no recursion
function ackermann2(m0: bigint, n0: bigint): bigint {
  const stack: [bigint, bigint][] = [];
  let ret: bigint | undefined = undefined;

  let mn: [bigint, bigint] | undefined = [m0, n0];
  do {
    let [m, n] = mn;

    for (;;) {
      if (m < 0n) { ret = 0n; break; }
      if (m === 0n) { ret = n + 1n; break; }
      if (m === 1n) { ret = n + 2n; break; }
      if (m === 2n) { ret = 2n * n + 3n; break; }
      if (m === 3n) { ret = 2n ** (n + 3n) - 3n; break; }
      if (n < 0n) { ret = 0n; break; }
      if (n === 0n) { m = m - 1n; n = 1n; continue; }

      // Recursive call
      if (ret === undefined) {
        stack.push([m, n]);
        n = n - 1n;
        continue;
      }

      // Returned from recursive call
      m = m - 1n;
      n = ret;
      ret = undefined;
    }
  } while (mn = stack.pop());

  return ret;
}

const m = 4n;
const n = 2n;

//console.time("ackermann0");
//console.log(ackermann0(m, n));
//console.timeEnd("ackermann0");

console.time("ackermann1");
const ret1 = ackermann1(m, n)
console.timeEnd("ackermann1");

console.time("ackermann2");
const ret2 = ackermann2(m, n);
console.timeEnd("ackermann2");

assert.deepEqual(ret1, ret2);
