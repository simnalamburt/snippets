'use strict';

let x = (() => {
  for (var i = 0; i < 5; ++i) {
    try {
      return i;
    } finally {
      if (i !== 3) continue;
    }
  }
})();
console.log(x); // 3
