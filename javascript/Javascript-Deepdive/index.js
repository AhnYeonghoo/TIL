const arr = [1, 2, 3];

arr.forEach(console.log);
// arr.forEach(alert);

let interger = 10;
const double = 10.12;
const negative = -10;
const binary = 0b01000001;
const octal = 0o101;
const hex = 0x41;

console.log(binary);
console.log(octal);
console.log(hex);
console.log(binary === octal);
console.log(octal === hex);

console.log(1 === 1.0);
console.log(4 / 2);
console.log(3 / 2);
console.log(1 * 'String');

let template = `<ul>\n\t<li><a href="#">Home</a></li>\n</ul>`;
console.log(template);

let first = 'Ung-mo';
let last = 'Lee';
console.log(`my name is ${first} ${last}.`);
console.log(`1+2 = ${1 + 2}`);
let foo = true;
console.log(foo);
foo = false;
console.log(foo);

console.clear();

let key = Symbol('key');
console.log(typeof key);
let obj = {};
obj[key] = 'value';
console.log(obj[key]);

var fee;
console.log(typeof fee);

fee = 3;
console.log(typeof fee);

fee = 'ee';
console.log(typeof fee);

fee = true;
console.log(typeof fee);

fee = null;
console.log(typeof fee);

fee = Symbol();
console.log(typeof fee);

fee = {};
console.log(typeof fee);

fee = [];
console.log(typeof fee);

fee = function () {};
console.log(typeof fee);

let a, b, c;
a = b = c = 0;
console.log(a, b, c);
console.log(NaN === NaN);
console.log(0 === -0);
console.log(-0 === +0);
console.log(Object.is(-0, +0));
console.log(Object.is(NaN, NaN));

console.clear();

let x = 2;

const result = x % 2 ? '홀' : '짝';
console.log(result);

const ex = null;
console.log(ex === null);
console.log(typeof ex === null);
console.log(typeof undeclared);

const y = null;
const t = y;
console.log(t);

let q = 1;
console.log(q);
q++;
console.log(q);

const o = { a: 1 };
delete o.a;
console.log(o);
