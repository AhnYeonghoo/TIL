// 콜백함수

// 일급객체의 개념이  JS에서는 함수 또한 일급함수이다. -> 모든 연산이 가능함.

const add = (a, b) => a + b;
const multiply = (a, b) => a * b;

// 함수의 인자로 함수를 받을 수 있는 특징: 일급함수!
// 함수의 레퍼런스만(참조) 받아오는 함수를 callback 함수라고 부른다.
// 전달된 action은 callback function이다.
// 전달될 당시에 함수를 바로 호출해서 반환된 값을 전달하는 것이 아니라!!
// 함수를 가리키고 있는 함수의 레퍼런스(참조값)가 전달된다. -> ########
// 그래서 함수는 고차함수 안에서 필요한 순간에 나중에 호출이 됨!!!!

function calculator(a, b, action) {
  if (a < 0 || b < 0) {
    return;
  }
  let result = action(a, b);
  console.log(result);
  return result;
}
// 콜백함수는 즉, 반환되는 게 아니라 실행할 때 즉시 실행된다.
// 언제 실행될 지는 모른다.(콜백지옥의 원인)
calculator(1, 2, add);
calculator(2, 3, multiply);
calculator(1, 1, add);
calculator(2, 2, multiply);
calculator(-1, -1, add);
calculator(-1, -1, multiply);
