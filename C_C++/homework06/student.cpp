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
void Person::move() { cout << "��� " << Person::get_name() << "�̰� �����Դϴ�." << endl; }
void Person::talk(string talk) { cout << "��� " << Person::get_name() << "�̰� " << talk << " �̶�� ���մϴ�." << endl; }
void Person::transporation(string trans) { cout << "��� " << Person::get_name() << "�̴�" << trans << "�� Ÿ�� �ٴմϴ�." << endl; }


// Elementary
void Elementary::move() { cout << "�ʵ��л� " << Elementary::get_name() << "�̰� �����Դϴ�." << endl; }
void Elementary::talk(string talk) { cout << "�ʵ��л�" << Elementary::get_name() << "�̰�" << talk << " �̶�� ���� �մϴ�." << endl; }
void Elementary::transporation(string trans) { cout << "�ʵ��л�" << Elementary::get_name() << "�̴� " << trans << "�� Ÿ�� �ٴմϴ�." << endl; }
void Elementary::graduated(int yyyy, int mm, int nn) { cout << "�ʵ��л�" << Elementary::get_name() << "�̴�" << yyyy << "��/" << mm << "��/" << nn << "�Ͽ� �����մϴ�."; }

// Middle
void Middle::move() { cout << "���л� " << Middle::get_name() << "�̰� �����Դϴ�." << endl; }
void Middle::talk(string talk) { cout << "���л�" << Middle::get_name() << "�̰�" << talk << " �̶�� ���� �մϴ�." << endl; }
void Middle::transporation(string trans) { cout << "���л�" << Middle::get_name() << "�̴� " << trans << "�� Ÿ�� �ٴմϴ�." << endl; }
void Middle::graduated(int yyyy, int mm, int nn) { cout << "�ʵ��л�" << Middle::get_name() << "�̴�" << yyyy << "��/" << mm << "��/" << nn << "�Ͽ� �����մϴ�."; }

// High
void High::move() { cout << "����л� " << High::get_name() << "�̰� �����Դϴ�." << endl; }
void High::talk(string talk) { cout << "����л�" << High::get_name() << "�̰�" << talk << " �̶�� ���� �մϴ�." << endl; }
void High::transporation(string trans) { cout << "����л�" << High::get_name() << "�̴� " << trans << "�� Ÿ�� �ٴմϴ�." << endl; }
void High::graduated(int yyyy, int mm, int nn) { cout << "����л�" << High::get_name() << "�̴�" << yyyy << "��/" << mm << "��/" << nn << "�Ͽ� �����մϴ�."; }
 
// Uni
void Uni::move() { cout << "���л� " << Uni::get_name() << "�̰� �����Դϴ�." << endl; }
void Uni::talk(string talk) { cout << "���л�" << Uni::get_name() << "�̰�" << talk << " �̶�� ���� �մϴ�." << endl; }
void Uni::transporation(string trans) { cout << "���л�" << Uni::get_name() << "�̴� " << trans << "�� Ÿ�� �ٴմϴ�." << endl; }
void Uni::graduated(int yyyy, int mm, int nn) { cout << "���л�" << Uni::get_name() << "�̴�" << yyyy << "��/" << mm << "��/" << nn << "�Ͽ� �����մϴ�."; }









