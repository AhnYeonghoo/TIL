// Expression

let b; // 선언문(Statement)
b = 2; // 표현식(Expression) 할당(assignment)

// 값(value)을 생성하면, 표현식, statement는 값을 생성하지 않음 right에 두지 못함.

let a = (b = 5);
console.log(a);

// 즉, 평가가 되어서 값이 생성되어 할당이 가능해지는 문장을 표현식이라고 한다.
// statement는 단순히 값을 할당 받거나, 아무런 값도 생성하지 않는 문장이다.
// 문장은 ;을 기준으로 한다.
