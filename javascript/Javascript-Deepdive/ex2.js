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
