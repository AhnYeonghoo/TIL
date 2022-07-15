{
  const foo = 0;
}
let y = 1;
if (y < 10) {
  y++;
}
function sum(a, b) {
  return a + b;
}
let num = 2;
let kind;
if (num > 0) {
  kind = '양수';
}
console.log(kind);
if (num > 0) {
  kind = 'yang';
} else {
  kind = 'um';
}
console.log(kind);
if (num > 0) {
  kind = 'yang';
} else if (num < 0) {
  kind = 'um';
} else {
  kind = 'zero';
}
console.log(kind);
if (num > 0) kind = 'yang';
else if (num < 0) kind = 'um';
else kind = 'zero';
console.log(kind);
let x = 2;
let result;
if (x % 2) {
  result = 'holl';
} else {
  result = 'Ww';
}
console.log(result);
result = x % 2 ? 'hooll' : 'WW';
console.log(result);
kind = num ? (num > 0 ? 'yang' : 'um') : 'zero';
let month = 11;
let monthName;

switch (month) {
  case 1:
    monthName = 'January';
    break;
  case 2:
    monthName = 'February';
    break;
  case 3:
    monthName = 'March';
    break;
  case 4:
    monthName = 'April';
    break;
  case 5:
    monthName = 'May';
    break;
  case 6:
    monthName = 'June';
    break;
  case 7:
    monthName = 'July';
    break;
  case 9:
    monthName = 'August';
    break;
  case 10:
    monthName = 'September';
    break;
  case 11:
    monthName = 'November';
    break;
  case 12:
    monthName = 'December';
    break;
  default:
    monthName = 'Invalid month';
}
console.log(monthName);
console.clear();

let year = 2000;
let month2 = 2;
let days = 0;

switch (month2) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    days = 31;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    days = 30;
  case 2:
    days = (year % 4 === 0 && year % 100 !== 0) || year % 400 === 0 ? 29 : 28;
    break;
  default:
    console.log('invalid month');
}
console.log(days);
for (let i = 0; i < 2; i++) {
  console.log(i);
}
for (let i = 1; i >= 0; i--) {
  console.log(i);
}
for (;;) {
  console.log('Loop');
  break;
}
for (let i = 1; i <= 6; i++) {
  for (let j = 1; j <= 6; j++) {
    if (i + j === 6) console.log(`[${i}, ${j}]`);
  }
}
let count = 0;
while (count < 3) {
  console.log(count);
  count++;
}
while (true) {
  console.log('loop');
  break;
}
while (true) {
  console.log(count);
  count++;
  if (count === 4) break;
}
count = 0;
do {
  console.log(count);
  count++;
} while (count < 3);

foo: console.log('foo');
foo: {
  console.log(1);
  break foo;
  console.log(2);
}
console.log('done!');
console.clear();
outer: for (let i = 0; i < 3; i++) {
  for (let j = 0; j < 3; j++) {
    if (i + j === 3) break outer;
    console.log(`inner [${i}, ${j}]`);
  }
}
console.log('done!');
let string = 'Hello World';
let search = 'l';
let index;

for (let i = 0; i < string.length; i++) {
  if (string[i] === search) {
    index = i;
    break;
  }
}
console.log(index);
console.log(string.indexOf('l'));
let countt = 0;
console.clear();
for (let i = 0; i < string.length; i++) {
  if (string[i] !== search) continue;
  countt++;
}
console.log(countt);
const regexp = new RegExp(search, 'g');
console.log(string.match(regexp).length);
x = 10;
let str = x.toString();
console.log(typeof str, str);
console.log(typeof x, x);
x = 10;
str = x + '';
console.log(typeof str, str);
console.log(typeof x, x);
function isfalsy(x) {
  return !x;
}

function isTruthy(x) {
  return !!x;
}
console.log(isfalsy(false));
console.log(isfalsy(undefined));
console.log(isfalsy(''));
console.log(isfalsy(0));
console.log(isfalsy(NaN));
console.log(isfalsy(null));
console.clear();
console.log(typeof String(1));
console.log(typeof String(NaN));
console.log(typeof String(Infinity));
console.log(typeof String(true));
console.log(typeof String(false));
console.log(1);
console.log((1).toString());
console.log(NaN.toString());
console.log(Infinity.toString());
console.log(true.toString());
console.log(false.toString());
console.clear();
console.log(typeof Number('0'));
console.log(typeof Number(-1));
console.log(typeof Number('10.53'));
console.log(typeof Number(true));
console.log(typeof parseInt('-1'));
console.log(parseInt(-1));
console.log(parseInt('10.213'));
console.log(parseFloat('10.213'));
console.log(+'0');
console.log(+true);
console.log(+false);
const dog = 'dog' || 'cat';
console.log(dog);
const cat = 'dog' && 'cat';
console.log(cat);
let done = true;
let message = '';
if (done) message = 'done';
console.log(message);
message = done && 'done';
console.log(message);
done = false;
message = '';
if (!done) message = 'not done';
console.log(message);
message = done || 'not done';
console.log(message);
message = done ? 'done' : 'not done';
console.log(message);
let elem = null;
// let value = elem.value;
let value = elem && elem.value;
console.log(value);
function getStringLength(str) {
  str = str || '';
  return str.length;
}
console.log(getStringLength());
console.log(getStringLength('ho'));
function getStringLength2(str = '') {
  return str.length;
}
console.log(getStringLength2());
console.log(getStringLength2('hi'));
console.clear();

elem = null;
value = elem?.value;
console.log(value);
str = '';
let length = str?.length;
console.log(length);

let too = null ?? 'default string';
console.log(too);

too = '' || 'default string';
console.log(too);
too = '' ?? 'default string';
console.log(too);
var person = {
  name: 'Lee',
  sayHello: function () {
    console.log(`Hello! My Name is ${this.name}`);
  },
};
console.log(typeof person);
console.log(person);
var empty = {};
console.log(typeof empty);
console.clear();
person = {
  // 객체는 프로퍼티의 집합이며, 프로퍼티는 key와 value로 구성된다.
  // 객체 리터럴은 JS에서 지원하는 객체지향 프로그래밍 패러다임이다.
  name: 'Lee',
  age: 20,
};
var obj = {};
const key = 'hello';
obj[key] = 'world';
console.log(obj[key]);
var doo = {
  '': '',
};
console.log(doo);
doo = {
  0: 1,
  1: 2,
  2: 3,
};
console.log(doo);
doo = {
  var: '',
  function: '',
};
console.log(doo);
doo = {
  name: 'Lee',
  name: 'Kim',
};
console.log(doo);
var circle = {
  radius: 5,

  getDiameter: function () {
    return 2 * this.radius;
  },
};

console.log(circle.getDiameter());
person = {
  name: 'Lee',
};
console.log(person.name);
console.log(person['name']);
person = {
  'last-name': 'Lee',
  1: 10,
};
person.age = 20;
console.log(person);
delete person[1];
delete person['last-name'];
console.log(person);

(x = 1), (y = 2);
obj = {
  x: x,
  y: y,
};
console.log(obj);
const objEs = { x, y }; // 위와 동일한 표현식으로 생략이 가능해짐 ES6+
console.log(objEs);
const prefix = 'prop';
let i = 0;
const objLi = {
  [`${prefix}-${++i}`]: i,
  [`${prefix}-${++i}`]: i,
  [`${prefix}-${++i}`]: i,
};
console.log(objLi);
obj = {
  name: 'Lee',
  sayHi() {
    console.log(`Hi! ${this.name}`);
  },
};
console.log(obj.sayHi());
