const util = require('util');

Error.prepareStackTrace = (error, trace) => trace;

let stack;
try { stack.e } catch(e) { stack = e.stack; }

stack.forEach(x => {
  const fn = x.getFunctionName();
  console.log(util.inspect(fn, { colors: true }));
});
