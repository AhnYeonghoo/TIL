const apple = {
  name: 'apple',

  display: function () {
    console.log(`this is ${this.name}`);
  },
};

const orange = {
  name: 'orange',
  display: function () {
    console.log(`this is ${this.name}`);
  },
};

// 생성자 함수
function Fruit(name, emoji) {
  //클래스처럼 대문자로 시작
  this.name = name;
  this.emoji = emoji;
  this.display = () => {
    console.log(`this is ${this.emoji}`);
  };
}

const apple2 = new Fruit('apple2', 'apple2');
const orange2 = new Fruit('orange2', 'orange2');
apple2.display();
orange2.display();
console.log(apple2);
console.log(orange2);
console.log(apple);
console.log(orange);
console.log(apple2.name);

console.log(apple2['name']);
