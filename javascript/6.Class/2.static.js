class Fruit {
  // static 프로퍼티
  static MAX_FRUITS = 4;
  // static 정적 프로퍼티, 메서드 (클래스 레벨의 맴버.)
  constructor(name, emoji) {
    this.name = name;
    this.emoji = emoji;
    console.log('create Fruit');
  }
  //클래스 레벨의 메서드
  static makeRandomFruit = () => {
    return new Fruit('banana', 'i`m banana');
  };

  // Arrow Function
  // 해당 함수는 인스턴스 레벨의 메서드
  display = () => {
    console.log(`${this.name}: ${this.emoji}`);
  };

  // 클래스 레벨의 메서드(static 맴버)
  static displayStatic = () => {
    console.log(`Hi Im Static`);
  };

  //클래스 레벨의 메서드에서는 this를 참조할 수 없다.
}

// apple은 Fruit 클래스의 인스턴스이다. -> 실제 메모리로 올라간 상태(객체가)
const apple = new Fruit('apple', 'i`m apple');
// orange는 Fruit 클래스의 인스턴스이다.
const orange = new Fruit('orange', 'i`m orange');
console.log(orange);
console.log(apple);
console.log(apple.name);
console.log(orange.name);
console.clear();

Fruit.displayStatic();
const banana = Fruit.makeRandomFruit();
console.log(banana);
console.log(banana.name);
console.log(banana.emoji);
console.log(Fruit.MAX_FRUITS);
console.log(banana.MAX_FRUITS);

console.log(Math.pow(2, 2)); // -> static method의 대표
console.log(Number.isFinite(1));
