// 5. boolean type

let cham = true;
let no = false;
console.log(cham);
console.log(no);

// 활용예
let isFree = true;
let isActivated = false;
let isEnrolled = true; // is를 붙여 사용
console.log(isFree);
console.log(isActivated);
console.log(isEnrolled);

console.clear();
// Falshy 거짓인 값
console.log(!!0);
console.log(!!-0);
console.log(!!'');
console.log(!!null);
console.log(!!undefined);
console.log(!!NaN);

// Truthy 참인 값
console.log(!!1);
console.log(!!-1);
console.log(!!'text');
console.log(!!{});
console.log(!!Infinity);
console.log(!![]);
