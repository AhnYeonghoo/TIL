#include <iostream>
#include <cmath>

int stonetolb(int);
int main()
{
	using namespace std;
	int stone;
	cout << "ü���� ���� ������ �Է��Ͻÿ�: ";
	cin >> stone;
	int pounds = stonetolb(stone);
	cout << stone << "������ ";
	cout << pounds << " �Ŀ���Դϴ�." << endl;
	
	return 0;

}


int stonetolb(int sts)
{
	return 14 * sts;

}

