// 10. typeof: 데이터 타입을 체크

// 값을 타입 문자열로 반환!

let variable;
console.log(typeof variable);

variable = '';
console.log(typeof variable);

variable = 123; // C/C++과 다르게 런타임 도중에 타입이 동적으로 결정된다.
// C/C++은 컴파일 전에 미리 정적으로 타입을 정해주어야 함.
// 즉, 정적 타입핑
// JS는 동적 타입핑
console.log(typeof variable);

// 자바스크립트는 약타입 언어
// 자바는 강타입 언어라고 함

variable = {};
console.log(typeof variable);

variable = function () {};
console.log(typeof variable);

variable = Symbol();
console.log(typeof variable);

console.log(typeof 123);
console.log(typeof '123');
console.log(123 == '123');
console.log(123 === '123');
