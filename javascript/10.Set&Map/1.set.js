// Set
const set = new Set([1, 2, 3]);
console.log(set);

set.add(4);
console.log(set);

console.log(set.size);

console.log(set.has(2));
console.log(set.has(6));

// Iterable

set.forEach((item) => {
  console.log(item);
});

console.clear();
for (const value of set.values()) {
  console.log(value);
}

console.clear();

set.add(6);
console.log(set);
set.add(6); // 중복 허용 x, 순서 x
console.log(set);
set.delete(6);
console.log(set);

// 전부 삭제
set.clear();
console.log(set);
console.log(set.size);

const obj1 = { name: 'apple', price: 8 };
const obj2 = { name: 'banana', price: 5 };
const objs = new Set([obj1, obj2]);
console.log(objs);

// quiz
obj1.price = 10;
objs.add(obj1);
console.log(objs);

// quiz
const obj3 = { name: 'banana', price: 5 }; // obj2와 obj3는 프로퍼티는 같아도 서로 다른 인스턴스이기 때문에
// 정상적으로 추가된다.

objs.add(obj3);
console.log(objs);

obj3.price = 8;
console.log(objs);
