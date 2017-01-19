// V8 micro-optimization practice
// ========
// Execute with the command below to make sure that nothing is deoptimized.
//
//     node --trace_deopt --allow-natives-syntax utf8-opt.js
//
// Reference: https://github.com/simnalamburt/web-checklist/blob/master/v8-microoptimization-guide.md
//
// --------
//
// This snippet includes source codes written by third parties. The
// following third party software is included, and carry their own copyright
// notices and license terms:
//
//     MIT License
//
//     Copyright (c) 2017 VBChunguk
//
//     Permission is hereby granted, free of charge, to any person obtaining a copy
//     of this software and associated documentation files (the "Software"), to deal
//     in the Software without restriction, including without limitation the rights
//     to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//     copies of the Software, and to permit persons to whom the Software is
//     furnished to do so, subject to the following conditions:
//
//     The above copyright notice and this permission notice shall be included in all
//     copies or substantial portions of the Software.
//
//     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//     IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//     AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//     LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//     SOFTWARE.
"use strict";

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
  if (input < 2**7) { return [input]; }
  if (input < 2**11) { return case1(input); }
  if (input < 2**16) { return case2(input); }
  return case3(input);
}


//
// Bench codes
//
console.log('\x1b[33mTest Result :', encode(0xD788), '\x1b[0m');
console.log('\x1b[33mExpected    :', [0xED, 0x9E, 0x88], '\x1b[0m');

var i;

console.log();
console.log('\x1b[33mWarming up... (1Mops)\x1b[0m');
for (i = 0; i < 1E6; ++i) {
  encode(
    Math.floor(Math.random() * 0x100) | 0
  );
}
console.log();

console.time('\x1b[33mNormal UTF-8 (10Mops)\x1b[0m');
(_ => {
  for (i = 0; i < 1E7; ++i) {
    encode(
      Math.floor(Math.random() * 0x110000) | 0
    );
  }
})();
console.timeEnd('\x1b[33mNormal UTF-8 (10Mops)\x1b[0m');

console.time('\x1b[33mUTF-8 invalid codepoints (10Mops)\x1b[0m');
(_ => {
  for (i = 0; i < 1E7; ++i) {
    encode(
      (Math.floor(Math.random() * 0x1000) | 0) + 0x110000
    );
  }
})();
console.timeEnd('\x1b[33mUTF-8 invalid codepoints (10Mops)\x1b[0m');

console.log();
