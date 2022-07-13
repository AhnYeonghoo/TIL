function fetchEgg(chicken) {
  return Promise.resolve(`${chicken} => Egg`);
}

function fryEgg(egg) {
  return Promise.resolve(`${egg} => fry`);
}

function getChicken() {
  return Promise.resolve(`get Chicken`);
}

function getChickenError() {
  return Promise.reject(new Error(`not found checken`));
}

fetchEgg('chicken').then((egg) => console.log(egg));
console.clear();

getChicken()
  .then((chicken) => {
    return fetchEgg(chicken);
  })
  .then((egg) => fryEgg(egg))
  .then((friedEgg) => console.log(friedEgg));

async function fecthGetChicken() {
  const chicken = await getChicken();
  const egg = await fetchEgg();
  return fryEgg(egg);
}

fecthGetChicken().then(console.log);
console.log('dd');
console.clear();

// Solution

async function makeFriedEgg() {
  let chicken;
  try {
    chicken = await getChicken();
  } catch {
    chicken = 'egg';
  }
  const egg = await fetchEgg(chicken);
  return fryEgg(egg);
}

makeFriedEgg().then(console.log);
