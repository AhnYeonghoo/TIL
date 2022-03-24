# 발표

- 각, 팀들이 프로젝트에 대한 개요를 발표함

# git motivation

- git은 프로그램 형상관리 툴이다.

- commit 단위는 작업자의 재량, 여기서 실력이 갈린다.

- 3단 콤보

  - 처음에 status에 추적되지 않은 파일에 새로 생성된 파일들이 위치 해있음.
  - git add 파일명하면 commit할 파일들을 stage에 추가할 수 있음.
  - git add해서 commit으로 묶을 단위는 순수히 commit할 사용자의 재량.
  - git commit -m "작업 내용"하면
  - 최종적으로 commit한 작업들을 git push origin main하면 원격저장소로 push됨.

- git clone URL

  => Remote -> Local

- git status

  => local의 현재 상황정보 보기

- git rm
  => 파일을 삭제할 때 사용하지만, 보통 파일을 삭제할 때 또한 git add 명령어를 자주 사용한다.

- git을 이용하는 원격저장소는 github 뿐만 아니라 gitlab 등 다양하게 있다.

- github와 같은 원격저장소에서는 Repository를 제공한다.

# SSH Key

    - SSH Key는 보안상의 이유로 발급하고 사용자 인증을 위해 사용한다.

# git fetch와 git pull

- git fetch

  - git fetch는 원격 저장소의 커밋들을 로컬 저장소로 가져온다. 그리고 자동으로 Merge를 해주기 않기 때문에 본인이 직접 확인을 한 후에 Merge하는 과정을 거쳐야 한다.

  - 즉, 본인이 가지고 있는 기존 프로젝트와 가져온 프로젝트를 따로따로 갖고 있는 셈이다. 이 둘을 직접 Merge 해주어야 한다.

- git pull

  - git pull이란 원격 저장소의 정보를 가져오면서 자동으로 로컬 브랜치에 Merge까지 수행해주는 명령어이다.
  - fetch와 다르게 기존 프로젝트와 가져온 프로젝트를 자동으로 Merge 해주는 명령어이다.
  - 한마디로 프로젝트의 가장 최신버전을 원격저장소로부터 본인의 컴퓨터나 가상서버로 가져다 오는 것이다.

# 작업순서

- 1. pull로 가장 최신화 된 소스코드를 가져온다.
- 2. 작업할 내용에 따라 개발을 진행한다.
- 3. 작업이 끝났으면 commit 단위에 따라 add를 통해 stage에 올린다.
- 4. 작업 단위로 commit 해준다.
- 5. 최종적으로 push를 통해 원격저장소로 push 해준다.

# git Merge

- 자신의 Branch를 생성한다.
- main이나 master branch에서 자신의 branch로 병합한다.
- 그 후 개발을 진행한다.
- add, commit, push를 통해 push 한다.
- github에서 Pull Request 생성하고
- 팀원들의 코드리뷰 요청하고, Merge를 승인 받는다.
- Merge된 후 자신의 branch 삭제하고 동기화한다.
- git 상에서 Merge 할 수 있는 방법을 공부해보아야겠다.
