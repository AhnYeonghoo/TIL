/**
 * 글로벌 컨텍스트의 this
 * - 브라우저:
 * - 노드: 모듈
 */
'use strict';

const x = 0;
// module.exports.x = x;
console.log(this);
console.log(globalThis);
// globalThis.setTimeout()
// setTimeout()

console.clear();

/**
 * 함수 내부에서의 this
 * 엄격모드에서는 undefined
 * 느슨한 모드에서는 globalThis
 */

function fun() {
  console.log(this);
}
fun();

/**
 * 생성자 함수 or 클래스에서의 this, 앞으로 생성될 인스턴스 자체를 가리킴
 */

function Cat(name) {
  this.name = name;
  this.printName = function () {
    console.log(this.name);
  };
}

const cat1 = new Cat('c1');
const cat2 = new Cat('c2');
cat1.printName();
cat2.printName();
