const u = (function () {
  const h = [0, 192, 224, 240];
  const c = [0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,2,3,3,3,3,3];
  function b($) { let c = 0; while ($>0) c++, $ >>>= 1; return c; }
  function t($) {
    const cnt = c[b($)];
    const ret = new Array(cnt+1);
    const head = h[cnt];
    for (let i = cnt; i > 0; i--) {
      ret[i] = 128 | $ & 63;
      $ >>>= 6;
    }
    ret[0] = head | $;
    return ret;
  }
  return function ($) {
    return $ === ($|0) && $ >= 0 && $ < 1114112 ? t($) : []
  }
})();

console.log('Test:', u(55176));
console.log('Warming up...');
for (let i = 0; i < 1000000; i++) {
  const val = Math.floor(Math.random() * 0x100);
  u(val);
}

console.time('Normal UTF-8 1000000');
for (let i = 0; i < 1000000; i++) {
  const val = Math.floor(Math.random() * 0x110000);
  u(val);
}
console.timeEnd('Normal UTF-8 1000000');

console.time('UTF-8 invalid codepoints 1000000');
for (let i = 0; i < 1000000; i++) {
  const val = Math.floor(Math.random() * 0x1000) + 0x110000;
  u(val);
}
console.timeEnd('UTF-8 invalid codepoints 1000000');
