#include "Elementary.h"
#include <iostream>

using namespace std;

Elementary::Elementary(const string& name, int age, const string& local, float record, const string& department)
	:
	m_record{ record },
m_department{ department }
{
	m_name = name;
	m_age = age;
	m_local = local;
	createSsNumber();
	std::cout << "Hello Elementary " << std::endl;

}

Elementary::~Elementary()
{
	std::cout << "Bye Elementary" << std::endl;
}