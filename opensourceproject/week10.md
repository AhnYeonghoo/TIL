# 10주차_오픈소스기초프로젝트

- 9주차 복기
    - 9주차 수업에 대한 내용 리마인드
    
<br />

- Logger는 모든 프로젝트 시작 전 항상 만들어야 하는 것.

- config 파일 생성의 이유
    - 각 설정을 필요한 파트마다 일일이 코드를 작성하여 집어넣으면 작동은 원할히 되겠지만, 설정이 바뀔 때마다 해당 코드를 찾아가 설정을 모두 손수 바꿔주어야 하는 단점이 있고 유지보수면에서 불리하다.
    - 따라서 하나의 설정 파일로써 프로그램 전체에 대한 설정값을 지정하여 개발자 입장에서 유지보수가 용이하도록 한다.

    - 환경설정 변경후에는 항상 가상환경을 재접속해야 적용이 됨!
    - 카테고리별로 각 각 환경변수 설정하기

<br />    

- myconfig.py 파일 작성 후 test.py로 테스트 진행

```python
if __name__ == '__main__'
```
- 의 의미는 import 되어서 실행되느냐 python3에 의해 바로 실행되느냐를 체크하는 조건문
- import 되어서 실행되면 if문은 False가 됨.


<br />

# MongoDB 

- document 기반의 DBMS
    - NoSQL(Not only SQL)에 속하는 DBMS
    - Fields에 Key&Value의 형태로 데이터 존재
    
- 파이썬의 딕셔너리 형태와 유사해서 파이썬과 자주 사용됨.

- Moon modeler로 db 설계 후 script나 문서를 참고해서 mongodb로 db 제작

<br />

# MongoDB Design Pattern

- Schema versioning pattern
    - Document-based
        - 각 version마다 다르게 동작하는 application으로 서비스를 하면서, Batch updater를 만들어서 version을 업데이트
    - Computed pattern 등.
    

<br />

# 데이터 수집
- 데이터 수집방법
    - 웹데이터 크롤러 사용
    - 웹데이터 스크래퍼 사용
    
- 데이터 수집시 고려사항 
    - 데이터를 사용해도 되는지에 대해 License, Copyright등에 대해 policy를 잘 확인 후 사용 가능한 데이터만 잘 가져오기
    
