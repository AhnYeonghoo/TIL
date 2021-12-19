// 함수의 표현식! (선언문과 다름)
// function name -> 함수 선언문 (function statement)
// const name = function() {} -> 함수 표현식(function expression) -> 값으로써 평가가 가능하다.
// const name = () => {} -> 화살표함수(Arrow function) -> 함수 표현식을 간결하게!

let add = function (a, b) {
  return a + b;
};

console.log(add(2, 3).toString());

add = (a, b) => {
  return a + b; // 반환만 하는 함수의 경우? 모든 것을 생략 가능
};

add = (a, b) => a + b; // -> 간결하게

console.log(add(1, 5));

// 생성자 함수 const object = new Function();

// IIFE (Immedicately-Invoked Function Expressions) -> 즉시 호출 함수 표현식
// 자주는 잘 사용하지 않음.
(function run() {
  console.log('run');
})(); //
