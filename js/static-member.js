class Foo {
  constructor() {
    console.log('Hi!');

    this.width = Foo.dimension;
  }

  static get dimension() { return 20; }
}

const f = new Foo();

console.log(Foo.dimension);
console.log(f.width);
