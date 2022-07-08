// 객체를 손쉽게 만들 수 있는 템플릿
// 1. 생성자 함수 (오래된 고전적인 방법) -> 사용 X
// 2. 클래스 (ES6에 새로 도입된 기술) -> OOP가 가능

class Fruit {
  // 생성자 함수 : new 키워드로 객체를 생성할 때 호출되는 함수
  constructor(name, emoji) {
    this.name = name;
    this.emoji = emoji;
    console.log('create Fruit');
  }

  // Arrow Function
  display = () => {
    console.log(`${this.name}: ${this.emoji}`);
  };
}

// apple은 Fruit 클래스의 인스턴스이다. -> 실제 메모리로 올라간 상태(객체가)
const apple = new Fruit('apple', 'i`m apple');
// orange는 Fruit 클래스의 인스턴스이다.
const orange = new Fruit('orange', 'i`m orange');
console.log(orange);
console.log(apple);
console.log(apple.name);
console.log(orange.name);
apple.display();
