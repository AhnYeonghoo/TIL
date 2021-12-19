// 주어진 숫자 만큼 0부터 순회하는 함수
// 순회하면서 주어진 특정한 일을 수행해야 함.
// 5, 순회하는 숫자를 다 출력하고 싶음.
// 5, 순회하는 숫자의 두배값을 다 출력하고 싶음.
// function iterate(max, action)

const printNumber = (numbers) => {
  for (let i = 0; i < numbers; i++) {
    console.log(i);
  }
};

const doubleNumber = (number) => {
  for (let i = 0; i < number; i++) {
    console.log(i * 2);
  }
};

function iterate(max, action) {
  action(max);
}

iterate(3, printNumber);
iterate(5, doubleNumber);

iterate(3, (num) => console.log(num));
iterate(3, (num) => console.log(num * 2));

setTimeout(() => {
  console.log('1s later exe');
}, 1000);

setTimeout(() => {
  console.log('4초뒤에 실행됩니다.');
}, 4000);
