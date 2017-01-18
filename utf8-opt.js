//
// node --allow-natives-syntax utf8-opt.js
// node --trace_opt --trace_deopt --allow-natives-syntax utf8-opt.js
//
"use strict";

function case0(input) {
  return [input];
}
function case1(input) {
  return [
    0b11000000 | (input >>> 6),
    0b10000000 | input & 0b00111111,
  ];
}
function case2(input) {
  return [
    0b11100000 | (input >>> 12),
    0b10000000 | (input >>> 6) & 0b00111111,
    0b10000000 | input & 0b00111111,
  ];
}
function case3(input) {
  return [
    0b11110000 | (input >>> 18),
    0b10000000 | (input >>> 12) & 0b00111111,
    0b10000000 | (input >>> 6) & 0b00111111,
    0b10000000 | input & 0b00111111,
  ];
}

function encode(input) {
  if (input !== (input|0) || input < 0 || input >= 0x00110000) { return []; }
  if (input < 2** 7) { return case0(input); }
  if (input < 2**11) { return case1(input); }
  if (input < 2**16) { return case2(input); }
  return case3(input);
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
  printStatus(case0);
  printStatus(case1);
  printStatus(case2);
  printStatus(case3);
}

console.log('\x1b[33mTest Result :', encode(0xD788), '\x1b[0m');
console.log('\x1b[33mExpected    :', [0xED, 0x9E, 0x88], '\x1b[0m');

var i;

console.log();
status();
console.log('\x1b[33mWarming up... (1Mops)\x1b[0m');
for (i = 0; i < 1E6; ++i) {
  encode(
    Math.floor(Math.random() * 0x100) | 0
  );
}
status();
console.log();

console.time('\x1b[33mNormal UTF-8 (10Mops)\x1b[0m');
for (i = 0; i < 1E7; ++i) {
  encode(
    Math.floor(Math.random() * 0x110000) | 0
  );
}
console.timeEnd('\x1b[33mNormal UTF-8 (10Mops)\x1b[0m');

console.time('\x1b[33mUTF-8 invalid codepoints (10Mops)\x1b[0m');
for (i = 0; i < 1E7; ++i) {
  encode(
    (Math.floor(Math.random() * 0x1000) | 0) + 0x110000
  );
}
console.timeEnd('\x1b[33mUTF-8 invalid codepoints (10Mops)\x1b[0m');

console.log();
status();
