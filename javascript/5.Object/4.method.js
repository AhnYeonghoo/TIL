// 메서드(method)

const apple = {
  name: 'apple',

  display: function () {
    console.log(`this is ${this.name} `);
  },
};

apple.display();
