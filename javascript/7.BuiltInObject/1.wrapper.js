// 래퍼 객체 (Wrapper Object)
// 원시값을 필요에 따라서 관련된 빌트인 객체로 변환한다!
const number = 123; //number 원시 데이터 타입
console.log(number);

// number 원시타입을 감싸고 있는 Number 객체로 감싸짐
console.log(number.toString()); // 메서드를 호출하는 순간 원시값이 아닌, 객체가 됨.

const text = 'text';
console.log(text);
const length = text.length;
console.log(length);
console.log(text.trim());
