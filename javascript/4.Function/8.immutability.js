// 함수의 불변성!!!!!!!!!!!!!!
// 함수 내부에서 외부로부터 주어진 인자의 값을 변경하는 것은 절대 하지않는다. -> 매우 중요
// 상태 변경이 필요한 경우에는, 새로운 상태(object, value)를 만들어서 반환해야 한다!!
// 원시값은 값에 의한 복사
// 객체값은 참조에 의한 복사(포인터)(메모리 주소가 전달)(결국 서로 동일한 object를 갖게됨)

function display(num) {
  num = 1; // 값이 변해버림
  console.log(num);
}

const value = 4;
display(value);
console.log(value); // but value의 값은 참조가 아니기 때문에, 기존 value는 변하지 않음.

// 잘못된 점
// 1. 함수명과 다른 일을 한다.(이름 변경)
// 2. 외부로부터 주어진 인자를 변경했다.
function displayObject(obj) {
  obj.name = 'kim';
  console.log(obj);
}

function changeName(obj) {
  return { ...obj, name: 'bob' };
}
const ahn = { name: 'ahn' };
displayObject(ahn);
console.log(ahn.name); // 오브젝트는 참조에 의한 변경이므로, 함수 내부에서 값을 변경해버리면
// 오브젝트를 가르키는 메모리 주소에 가서 값을 변경하므로, 실제 오브젝트 값이 변경됨
const kim = { name: 'kim' };
console.log(changeName(kim));
console.log(kim.name);
