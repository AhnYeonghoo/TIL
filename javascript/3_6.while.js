// 반복문
// while(조건) {}
// 조건이 false 될 때 까지 {} 무한 실행

let num = 5;

while (num >= 0) {
  console.log(num);
  num--;
}

let isActive = false;
let i = 0;

while (isActive) {
  console.log('is alive');
  if (i === 100) break;
  i++;
}

do {
  console.log('do while');
} while (isActive);
