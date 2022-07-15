// 프로토타입을 베이스로한 객체지향 프로그래밍

function Animal(name, emoji) {
  this.name = name;
  this.emoji = emoji;
}

Animal.prototype.printName = () => {
  console.log(`${this.name} ${this.emoji}`);
};

function Dog(name, emoji, owner) {
  Animal.call(this, name, emoji);
  this.owner = owner;
}

function Tiger(name, emoji) {
  Animal.call(this, name, emoji);
}
Tiger.prototype = Object.create(Animal.prototype);
Tiger.prototype.hunt = () => {
  console.log(`tiger hunt!`);
};

Dog.prototype = Object.create(Animal.prototype); // 프로토타입 상속

Dog.prototype.play = () => {
  console.log(`let go play!`);
};

const dog1 = new Dog('dog', 'dodd', 'ahn');
const tiger = new Tiger('tiger', 'tiger');
console.log(dog1.name);
console.log(tiger.name);
tiger.hunt();

console.log(dog1 instanceof Dog);
console.log(dog1 instanceof Animal);
console.log(dog1 instanceof Tiger);
console.log(tiger instanceof Animal);
console.log(tiger instanceof Tiger);
console.log(tiger instanceof Dog);
