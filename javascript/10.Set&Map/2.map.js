// key & value로 이루어진 자료구조
// 파이썬의 딕셔너리!
// 파이썬의 set === Js의 set

// Key는 유일하며, Value는 중복을 허용하며, 순서는 없다.

const map = new Map([
  ['key1', 'apple'],
  ['key2', 'banana'],
  ['key3', 'kiwi'],
]);

console.log(map);

console.log(map.values());

// size check
console.log(map.size);

// 존재하는지 확인
console.log(map.has('key1'));
console.log(map.has('key5'));

// 순회
map.forEach((value, key) => console.log(key, value));
console.log(map.keys());
console.log(map.values());
console.log(map.entries());
console.clear();

// 찾기
console.log(map.get('key1'));
console.log(map.get('key1'));
console.log(map.get('key5'));

// 추가
map.set('key4', 'orange');
console.log(map);

// 삭제
map.delete('key4');
console.log(map);

// 전부 삭제
map.clear();
console.log(map);

// 오브젝트와의 큰 차이점??
const key = { name: 'milk', price: 10 };
const milk = { name: 'milk', price: 10, description: 'good milk' };
const obj = {
  [key]: milk,
};
console.log(obj);
const map2 = new Map([[key, milk]]);
console.log(map2);
console.log(obj[key]);
console.log(map2.get(key));
