function getBanana() {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve('banana');
    }, 1000);
  });
}

function getApple() {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve('apple');
    }, 3000);
  });
}

function getOrange() {
  return Promise.reject(new Error('not found orange'));
}

// 바나나와 사과를 같이 가지고 오기

getBanana()
  .then((banana) =>
    getApple().then((apple) => {
      return [banana, apple];
    })
  )
  .then(console.log);

// Promise.all 병렬적으로 한번에 모든 Promise들을 실행
Promise.all([getBanana(), getApple()]).then((fruits) =>
  console.log(`all`, fruits)
);

Promise.race([getBanana(), getApple()]).then((fruits) =>
  console.log('race', fruits)
);

Promise.all([getBanana(), getApple(), getOrange()])
  .then((fruits) => console.log(`all-error`, fruits))
  .catch(console.log);

Promise.allSettled([getBanana(), getApple(), getOrange()])
  .then((fruits) => console.log(`allSettled`, fruits))
  .catch(console.log);

async function fetchFruits() {
  const banana = await getBanana();
  const apple = await getApple();
  return [banana, apple];

  //   return getBanana().then((banana) =>
  //     getApple().then((apple) => [banana, apple])
  //   );
}
console.clear();

fetchFruits().then((fruits) => console.log(fruits));
