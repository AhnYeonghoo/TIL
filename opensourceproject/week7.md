# 7주차_오픈소스기초프로젝트

<br >

## Github ssh key management
- 작업하는 방법 크게 두가지
    - 직접 자기 머신에서 작업
    - 연구실이나 회사 서버머신에 원격으로 접속하여 작업
    
<br >

- git ssh
    - ssh key를 발급받아 안전하게 clone 받기
    - 다른 머신에서 repo에 접근하기 위해서는, SSH Key 생성, 등록이 필요
    - github 안에서 사용되는 SSH Key는 유일해야 한다.(계정이 다르더라도)


<br>

## Git move of git-branchless

- git rebase
    - Branch를 통째로 옮길 수 있게 흉내내는 명령어
    - 하지만 한계점이 존재. 
    - 그래서 git move를 만들게 됨.

<br>

- git reset
    - add, commit, push까지 했더라도 했던 작업을 되돌릴 수 있음.
    - reset 한 뒤에 push를 해주어야 함. git에서 실수로 받아들이기 때문에 -f 옵션을 주어야 함.

<br>

- git-branchless
    - Customized git 명령어를 제작하는 곳
    - 다운로드 받아서 여러가지 Customized된 git 명령어를 사용할 수 있음.
    - git, rust, cargo, branchless 등 여러가지 환경을 설치해야 함.

- git move
    - git move -s(from) commit_id -d(to) commit_id하면 move 가능
    - 그 후, git push -f origin --all해서 강제로 push 해주어야 함.
    
<br>

## Anaconda
- 아나콘다 설치에 대한 설명들음
- 실습은 개인이 
- 콘다를 설치하면 터미널 들어갈 때 마다 자동으로 콘다 가상환경으로 접속하도록 설정되어 있음.
- conda config --set auto activate base false 명령어로 자동으로 (base)에 들어가지 않게 설정 가능
    - 오류 발생시 conda 환경변수 설정해주어야 함(path)

<br>

## 코드 문서화(Documentation)

- 좋은 DocString
    - DocString: 모듈, 함수, 클래스, 메서드의 정의에 대한 설명
    - 1줄짜리: 기능과 Return type만 간단히 명시
    - 어떤 의미의 변수들을 다루는지 등과 같은 너무 자세한 설명은 배제
        - 좋은 예: 두개의 변수의 합을 계산하고, 반환 값은 int형입니다.
        - 나쁜 예: 두 개의 나이 값을 받아 계산하고 나이의 합계를 반환합니다.

- PEP에서의 DocString과 Sphinx에서의 DocString 양식이 다름.

<br >

- 좋은 Naming
    - 변수명: 카멜표기법
    - 함수명: 스네이크 표기법
    - 클래스/모듈: 스네이크 표기법
    - 공통: 무조건 알파벳 소문자로 시작하고, 꼭 필요하지 않다면 숫자/특수문자는 제외
    
        
