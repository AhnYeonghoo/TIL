const array = [1, 2, 3];

// for..of
for (const item of array) {
  console.log(item);
}
for (const item of array.values()) {
  console.log(item);
}
for (const item of array.entries()) {
  console.log(item);
}

// 객체는 이터러블 프로토콜 따르지 않음
const obj = { 0: 1, 1: 2 };
for (const item in obj) {
  console.log(item);
  console.log(item.valueOf());
}

// Iterable 하다는건, 순회가 가능하다는 것.
// [Symbol.iterator](): Iterator를 반환해야 함
// 심볼 정의를 가진 객체나, 특정한 함수가 Iterator를 리턴한다는 것은
// 순회 가능한 객체이다.
// 순회가 가능하면 무엇을 할 수 있나?
// 1. for .. of,
// 2. spread 문법

console.clear();
const iterator = array.values();

console.log(iterator.next().value);
console.log(iterator.next().value);
console.log(iterator.next().value);
console.log(iterator.next().value); // undeifned
console.log(iterator.next().done);

while (true) {
  const item = iterator.next();
  if (item.done) break;
  console.log(item.value);
}
