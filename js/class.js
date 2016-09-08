'use strict';
function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }
var Parent = function () {
  function Parent() {
    _classCallCheck(this, Parent);

    this.foo = function () {
      console.log('부모');
    };
  }

  Parent.prototype.render = function render() {
    this.foo();
  };

  return Parent;
}();

//////

class Child extends Parent {
  constructor() {
    super();
    this.foo = () => { console.log('ㅇㅅㅇ'); };
  }
}

const parent = new Parent();
const child = new Child();

parent.render();
child.render();
