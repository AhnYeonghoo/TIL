#include <iostream>
#include <string>
#include "student.h"

using namespace std;

int main(){
	string name = "안영후";
	int s_number = 990403;
	int age = 24;
	string local = "사창동";
	int record;
	string bestfriend = "홍길동";
	int id = 2021040016;
	
	int step = 0;

	Person person(s_number, age, local, name);
	Elementary ele(s_number, age, local, name, record=90, bestfriend);
	Middle middle(s_number, age, local, name, record=50, bestfriend);
	High high(s_number, age, local, name, record=100, bestfriend);
	Uni univ(s_number, age, local, name, record=50, bestfriend, id);

	
	while(1) {
		cout << "----Menu----" << endl;
		cout << "1.초등" << endl
			<< "2. 중학" << endl
			<< "3. 고등" << endl
			<< "4. 대학" << endl
			<< "5. 종료" << endl
			<< "선택: ";
		cin >> step;

		cout << endl;
		
		if (step == 1) {
			cout << "초등학교 정보" << endl;
			ele.move();
			cout << "이름: " << ele.get_name() << endl;
			cout << "사는곳: " << ele.get_local() << endl;
			ele.transporation("도보");
			ele.talk("하하하");
		}
		else if (step == 2) {
			cout << "중학교 정보" << endl;
			middle.move();
			cout << "이름: " << middle.get_name() << endl;
			cout << "사는 곳: " << middle.get_local() << endl;
			middle.transporation("도보");
			middle.talk("중학생이다");
		}
		else if (step == 3) {
			cout << "고등학교 정보" << endl;
			high.move();
			cout << "이름: " << high.get_name() << endl;
			cout << "사는 곳: " << high.get_local() << endl;
			high.transporation("도보");
			high.talk("고등학생이다");
		}
		else if (step == 4) {
			cout << "대학 정보" << endl;
			univ.move(); 
			 cout << "학번: " << univ.get_id() << endl;
			 cout << "사는곳: " << univ.get_local() << endl;
			 cout << "성적: " << univ.get_record() << endl;
			univ.transporation("자동차");
			univ.talk("시험이 싫어");
		}
		else if (step == 5) break;
		else {
			cout << "1~5 사이의 숫자를 입력하세요." << endl;
		}

	}

	
}