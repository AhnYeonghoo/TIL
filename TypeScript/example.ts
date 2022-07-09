let arr: Array<number> = [10, 20, 30];
let arr2: number[] = [10, 20, 30];
let arr3: Array<string> = ['lion', 'tiger'];
let arr4: [string, number] = ['sejong', 182];
let str: string = 'hello';
let num: number = 100;
let obj: object = { name: 'yeom', age: 29 };
let person: { name: string; age: number };
let isAvaliable: boolean = true;
function log(time: string, result?: string, option?: string) {
  console.log(time, result, option);
}

log('2021-10-04', 'success');
function sum(a: number, b: number): number {
  return a + b;
}
interface User {
  age: number;
  name: string;
}
const yeom: User = { age: 30, name: 'kyeorae' };
function getUser(user: User) {
  console.log(user);
}

getUser({ age: 10, name: 'hayoon' });

interface Sum {
  (a: number, b: number): number;
}

let sumFunc = function (a: number, b: number): number {
  return a + b;
};

interface StringArray {
  [index: number]: string;
}

let arr: StringArray = ['a', 'b', 'c'];


interface StringRegexObject {
    [key: string]: RegExp;
  }
  
  const obj: StringRegexObject {
    cssFile: /\.css$/,
    jsFile: /\.js$/
  }

  interface Person {
    name: string;
    age: number;
  }
  
  interface Developer extends Person {
    skill: string;
  }
  
const juniorDeveloper = {
    name: 'yeom',
    age: 29,
    skill: 'sleep'
}


type MyString = string;
const str: MyString = 'I love you';

type Todo = { 
  id: string;
  title: string;
  done: boolean;
};

function getTodo(todo: Todo) {
  console.log(todo);
}

function logMessage(value: string | number) {	// 함수 호출시 value 인자의 타입에는 string 또는 number
    if(typeof value === 'string') {
      value.toString();
    } else if(typeof value === 'number') {
      value.toLocaleString();
    } else {
      throw new TypeError('value must be string or number');
    }
  }
  
  logMessage('hello');
logMessage(100);
  
interface Zoo {
    name: string;
    location: string;
    price: number;
}

interface Animal {
    name: string;
    count: number;
}

// Union: Zoo나 Animal에 해당하는 인자를 제공해야 한다
askZookeeper({ name: 'tiger', count: 3});

// Intersection: Zoo나 Animal에 해당하는 인자를 줘야한다(합집합 같은 개념)
askZookeeper2({ name: '어린이대공원', location: '서울시 광진구', price: 10000, count: 10000 });


class Tiger {
    // constructor 위에 선언
    private name: string;
    public age: number;
    readonly log: string;
    
    constructor(name: string, age: number) {
      this.name = name;
      this.age = age;
    }
}
  
function logText<T>(text: T): T {
    consol.log(text);
    return text;
  }
  
logText<string>('Hello My World!');
  
interface Dropdown<T> {
	value: T;
  selected: boolean;
}

const obj: Dropdown<string> = { value: 'hamburger', selected: true };


interface LengthType {
    length: number;
}

function logTextLen<T extends LengthType>(text: T): T {
    console.log(text.length);
    return text;
}

logTextLen('abc');
// logTextLen(100); // 숫자에 length property가 없으므로 에러
logTextLen({ length: 100 });

// interface 1개
interface Dropdown<T> {
    value: T;
    title: string;
}
const shoppingItem: Dropdown<number> = {
    value: 10000,
    title: 'shoe'
}

// interface 2개
interface Dropdown2<T> {
    value: T;
    title: string;
}
interface DetailedDropdown<K> extends Dropdown2<K> {
    tag: K;
    desc: string;    
}
const detailed: DetailedDropdown<string> = {
    value: '10000',
    title: 'shoe',
    tag: '10000',
    desc: 'description'
}

function isDeveloper(target: Developer | Humanoid): target is Developer {
    return (target as Developer).skill !== undefined;
}

if(isDeveloper(tom)) {
    console.log(tom.name);
    console.log(tom.skill);
} else {
    console.log(tom.name);
    console.log(tom.age)
}