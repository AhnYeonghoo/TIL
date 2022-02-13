// 6. empty type (null, undefined)

let variable;
console.log(variable);

variable = null;
console.log(variable);

let activeItem; // -> 활성화된 아이템이 있는 지 없는 지 모르는 상태
activeItem = null; // -> 활성화된 아이템이 없다는 것이 명확히 명시됨

console.log(typeof 123);
console.log(typeof '123');
console.log(typeof undefiend);
console.log(typeof null); // -> Object!!
