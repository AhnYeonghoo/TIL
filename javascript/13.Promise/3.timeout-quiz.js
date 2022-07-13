// 주어진 seconds(초)가 지나면 callback 함수를 호출
// 단, seconds가 0보다 작으면 에러를 던지자

function runInDelay(callback, seconds) {
  if (seconds < 0) {
    throw new Error('seconds not found');
  } else {
    setTimeout((callback, seconds) => {
      callback;
    }, seconds * 1000);
  }
}

function callback() {
  console.log('111');
}

runInDelay(callback(), 2);

function runInDelaySolution(callback, seconds) {
  if (!callback) {
    throw new Error('not found callback function');
  }
  if (!seconds || seconds < 0) {
    throw new Error('seconds not found');
  }

  setTimeout(callback, seconds * 1000);
}

try {
  runInDelaySolution(() => {
    console.log('timer');
  }, 2);
} catch (error) {
  console.log(error);
}

try {
  runInDelaySolution(() => {
    console.log('timer');
  }, -1);
} catch (error) {
  console.log(error);
}
