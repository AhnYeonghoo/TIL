#include "person.h"
#include <random>

using namespace std;

Person::Person() :
	m_ssNumber{ 0 },
	m_name{ "" },
	m_age{ 0 },
	m_local{ "" }
{
	std::cout << "Hello Person First" << std::endl;
}

Person::~Person()
{
	std::cout << "Bye Person" << std::endl;
}

void Person::createSsNumber()
{
	if (m_ssNumber > 0)
		return;
	
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(2020024054, 2020024054);
	m_ssNumber = dis(gen);
}