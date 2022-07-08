// 정직원과 파트타임직원을 나타낼 수 있는 클래스를 만들어 보자
// 직원들의 정보: 이름, 부서이름, 한달 근무 시간
// 매달 직원들의 정보를 이용해서 한달 월급을 계산할 수 있다.
// 정직원은 시간당 10000원
// 파트타임 직원은 시간당 8000원

class Employee {
  #name;
  #time;
  #partment;
  #salary;

  constructor(name, time, partment, salary) {
    this.#name = name;
    this.#time = time;
    this.#partment = partment;
    this.#salary = salary;
  }

  get time() {
    return this.#time;
  }

  get partment() {
    return this.#partment;
  }

  get name() {
    return this.#name;
  }
}

class Jung extends Employee {
  #salary = 10000;
  monthSalary = () => {
    return this.#salary * this.time;
  };
}

class Part extends Employee {
  #salary = 8000;
  monthSalary = () => {
    return this.#salary * this.time;
  };
}

const jung = new Jung('ahn', 5, 'it');
console.log(jung.monthSalary());
console.clear();

class Employee2 {
  constructor(name, department, hoursPerMonth, payRate) {
    this.name = name;
    this.department = department;
    this.hoursPerMonth = hoursPerMonth;
    this.payRate = payRate;
  }
  calculatePay() {
    return this.hoursPerMonth * this.payRate;
  }
}

class FullTimeEmployee extends Employee2 {
  static PAY_RATE = 10000;
  constructor(name, department, hoursPerMonth) {
    super(name, department, hoursPerMonth, FullTimeEmployee.PAY_RATE);
  }
}

class PartTimeEmployee extends Employee2 {
  static PAY_RATE = 8000;
  constructor(name, department, hoursPerMonth) {
    super(name, department, hoursPerMonth, PartTimeEmployee.PAY_RATE);
  }
}

const ellie = new FullTimeEmployee('ellie', 's/w', 30);
const bob = new PartTimeEmployee('bob', 's/w', 20);
console.log(ellie.calculatePay());
console.log(bob.calculatePay());
