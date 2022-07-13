function a() {
  console.log('a');
  return 'a end';
}

function b() {
  console.log('b');
  a();
  return 'b and';
}

function c() {
  b();
  console.log('c');
  return 'c end';
}
console.log('start');
const result = c();
console.log('end');
console.log(result);
