function chunk(input, size) {
  'use strict';
  let array = input.slice(0);
  let ret = []
  while (array.length > 0) {
    ret.push(array.splice(0, size));
  }
  return ret;
}

exports.chunk = chunk;
