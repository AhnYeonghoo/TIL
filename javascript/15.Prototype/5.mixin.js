// // 오브젝트는 단 하나의 prototype을 가리킬 수 있다.
// (부모는 단 하나)
// 하지만! 여러개의 함수들을 상속하고 싶다!
// Mixin!

const play = {
  play: function () {
    console.log(`${this.name} play!`);
  },
};
const sleep = {
  sleep: function () {
    console.log(`${this.name} sleep!`);
  },
};

function Dog(name) {
  this.name = name;
}
Object.assign(Dog.prototype, play, sleep);

const dog = new Dog('dd');
console.log(dog);
dog.play();
dog.sleep();

// JS는 기본적으로 프토토타입 기반의 언어이기 때문에
// 클래스를 사용해도 내부적으로는 프로토타입 기반으로 작동
// 따라서 프로토타입처럼 다중 상속이 가능
class Animal {}
class Tiger extends Animal {
  consturctor(name) {
    super();
    this.name = name;
  }
}

Object.assign(Tiger.prototype, play, sleep);
const tiger = new Tiger('name');
tiger.play();
tiger.sleep();
