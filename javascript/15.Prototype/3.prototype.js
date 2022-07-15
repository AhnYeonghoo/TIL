const dog1 = { name: 'monj', emoji: 'dog' };
const dog2 = { name: 'coco', emoji: 'dog2' };

// 클래스는 프로토타입을 이용한 설탕같은 문법 JS만

// 생성자 함수
function Dog(name, emoji) {
  this.name = name;
  this.emoji = emoji;
  // 인스턴스 레벨의 함수 -> 인스턴스마다 모두 함수를 메모리에 생성됨
  // 메모리 낭비!
  // 방지하기 위해 프로토타입의 레벨의 함수로 만듦.
  //   this.printName = () => {
  //     console.log(`${this.name} ${this.emoji}`);
  //   };
}

const dog3 = new Dog('dog3', 'dog3');
const dog4 = new Dog('dog4', 'dog4');

console.log(dog3);
console.log(dog4);
// prototype 레벨의 함수
Dog.prototype.printName = function () {
  console.log(`${this.name} ${this.emoji}`);
};

dog3.printName();
dog4.printName();

// 오버라이딩
// 인스턴스 레벨에서(자식) 동일한 이름으로 함수를 재정의하면
// 프로토타입 레벨의(부모) 함수의 프로퍼티는 가려진다. (섀도잉)

dog3.printName = function () {
  console.log(`Hello`);
};
dog3.printName();
dog4.printName();

// 스태틱 레벨
Dog.hello = () => {
  console.log('hello static');
};
Dog.hello();
// dog2.hello(); -> 스태틱으로만 접근 가능
Dog.MAX_AGE = 20;
console.log(Dog.MAX_AGE);
console.log(dog2.MAX_AGE);
