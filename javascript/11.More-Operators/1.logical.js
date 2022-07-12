// 논리연산자 Logical Operator
// && And
// || Or
// 단축평가: Short-Circuit Evaluation

const obj1 = { name: 'dog' };
const obj2 = { name: 'cat', owner: 'Ellie' };

if (obj1 && obj2) {
  console.log('And true');
}
if (obj1 || obj2) {
  console.log('Or true');
}

let result = obj1 && obj2; // 평가되지 않고, 변수에 할당됨(obj2)
console.log(result);

result = obj1 || obj2; // 평가되지 않고, 변수에 할당됨(obj1)
console.log(result);

if (result) {
  console.log('object True');
}

result = false || obj2;
console.log(result);

console.clear();

// 활용 예시
// 조건이 truthy 일 때, && 무언가를 해야 할 경우
// || 조건이 falshy 일 때, || 무언가를 해야 할 경우
function changeOwner(animal) {
  if (!animal.owner) {
    throw new Error('you havent owner!');
  }
  animal.owner = 'changeOwner';
}
function makeNewOwner(animal) {
  if (animal.owner) {
    throw new Error('have owner!');
  }
  animal.owner = 'newOwner!';
}

obj1.owner && changeOwner(obj1);
obj2.owner && changeOwner(obj2);
console.log(obj1);
console.log(obj2);

obj1.owner || makeNewOwner(obj1);
obj2.owner || makeNewOwner(obj2);
console.log(obj1);
console.log(obj2);

// null 또는 undefined인 경우를 확인할 때
let item = { price: 1 };
const price = item && item.price; // safe Assignment
console.log(price);

// 기본값을 설정
// default parameter 전달하지 않거나, undefined 설정! -> 0, null 모두 그대로 출력해버림
// ||은 값이 falshy한 경우 설정(할당): 0, -0, null, undifined, ''인 경우 Hello가 출력됨

function print(message) {
  const text = message || 'Hello';
  console.log(text);
}
print();
print('hello New');
print(0);
print(null);
console.clear();
