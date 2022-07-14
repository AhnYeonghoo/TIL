// 엄격 모드 strict mode
// 리액트와 같은 프레임워크 사용시 기본적으로 strict mode임

'use strict';
var x = 1;
// delete x; -> 불가능

function add(x) {
  var a = 2;
  // b = a + x; -> 불가능
  var b = a + x;
  console.log(this); // undefined가 나옴
}
add(1);

const array = [1, 2, 3];
for (let num of array) {
  // let, const없이 사용 불가능
  console.log(num);
}

function strict() {
  'use strict';
  // 함수 내부에서만 엄격모드 적용 가능
}
