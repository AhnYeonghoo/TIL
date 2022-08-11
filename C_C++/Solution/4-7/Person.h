#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person
{
	string name;
	string tel;
public:
	Person() {}
	string getName();
	string getTel();
	void set(string name, string tel);
};
#endif