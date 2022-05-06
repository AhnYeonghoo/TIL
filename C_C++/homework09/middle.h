#pragma once
#include "person.h"
#include <string>

using namespace std;

class Middle : public Person
{
private:
	float m_record;
	string m_best_friend;
	string m_department;
	
public:
	Middle(const string& name, int age, const string& local, float record, const string& department);
	~Middle();
};
