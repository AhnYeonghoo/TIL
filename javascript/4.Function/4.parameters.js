// 매개변수의 default value는 무조건 undefined이다.
// 매개변수의 정보는 함수 내부에서 접근이 가능한 arguments 객체에 기본적으로 저장된다.(배열 형태)
// 매개변수의 default Parameers a = 1, b = 1
function add(a, b) {
  console.log(a);
  console.log(b);
  console.log(arguments); // 특정 예약어임
  console.log(arguments[0]);
  console.log(arguments[1]);
  console.log(arguments[2]);
  return a + b;
}

function defaultAdd(a = 1, b = 1) {
  console.log(a);
  console.log(b);
  return a + b;
}

add(1, 2, 3);
add();

console.log('\n\n\n');
console.log(defaultAdd());

// Rest 매개변수, Rest Parameters

function sum(...numbers) {
  console.log(numbers);
}

console.log(sum(1, 2, 3, 4));
