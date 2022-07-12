// Symbol 심볼
// 유일한 키를 생성할 수 있음.
const map = new Map();
const key1 = 'key';
const key2 = 'key';
map.set(key1, 'hello');
map.get(key2);
console.log(map.get(key2));
console.log(key1 === key2); // 유일하지 않은 key

const key3 = Symbol('key');
const key4 = Symbol('key');
map.clear();
map.set(key3, 'hello');
console.log(map.get(key4));
console.log(key3 === key4);
console.log(map.get(key3));

// 동일한 이름으로 하나의 키를 사용하고 싶다면, Symbol.for
// 전역 심벌 레지스트리 (Global Symbol Registry)

const k1 = Symbol.for('key');
const k2 = Symbol.for('key');
console.log(k1 === k2);

console.log(Symbol.keyFor(k1));
console.log(Symbol.keyFor(key3));

const obj = { [k1]: 'Hello', [Symbol('key')]: 1 };
console.log(obj);
console.log(obj[k1]);
console.log(obj[Symbol['key']]);
