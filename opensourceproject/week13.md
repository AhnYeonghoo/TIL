# 13주차 오픈소스기초프로젝트

<br >

# Git repo Release
- 필요한 사람이 원격저장소의 주소를 통해 직접 git pull하여 사용할 수 있지만, 매우 불편. => 릴리즈 하는 이유
- pytorch repo 방문하여 릴리즈 살펴보기
    - 이처럼 잘 개발되어 있는 프레임워크도 오픈소스로써 오픈되어 있으며, 전세계 개발자들이 일하는 방법에 대해서 상세히 알 수 있음.
    - 공부를 할 수 있는 가장 좋은 수단!

    <br>

- Release 해보기!
    - tag가 version명 
        - version은 세자리의 dot으로 구분
        - Major.Minor.Patch 
        - Major에 해당하는 첫째자리 수는 프로그램이 돈 받고 팔 수 있을 지경에 이르렀을 때 정도가 되어야 가능한 버전.
        - E.g) 에일리언1 -> 에일리언2 개봉

<br>

- Relase 할 수 있는 방법은 한가지가 아니다!
    - 원격저장소에서 직접 릴리즈
    - commit id를 통한 릴리즈
    - PR을 이용한 릴리즈 etc..


<hr >
<br>
<br>

# Git의 원리
- ### 형상관리 시스템
    - 2가지의 종류가 존재.
        - 중앙 집중식
            - 중앙 서버에서 모든 파일들을 저장 및 유지
            - 팀원들이 서로 무슨 작업을 하는지 알 수 있음.
        - 분산식
            - 각 팀원들의 클라이언트에 레포지토리를 통째로 복사하여 작업
            - 이 방법은 중앙 서버에 문제가 생기거나, 통신이 끊겨도 작업이 가능하다는 장점이 존재.
- 즉, Git은 분산 버전관리 시스템중에서 널리 사용되는 프로그램. 
- Git을 이용하면 인터넷이 끊겨있어도, pull만 되어있다면, 자신의 노트북 혹은 데스크탑으로 실컷 작업하고, 나중에 한 번에 push하는 방법으로 형상관리를 효율적으로 할 수 있음.

<br>

- ### Git 동작원리
    - add와 commit까지는 자신의 local 머신에서만 동작함.(원격저장소와 연결X)
    - Working directory: 첫 clone 받아 git과 연결된 상태의 작업 폴더를 의미. 즉, 추상적인 공간이 아닌 실재하는 공간
    - add하면 Staging area로 올라감.
        - Staging area 또한 실재하는 공간임
        - .git/index로서 존재.
    - commit시 local Repository로 올라감.
        - Push시 비로소 Remote Repository에 반영.
        - pull은 그 반대 
    - Repository의 구조
        - .git/objects/folder안에 데이터들이 존재
            - Blob File
                - 버전 관리하는 파일들 각 각의 내용은 깃의 저장소에서 Blob 파일 형태로 저장. 
                - !! 내용이 같은 파일들은 모두 하나의 Blob 파일로서 저장!!
            - Commit File
                - 하나의 버전을 생성한다는 것은 하나의 Commit File을 만드는 것을 의미
                - !! 가리키고 있는 Tree file의 주소와 직전 버전에 해당하는 commit file의 주소가 기록
            - Tree File
                - 커밋 시점의 파일들 각각에 대해 그 파일명과 해당 파일의 내용을 담고 있는 Blob 파일의 주소가 기록됨.
                - .git/index 폴더 성격과 유사
    - 즉, Git 버전관리 모든것은 file로서 존재한다! 추상적인 것이 아님!
    

<br>

### Git object: Blob
- Blob(Binary Large Object): 일련의 데이터 자체
- Blob 파일 내용 확인: git cat_file -p 'filename'
- Blob 파일 여부 확인: git cat-file -t 'filename'
- Blob 파일은 파일 내용에 대한 해쉬를 'directory/filename'으로 저장
    - 같은 내용을 담은 다른 파일의 내용도 모두 1개의 Blob file로 저장
    - 1개의 file 내용이 변할 때마다 새로운 Blob file이 생성됨.

                    
<br >

### Git object: Tree
- git ls-tree master로 확인 가능.

        100644 blob 11df6ec87fe20e47e9a04fcb5b825bf7c7fd5a8e    .gitignore
        100644 blob 49281d5a48c8d55b282d83ce405e1d233f04472c    README.md
        100644 blob e19f4d409746307842694de1fbe681636d217537    key.config
        040000 tree 5e10a7579e03af90491a6c611c6a2ecc433ca948    lib
        040000 tree 96233b34ccba706a9f89dca87a9282a3cd836e0a    log
        100644 blob 38e718ad88c8689f74f41c69a741e289ec6309cb    requirements.txt
        040000 tree 69d01a1a2731b9af632b27f820dc246cc766f086    service
        040000 tree 601d5d8cf31e6b374e571a34b16a72d90f2e1309    share
        040000 tree 69276297d35db86ab5f39e44568ee6a8dc19ac3f    src
        100644 blob 1a83365d31ac48ce95f6f0dec343ca7ab6797bae    temp.py
        100644 blob 40ceec8e71cc408cacad4350cf63139656ec2b16    test.py
    



<hr>
<br>
<br>

# Docker를 이용한 GitLab 서비스 서버 구축

### Git & GitHub & GitLab
- Git: 기술적인 부분
    - 코드의 형상관리
    - 분산 저장 방식으로 운영
    - 공짜고, 오픈소스
- Github, Gitlab, BitBucket, etc..
    - Git 기술 바탕의 서비스(플랫폼)
    - 가격 정책이나 제공 기능 등이 차이가 있음.
- 추천하는 방식
    - 절대 공개하지 않을 나만의 repo들을 관리 == Gitlab
    - 일부, 혹은 전체공개 == Github

<br>

### why make git service server?
- 기업
    - 사내 git 서비스 운영을 통해 sw 자산에 대한 보안
    - git 서비스 버전 직접 관리
        - 더 나은 보안
    
- 개인
    - 신기..하니까?

- 개인&기업
    - 저장용량 제한으로부터의 자유


<br>

### Docker란?
- Container 기반의 가상화 플랫폼
    - Container: 소프트웨어의 실행에 필요한 모든것을 포함하는 독립된 실행환경(os, library.. etc)
    - 프로그램 배포 및 관리에 용이
    
- 사용 방법
    - 컨테이너 실행에 필요한 파일과 설정을 이미지화
    - 이미지를 실행 -> Container

- Docker 설치는 공식 문서를 살펴보기.

- 설치 준비
    - apt-get 설정 & 설치에 필요한 패키지 다운
        - $ sudo apt-get update
        - $ sudo apt-get -y install apt-transport-https ca-certificates curl gnupg lsb-release
    - Docker Official Key 등록
        - $ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o 
        /usr/share/keyrings/docker-archive-keyring.gpg
    - Docker 설치를 위해 다운로드 받을 리스트 생성
        -  echo "deb [arch=amd64 signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] 
        https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" | sudo tee 
        /etc/apt/sources.list.d/docker.list > /dev/null
    - Docker 설치 
        - sudo apt-get update
        - sudo apt-get install docker-ce     docker-ce-cli containerd.io docker-compose-plugin
        
    - Docker 설치 확인
        - sudo docker run hello-world
        - 테스트용 image download
            - 컨테이너로 실행
            - 화면에 메시지 출력
            - 종료
    - Docker 버전 확인
        - sudo docker --version

    - Gitlab image download
        - sudo docker pull gitlab/gitlab-ce
        - 가장 최신버전을 다운받음
        - 특정 버전의 이미지를 다운 받고자 할 경우 버전명을 명시해서 다운 가능


<hr>
<br>
<br>

# 잡다한 git 명령어들
- git checkout -- 파일명
    - 수정된 내역으로 인해 추적되는 파일에 대해 수정내역 취소시킴.

- git restore --staged 파일명
    - git add 되었던 파일에 대해 add cancel

- git reset HEAD^숫자
    - HEAD에서 최근의 '숫자' 개수만큼 commit cancel

