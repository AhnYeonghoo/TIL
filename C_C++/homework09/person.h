#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	int m_ssNumber;
	
protected:
	string m_name;
	int m_age;
	string m_local;
	
public:
	Person();
	virtual ~Person(); // 소멸자 가상함수화

	void createSsNumber();
	int get_ss_number() const { return m_ssNumber;  }
};