# 오픈소스기초프로젝트 12주차 

<hr >

# Git diff
- ## git status
    - 변경된 파일이 어떤 파일인지만 알려줌.

<br >

- ## git diff
    - 정확히 파일의 어떤 내용이 변경되었는 지를 알려줌.
    - 원하는 파일만 보려면 git diff "file_name"
    - a/file_name -> 과거의 버전
    - b/file_name -> 현재의 버전을 표시
        - 추가된 부분은 +와 초록색으로 표기 
        - 삭제된 부분은 -와 빨간색으로 표기
    - ### *의문점: a는 왜 과거고, b는 왜 현재가 된 것일까?*     
    - 변경사항을 통해 add,commit할 판단 기준을 세워주게 됨.

    <br>

    - ## 브랜치 간 변경사항 확인하는 방법
        - git diff [repo명/]브랜치명 [repo명/]브랜치명
        - 괄호안 repo명은 선택사항.
            - 브랜치 간 변경사항은 브랜치명의 순서에 따라 상대적이기 떄문에 추가된 파일이 표기될 수도, 삭제된 파일이 표기될 수도 있음.
        - 브랜치 내에서도 특정 파일의 변경사항만 확인하는 방법
            - git diff [repo명/]브랜치명:파일명 [repo명/]브랜치명:파일명

            <br>
            
    - ## Commit간 변경사항 확인하는 방법
        - git diff <commit_id> <commit_id>로 사용
        - git log를 통해 commit log를 확인할 수 있다.
        - 노란색 텍스트에 나와있는 의문의 문자열이 commit_ID임.
        - 보통 commit_id 길이가 길기 떄문에 모든 문자열을 입력하지 않고 앞부분으로부터 7~8자리만 입력해도 무방하다.
        
<br>

# Git rebase with conflict
- Merge와 쌍벽을 이루는 git의 대표적인 명령어
- 개발자 성향에 따라서 자주 사용하는 명령어가 다르다.
- ## Merge
    - 병합하고자 하는 커밋들의 모든 것을 기록에 남길 수 있다.
    - Merge는 Master Branch와 말 그대로 모든것이 병합
- ## Rebase
    - Cherry-pick, 병합은 병합인데 원하는 커밋만을 병합할 수가 있다. Merge와 성격이 다름.
    - Rebase는 master Branch 기존 커밋들의 꼬리에 이어 붙히는 개념
- ## Rebase를 사용해도 될 지? 안 될지? 판단기준
    - Master이건 아니건, 원격 저장소에 공유된 commit에 대해서는 rebase는 지양하는 것이 좋다.(단, 구성원 모두가 동의하면 문제없음)
    - Rebase는 작업자가 팀원들의 의견과 상관없이 남이 보았을 때, 좋은 commit을 날려버릴 수도 있으므로 팀원간 상의하는 것이 좋다.
    - 원격 저장소에 공유되지 않은 branch에 대해서는 아직 남들이 branch를 보지 않고, 나만 알고 있는 작업이기 때문에 자유롭게 가능.
    - but 과거에 작업했던 branch들은 이미 원격저장소에 올라갔으므로, rebase 지양.
- ## Merge 동작 과정
    - 3-way Merge
        - Feature -> Master로 Merge 하고자 할 경우, 3개의 commit 들을 비교
        - 각 commit들에서의 시간이 지난 후의 commit은 그 이전의 commit 내용들을 이미 포함하고 있음.
- ## Rebase 동작 과정
    - Merge와 다르게 checkout을 feature branch로 한 후에 master와 rebase를 진행한다.(주체가 다름)
    - #### Conflict 발생시 대처방안
        - git status로 상태 확인!
        - 안내 문구에 따라 대처 진행
        - 그 후, 정상적으로 rebase 진행
            - git checkout master
            - feature branch와 merge
            - 최종적으로 push

<br>

# Git filter-branch
- ## Motivation
    - ### 상황1) 민감파일 없애버리기
        - key.config와 같은 repo에 push되면 안되는 비밀 파일이 존재
        - commit까지 한 시점까지는 되돌릴 수 있으나, push까지 하여 Remote Repository로 올라간 상태에선 일이 복잡해짐
        - git rm으로 파일을 local repository상에서 민감파일을 지우고 push 함 -> 실제로 지워졌다고 생각할 수 있으나, network graph상에서 commit 내용은 그대로 유지되고 있음.(해결X)
            - #### *소소한 TIP) git checkout은 branch에서만 가능한 것이 아닌, commit간에도 이동이 가능!*
        - git filter-branch --force --index-filer git rm --cached --ignore-unmatch file_name --prune-empty HEAD 명령어로 해결
        
        - ### 명령어 뜯어보기
            - force: 따지지 말고 무조건 실행
            - cached: index에 있는 것들을 삭제
            - --ignore-unmatch: 이름 매칭이 안되는 것들은 삭제에서 제외!
            - --prune-mepty: index에서 이름 매칭이 되는 것들을 삭제하다보면 빈 commit이 발생할 수 있는데 이 빈 commit도 지우라는 의미.
            
        <br>

    - ### 상황2) 프로젝트 동강내기
        - 별도의 repository로 떼어내기!

            - git filter-branch --force \ --index-filter \ 'git rm --cached -r --ignore-unmatch -- && \ git reset $GIT_COMMIT -- file_name file_name file name' \ --prune-empty -- --all
            - 두가지의 명령어의 조합(filter-branch && reset)

        - ### 3개의 file_name에 대해서 index에서만 지워지고, Working tree에는 남아있게 된다.

        - 그 후 push하게 되면 Remote Repository에는 원하는 파일만 남게 되고 다 사라지게 된다.
    
    
        
    
<br>

# Github - Code review control

- ### Concept: Repository의 Maintainer에 의해 '선택된 자'들에게만 Approval과 Request를 허용
    - '읽기 권한' 이상을 부여받은 사용자들만 허용됨
    - 단, Comment는 누구나 가능하다.
    
    <br>

- ### Maintainer의 결정에 맡김
    - 선택지 1: 기존의 방식대로 운영
    - 선택지 2: Code review control 도입

- ### How to do it?
    - 해당 방법은 Public Repository에만 적용이 가능하다.

    - ### 특정 repository에 대한 Setting 
        - Setting -> Moeration settings -> Code review limits의 Limit to users explictly grated read or higher access에 check(해당하는 repo의 Setting임)
    - ### 계정 전체 repository에 대한 Setting
        - 계정의 Setting -> Moderation settings -> Code review limits 설정
        
    - ### Repo에 초대 & 권한 설정
        - 해당 repo에 각 각 권한을 줄 수 있음.
        - 무료버전은 권한의 범위가 넓지 않음.
        - 유료버전의 경우 Read, Triage, Write, Maintain, Admin 등.. 다양하게 있음.
    
    
    <br>

# Github -LFS(Large File Storage)

- ### Motivation
    - 대용량 파일을 어떻게 관리할 것인가?
    
- ### github의 정책
    - 50MB -> 경고
    - 100MB -> 거부
    
- ### 그렇다면 50MB보다 작은 파일을 무한으로 Push하면 안될까?
    - 속도가 느려진다.(깃헙에선 무료 유저에게 큰 용량을 관리해줄 이유가 없음)
    - 1 ~ 5GB 이내의 크기로 Repo를 관리하는 것을 권장
    - 이를 무시하면 경고 메일이 날라옴
    - 속도가 생각보다 많이 느려지므로, 큰 데이터 파일은 되도록 Remote Repository에 push하는건 지양!

- ### 해결방안?
    - 1. Dropbox와 같은 클라우드 이용
    - 2. Release 이용한다.
    - 3. LFS를 사용한다.

- ### LFS 설치방법
    - sudo apt update
    - sodo apt install git-lfs
    - git lfs install --skip-repo
    

    <br >




```cpp
#include <iostream>

class Person {

    Person(int _health, int _age): health(_health), age(_age){};

    private:
    int health;
    int age;
    
    public:
    
    int get_health() { return this->health; }
    int get_age() { return this->age; }
    void set_health(int _health) { this->health = _health;}
    void set_age(int _age) { this->age = _age; }
    
    
};

int main() {

    Person person(100, 23);
    person.get_health();
    person.get_age();
    person.set_health(200);
    person.set_age(40);

    return 0;
    
}
```







<br>


### 느낀점(고찰)
     git의 기능이 엄청나게 많고 내가 쓰던 add, commit, push를 비롯한 기본적인 기능과 더불어 PR 날리는 것까지 하면 git의 기능은 다 알고 있다고 생각했는데 생각보다 훨씬 많은 기능이 있다는 것을 알고 놀라웠다. 아직 git을 향한 여정이 멀었다고 생각이 들었다. 자주 사용하는 명령어는 손에 익었으니, 새로운 기능들도 손에 익히도록 연습해야겠다.
