// 배열 생성 방법
let array = new Array(2);
console.log(array);

array = new Array(1, 2, 3);
console.log(array);

array = Array.of(1, 2, 3, 4, 5);
console.log(array);

// Array Literal
const anotherArray = [1, 2, 3, 4];
console.log(anotherArray);

array = Array.from(anotherArray);
console.log(array);

array = Array.from('text');
console.log(array);

// 일반적으로 배열은 동일한 메모리 크기를 가지며, 연속적으로 이어져 있어야함
// 하지만 자바스크립트에서의 배열은 연속적으로 이어져 있지 않다(보장X)
// Object와 동일시 됨.
// 자바스크립트의 배열은 다른 언어에서의 배열의 흉내낸 특수한 객체다!
// 이걸 보완하기 위해서 타입이 정해져 있는 타입 배열이 있음. (Typed Collections)
array = Array.from({
  0: 'ahn',
  1: 'kim',
  length: 2,
});
console.log(array);
