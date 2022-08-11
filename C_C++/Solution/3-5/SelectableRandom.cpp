#include "SelectableRandom.h"

SelectableRandom::SelectableRandom()
{
	srand((unsigned)time(0));
}

int SelectableRandom::EvenRandom()
{
	int rNum = rand();
	if (rNum % 2 == 0)
		return rNum;
	else
		return -1;
}

int SelectableRandom::EvenInRange(int n1, int n2)
{
	int rNum = rand() % (n2 - n1 + 1) + n1;
	if (rNum % 2 == 0)
		return rNum;
	else
		return -1;
}

int SelectableRandom::OddRandom()
{
	int rNum = rand();
	if (rNum % 2 == 1)
		return rNum;
	else
		return -1;
}

int SelectableRandom::OddInRange(int n1, int n2)
{
	int rNum = rand() % (n2 - n1 + 1) + n1;
	if (rNum % 2 == 1)
		return rNum;
	else
		return -1;
}