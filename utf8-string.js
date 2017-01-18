const ustr = (function () {
  const fcp = String.fromCodePoint;
  function encodeCodepoint($) {
    $ = $ | 0;
    if ($ < 128) {
      return fcp($);
    } else if ($ < 2048) {
      const a = 128 | $ & 63;
      $ >>>= 6;
      return fcp(192 | $, a);
    } else if ($ < 65536) {
      const a = 128 | $ & 63;
      $ >>>= 6;
      const b = 128 | $ & 63;
      $ >>>= 6;
      return fcp(224 | $, b, a);
    }
    const a = 128 | $ & 63;
    $ >>>= 6;
    const b = 128 | $ & 63;
    $ >>>= 6;
    const c = 128 | $ & 63;
    $ >>>= 6;
    return fcp(240 | $, c, b, a);
  }
  return function ustr(str) {
    let i = -1;
    let ret = '';
    const len = str.length;
    while (++i < len) {
      const $ = str.codePointAt(i) | 0;
      ret += encodeCodepoint($);
    }
    return ret;
  }
})();

console.log('Test:', ustr('\xa9'));
console.log('Warming up...');
let tin = '';
for (let i = 0; i < 1000000; i++) {
  tin += String.fromCharCode(Math.floor(Math.random() * 0x100));
}
ustr(tin);

console.log('Reading text file...');
const inputString = require('fs').readFileSync('input.txt').toString();
const label = `Encode text file ${inputString.length}`;
console.time(label);
ustr(inputString);
console.timeEnd(label);
