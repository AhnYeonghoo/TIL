// function basic

function add(num1, num2) {
  return num1 + num2;
}

console.log(add(3, 4));

const result = add(1, 2);
console.log(result);

let lastName = 'kim';
let firstName = 'jisu';
// let fullName = `${lastName} ${firstName}`;
console.log(fullName(firstName, lastName));

let lastName2 = 'park';
let firstName2 = 'chulsu';
let fullName2 = `${lastName2} ${firstName2}`;
console.log(fullName2);

function fullName(firstName, lastName) {
  return `${firstName} ${lastName}`;
}

console.log(fullName(firstName2, lastName2));
