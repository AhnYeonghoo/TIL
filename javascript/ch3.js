// 1. Use strict
// added in ES5
// use this for valina Javascript
"use strict";

// CH3. Variable
// let (added in ES6)

let name = "ahn";
console.log(name);
name = "hello";
console.log(name);

let global_variable = 321;
{
  let block_variable = 123;
}
// console.log(block_variable);  => error!
console.log(global_variable);

// var (don`t ever use this)
console.log(age); // -> var hoisting
var age = 4;
// but let cannot use hoisting
// console.log(ki);  => error
let ki = 5;

// 3. Constants
// favor immutable data type always for a few reasons
// - security
// - thread safety
// - reduce human mistakes
const day_in_week = 26;
const max_number = 5;

// 4. Variable types
// primitive, single item: number, string, boolean, null, undefined, symbol
// object, box container
// function, first-class function

const count = 17; // integer
const size = 17.1; // decimal number
console.log(`value: ${count}, type: ${typeof count}`);
console.log(`value: ${size}, type: ${typeof size}`);

// number - special numeric values: infinity, -infinity, NaN
const infinity = 1 / 0;
const negative_infinity = -1 / 0;
const NaN = "not a number " / 2;
console.log(infinity);
console.log(negative_infinity);
console.log(NaN);

// bigInt (fairly new, don`t use it yet)
const bigInt = 1231231231231231323213213123123123123n;
console.log(`value: ${bigInt}, type: ${typeof bigInt}`);

// string
const char = "c";
const brendan = "brendan";
const greeting = "hello " + brendan;
console.log(`value: ${greeting}, type: ${typeof greeting}`);
const hello_bob = `hi ${brendan}! `; // template literals(string)
console.log(`value: ${hello_bob}, type: ${typeof hello_bob}`);

//boolean
// false:0, numm, undefined, NaN, ''
// true: any other value
const can_read = true;
const test = 3 < 1;
console.log(can_read);
console.log(test);

// null
let nothing = null;
console.log(`value: ${nothing}, type: ${typeof nothing}`);

// undefined
let x;
console.log(`value: ${x}, type: ${typeof x}`);

// symbol, create unique identifiers for objects
const symbol1 = Symbol("id");
const symbol2 = Symbol("id");
console.log(symbol1 === symbol2);

const g_symbol1 = Symbol.for("id");
const g_symbol2 = Symbol.for("id");
console.log(g_symbol1 === g_symbol2);
console.log(`value: ${symbol1.description}, type: ${typeof symbol1}`);

// 5. Dynamic typing: dynamically typed language

let text = "hello";
console.log(`value: ${text}, type: ${typeof text}`);
text = 1;
console.log(`value: ${text}, type: ${typeof text}`);
text = "7" + 5;
console.log(`value: ${text}, type: ${typeof text}`);
text = "8" / "2";
console.log(`value: ${text}, type: ${typeof text}`);
// console.log(text.charAt(0));  -> integer에 indexing 불가능

// object, real-life object, data structure
const yg = { name: "yg", age: 20 };
yg.age = 30;
console.log(yg.name, yg.age);
