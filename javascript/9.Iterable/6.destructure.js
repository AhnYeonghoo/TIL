// 구조 분해 할당 Desturcturing Assignment
// 데이터 뭉치(그룹화)를 쉽게 만들 수 있다.
const fruits = ['apple', 'kiwi', 'orange', 'banana'];
const [first, second, ...others] = fruits;
console.log(fruits[0]);

console.log(first);
console.log(second);
console.log(others);

const point = [1, 2];
const [x, y, z = 0] = point;

console.log(x);
console.log(y);
console.log(z);

function createEmoji() {
  return ['apple', 'appleEmoji'];
}

const [title, emoji] = createEmoji();
console.log(title);
console.log(emoji);

const ellie = { name: 'Ellie', age: 20, job: 's/w engineer' };
function display({ name, age, job }) {
  console.log(`name: ${name}`);
  console.log(`age: ${age}`);
  console.log(`job: ${job}`);
}

console.log(display(ellie));
const { name, age, job: occupation, pet = 'dog' } = ellie;
console.log(name);
console.log(age);
console.log(occupation);
console.log(pet);
