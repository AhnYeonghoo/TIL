class Animal {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  play = () => {
    console.log(`${this.name} play!`);
  };
  sleep = () => {
    console.log(`${this.name} sleep!`);
  };
}

class Tiger extends Animal {
  constructor(name, age, damage) {
    super(name, age);
    this.damage = damage;
  }
}
class Dog extends Animal {
  constructor(name, age, health) {
    super(name, age);
    this.health = health;
  }
}
const dog = new Dog('dog', 23, 100);
const tiger = new Tiger('tiger', 40, 200);
console.log(dog);
console.log(tiger);
dog.play();
tiger.play();
dog.sleep();
tiger.sleep();

console.log(dog instanceof Dog);
console.log(dog instanceof Animal);
console.log(tiger instanceof Tiger);
console.log(dog instanceof Tiger);
console.log(tiger instanceof Dog);
