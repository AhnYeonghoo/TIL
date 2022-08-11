#include "Sample.h"

void Sample::read()
{
	for (int i = 0; i < size; i++)
	{
		cin >> p[i];
	}
}

void Sample::write()
{
	for (int i = 0; i < size; i++)
	{
		cout << p[i] << ' ';
	}
	cout << endl;
}

int Sample::big()
{
	int nMax = p[0];
	for (int i = 1; i < size; i++)
	{
		nMax = MAX(nMax, p[i]);
	}
	return nMax;
}

Sample::~Sample()
{
	delete[] p;
}