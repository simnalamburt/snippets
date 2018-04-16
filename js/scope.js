function foo() {
  function bar() {
    console.log('bar()')
  }
}

foo()
bar() // ReferenceError
