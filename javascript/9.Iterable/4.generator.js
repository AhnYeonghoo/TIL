// 이터러블을 좀 더 쉽게 만드는 제너레이터
function makeIterable(initialValue, maxValue, callback) {
  return {
    [Symbol.iterator]() {
      let num = initialValue;
      return {
        next() {
          return { value: callback(num++), done: num > maxValue };
        },
      };
    },
  };
}

function* multipleGenerator() {
  try {
    for (let i = 0; i < 10; i++) {
      console.log(i);
      yield i ** 2; // next를 호출할 때 까지 기다렸다가 실행해야만 다음 for문으로
      // 순회한다.
    }
  } catch (error) {
    console.log(error);
  }
}

const multiple = multipleGenerator();
let next = multiple.next();
console.log(next.value, next.done);
next = multiple.next();
multiple.throw('error');
next = multiple.next();

console.log(next.value, next.done);
next = multiple.next();

console.log(next.value, next.done);
