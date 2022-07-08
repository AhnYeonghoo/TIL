// Getter, Setter -> 접근자 프로퍼티(Accessor Property)

class Student {
  constructor(firstName, lastName) {
    this.firstName = firstName;
    this.lastName = lastName;
  }

  // Getter
  get fullName() {
    return `${this.lastName} ${this.firstName}`;
  }

  // Setter
  set fullName(value) {
    console.log(value);
  }
}

const student = new Student('suji', 'kim');
console.log(student.firstName);
console.log(student.fullName);
console.log(student.lastName);
student.fullName = 'kim chulsu';
