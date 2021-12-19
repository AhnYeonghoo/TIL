// function & memory

function add(a, b) {
  return a + b;
}

// 함수의 이름은, 해당 함수가 저장되어 있는 메모리 공간의 주소이다(참조값이다.)
// 원시데이터는 value값이고, object, class, function etc.. 들은 참조값이다. (배열의 이름은 배열의 주소이다와 동일)
// 포인터와 동일한듯?

const sum = add;

console.log(sum(1, 2));
console.log(add('1', '2'));
console.log(add(undefined, NaN));
console.log(sum(1));
