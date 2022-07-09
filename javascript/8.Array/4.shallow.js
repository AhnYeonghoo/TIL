// Shallow Copy (얉은 복사)
// 객체는 메모리의 주소를 복사하게 됨
// JS에서 객체를 복사할 때는 항상 얕은 복사가 이루어짐.
// Array.from, concat, slice, spread(...), Object.assign etc... 모두
// 그렇기 떄문에 함수 내부에서 인자로 객체를 받을 때는
// 객체를 함수 내부에서 변경하는 것은 바람직하지 않음.
// 함수 내부에서 새로운 객체를 만들어 반환!

const pizza = { name: 'pizza', price: 2, owner: { name: 'ahn' } };
const ramen = { name: 'ramen', price: 3 };
const sushi = { name: 'sushi', price: 1 };
const store1 = [pizza, ramen];
const store2 = Array.from(store1);
console.log('store1', store1);
console.log('store2', store2);

store2.push(sushi);
console.log(store1);
console.log(store2);

pizza.price = 4;

console.log(store1);
console.log(store2);
