// 주어진 배열에서 중복을 제거하라.
const fruits = ['banana', 'apple', 'orange', 'banana', 'apple', 'kiwi'];
// ['banana', 'apple', 'orange', 'kiwi']
const resultFruits = new Set(fruits);
console.log(resultFruits);
console.log([...new Set(fruits)]);
function removeDuplication(array) {
  return [...new Set(array)];
}
console.log(removeDuplication(fruits));

// 주어진 두 세트의 공통된 아이템만 담고 있는 세트 만들어라.
const set1 = new Set([1, 2, 3, 4, 5]);
const set2 = new Set([1, 2, 3]);
const resultSet = new Set();
console.log(set1);
resultSet.add(set1.values() && set2.values());
console.log(resultSet);

function findIntersection(set1, set2) {
  const set = [...set1].filter((item) => set2.has(item));
  return new Set(set);
}
console.log(findIntersection(set1, set2));
