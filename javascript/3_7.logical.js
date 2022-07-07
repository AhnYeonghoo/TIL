// 논리연산자 (Logical Operators)

// && and
// || or
// ! not
// !! convert to boolean

let num = 21;
if (num >= 0 && num < 9) {
  console.log('first');
} else if (num >= 0 || num < 9) {
  console.log('second');
}

if (!(num >= 0 && num < 9)) {
  console.log('first');
} else if (num >= 0 || num < 9) {
  console.log('second');
}

if (num != 8) {
  console.log('first');
}

console.log(true && true);
console.log(true && false);
console.log(false && true);
console.log(false && false);

console.log(true || true);
console.log(true || false);
console.log(false || true);
console.log(false || false);

console.log(!!'text');
console.log(!!'');

console.log(!!0);
console.log(!!1);
