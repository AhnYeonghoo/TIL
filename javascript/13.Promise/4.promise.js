function runInDelaySolution(callback, seconds) {
  if (!callback) {
    throw new Error('not found callback function');
  }
  if (!seconds || seconds < 0) {
    throw new Error('seconds not found');
  }

  setTimeout(callback, seconds * 1000);
}

//   try {
//     runInDelaySolution(() => {
//       console.log('timer');
//     }, 2);
//   } catch (error) {
//     console.log(error);
//   }

function runInDelayPromise(seconds) {
  return new Promise((resolve, reject) => {
    if (!seconds || seconds < 0) {
      reject(new Error('not found seconds'));
    }
    setTimeout(() => {
      resolve();
    }, seconds * 1000);
  }); // 약속을 리턴
}

runInDelayPromise(2)
  .then(() => console.log('timer done'))
  .catch(console.error)
  .finally(() => console.log('done'));
