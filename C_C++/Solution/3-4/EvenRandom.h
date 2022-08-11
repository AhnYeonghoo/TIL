#ifndef EVENRANDOM_H
#define EVENRANDOM_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class EvenRandom
{
public:
	EvenRandom();
	int ERandom();
	int EvenInRange(int n1, int n2);
};
#endif
