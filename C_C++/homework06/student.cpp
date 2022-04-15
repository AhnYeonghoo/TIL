#include <string>
#include <iostream>
#include "student.h"

using namespace std;

// setter

void Person::set_ss_number(int ss_number_) { this->ss_number = ss_number_; }
void Person::set_age(int age_) { this->age = age_; }
void Person::set_local(string local_) { this->local = local_; }
void Person::set_name(string name_) { this->name = name_; }

void Elementary::set_record(int record_) { this->record = record_; }
void Elementary::set_bestfriend(string bestfriend_) { this->bestfriend = bestfriend_; }

void Middle::set_record(int record_) { this->record = record_; }
void Middle::set_bestfriend(string bestfriend_) { this->bestfriend = bestfriend_; }

void High::set_record(int record_) { this->record = record_; }
void High::set_bestfriend(string bestfriend_) { this->bestfriend = bestfriend_; }


void Uni::set_record(int record_) { this->record = record_; }
void Uni::set_bestfriend(string bestfriend_) { this->bestfriend = bestfriend_; }
void Uni::set_id(int id_) { this->id = id_; }

// getter

int Person::get_ss_number() { return this->ss_number; }
int Person::get_age() { return this->age; }
string Person::get_local() { return this->local; }
string Person::get_name() { return this->name; }

int Elementary::get_record() { return this->record; }
string Elementary::get_bestfriend() { return this->bestfriend; }

int Middle::get_record() { return this->record; }
string Middle::get_bestfriend() { return this->bestfriend; }

int High::get_record() { return this->record; }
string High::get_bestfriend() { return this->bestfriend; }

int Uni::get_record() { return this->record; }
string Uni::get_bestfriend() { return this->bestfriend; }
int Uni::get_id() { return this->id; }

// general function

//Person
void Person::move() { cout << "사람 " << Person::get_name() << "이가 움직입니다." << endl; }
void Person::talk(string talk) { cout << "사람 " << Person::get_name() << "이가 " << talk << " 이라고 말합니다." << endl; }
void Person::transporation(string trans) { cout << "사람 " << Person::get_name() << "이는" << trans << "를 타고 다닙니다." << endl; }


// Elementary
void Elementary::move() { cout << "초등학생 " << Elementary::get_name() << "이가 움직입니다." << endl; }
void Elementary::talk(string talk) { cout << "초등학생" << Elementary::get_name() << "이가" << talk << " 이라고 말을 합니다." << endl; }
void Elementary::transporation(string trans) { cout << "초등학생" << Elementary::get_name() << "이는 " << trans << "을 타고 다닙니다." << endl; }
void Elementary::graduated(int yyyy, int mm, int nn) { cout << "초등학생" << Elementary::get_name() << "이는" << yyyy << "년/" << mm << "월/" << nn << "일에 졸업합니다."; }

// Middle
void Middle::move() { cout << "중학생 " << Middle::get_name() << "이가 움직입니다." << endl; }
void Middle::talk(string talk) { cout << "중학생" << Middle::get_name() << "이가" << talk << " 이라고 말을 합니다." << endl; }
void Middle::transporation(string trans) { cout << "중학생" << Middle::get_name() << "이는 " << trans << "을 타고 다닙니다." << endl; }
void Middle::graduated(int yyyy, int mm, int nn) { cout << "초등학생" << Middle::get_name() << "이는" << yyyy << "년/" << mm << "월/" << nn << "일에 졸업합니다."; }

// High
void High::move() { cout << "고등학생 " << High::get_name() << "이가 움직입니다." << endl; }
void High::talk(string talk) { cout << "고등학생" << High::get_name() << "이가" << talk << " 이라고 말을 합니다." << endl; }
void High::transporation(string trans) { cout << "고등학생" << High::get_name() << "이는 " << trans << "을 타고 다닙니다." << endl; }
void High::graduated(int yyyy, int mm, int nn) { cout << "고등학생" << High::get_name() << "이는" << yyyy << "년/" << mm << "월/" << nn << "일에 졸업합니다."; }
 
// Uni
void Uni::move() { cout << "대학생 " << Uni::get_name() << "이가 움직입니다." << endl; }
void Uni::talk(string talk) { cout << "대학생" << Uni::get_name() << "이가" << talk << " 이라고 말을 합니다." << endl; }
void Uni::transporation(string trans) { cout << "대학생" << Uni::get_name() << "이는 " << trans << "을 타고 다닙니다." << endl; }
void Uni::graduated(int yyyy, int mm, int nn) { cout << "대학생" << Uni::get_name() << "이는" << yyyy << "년/" << mm << "월/" << nn << "일에 졸업합니다."; }









