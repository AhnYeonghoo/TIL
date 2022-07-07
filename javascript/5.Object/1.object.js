// 객체 만드는 방법들
// Object literal { key: value }
// new Object()
// Object.create();
// key -> 문자, 숫자, 문자열, 심볼
// value -> 원시데이터, 객체, 함수 모두 가능

let apple = {
  name: 'apple',
  'hello-bye': 'hello',
  0: 1,
  ['hello-bye1']: 'bye',
};

// 프로퍼티 접근법
console.log(apple.name); // dot notation 마침표 표기법
console.log(apple['hello-bye']); // 대괄호 표기법 bracket notation
console.log(apple[0]);
console.log(apple['hello-bye1']);
console.log(apple['name']); // dot notation을 bracket notation으로 접근 가능

apple.emoji = 'emoji'; // 프로퍼티 동적 추가 가능
console.log(apple);
console.log(apple['emoji']);

// 프로퍼티 삭제
delete apple.emoji;
console.log(apple);
