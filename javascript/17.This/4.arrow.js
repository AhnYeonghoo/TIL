// JavaScript에서의 function은 만능 슈퍼맨!
// 함수처럼 사용 가능, 생성자 함수로도 사용(클래스 대체)
// ES6 이전에는 클래스가 없었기 때문에 함수의 중요성이 높았음.
// 하지만, 이걸 위해서 불필요한 무거운 Prototype이 생성됨. -> 메모리 낭비하는 객체
// Prototype 자체가 많은 상속관계를 포함하기 때문에 메모리 낭비가 심함

const dog = {
  name: 'dog',
  play: function () {
    console.log(`play !`);
  }, // -> 이런식으로 함수 표현식은 매우 무거운  Prototype이 생성되기 떄문에
  // ES6 문법 사용 권장
};

dog.play();
const obj = new dog.play(); // -> 프로그램이 쓸 데 없이 무거워지는 표현식
console.log(obj);

// 이러한 문제를 해결하기 위해 도입된 ES6 문법
// key의 value를 함수로 잡은 것이 아니라
// object 자체의 method를 생성함.
const cat = {
  name: 'cat',
  play() {
    console.log('cat!');
  },
};

// Or Arrow Function을 애용
const catArrow = {
  name: 'cat',
  play: () => {
    console.log('cat2!');
  },
};

cat.play();
// const obj2 = new cat.play(); -> 생성자 함수가 아닌데 왜 오브젝트 만들어? 에러 발생
// 생성자 함수로 사용 X
catArrow.play();
// const cat2 = new catArrow.play();

// Arrow Function의 특징
// 1. 문법이 깔끔함
// 2. 생성자 함수로 사용이 불가능 (즉, 무거운 Prototype을 만들지 않는다.)
// 3. 함수 자체 arguments
// 4. this에 대한 바인딩이 정적으로 결정됨!(자바와 C#, C++과 같이)
//     - 함수에서 제일 근접한 상위 scope의 this에 정적으로 바인딩됨

const add = (a, b) => {
  console.log(a, b);
};
add(1, 2);

const printArrow = () => {
  console.log(this);
};
printArrow();

catArrow.printArrow = printArrow;
catArrow.printArrow(); // 정적으로 this가 결정된다.

// JS의 동적바인딩 문제를 해결할 수 있다.
// Arrow Function 사용!
