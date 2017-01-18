//
// node --trace_opt --trace_deopt --allow-natives-syntax utf8-opt.js
//
"use strict";

function case0(input) {
  return [input];
}
function case1(input) {
  return [
    192 | (input >>> 6),
    128 | input & 63,
  ];
}
function case2(input) {
  return [
    224 | (input >>> 12),
    128 | (input >>> 6) & 63,
    128 | input & 63,
  ];
}
function case3(input) {
  return [
    240 | (input >>> 18),
    128 | (input >>> 12) & 63,
    128 | (input >>> 6) & 63,
    128 | input & 63,
  ];
}

function encode(input) {
  if (!(input === (input|0) && input >= 0 && input < 1114112)) { return []; }
  else if (input < 128) { return case0(input); }
  else if (input < 2048) { return case1(input); }
  else if (input < 65536) { return case2(input); }
  else { return case3(input); }
}


//
// Bench codes
//
function printStatus(fn) {
  switch(%GetOptimizationStatus(fn)) {
  case 1:   console.log(`\x1b[32m${fn.name}() : optimized\x1b[0m`); return;
  case 2:   console.log(`\x1b[32m${fn.name}() : not optimized\x1b[0m`); return;
  case 3:   console.log(`\x1b[32m${fn.name}() : always optimized\x1b[0m`); return;
  case 4:   console.log(`\x1b[32m${fn.name}() : never optimized\x1b[0m`); return;
  case 6:   console.log(`\x1b[32m${fn.name}() : maybe deoptimized\x1b[0m`); return;
  case 7:   console.log(`\x1b[32m${fn.name}() : optimized by TurboFan\x1b[0m`); return;
  default:  console.log(`\x1b[32m${fn.name}() : unknown optimization status\x1b[0m`); return;
  }
}
function status() {
  printStatus(encode);
}

console.log('\x1b[33mTest Result :', encode(55176), '\x1b[0m');
console.log('\x1b[33mExpected    :', [237, 158, 136], '\x1b[0m');

console.log();
status();
console.log('\x1b[33mWarming up... (1Mops)\x1b[0m');
for (let i = 0; i < 1000000; i++) {
  const val = Math.floor(Math.random() * 0x100);
  encode(val);
}
status();
console.log();

console.time('\x1b[33mNormal UTF-8 (10Mops)\x1b[0m');
for (let i = 0; i < 10000000; i++) {
  const val = Math.floor(Math.random() * 0x110000);
  encode(val);
}
console.timeEnd('\x1b[33mNormal UTF-8 (10Mops)\x1b[0m');

console.time('\x1b[33mUTF-8 invalid codepoints (10Mops)\x1b[0m');
for (let i = 0; i < 10000000; i++) {
  const val = Math.floor(Math.random() * 0x1000) + 0x110000;
  encode(val);
}
console.timeEnd('\x1b[33mUTF-8 invalid codepoints (10Mops)\x1b[0m');

console.log();
status();
