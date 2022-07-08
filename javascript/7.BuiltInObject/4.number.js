console.log(Number.EPSILON);
console.log(Number.NaN);
console.log(Number.MAX_VALUE);

console.log(Number.prototype);

const num1 = 123;
const num2 = new Number(123); // 굳이? 메모리 낭비 객체!
console.log(num1); // 원시타입
console.log(num2); // 객체
console.log(typeof num1);
console.log(typeof num2);

console.log(Number.MAX_VALUE);
console.log(Number.MIN_VALUE);
console.log(Number.MAX_SAFE_INTEGER);
console.log(Number.MIN_SAFE_INTEGER);
console.log(Number.NaN);
console.log(Number.NEGATIVE_INFINITY);
console.log(Number.POSITIVE_INFINITY);

if (num1 === Number.NaN) {
  console.log('Not a Number');
}
if (Number.isNaN(num1)) {
  console.log(num1);
}

// 지수표기법 (매우 크거나 작은 숫자를 표기할 때 사용, 10의 n승)
const num3 = 102;
console.log(num3.toExponential());

const num4 = 1234.12;
console.log(num4.toFixed());

console.log(num4.toString());
console.log(num4.toLocaleString('ar-EG')); // 그 나라 지역에 맞는 언어로 변환

// 원하는 자릿수까지 유효하도록 반올림
console.log(num4.toPrecision(5));
console.log(num4.toPrecision(4));
console.log(num4.toPrecision(2)); // 전체 자릿수 표기가 안될때는 지수표기법으로 됨
console.log(Number.EPSILON); // 0과 1 사이에서 나타낼 수 있는 가장 작은 수
if (Number.EPSILON > 0 || Number.EPSILON < 1) {
  console.log('EPSLION');
}

const num = 0.1 + 0.2 - 0.2; // 2진수로 변환되는 과정에서 약간의 오차
console.log(num); // 부동소수점

function isEqual(original, expected) {
  return original - expected < Number.EPSILON;
}

function isEqual2(original, expected) {
  return Math.abs(original - expected) < Number.EPSILON;
}

console.log(isEqual(1, 1));
console.log(isEqual(0.1, 0.1));
console.log(isEqual(num, 0.1));
console.log(isEqual(0.2, 0.2 + 0.1 - 0.1));
