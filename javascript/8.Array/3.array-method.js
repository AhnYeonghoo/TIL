// 배열의 유용한 함수들
// 배열 자체를 변경하는지, 새로운 배열을 반환하는지가 포인트

const fruits = ['banana', 'apple', 'orange'];

// 특정 오브젝트가 배열인지 check
console.log(Array.isArray(fruits));
console.log(Array.isArray({}));

// 특정한 아이템의 위치를 찾을 떄
console.log(fruits.indexOf('banana'));
console.log(fruits.indexOf('kiwi'));

// 배열안에 특정한 아이템이 있는지 체크
console.log(fruits.includes('banana'));
console.log(fruits.includes('kiwi'));

// add - lastOf
let length = fruits.push('kiwi'); // 배열 자체를 업데이트 -> 반환 값은 길이
console.log(fruits);
console.log(length);

// add - firstOf
length = fruits.unshift('blueberry');
console.log(fruits);
console.log(length);

// remove - lastOf
let lastItem = fruits.pop();
console.log(fruits);
console.log(lastItem);

// remove - firstOf

let firstItem = fruits.shift();
console.log(fruits);
console.log(firstItem);

// 중간에 추가 또는 삭제
fruits.splice(1, 0, 'kiwi'); // 시작할 인덱스, 끝낼 인덱스(0이면 추가), 추가할 요소
console.log(fruits);

const deleted = fruits.splice(1, 1);
console.log(deleted);
fruits.splice(1, 0, 'a', 'b');
console.log(fruits);

console.clear();

// 잘라진 새로운 배열을 만듦
let newArr = fruits.slice(0, 2); // 이상~미만
console.log(newArr);
console.log(fruits);

newArr = fruits.slice();
console.log(newArr);
newArr = fruits.slice(-1);
console.log(newArr);

const arr1 = [1, 2, 3];
const arr2 = [4, 5, 6];
const arr3 = arr1.concat(arr2);
console.log(arr1);
console.log(arr2);
console.log(arr3);

// 순서를 거꾸로
const arr4 = arr3.reverse();
console.log(arr4);

// 중첩 배열을 하나의 배열로 쫙 펴기

let arr = [
  [1, 2, 3],
  [4, [5, 6]],
];
console.log(arr);
console.log(arr.flat());
console.log(arr.flat(2));
console.log(arr.flat().flat());

// 특정한 값으로 배열을 채우기

arr = arr.flat(2);
arr.fill(0, 1, 3); // 배열 자체를 수정
console.log(arr);
arr.fill('s', 3, 5);
console.log(arr);

// 배열을 문자열로 합하기
let text = arr.join(' | ');
console.log(text);
text = arr.join(' ');
console.log(text);
text = arr.join(' : ');
console.log(text);
