#ifndef SELECTABLERANDOM_H
#define SELECTABLERANDOM_H
#include <iostream>
#include <cstdlib>
#include <ctime>
class SelectableRandom
{
public:
	SelectableRandom();
	int EvenRandom();
	int EvenInRange(int n1, int n2);
	int OddRandom();
	int OddInRange(int n1, int n2);
};

#endif