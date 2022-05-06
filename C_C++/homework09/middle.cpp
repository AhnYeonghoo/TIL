#include "middle.h"
#include <iostream>

using namespace std;

Middle::Middle(const string& name, int age, const string& local, float record, const string& department)
	:
	m_record{ record },
	m_department{ department }
{
	m_name = name;
	m_age = age;
	m_local = local;
	createSsNumber();
	cout << "Hello Middle" << endl;
}

Middle::~Middle()
{
	cout << "Bye Middle" << endl;
}