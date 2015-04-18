'use strict';

function* guguClass() {
  for (let i = 2; i <= 9; ++i) { yield* guClass(i); }
}

function* guClass(i) {
  for (let j = 2; j <= 9; ++j) { yield [i, j]; }
  yield [];
}

let gen = guguClass();

while (true) {
  const result = gen.next();
  if (result.done) { break; }

  if (result.value.length) {
    const a = result.value[0];
    const b = result.value[1];
    console.log(a + ' * ' + b + ' = ' + a*b);
  } else {
    console.log();
  }
}
