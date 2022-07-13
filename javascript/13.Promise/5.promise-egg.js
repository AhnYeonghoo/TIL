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

getChicken()
  .then((chicken) => {
    return fetchEgg(chicken);
  })
  .then((egg) => fryEgg(egg))
  .then((friedEgg) => console.log(friedEgg));

getChickenError()
  .then((chicken) => {
    return fetchEgg(chicken);
  })
  .then((egg) => fryEgg(egg))
  .then((friedEgg) => console.log(friedEgg))
  .catch((e) => console.log(e.name));

getChickenError()
  .catch((error) => {
    console.log(error.name);
    return 'new Egg';
  })
  .then((c) => {
    return fetchEgg(c);
  })
  .then((e) => fryEgg(e))
  .then((fe) => console.log(fe));

getChicken()
  .catch(() => 'egg')
  .then(fetchEgg)
  .then(fryEgg)
  .then(console.log);
