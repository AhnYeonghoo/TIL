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
let array = ['banana', 'str', 'orange', 'str'];
array = array.map((value) => {
  if (value === 'str') {
    return (value = 'kiwi');
  } else {
    return (value = value);
  }
});

// const array = ['banana', 'str', 'orange', 'str'];
console.log(array);
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
let array2 = ['banana', 'kiwi', 'orange', 'kiwi'];
let count2 = 0;

array2.find((value) => {
  if (value === 'kiwi') count2++;
});
console.log(count2);
// const resultt2 = count(array2, 'kiwi');
// console.log(resultt2);

// // 퀴즈3: 배열1, 배열2 두개의 배열을 전달받아,
// // 배열1 아이템중 배열2에 존재하는 아이템만 담고 있느 ㄴ배열 반환

function match(input, search) {
  const result = [];
  for (let i = 0; i < input.length; i++) {
    if (search.includes(input[i])) {
      result.push(input[i]);
    }
  }
  return result;
}

const array4 = ['banana', 'kiwi', 'orange'];
const array5 = ['banana', 'str', 'orange', 'str'];
let resultArr = array4.filter((value, index) => {
  if (value === array5[index]) {
    return value;
  }
});
console.log(resultArr);
// console.log(
//   match(['banana', 'kiwi', 'orange'], ['banana', 'str', 'orange', 'str'])
// );

// // 퀴즈 4 5이상(보다 큰)의 숫자들의 평균

const nums = [3, 16, 5, 25, 4, 34, 21];
let average = nums.reduce((result, value) => {
  if (value >= 5) {
    result += value;
  }
  return result / nums.length;
});
console.log(average);
console.log((16 + 5 + 25 + 34 + 21) / nums.length);

console.clear();
// 선생님 풀이 ---------------

// 1.
function replaceSolution(array, from, to) {
  return array.map((item) => (item === from ? to : item));
}
const array6 = ['banana', 'str', 'orange', 'str'];
console.log(replaceSolution(array, 'str', 'kiwi'));

// 2.
function countSolution(array, item) {
  return array.filter((value) => value === item).length;
}
console.log(countSolution(['banana', 'kiwi', 'str', 'kiwi'], 'kiwi'));

// 3.
function matchSolution(input, search) {
  return input.filter((item) => search.includes(item));
}
console.log(matchSolution(['banana', 'kiwi', 'orange'], ['banana', 'str']));

// 4.
const result6 = nums
  .filter((num) => num > 5)
  .reduce((avg, num, index, array) => avg + num / array.length, 0);
console.log(result6);
