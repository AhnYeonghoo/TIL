// GC(Garbage Collector)
// C#, GO, Java, JavaScript!

let apple = {
  name: 'apple',
};

let orange = apple;
orange = null;
console.log(orange);
console.log(apple);
apple = null;
// 이후에는 아무도 object를 참조하고 있지 않기 때문에, object가 저장되어
// 있는 메모리에서 가비지 컬렉터에 의해 청소(삭제)됨.

// 가비지 컬렉터는 자바스크립트 엔진 백그라운드 프로세스.

const global = 1; // Global Variable의 Life Cycle은 App Life Cycle과 동일.
// 즉 전역변수는 최대한 지양. (메모리 낭비)
// variable은 최대한 필요한 곳에서만 선언 및 할당
{
  const local = 1;
  // local variable이 필요한 block, block이 종료되면 GC에 의해 메모리 청소
}

function print() {
  // 함수 내부에서도 블럭 안에서만 필요한 경우에는, 블럭 안에서 변수를 선언 및 할당한다.
  if (true) {
    let temp = 0;
  }
}
