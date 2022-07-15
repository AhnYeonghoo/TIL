const dog = { name: 'dog', emoji: 'wow' };

console.log(Object.keys(dog));
console.log(Object.values(dog));
console.log(Object.entries(dog));

console.log('name' in dog);
console.log(dog.hasOwnProperty('name'));
console.log(dog.hasOwnProperty('emoji'));

// 오브젝트의 각각의 프로퍼티는 프로퍼티 디스크립터라고 하는 객체로 저장됨
const des = Object.getOwnPropertyDescriptors(dog);
console.log(des);

const desc = Object.getOwnPropertyDescriptor(dog, 'name');
console.log(desc);

const desc2 = Object.getOwnPropertyDescriptor(dog, 'emoji');
console.log(desc2);

Object.defineProperty(dog, 'name', {
  value: 'dogdog',
  writable: false,
  enumerable: false,
  configurable: false,
});

console.log(dog.name);
console.log(Object.keys(dog));
// delete dog.name; // configurable false여서 불가능
console.log(dog.name);

const student = {};
Object.defineProperties(student, {
  firstName: {
    value: 'yong',
    writable: true,
    enumerable: true,
    configurable: true,
  },
  lastName: {
    value: 'kim',
    writable: true,
    enumerable: true,
    configurable: true,
  },
  fullName: {
    get() {
      return `${lastName} ${firstName}`;
    },
    set(name) {
      [this.lastName, this.firstName] = name.split(' ');
    },
    configurable: true,
  },
});

console.log(student);
console.log();
