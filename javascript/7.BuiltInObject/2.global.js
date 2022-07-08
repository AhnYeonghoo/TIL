console.log(globalThis);
console.log(Infinity);
console.log(NaN);
console.log(undefined);
console.log(this); // brower에서 this는 global을 가리킴

eval('const num = 2; console.log(num);');
console.log(isFinite(1));
console.log(isFinite(Infinity));

console.log(typeof parseFloat('12.4213'));
console.log(typeof parseInt('12.43'));
console.log(typeof parseInt('12'));

// URL (URI의 하위 개념 Uniform Resource Identifier)
// 아스키 문자로만 구성되어야 한다.
// 한글이나 특수문자는 이스케이프 처리를 하여야 한다.

const URL = 'https://한글.com';
const encoded = encodeURI(URL);
console.log(URL);
console.log(encoded); // -> 이스케이프 처리가 됨
const decoded = decodeURI(encoded);
console.log(decoded);

// 전체 URL이 아니라 부분적인 것은 Component 이용
const part = '한글.com';
const com = encodeURIComponent(part);
console.log(com);
