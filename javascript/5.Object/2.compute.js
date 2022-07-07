const obj = {
  name: 'ahn',
  age: 24,
};

// 코딩하는 시점에, 정적으로 접근이 확정될 떄 사용 가능
obj.name;
obj.age;

// 동적으로 속성에 접근하고 싶을 때 대괄호 표기법 사용!

function getValue(obj, key) {
  return obj[key];
}

console.log(getValue(obj, 'age'));
console.log(getValue(obj, 'name'));

function addKey(obj, key, value) {
  obj[key] = value;
}

function deleteKey(obj, key) {
  delete obj[key];
}

addKey(obj, 'eat', 'cookie');
console.log(obj);
deleteKey(obj, 'eat');
console.log(obj);
