# Pandas 라이브러리 Release note

<br>

## Motivation

- Release Note란?
  - 배포 노트
  - 라이브러리를 배포한 내용(언제, 무엇을, 어떻게, 왜)을 기록한 노트
  - Release 버전 단위로 기록
- 그렇다면 왜 기록할까?
  - 기록하는 것은 데이터를 남기는 것
  - 머신러닝 모델만 데이터를 배우는 게 아니라, 사람도 데이터로부터 배워야 한다!
  - 배우지 않는 개발자는 정체되어 있고, 성장하지 못함.
  - 그렇기 때문에 릴리즈 노트를 기록하는 것임.
- 우리가 쉽게 알 수 있는 예시들
  - 게임의 업데이트, 패치 노트 etc..

<br>
<hr />

## Pandas 라이브러리 훑어보기

- 관전 포인트
  - 엄청 많은 bug와 bug fix
  - bug fix되는 과정
    - 현상-> 분석 -> 원인 후보 -> 해결방안 후보 -> 해결방안 결정 -> 해결
  - Bug는 가령 초보자들에게만 해당되는 이야기가 아님.
  - Pandas를 만드는 개발자 마저도 Bug를 일으킴.
  - 실제 개발자들이 시간을 많이 할애하는 부분이 bug fix임.
  - release note를 보며 fix 과정을 보며, 배울 점도 있음.
- x.x.x version -> 왼쪽부터 큰 단위의 업데이트가 이루어진 버전.(경기도 xx시 xx동과 같음)

<br>

- What`s new in 1.3.5 (December 12, 2021)
  - Fixed regressions
    - Serires.equals()함수에서 소수점을 None 객체와 비교했을 때 문제가 발생했고, Fix함
      - 보다 상세한 내용은 github repository로 이동해서 볼 수 있음!
      - Issue로 관리됨
      - 실제 issue 글이 올라온 날과 release된 날은 bug fix가 되는 시간이 흐름에 따라 다를 수 있음.
      - Issue를 open한 사람은 한 사람이지만, contributor는 여러명일 수 있다.
      - PR할 때, 어떤 issue에 대한 작업을 한 것인지 해당 issue를 mention 함으로써, 표기할 수 있음.
      - issue에도 merge 됨이 파악되고, pr에서도 해당 issue를 확인할 수 있다.
  - 이런식으로, 오픈소스 release note를 통해, 실제 천상계 개발자들이 일하는 방식, 문제를 해결해나가는 과정을 엿봄으로써, 배울 점들이 많음.

<br>
<br>
<hr>

# PIP 패키지 등록 및 등록취소

<br >

## PIP이란?

- PyPI(Python, Package Index)
  - 파이썬으로 만든 패키지들을 관리하고 열람할 수 있는 저장소
  - PIP(pip install packages) -> 재귀적인 약자
    - 파이썬으로 작성된 패키지를 쉽게 설치하도록 도와주는 프로그램
    - 패키지 관리 시스템
    - 파이썬을 설치하면 기본적으로 PIP도 같이 설치됨
- PIP을 사용하여 많은 패키지들을 설치할 수 있음.
  - Python2.x와 Python3.x는 호환되지 않으므로 pip 명령어 대신 pip3 명령어를 사용하여 명시적으로 python3 버전에 해당하는 패키지를 설치할 수 있음.
  - 가상환경 안에서 pip/pip3 명령어를 사용하는 것이 권장됨
- PIP의 사용 예시
  - Tensorflow 설치시, pip 사용하여 설치 가능.
  - 먼저 python version 확인 필수!
  - 가상환경 만들어서 설치하는 것을 권장함
  - pip install -- upgrade pip
  - pip install --upgrade tensorflow -> Tensorflow 설치
- PIP 설치(Ubuntu os 사용시)
  - sudo apt update
  - sudo apt install python3-pip
- 버전확인
  - pip3 --version
- 업그레이드
  - pip3 install -U pip
    - 하지만, 보통 Python을 설치하면 pip은 딸려오기 때문에, 직접 pip을 설치할 일은 많지 않다.

<br>
<hr>

## PIP으로 Package 설치하는 방법

- Package 최신버전 설치
  - pip3 install package name
- Package 삭제
  - pip3 uninstall package name
- Package의 특정 버전 설치
  - pip3 install package_name==version
- 기 설치된 package 업그레이드
  - pip3 install --upgrade package_name (or package_name==version)
- 설치된 package 목록 보기
  - pip3 list

<br>
<hr>

## PIP에 나의 S/W 등록하기

- PyPI 가입하고 이메일 verification

<br>

## PIP에 나의 S/W 등록하기

- Step 1. 프로젝트 디렉토리 준비
  - 추후, 설치된 이후에 사용시, import 000 명령어에서 사용될 이름임.
- Step 2. 아래와 같이 소스코드와 몇 가지 파일들을 만든다.
  - 최상위 디렉토리
    - README.md
    - requirements.txt
    - LICENSE
    - setup.py
    - project source codes
      - 각 디렉토리마다 **init**.py 만들기
    - MY_PKG(복제 떠서 만들 예정)
      - 프로젝트 소스코드들 포함
- Step 4. 프로젝트의 모든 디렉토리마다 **init**.py 만들고, 통째로 카피
- Step 5. 패키지를 구성하기 위한 라이브러리 설치
- Step 6. 패키지 구성
- Step 7. 프로젝트 .gitignore 설정
  - git에 add되지 않게 해주는 파일
- Step 8. 패키지 업로드
- Step 9. PyPI에서 확인해보기
- Step 10. 다운로드 확인해보기
  - cython으로 설정해놓았으면, cython도 포함해서 설치됨

<br>
<hr>

## PIP에서 나의 S/W 등록취소하기

- PyPI 웹페이지에 로그인
  - Manage 버튼 클릭
  - 업로드 했던 프로젝트들이 버전별로 표시됨
  - Options 버튼 클릭 후, Delete 눌러 삭제 가능

<br>

## 각 각의 파일들 알아보기

- README.md
  - 해당 repository의 대문과 같은 역할
  - 잘 작성해두면, 보기 좋음
  - LICENSE 정보도 README.md에 명시해줌
- requirements.txt
  - 라이브러리 >= version
  - 패키지 >= version
  - 프로그램 >= version
  - etc... >= version
  - github에 자동으로 반영!
- LICENSE
  - 라이센스 생성
  - MIT, Apache License, BSD-2 etc..
- setup.py
  - meta 정보를 다루는 내용들을 명시해줌
  - name, version, url, author author_email, packages, description, install_requires, classifiere ... etc...

<br>
<br>
<hr>

# Pycharm으로 Ubuntu 딥러닝 가상환경 연동하기

- IDE란?

  - Integrated Development Environment의 약자
  - 통합 개발 환경
  - 개발 과정에서 필요한 것들을 모아서 제공하는 S/W
    - 프로그램 코드 편집 기능
    - 빌드 자동화
    - 디버깅
    - CI/CD
    - 플러그인 확장 기능
  - 보기 편한 GUI 환경

- 이러한 IDE중 PyCharm이란?

  - 파이썬을 위한 IDE
  - Java + Python으로 개발됨
  - 지원 OS: windows, macos, linux
  - 2010. 2월에 최초 Release
  - 대학생은 학생용 라이센스로 Edu 버전(유료버전) 무료로 사용 가능
  - 인텔리제이(자바), CRion(C, C++)들도 무료로 유료버전 사용 가능

- Pycharm: 원격 Ubuntu 서버 머신 연동
  - SSH, Docker 등을 통한 연동은 PyCharm Professional 버전에서만 가능(2022.5 기준)
  - Community 버전에서는, python interprete를 선택하는 메뉴에서, SSH Interpreter가 보이지 않음.
  - Jetbrains 홈페이지 회원가입
  - trial 버전 사용해보기
  - Server 머신 상황
    - Ubuntu 20.04 LTS
    - Python 3.8.10
    - SSH 서버 가동 중
    - 가상환경 venv에서 PyTorch 설치된 상황
    - 경로 /home/ID/pisun_project에서 git을 통해 형상관리 중임을 가정
