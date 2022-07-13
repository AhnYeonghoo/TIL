fetch(
  'https://www.7timer.info/bin/astro.php?lon=113.2&lat=23.1&ac=0&unit=metric&output=json&tzshift=0'
).then((response) => {
  const data = response.json();
  console.log(data);
  console.log(response.ok);
  console.log(response.body);
});

console.log(data);
