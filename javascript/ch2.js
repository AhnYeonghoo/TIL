// CH1
// 1993년  Mosaic Web Browser
// Marc Andreessen이 1994년 Netscape를 제작, 당시 시장점유율 80%
// 동적인 웹사이트를 만들고자 고민하다가 script형 언어를 고안함.
// DOM(Document Object Model) 요소를 조작하는 언어를 만들고자 함.
// Brenden Eich라는 사람과 함께 10일만에 LiveScript가 출시함. (1994.9)
// Java의 흥행에 묻혀가기 위해 Javascript로 개명! + interpreter(엔진)를 출시
// 1995년 Microsoft가 Javascript와 엔진을 Reverse engineering하여 똑같은 Jscript 언어를 출시
// Internet Explore가 탄생 -> 개발자 고통의 시작
// ECMA라는 회사에 부탁하여 ECMAScript 1 .... ~ 4..까지 출시됨
// 2004년 mozilla에서 firefox 브라우저 출시하고 ECMAScript에 협업 요청(언어의 표준화)
// 이때까진 웹 브라우저마다 각기 다른 개발 방식으로 개발을 했어야 했음.
// 2004년 AJAX 등장
// 2008년 Chrome 등장! 다른 브라우저들이 위기를 느끼고 2008.7 드디어 모든 브라우저들이 통일된 언어를 위해 협업함
// 2015년 ECMAScript 6가 출시.(5와 6부터 클래스, 객체 등을 모두 사용할 수 있음)
// 2019년 ECMAScript 10까지 출시
// Chrome의 Javascript Engine은 V8. Node 또한 해당 엔진 사용
// Javascript의 활용 분야들이 무궁무진해짐.(프레임워크, 라이브러리의 등장)

// <-- -->

// CH2

console.log('hello world');
// async는 병렬적으로 처리 html을 parsing하다가 async를 만나면
// javascript를 다운받으며 html을 계속 parsing하고 javascript 다운이 끝나면
// html 파싱을 멈추고 javascript를 실행한다.

// defer는 html을 파싱하다가 defer를 만난 시점에 javascript를 다운로드를 다 한 후에
// javascript를 실행하고 그 후에 남은 html을 파싱함
// 결론: defer가 최선.

// 'use strict' -> 엄격모드 적용. 유연한 자바스크립트의 위험성을 방지해줌.
// flexible === dangerous
// added ECMAScript 5!
('use strict');

a = 6;
