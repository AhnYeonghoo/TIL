// Object 동결 Object.freeze
// 단 얕은 동결임
const ellie = { name: 'ellie' };
const dog = { name: 'wow', emoji: 'dog', owner: ellie };

Object.freeze(dog);
//dog.name = 'dog';
console.log(dog.name);
//dog.age = 4;
console.log(dog.age);
//delete dog.name; -> 모두 수정 불가능

ellie.name = 'kim';
console.log(dog); // -> 객체에서 참조하는 다른 객체는 동결시키지 못함(얕음)

// 밀봉! Object.seal
const cat = {};
const cat2 = { ...dog }; // object copy
Object.assign(cat, dog); // object copy
console.log(cat);
console.log(cat2);
Object.seal(cat);
cat.name = 'cat'; // 밀봉은 가능!
// delete cat.emoji; -> 밀봉하면 값 수정만 가능, 삭제는 불가능
console.log(cat);

console.log(Object.isFrozen(dog));
console.log(Object.isSealed(cat));

// 확장 금지, preventExtensions
const tiger = { name: 'tiger' };
Object.preventExtensions(tiger);
console.log(Object.isExtensible(tiger)); // 확장 불가능
tiger.name = 'tiger2';
// tiger.age = 23; -> 확장만 불가능. 변경, 삭제 가능
delete tiger.name;
console.log(tiger);
