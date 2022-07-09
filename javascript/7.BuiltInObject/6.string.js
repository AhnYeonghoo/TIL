const textObj = new String('Hello World!');
const text = 'Hello world!';
console.log(textObj);
console.log(text);
console.log(text.substring(6, text.length));

console.log(text[0]);
console.log(text[1]);
console.log(text[2]);
console.log(text.charAt(0));
console.log(text.charAt(1));
console.log(text.charAt(2));
console.log(text.length);

console.log(text.indexOf('l'));
console.log(text.indexOf('H'));
console.log(text.indexOf('q'));
console.log(text.indexOf('l'));
console.log(text.includes('tx'));
console.log(text.includes('h'));
console.log(text.includes('H'));
console.log(text.startsWith('h'));
console.log(text.startsWith('Hello'));
console.log(text.endsWith('!'));
console.log(text.toUpperCase());
console.log(text.toLowerCase());

console.log(text.substring(0, 2)); // 이상 미만
console.log(text.slice(2));
console.log(text.slice(-2));

const space = '        space         ';
console.log(space.trim());
const longText = 'Get to the point';
console.log(longText.split(' '));
const longTextSpace = longText.split(' ').toString();
console.log(longTextSpace);
