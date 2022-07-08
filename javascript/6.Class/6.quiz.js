// 카운터를 만들기
// 0 이상의 값으로 초기화 한 뒤 하나씩 숫자를 증가할 수 있는 카운터를 만들기

class Counter {
  #number;
  constructor(number) {
    if (isNaN(number) || number < 0) {
      this.#number = 0;
    } else {
      this.#number = number;
    }
  }

  get number() {
    return this.#number;
  }

  increment = () => {
    this.#number++;
  };
}

const count = new Counter(-1);
const count2 = new Counter(3);
console.log(count);
console.log(count2);
console.log(count.number);
console.log(count2.number);
count2.increment();
console.log(count2.number);
