#include "EvenRandom.h"

EvenRandom::EvenRandom()
{
	srand((unsigned)time(0));
}

int EvenRandom::ERandom()
{
	int rNum = rand();
	if (rNum % 2 == 0)
		return rNum;
	else
		return -1;
}

int EvenRandom::EvenInRange(int n1, int n2)
{
	int rNum = rand() % (n2 - n1 + 1) + n1;
	if (rNum % 2 == 0)
		return rNum;
	else
		return -1;
}
