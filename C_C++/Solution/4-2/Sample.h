#ifndef SAMPLE_H
#define SAMPLE_H
#define MAX(x,y) ((x) > (y) ? (x) : (y))

#include <iostream>
using namespace std;

class Sample
{
	int *p;
	int size;
public:
	Sample(int n)
	{
		size = n;
		p = new int[n];
	}
	void read();
	void write();
	int big();
	~Sample();
};

#endif