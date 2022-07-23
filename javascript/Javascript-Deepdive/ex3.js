// 즉시 실행함수

(function () {
  var a = 3;
  var b = 5;
  return a * b;
})();

(function () {
  // ...
})();
!(function () {})();
+(function () {})();

let res = (function () {
  let a = 3;
  let b = 5;
  return a * b;
})();
console.log(res);

res = (function (a, b) {
  return a * b;
})(3, 6);
console.log(res);
console.log(typeof function f() {});
console.log(typeof function () {});
console.clear();

// Recursive Function
function countDown(n) {
  for (let i = n; i >= 0; i--) console.log(i);
}
countDown(10);

function recursiveCountDown(n) {
  if (n < 0) return;
  console.log(n);
  recursiveCountDown(n - 1);
}
recursiveCountDown(5);
// Factorial Function
function factorial(n) {
  if (n <= 1) return 1;
  return n * factorial(n - 1);
}
console.log(factorial(0));
console.log(factorial(1));
console.log(factorial(2));
console.log(factorial(3));
console.log(factorial(4));
console.log(factorial(5));
console.clear();

// 함수 표현식
let factorialExpression = function foo(n) {
  if (n <= 1) return 1;
  return n * factorialExpression(n - 1);
};
console.log(factorialExpression(5));

function whileFactorial(n) {
  if (n <= 1) return 1;
  let res = n;
  while (--n) res *= n;
  return res;
}
console.log(whileFactorial(1));
console.log(whileFactorial(2));
console.log(whileFactorial(3));
console.log(whileFactorial(4));
console.log(whileFactorial(5));
console.clear();

// Nested Function
function outer() {
  let x = 1;

  // Inner F
  function inner() {
    let y = 2;
    console.log(x + y);
  }
  inner();
}
outer();

// callback function
function repeat(n) {
  for (let i = 0; i < n; i++) console.log(i);
}
repeat(5);

function repeat1(n) {
  for (let i = 0; i < n; i++) console.log(i);
}
repeat1(5);

function repeat2(n) {
  for (let i = 0; i < n; i++) {
    if (i % 2) console.log(i);
  }
}
repeat2(5);

function repeatSolution(n, f) {
  for (let i = 0; i < n; i++) {
    f(i); // callback
  }
}

let logAll = function (i) {
  console.log(i);
};
repeatSolution(4, logAll);

let logOdd = function (i) {
  if (i % 2) console.log(i);
};
repeatSolution(5, logOdd);
console.clear();

// callback Function의 활용예
setTimeout(function () {
  console.log('a few second');
}, 1000);

// 배열 고차함수
let res2 = [1, 2, 3].map(function (item) {
  return item * 2;
});

console.log(res2);

res2 = [1, 2, 3].filter(function (item) {
  return item % 2;
});
console.log(res2);

res2 = [1, 2, 3].reduce(function (acc, cur) {
  return acc + cur;
});
console.log(res2);
