async function* subscribe(dom, event) {
  while(true) {
    yield await new Promise(resolve =>
      dom.addEventListener(event, resolve, { once: true })
    )
  }
}

// How to use
for await (let event of subscribe(document, 'click')) {
  console.log(event)
}
