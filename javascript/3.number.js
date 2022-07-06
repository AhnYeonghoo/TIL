// 3. number type

let integer = 123; // 정수
let negative = -123; // 음수
let double = 1.23; // 실수
console.log(integer);
console.log(negative);
console.log(double);

let binary = 0b1111011; // 2진수
let octal = 0o173; // 8진수
let hex = 0x7b; // 16진수
console.log(binary);
console.log(octal);
console.log(hex);

console.log(0 / 123); // Zero
console.log(123 / 0); // infinity
console.log(123 / -0); // -infinity
console.log(123 / 'text'); // Not a Number
// 타입의 불일치

let bigInt = 123412412414344343432424343n; // 마지막에 n을 붙임으로써 bigInt형 사용 -> 거의 사용하지 않는다.
console.log(bigInt);
