// 접근제어자 - 캡슐화 가능(불변성)
// private(#), public(default), protected -> Js는 없음
//

class Fruit {
  static MAX_FRUITS = 4;
  #name;
  #emoji; // -> #을 붙이면 private됨
  #type = 'fruit'; // 미리 초기화된 필드 맴버
  constructor(name, emoji) {
    this.#name = name;
    this.#emoji = emoji;
  }

  static makeRandomFruit() {
    return new Fruit('banana', 'i`m banana');
  }

  #display = () => {
    console.log(`${this.#name}: ${this.#emoji}`);
  };
}

const banana = Fruit.makeRandomFruit();

const apple = new Fruit('apple', 'i`m apple');
console.log(apple);
// apple.#name = 'asdad'; -> #field는 외부에서 접근시 에러 private!
// apple.#display(); -> 불가
