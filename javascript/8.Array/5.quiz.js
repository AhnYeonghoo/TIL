// 퀴즈1: 주어진 배열 안의 딸기 아이템을 키위로 교체하는 함수를 만들기
// 단, 주어진 배열을 수정하지 않도록
// ㅇinput: ['banana', 'str', 'orange', 'str']
// output: ['banana', 'kiwi', 'orange', 'kiwi']

let input = ['banana', 'str', 'orange', 'str'];
let output = input.slice(0, 1);
let output2 = input.slice(2, 3);
console.log(output2);
console.log(output);
let result = output.concat(output2);
result.splice(1, 0, 'kiwi');
result.splice(3, 0, 'kiwi');
// result = result.splice(-1, 0, 'kiwi');
console.log(result);

let input2 = ['banana', 'str', 'orange', 'str'];
console.clear();

// 퀴즈1: 주어진 배열 안의 딸기 아이템을 키위로 교체하는 함수를 만들기
// 단, 주어진 배열을 수정하지 않도록
// input: ['banana', 'str', 'orange', 'str']
// output: ['banana', 'kiwi', 'orange', 'kiwi']
function replace(array, from, to) {
  const replaced = Array.from(array);
  for (let i = 0; i < replaced.length; i++) {
    if (replaced[i] === from) {
      replaced[i] = to;
    }
  }
  return replaced;
}

const array = ['banana', 'str', 'orange', 'str'];
const resultt = replace(array, 'str', 'kiwi');
console.log(resultt);

// 퀴즈2:
// 배열과 특정한 요소를 전달받아, 배열안에 그 요소가 몇개나 있는지 카운트 하는 함수 만들기
// input: ['banana', 'kiwi', 'orange', 'kiwi'] 'kiwi'
// output: 2

function count(array, arg) {
  const newArr = Array.from(array);
  let count = 0;
  for (let i = 0; i < newArr.length; i++) {
    if (newArr[i] === arg) {
      count++;
    }
  }
  return count;
}

const array2 = ['banana', 'kiwi', 'orange', 'kiwi'];
const resultt2 = count(array2, 'kiwi');
console.log(resultt2);

// 퀴즈3: 배열1, 배열2 두개의 배열을 전달받아,
// 배열1 아이템중 배열2에 존재하는 아이템만 담고 있느 ㄴ배열 반환

function match(input, search) {
  const result = [];
  for (let i = 0; i < input.length; i++) {
    if (search.includes(input[i])) {
      result.push(input[i]);
    }
  }
  return result;
}
console.log(
  match(['banana', 'kiwi', 'orange'], ['banana', 'str', 'orange', 'str'])
);
