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
