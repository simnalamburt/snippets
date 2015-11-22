// ES6 style
import * as hello from './export-hello';

console.log(hello.hello());

// commonjs
declare var require: (string) => any;
var fs = require('fs');

console.log(fs.readdirSync('.'));
