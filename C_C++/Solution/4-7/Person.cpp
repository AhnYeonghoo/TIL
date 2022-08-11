#include "Person.h"
#include <string>
using namespace std;

string Person::getName() { 
	return name; 
}

string Person::getTel() { 
	return tel; 
}

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}