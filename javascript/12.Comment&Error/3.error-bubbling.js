// bubbling up, Propagating

function a() {
  throw new Error('error');
}

function b() {
  try {
    a();
  } catch (error) {
    console.log('In function Catched');
    console.log('nope!');
    throw error;
  }
}
function c() {
  b();
}

try {
  c();
} catch (error) {
  console.log('Catched!');
}
console.log('done');
