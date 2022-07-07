// 9. const(상수)

let a = 1;
a = 2; // ok

// const는 재할당 불가능
// 1. 상수
// 2. 상수변수, 변수
const b = 3;
console.log(b);

// 1. 상수는 대문자와 언더바 조합!
const MAX_FRUITS = 5;

// 2. 재할당 불가능한 상수변수 또는 변수
const apple = {
  name: 'apple',
  color: 'red',
  display: 'apple!',
};

// apple = {};  // impossible

console.log(apple);
apple.name = 'hello im change';
console.log(apple.name);
apple.color = 'blue';
console.log(apple.color);
