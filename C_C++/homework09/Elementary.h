#pragma once

#include "Person.h"
#include <string>

using namespace std;

class Elementary : public Person
{
private:
	float m_record;
	string m_best_friend;
	string m_department;

public:
	Elementary(const string& name, int age, const string& local, float record, const string& department);
	~Elementary();
};