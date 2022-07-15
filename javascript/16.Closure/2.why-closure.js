// why use?
// 내부 정보를 은닉하고, 공개 함수(public)를 통한 데이터 조작을 위해 쓰임.
// 캡슐화와 정보은닉
// class private field or method와 비슷한 환경을 구현.

function makeCounter() {
  let count = 0;
  function increase() {
    count++;
    console.log(count);
  }
  return increase;
}

const increase = makeCounter();
increase();
increase();
increase();

// 근데 요즘은 클래스로 모두 해결 ES6+

class Counter {
  #count = 0;
  increase() {
    this.#count++;
    console.log(this.#count);
  }
}

const counter = new Counter();
counter.increase();
