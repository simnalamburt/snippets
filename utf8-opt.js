//
// node --trace_opt --trace_deopt --allow-natives-syntax utf8-opt.js
//
"use strict";

const h = [0, 192, 224, 240];
function t($) {
  const cnt = $ < 128 ? 0 : $ < 2048 ? 1 : $ < 65536 ? 2 : 3;
  const ret = new Array(cnt+1);
  const head = h[cnt];
  for (var i = cnt; i > 0; i--) {
    ret[i] = 128 | $ & 63;
    $ >>>= 6;
  }
  ret[0] = head | $;
  return ret;
}
function u($) {
  return $ === ($|0) && $ >= 0 && $ < 1114112 ? t($) : []
}


//
// Bench codes
//
function printStatus(fn) {
  switch(%GetOptimizationStatus(fn)) {
  case 1:   console.log("\x1b[32mFunction is optimized\x1b[0m"); return;
  case 2:   console.log("\x1b[32mFunction is not optimized\x1b[0m"); return;
  case 3:   console.log("\x1b[32mFunction is always optimized\x1b[0m"); return;
  case 4:   console.log("\x1b[32mFunction is never optimized\x1b[0m"); return;
  case 6:   console.log("\x1b[32mFunction is maybe deoptimized\x1b[0m"); return;
  case 7:   console.log("\x1b[32mFunction is optimized by TurboFan\x1b[0m"); return;
  default:  console.log("\x1b[32mUnknown optimization status\x1b[0m"); return;
  }
}

console.log('\x1b[33mTest:', u(55176), '\x1b[0m');
console.log('\x1b[33mExpected    :', [237, 158, 136], '\x1b[0m');

console.log();
printStatus(u);
console.log('\x1b[33mWarming up... (1Mops)\x1b[0m');
for (let i = 0; i < 1000000; i++) {
  const val = Math.floor(Math.random() * 0x100);
  u(val);
}
printStatus(u);
console.log();

console.time('\x1b[33mNormal UTF-8 (10Mops)\x1b[0m');
for (let i = 0; i < 10000000; i++) {
  const val = Math.floor(Math.random() * 0x110000);
  u(val);
}
console.timeEnd('\x1b[33mNormal UTF-8 (10Mops)\x1b[0m');

console.time('\x1b[33mUTF-8 invalid codepoints (10Mops)\x1b[0m');
for (let i = 0; i < 10000000; i++) {
  const val = Math.floor(Math.random() * 0x1000) + 0x110000;
  u(val);
}
console.timeEnd('\x1b[33mUTF-8 invalid codepoints (10Mops)\x1b[0m');

console.log();
printStatus(u);
