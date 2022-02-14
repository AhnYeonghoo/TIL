// 원시데이터는 Data, Stack에 저장 -> global은 Data, local은 Stack
// Object는 Heap에 저장.(동적)

let apple = {
  name: 'apple',
  color: 'red',
  display: 'apple!',
};

console.log(apple);
console.log(apple.color);
console.log(apple.name);
console.log(apple.display);

let appleName = 'apple';
let color = 'red';
let display = 'picture';
let orangeName = 'orange';

let orange = {
  name: 'orange',
  color: 'orangeColor',
  display: 'picture',
};

console.log(orange);
console.log(orange.name);
console.log(orange.color);
console.log(orange.display);

let copy = orange;
copy.name = 'copy';
console.log(orange.name);
