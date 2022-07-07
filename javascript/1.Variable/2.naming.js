// Naming Variable

/**
 *  변수 규칙
 * 라틴문자(0-9, a-z, A-Z), _
 * 대소문자를 구분한다.
 * 관례: camelCase (likeThis)
 * 변수명은 영어!
 * 주석은 되도록 영어지만, 필요시 한국어.
 * 예약어 사용 불가능(error)
 * 숫자로 시작할 수 없다.
 * 특수문자 사용 불가능하지만, 언더바(_)와 달러($)는 예외
 * 이모지 사용 불가능
 * 여러 동일한 변수를 1,2,3 등 숫자로 구분하는 것은 나쁨!
 * 최대한 의미있게, 구체적으로 변수명 네이밍!
 */

let apple; // ok
let redApple; // ok

// Bad Case
let num = 20; // bad
let audio1;
let audio2; // 변수 이름을 숫자로 구분하는 것은 매우 나쁜 습관!!

// Good Case
let myAge = 24; // ok
let backgroundAudio;
let windAudio;

// 꿀팁!
let audioBackground;
let audioWind; // -> 구체적인 것을 뒤에 작성하는 방법이 좋다.
