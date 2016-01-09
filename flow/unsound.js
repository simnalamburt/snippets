/* @flow */
var b: ?number = undefined; // OK
var a: number = undefined; // Check failed, OK (Sound)
var a: number = {}['a']; // Check Passed, Unsound
