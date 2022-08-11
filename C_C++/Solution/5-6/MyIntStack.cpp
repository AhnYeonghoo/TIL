#include "MyIntStack.h"

MyIntStack::MyIntStack(int size)
{
	this->size = size;
	p = new int[size];
	tos = 0;
}

MyIntStack::MyIntStack(MyIntStack& s)
{
	this->size = s.size;
	this->p = new int[size];
	this->tos = 0;
}

bool MyIntStack::push(int n)
{
	if (tos < size)
	{
		p[tos++] = n;
		return true;
	}
	else
		return false;
}

bool MyIntStack::pop(int &n)
{
	if (--tos > 0)
	{
		n = p[tos];
		return true;
	}
	else if (tos == 0)
	{
		n = p[tos];
		return true;
	}
	return false;
}

MyIntStack::~MyIntStack()
{
	delete[] p;
}
