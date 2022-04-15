#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	int ss_number; // 주민번호 
	int age; // 나이
	string local; // 지역
	string name; // 이름

public:
	Person(int ss_number_, int age_, string local_, string name_){
		this->ss_number = ss_number;
		this->age = age_;
		this->local = local_;
		this->name = name_;
	} 

	~Person(){
		cout << "파괴자 실행" << endl;
	}
	
	// getter
	int get_ss_number();
	int get_age();
	string get_local();
	string get_name();

	//setter
	void set_ss_number(int ss_number_);
	void set_age(int age_);
	void set_local(string local_);
	void set_name(string name_);

	// move()
	void move();

	// talk()
	void talk(string talk);
	
	//transporation()
	void transporation(string trans);

	
	

		
};

// 초등학교
class Elementary : public Person {
private:
	int record;
	string bestfriend;

public:
	Elementary(int ss_number_, int age_, string local_, string name_, int record_, string bestfriend_) :Person(ss_number_, age_, local_, name_) {
		this->record = record_;
		this->bestfriend = bestfriend_;
	};

	~Elementary() {
		cout << "초등학교 클래스 파괴자" << endl;
	}
	// setter
	void set_record(int record_);
	void set_bestfriend(string bestfriend_);

	// getter 
	int get_record();
	string get_bestfriend();


	
	void move();
	void talk(string talk);
	void transporation(string trans);
	void graduated(int yyyy, int mm, int nn);
	
	

};

class Middle : public Person {
private:
	int record;
	string bestfriend;
	
public:
	Middle(int ss_number_, int age_, string local_, string name_, int record_, string bestfriend_) :Person(ss_number_, age_, local_, name_) {
		this->record = record_;
		this->bestfriend = bestfriend_;
	};
	
	~Middle() {
		cout << "중학교 클래스 파괴자" << endl;
	}
	// setter
	void set_record(int record_);
	void set_bestfriend(string bestfriend_);

	// getter
	int get_record();
	string get_bestfriend();

	void move();
	void talk(string talk);
	void transporation(string trans);
	void graduated(int yyyy, int mm, int nn);

};

class High : public Person {
private:
	int record;
	string bestfriend;

public:
	High(int ss_number_, int age_, string local_, string name_, int record_, string bestfriend_) :Person(ss_number_, age_, local_, name_) {
		this->record = record_;
		this->bestfriend = bestfriend_;
	}

	~High() {
		cout << "high 클래스 파괴자" << endl;
	}
	// setter
	void set_record(int record_);
	void set_bestfriend(string bestfriend_);
	

	// getter
	int get_record();
	string get_bestfriend();

	void move();
	void talk(string talk);
	void transporation(string trans);
	void graduated(int yyyy, int mm, int nn);

};

class Uni : public Person {
private:
	int record;
	string bestfriend;
	int id;

public:
	Uni(int ss_number_, int age_, string local_, string name_, int record_, string bestfriend_, int id_) :Person(ss_number_, age_, local_, name_) {
		this->record = record_;
		this->bestfriend = bestfriend_;
		this->id = id_;
	};

	~Uni() {
		cout << "uni 클래스 파괴자" << endl;
	}
	// setter
	void set_record(int record_);
	void set_bestfriend(string bestfriend_);
	void set_id(int id);

	// getter
	int get_record();
	string get_bestfriend();
	int get_id();

	void move();
	void talk(string talk);
	void transporation(string trans);
	void graduated(int yyyy, int mm, int nn);

};