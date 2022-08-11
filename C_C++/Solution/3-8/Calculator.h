#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
using namespace std;

class Add
{
private:
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};

class Sub
{
private:
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};

class Mul
{
private:
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};

class Div
{
private:
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};

#endif