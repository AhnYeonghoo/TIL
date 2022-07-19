// const 키워드를 사용해 선언한 변수는 재할당이 금지된다. 상수는 재할당이 금지된 변수일 뿐이다.
const o = {};

// const 키워드를 사용해 선언한 변수에 할당한 원시 값은 변경할 수 없다.
// 하지만 const 키워드를 사용해 선언한 변수에 할당한 객체는 변경할 수 있다.
// 원시타입은 immutable
// 객체타입은 mutable
o.a = 1;
console.log(o);
const str = 'string';
console.log(str[0]);
console.log(str.length);
console.log(str.toUpperCase());
str[0] = 'S'; // -> 원시타입은 readOnly이기 때문에 변경할 수 없음.
console.log(str);
let score = 80;
let copy = score; // pass by value
console.log(score);
console.log(copy);
score = 100;
console.log(score);
console.log(copy);
console.clear();
score = 80;
console.log(score === copy);
score = 100;
console.log(score === copy);
const person = {
  name: 'jason',
};
console.log(person);
// property value update
person.name = 'kim';
// property allocation update
person.address = 'Seoul';
console.log(person);

const x = { x: { y: 1 } };
// shallow copy
const c1 = { ...x };
console.log(c1 === x);
console.log(c1.x === x.x);

// lodash의 cloneDeep을 사용한 deep copy
// const _ = require('lodash');
// const c2 = _.cloneDeep(x);
// console.log(c2 === x);
// console.log(c2.x === x.x);

const person2 = {
  name: 'Lee',
};
// shallow copy
const copy2 = person2;
console.log(copy2 === person2);
copy2.name = 'Kim';
person2.address = 'Seoul';
console.log(person2);
console.log(copy2); // -> shallow copy이기 때문에 같은 곳을 레퍼런스한다. 따라서 값의 변경을 하면 서로에게 영향을 줌

let person1 = {
  name: 'Lee',
};
let person3 = {
  name: 'Lee',
};
console.log(person1 === person3); // 객체타입은 서로 다른 참조값을 가지고 있기 때문에 다른 데이터다
console.log(person1.name === person3.name); // 객체더라도 객체안에 프로퍼티는 원시타입이기 때문에 서로 같은 데이터다
console.clear();

// 함수 리터럴: 변수에 함수를 할당할 수 있는, 자바스크립트만의 특징
// 함수가 객체임을 알 수 있는 특징이다.

let twoAdd = function (a, b) {
  return a + b;
};
console.log(twoAdd(1, 2));

function arrayAdd(...array) {
  let result = 0;
  for (const number of array) {
    result += number;
  }
  return result;
}
console.log(arrayAdd(1, 2, 3, 4, 5));

// 함수 선언문의 4가지 종류
// 1. 함수 선언식
function normalAdd(a, b) {
  return a + b;
}
// 2. 함수 표현식
let expressionAdd = function (a, b) {
  return a + b;
};
// 3. Function 생성자 함수
let newAdd = new Function('a', 'b', 'return a+b');
// 4. 화살표 함수(ES6)
let arrowAdd = (a, b) => a + b; // return 생략 가능(단일 연산일 경우)
console.dir(normalAdd);
// 함수 선언문은 이름을 생략할 수 없다.
(function foo() {
  console.log('foo');
})();
(function bar() {
  console.log('bar');
})(); // -> 즉시 실행 함수
// 함수는 일급객체!, 즉, 모든 곳에서 값으로써 사용될 수 있음을 의미한다.
// 배열의 요소, 객체의 요소, 함수의 인자 모든 곳에서 객체로써 사용될 수 있다.
// 함수 선언문 같은 경우는 런타임 이전에 미리 스크립트를 읽어들여 함수와 변수를 가장 먼저 정의, 선언하고
// 메모리를 할당한다.
// 하지만 함수 표현식(let add = function () { }...)은 선언하기 이전에 위에서 실행될 수 없다.
// 예제.
add3(3, 5);
// add4(4, 4); -> 함수 표현식은 함수 선언 전에 실행 불가능!
function add3(a, b) {
  return a + b;
}
let add4 = function (a, b) {
  return a + b;
};
console.clear();
// 이처럼 함수 선언문이 실행 이전에 끌어올려지는 것을 함수 호이스팅 이라고 한다.
// 이와 동일한 개념으로 변수 호이스팅도 존재한다. 함수는 객체로써 메모리에 탑재된다.
// 반면, 함수 표현식은 변수와 같이 변수 호이스팅으로 취급되어, undefined로 초기화된다.
// 변수도 먼저 undefined로 선언된 후 값이 할당됨.

// arrow function
const sum = (a, b) => a + b;
const sum2 = (a, b) => {
  console.log(arguments);
  return a + b;
};
console.log(sum(1, 2));
console.log(sum(1)); // 전달되지 않은  argument는 undefined으로 취급되어 NaN이 된다.
console.log(sum(2, 3, 4)); // 초과되어 호출되는 argument는 무시된다.
sum2(3, 4, 5); // 초과되는 인수가 완전히 사라지는건 아니고, arguments에 객체로써 저장된다.

// 자바스크립트는 동적 타입 언어이며, 매개변수와 인수의 개수가 일치하는지 확인하지 않는다.
// 따라서 함수를 정의할 때 좀 더 세심하게 정의할 필요가 있다.
function goodAdd(x, y) {
  if (typeof x !== 'number' || typeof y != 'number') {
    throw new TypeError('not a number');
  }
  return x + y;
}
console.log(goodAdd(1, 2));
// console.log(goodAdd('a', 'b')); -> TypeError
function shortAdd(a, b, c) {
  a = a || 0;
  b = b || 0;
  c = c || 0; // -> || 연산자는 falsy한 값을 판별할 때 && 연산자는 truethy한 값을 판별
  return a + b + c;
}
console.log(shortAdd('', '', ''));
console.log(shortAdd(1, 2, 3));
console.log(shortAdd(1, 2));
console.log(shortAdd(1));
console.log(shortAdd());

function defaultAdd(a = 0, b = 0, c = 0) {
  return a + b + c;
}
console.log(defaultAdd(1, 2, 3));
console.log(defaultAdd(1, 2));
console.log(defaultAdd(1));
console.log(defaultAdd());
console.clear();

// 함수의 매개변수(paramets)의 개수에는 제한이 없으나 되도록 0개인 게 바람직하며,
// 매개변수가 많다는 것은 함수가 하는 일이 다양하고 많다는 의미기 때문에 좋지 않다.
// 함수는 반드시 한 가지 일만 하도록 정의하여야 바람직하다.
// $.ajax({
//   method: 'POST',
//   url: '/user',
//   data: { id: 1, name: 'Lee' },
//   cache: false,
// });
function changeVal(primitive, obj) {
  primitive += 100;
  obj.name = 'Kim';
}

let num = 100;
const person4 = { name: 'Lee' };
console.log(num);
console.log(person4);

changeVal(num, person4);
console.log(num);
console.log(person4);
// 원시타입 primitive type은 함수에서 값을 조작해도 side effect가 발생하지 않는다. -> Immutable
// 반면, 객체 object type은 함수 내에서 값을 조작하면 side effect가 발생하며 이런 현상은 바람직하지 않다. -> Mutable
// primitive type -> pass by value
// object type -> pass by reference
// 객체를 함수 내에서 조작해야 하는 경우에는, 방어적 복사(defensive copy)를 통해 객체를 완전히 깊은 복사하여
// 즉, 새로운 객체를 만들어 해당 객체를 조작하여 반환하는 것이 바람직하다.
// 원본은 건들지 않고, 새로운 객체만을 생성하여 조작하는 방법! side effect XX
