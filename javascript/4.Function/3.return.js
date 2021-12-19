// return을 명시적으로 하지 않으면, 자동으롤 undefined를 반환함. return undefined 자동 생성
function add(a, b) {
  return a + b;
}

const result = add(1, 2);
console.log(result);

function print(text) {
  console.log(text);
}

// return을 함수 중간에 하게 되면 함수가 종료됨
// 사용예: 조건이 맞지 않는 경우 함수 도입부분에서 함수를 일찍이 종료함!

function print2(num) {
  if (num < 0) {
    return;
  }
  console.log(num);
}

const outcome = print('text'); // -> return X
console.log(outcome);
print2(5);
print2(-3);
