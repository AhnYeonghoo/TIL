// extends, override

class Tiger {
  constructor(color) {
    this.color = color;
  }

  eat() {
    console.log('eating');
  }

  sleep() {
    console.log('sleeping');
  }
}

class Dog {
  constructor(color) {
    this.color = color;
  }

  eat() {
    console.log('eating');
  }

  sleep() {
    console.log('sleeping');
  }

  play() {
    console.log('go play!');
  }
}

class Animal {
  constructor(color) {
    this.color = color;
  }

  eat() {
    console.log('eating');
  }
  sleep() {
    console.log('sleep');
  }
}

class Tiger2 extends Animal {
  // 오버라이딩
  eat() {
    console.log('tiger eat');
  }
}
class Dog2 extends Animal {
  constructor(color, ownerName) {
    super(color);
    this.ownerName = ownerName;
  }
  play() {
    console.log('go play!');
  }

  //오버라이딩
  eat() {
    super.eat();
    console.log('dog eat');
  }
  sleep() {
    console.log('dog sleep');
  }
}

const tiger = new Tiger2('yello');
console.log(tiger);
tiger.sleep();
tiger.eat();
const dog = new Dog2('red', 'ahn');
console.log(dog);
dog.sleep();
dog.eat();
dog.play();
