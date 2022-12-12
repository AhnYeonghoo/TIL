# 오픈소스기초프로젝트_5주차

<hr />
<hr />

- 작업 내용 같은 것들을 카톡이 아닌 깃허브 이슈를 이용해서 의논하기.

- bracnh 명이 feature_xxx인 이유는 특정한 기능을 개발하겠다라는 것을 확실히 보여주기 위함
    - 관행으로 자리잡음.
    - hotfix등.. 다양한 branch명을 정하는 convention이 존재.
    - 마치 git push origin master에서 origin을 변경하지 않는 것 처럼
    

- master branch로 merge하기 위해서는 자신의 현재 작업중인 branch에 위치해있는 지를 git status로 확인하는 습관들이기.

- git의 branch에도 master가 존재하지만 자신의 작업 branch에도 master가 존재하므로 이 점을 유의해야 함.
    - 자신의 branch에서 작업 후 "자신의 branch의 master"로 merge 한 다음, 최종적으로 remote repo의 master branch로 "push" 하는 것임.

    <br >
    <br>

<hr />
<hr />

<br >
<br >
- 원격저장소의 master branch로부터 최신버전을 pull 해온 후 자신의 작업 master branch에서 feature branch로 먼저 merge를 해서 pull 해온 코드와 자신의 기존 코드와의 호환성이나 에러가 발생하는 지를 체크하고 문제가 생겨도 자신의 feature branch에서만 문제가 생기도록 한다. feature branch에서 문제를 해결하고 작업하고 다시 자신의 작업 master branch로 merge하고 최종적으로 원격저장소의 master branch로 push하고 MR한다.


<br >
<br >


- issus는 생성한 사람도 중요하고, assign 되어있는 사람, 그 issue를 해결하여 closed 시킨 사람도 중요하다.

(eg: 개발자 A가 issue를 발견하여 이를 해결하고자 issue를 남기고자 하는데, 개발자 B가 해당 작업을 수행하는데 적합하다고 생각해 개발자 B를 assign한다.)

- conflict(충돌)나지 않게 작업하는 것이 중요.. 
    - 자신의 작업 MASTER BRANCH에서 직접 작업하지 않기
    - 작업의 feature branch에서 작업하기.
    - 역할분담이 됐으면 각자 역할에만 충실하기
    
<br >
<br >
<hr />
<hr />

<br >



## MR(merge_request) 또는 PR(pull_request) 이용하기

- 1. remote repository로부터 기존 작업 소스코드가 존재할시엔 git pull, 새로 받는거면 git clone으로 최신버전 가져오기
- 2. 자신의 작업 브랜치 생성 후(이름은 feature_xxx) 그 브랜치에서 작업하기
- 3. 작업이 완료되면 git add, commit, push 하기.
- 4. 이후 자신의 작업 master branch로 MR하는 것이 아니다!(이건 혼자 일할 때)
- 5. 바로 remote repository로 MR을 하여 팀원들에게 소스코드 검토 및 업로드 허락을 받아 최종적으로 자신의 작업 branch -> remote repository로 Merge(합병)하게 된다.

<br >
<br >

- MR한 곳에서 commnet 가능, 소스코드 검토 중 문제가 있어 보이는 line 클릭 후 해당 코드에 대해 comment 남기기 가능
- MR한 유저는 comment를 확인하고, 코드를 수정하거나 자신의 의견을 다시 comment 
- 해당 과정 반복.... 결국 결판나고 merge 되든지 말든지 할 것.

<br >
<br >
<b>
- ? 질문: git branch를 만들면 예를 들어 yg라는 브랜치로 checkout 해서 작업하고 
그 브랜치에서 git add commit push하고 깃허브 홈페이지에서 MR하는 것이 맞는지
그리고 자신의 브랜치에서 push해도 깃허브 홈페이지에는 바로 push 되는 것이 아닌 MR이 수락되어야
최종적으로 깃허브 홈페이지에 최종 소스코드가 업로드 되는 것인지 궁금.
</b>
<br >
<br >

<b>
답변: 원격저장소에는 push하는 순간 바로 반영은 되지만, merge는 안된 상태임. 즉, master branch에는 merge(합병)이 안된 상태. request가 승인되어야 최종 master branch(깃허브 repo의 첫페이지)에 반영되는 것임.
</b>