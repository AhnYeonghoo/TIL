// 8. value와 reference의 차이

let a = 1;
let b = a; // copy by value!
console.log(a);
console.log(b);
b = 2;
console.log(a);
console.log(b);

let apple = {
  name: 'apple',
};

let orange = apple; // copy by reference!! heap에 저장되어 있는 주소를 복사함

console.log(apple);
console.log(orange);
orange.name = 'orange';
console.log(apple);
console.log(orange);
