print(); // 함수 호이스팅

function print() {
  console.log('Hello');
}
// 변수는 불가능 console.log(hi);
// 이전 키워드인 var는 호이스팅이 됐기 때문에 사용이 지양된 것.
let hi = 'hi';
console.log(hi);
console.log(f);
var f = 'f';

// 즉, 변수(let, const)와 클래스는 선언만 호이스팅 되고,
// 초기화는 안된다.(Initialization)
// 즉, 초기화 전, 변수에 접근하는 것이 되기 때문에 컴파일 에러가 발생한다.

// 함수식 또한 변수와 같이 선언만 호이스팅이 됨.
let func1 = function () {
  console.log('asd');
};
// const cat = new Cat(); // 변수와 같이 선언만 호이스팅 되기 때문에
// 초기화가 불가능
class Cat {}

const cat = new Cat();

let x = 1;
{
  console.log(x);
  // let x = 2; 이 또한 컴파일 에러 발생.
}
