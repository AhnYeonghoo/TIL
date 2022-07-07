// 4. string type

let string = 'hello';
console.log(string);

string = `Hello!`;
console.log(string);
string = '"Hello!"';
console.log(string);
string = "'Hello!'";
console.log(string);

// Escape expression
string = 'Hello!\nthis is korea\t\tmy name\\\u09AC';
console.log(string);

// Template Literal
let id = 'ahn';
let greetings = "'Hello!', " + id + '\n Good moning';
console.log(greetings);

greetings = `Hello! ${id} \n Good Moning ${1 + 3}`;
console.log(greetings);
