// 산술 연산자(arithmetic operators)
// +
// -
// *
// /
// %
// ** 지수

console.log(5 + 2);
console.log(5 - 2);
console.log(5 * 2);
console.log(5 / 2);
console.log(5 % 2);
console.log(5 ** 2); // ES7에 추가된 연산자
console.log(Math.pow(5, 2));

// + 연산자 주의점!
let text = '두개의' + '문자를';
console.log(text);
// 자바스크립트의 불안정성 때문에 문자열+숫자는 문자열로 변환되므로 주의!!
text = '1' + 1;
console.log(text);
