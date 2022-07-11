// Spread Operators (전개구문)
// 모든 iterable은 Spread 될 수 있다.
// 순회가 가능한 모든 것들은 펼쳐질 수 있다.
// func(...iterable)
// [...iterable]
// { ... obj }
// EcmaScript 2018에 도입

function add(a, b, c) {
  return a + b + c;
}

const nums = [1, 2, 3];
console.log(add(...nums));

// Rest Parameters
function sum(first, second, ...nums) {
  return first + second + nums;
}

// Array Concat

const fruits = ['apple', 'kiwi'];
const fruits2 = ['oragne', 'banana'];
let arr = fruits.concat(fruits2);
console.log(arr);
arr = [...fruits, 'remon', ...fruits2];
console.log(arr);

// Object
const ellie = { name: 'Ellie', age: 20 };
const updated = {
  ...ellie,
  height: 180,
  job: 's/w engineer',
};
console.log(ellie);
console.log(updated);
