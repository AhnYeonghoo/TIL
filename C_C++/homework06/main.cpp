#include <iostream>
#include <string>
#include "student.h"

using namespace std;

int main(){
	string name = "�ȿ���";
	int s_number = 990403;
	int age = 24;
	string local = "��â��";
	int record;
	string bestfriend = "ȫ�浿";
	int id = 2021040016;
	
	int step = 0;

	Person person(s_number, age, local, name);
	Elementary ele(s_number, age, local, name, record=90, bestfriend);
	Middle middle(s_number, age, local, name, record=50, bestfriend);
	High high(s_number, age, local, name, record=100, bestfriend);
	Uni univ(s_number, age, local, name, record=50, bestfriend, id);

	
	while(1) {
		cout << "----Menu----" << endl;
		cout << "1.�ʵ�" << endl
			<< "2. ����" << endl
			<< "3. ���" << endl
			<< "4. ����" << endl
			<< "5. ����" << endl
			<< "����: ";
		cin >> step;

		cout << endl;
		
		if (step == 1) {
			cout << "�ʵ��б� ����" << endl;
			ele.move();
			cout << "�̸�: " << ele.get_name() << endl;
			cout << "��°�: " << ele.get_local() << endl;
			ele.transporation("����");
			ele.talk("������");
		}
		else if (step == 2) {
			cout << "���б� ����" << endl;
			middle.move();
			cout << "�̸�: " << middle.get_name() << endl;
			cout << "��� ��: " << middle.get_local() << endl;
			middle.transporation("����");
			middle.talk("���л��̴�");
		}
		else if (step == 3) {
			cout << "����б� ����" << endl;
			high.move();
			cout << "�̸�: " << high.get_name() << endl;
			cout << "��� ��: " << high.get_local() << endl;
			high.transporation("����");
			high.talk("����л��̴�");
		}
		else if (step == 4) {
			cout << "���� ����" << endl;
			univ.move(); 
			 cout << "�й�: " << univ.get_id() << endl;
			 cout << "��°�: " << univ.get_local() << endl;
			 cout << "����: " << univ.get_record() << endl;
			univ.transporation("�ڵ���");
			univ.talk("������ �Ⱦ�");
		}
		else if (step == 5) break;
		else {
			cout << "1~5 ������ ���ڸ� �Է��ϼ���." << endl;
		}

	}

	
}