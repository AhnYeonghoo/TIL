// 조건문(Conditional Statement)
// if (Condition) {}
// if () { } else { }

let fruit = 'apple';

if (fruit === 'apple') {
  console.log(':apple');
  let a = 1;
  console.log(a);
} else if (fruit === 'orange') {
  console.log('orange');
} else {
  console.log('!!');
}

let fruit2 = 'orange';

if (fruit2 === 'apple') {
  console.log('appple');
} else {
  console.log('Error');
}

if (0) {
  console.log('do not print');
}
if (undefined) {
  console.log('do not print');
}
if ('') {
  console.log('do not print');
}
if (2 > 1) {
  console.log('true');
}
if (false) {
  console.log('do not print');
}
if (true) {
  console.log('print');
}
