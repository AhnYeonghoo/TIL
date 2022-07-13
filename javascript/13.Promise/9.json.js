// JSON: JavaScript Object Notation
// 서버와 클라이언트(브라우저, 모바일) 간의 HTTP 통신을 위한
// 오브젝트 형태의 텍스트 포맷
// stringify(object): JSON
// parse(JSON): object  -> JSON을 통한 네트워크 통신 함수는 딱 두가지!

const ellie = {
  name: 'ellie',
  age: 20,
  eat: () => {
    console.log('eat');
  },
};

// 객체를 문자열로 만드는 것 -> 직렬화(Serializing): stringify
// 문자열을 객체로 만드는 것 -> 역직렬화(Deserializing) parse
const json = JSON.stringify(ellie); // JSON엔 메서드가 포함되지 않는다.
console.log(json);
console.log(ellie);
const string = JSON.parse(json);
console.log(string);
