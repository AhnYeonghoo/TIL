const fruits = ['banana', 'str', 'orange', 'str'];

for (let i = 0; i < fruits.length; i++) {
  console.log(fruits[i]);
}

console.clear();
// 고차함수 사용
fruits.forEach(function (value, index, array) {
  console.log('---------------');
  console.log(value);
  console.log(index);
  console.log(array);
});

fruits.forEach((value) => {
  console.log(value);
});

fruits.forEach((value) => console.log(value));

console.clear();

// 조건에 맞는(콜백함수) 아이템을 찾을 때
const item1 = { name: 'milk', price: 2 };
const item2 = { name: 'egg', price: 3 };
const item3 = { name: 'bob', price: 1 };
const products = [item1, item2, item3, item2];

let found = products.find((value) => {
  return value.name === 'egg';
});

const found2 = products.find((value) => value.name === 'egg');

console.log(found);
console.log(found);

// findInde: 제일 먼저 조건에 맞는아이템의 인덱스를 반환

found = products.findIndex((value) => value.name === 'egg');
console.log(found);

// 배열의 아이템들이 부분적으로 조건(콜백함수)에 맞는지 확인

found = products.some((item) => item.name === 'egg');
console.log(found);

// 배열의 아이템들이 전부 조건(콜백함수)에 맞는지 확인

found = products.every((item) => item.name === 'egg');
console.log(found);

// 조건에 맞는 모든 아이템들을 새로운 배열로써 반환
found = products.filter((item) => item.name === 'egg');
console.log(found);
console.clear();

// Map 배열의 아이템들을 각각 다른 아이템으로 매핑할 수 있는, 변환해서 새로운 배열 생성!
const nums = [1, 2, 3, 4, 5];
let result = nums.map((value) => value * 2);
console.log(result);

result = nums.map((value) => {
  if (value % 2 === 0) {
    return value * 2;
  } else {
    return value;
  }
});
console.log(result);

// Flatmap: 중첩된 배열을 쫘악 펴줌

result = nums.flatMap((item) => [1, 2]);
console.log(result);

result = ['dream', 'coding'].flatMap((text) => text.split(''));
console.log(result);

// sort 배열의 아이템들을 정렬
// 문자열 형태의 오름차순으로 요소를 정렬하고, 기존의 배열을 변경!

const texts = ['hi', 'abc'];
texts.sort();
console.log(texts);

const numbers = [0, 5, 4, 2, 1, 10];
numbers.sort();
console.log(numbers);

numbers.sort((a, b) => a - b);
console.log(numbers);

// reduce 배열의 요소들을 접어서 접어서 값을 하나로!

result = [1, 2, 3, 4, 5].reduce((sum, value) => (sum += value), 0);
console.log(result);

result = [5, 10, 25, 30].reduce((sum, value) => {
  sum += value;
  return sum;
}, 0);
console.log(result);
