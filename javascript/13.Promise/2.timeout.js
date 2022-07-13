function execute() {
  console.log('1');
  setTimeout(() => {
    console.log('2');
  }, 3000); // 병렬적으로 실행
  console.log('3');
  setTimeout(() => {
    console.log('last');
  }, 5000);
}

execute();
console.log('end');
