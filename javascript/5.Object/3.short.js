// 객체 축약 버전

const x = 0;
const y = 0;
const coordinate = {
  x: x,
  y: y,
};
console.log(coordinate);

const coordinate2 = {
  x, // -> 생략 하기 권장
  y,
};

console.log(coordinate2);

function makeObj(name, age) {
  return {
    name,
    age,
  };
}

console.log(makeObj('kim', 'ddd'));
