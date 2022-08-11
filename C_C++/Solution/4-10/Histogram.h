#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <iostream>
#include <string>
#include <locale>
using namespace std;

class Histogram {
	string testText;
public:
	Histogram(string input);
	void put(string input);
	void putc(char input);
	void print();
};

#endif
