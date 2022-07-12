// 옵셔널 체이닝 연산자 Optional Chaning Operator
// ES11 (ECMAScript 2020)에 추가됨
// ?.
// null 또는 undefined을 check 할 때
let item = { price: 1 };
const price = item?.price;
console.log(price);

let obj = { name: 'dog', owner: { name: 'Ellie' } };
function printName(obj) {
  const ownerName = obj?.owner?.name;
  return ownerName;
}
console.log(printName(obj));
