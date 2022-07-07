// 반복문 (Loop statement)
// for(변수선언문; 조건식; 증감식) { process... }
// 실행순서:
// 1. 변수 선언문
// 2. 조건식의 값이 참 -> {} 실행
// 3. 증감식 수행
// 4. 조건식이 거짓이 될 때 까지 2~3번 반복

for (let i = 0; i < 5; i++) {
  console.log(i);
}

for (let i = 0; i < 5; i += 2) {
  console.log(i);
}

for (let i = 0; i < 5; i++) {
  for (let j = 0; j < 5; j++) {
    console.log(i, j);
  }
}

// 무한루프 (Infinity Loop)

// for (;;) {
//   console.log('asd');
// }

// 반복문 제어: continue, break;

for (let i = 0; i < 20; i++) {
  if (i === 10) {
    console.log('i is ten');
    continue;
  }
  console.log(i);
}
