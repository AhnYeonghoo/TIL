// var의 특징
// -> 일반 코딩 방식과 어긋나서 개발하면서도 멘붕이 옴
// -> 코드의 가독성과 유지보수성에 좋지 않음

// 1. 변수 선언하는 키워드 없이 선언 & 할당이 가능함.
// 선언인지, 재할당인지 구분하기 힘듦.

// something = 'aa';
// console.log(something);

// 2. 중복 선언이 가능함
var poo = 'poo';
var poo = 'poo2';

console.log(poo);

// 3. 블록 레벨의 scope가 적용되지 않음..
// 지역변수 === 전역변수 -> 매우 치명적
var apple = 'apple';
{
  var apple = 'apple2';
  {
    var apple = 'apple3';
    {
      var apple = 'apple4';
    }
  }
}
console.log(apple);

// 4. 함수 레벨 스코프만 지원이 됨
function example() {
  var dog = 'dog';
}
// console.log(dog); -> Error

// 하지만 var는 금지어 수준이다(레거시 말고는..)
