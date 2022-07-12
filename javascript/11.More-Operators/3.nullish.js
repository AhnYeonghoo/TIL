// Nullish Coalescing Operator
// ES11 (ECMAScript 2022)
// ?? null, undefined인 경우에만 뒤에껄 수행
// 0, -0, ''
let num = 0;
console.log(num || '-1');
console.log(num ?? 1);

num = 10;
console.log(num ?? 1);

let text = '';
console.log(text ?? 'not empty');
