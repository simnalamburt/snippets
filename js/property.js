class Foo {
  constructor() {
    this._hp = 100;
  }

  get hp() {
    console.log('내 체력은 알아서 뭐하게');

    return this._hp;
  }

  set hp(value) {
    if (value > this._hp) { console.log('고마웡'); }
    else if (value < this._hp) { console.log('아야'); }
    else { console.log('ㅇㅅㅇ'); }

    this._hp = value;
  }
}

const f = new Foo();

console.log(f.hp);
f.hp = 50;
console.log(f.hp);
f.hp = 100;
console.log(f.hp);
f.hp = 100;
