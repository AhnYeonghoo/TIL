// Conditional statement
// switch

let day = 6;
let dayName;
if (day === 0) {
  dayName = '1';
} else if (day === 1) {
  dayName = '2';
} else if (day === 2) {
  dayName = '3';
} else if (day === 3) {
  dayName = '4';
} else if (day === 4) {
  dayName = '5';
}
// so Bad

switch (day) {
  case 0:
    dayName = '월';
    break;
  case 1:
    dayName = '화';
    break;
  case 2:
    dayName = '수';
    break;
  case 3:
    dayName = '목';
    break;
  case 4:
    dayName = '금';
    break;
  case 5:
    dayName = '토';
    break;
  case 6:
    dayName = '일';
    break;
  default:
    dayName = '??';
}

console.log(dayName);

let condition = 'okay';
let text;
switch (condition) {
  case 'okay':
  case 'good':
    text = 'good!';
    break;

  case 'bad':
    text = 'bad!';
}
console.log(text);
