// 동등 비교 관계연산자 (Equality Operators)

// ==
// !=
// === 값과 타입을 둘 다 확인
// !== 값과 타입을 둘ㄷ다 확인
console.log(2 == 2);
console.log(2 != 2);
console.log(2 != 3);
console.log(2 == 3);
console.log(2 == '2'); // 타입까진 검사 x
console.log(2 === '2'); // 타입까지 검사 o
console.log('asdasd');
console.log(true == 1);
console.log(true === 1);
console.log(false == 0);
console.log(false === 0);
console.log('asdadssd');

const obj1 = {
  name: 'js',
};
const obj2 = {
  name: 'js',
};
// Head에 저장되는 각 object의 주소가 다르기 떄문에 false임.
console.log(obj1 == obj2);
console.log(obj1 === obj2);
console.log(obj1.name == obj2.name);
console.log(obj1.name === obj2.name);

let obj3 = obj2;
console.log(obj2 == obj3);
console.log(obj2 === obj3);

let a = 2;
let b = a;
console.log(a == b);
console.log(a === b);
