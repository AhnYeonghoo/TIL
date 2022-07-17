// this 바인딩
// 자바, C#, C++ 대부분의 OOP 언어에서는
// this는 항상 자신의 인스턴스 자체를 가리킴!
// 정적으로 인스턴스가 만들어지는 시점에 this가 결정됨!(변경 불가능)
// But, 자바스크립트에서는 누가 호출하냐에 따라서 this가 달라질 수 있다.
// 즉, this는 호출하는 사람(caller)에 의해 "동적"으로 결정된다.

function Cat(name) {
  this.name = name;
  this.printName = function () {
    console.log(`print the cat name ${this.name}`);
  };
}

function Dog(name) {
  this.name = name;
  this.printName = function () {
    console.log(`print the dog name ${this.name}`);
  };
}

const cat = new Cat('cat');
const dog = new Dog('dog');
cat.printName();
dog.printName();

dog.printName = cat.printName; // this가 변경됨 -> 즉, 동적 바인딩
dog.printName();
cat.printName();

console.clear();

function printOnMonitor(printName) {
  console.log(`set ready monitor, callback go`);
  printName();
}

printOnMonitor(cat.printName);
