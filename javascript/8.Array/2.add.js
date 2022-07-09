// 배열의 추가 삭제

const fruits = ['apple', 'orange', 'banana'];

console.log(fruits[0]);
console.log(fruits[1]);
console.log(fruits[2]);
//console.log(fruits.fill('asd'));
console.log(fruits.length);

for (let i = 0; i < fruits.length; i++) {
  console.log(fruits[i]);
}

// add, remove - Not Good Method

fruits[3] = 'kiwi';
console.log(fruits);

delete fruits[3];
console.log(fruits); // 이 방법은 사용을 지양.
