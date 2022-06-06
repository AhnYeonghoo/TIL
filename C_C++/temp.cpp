#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int K = NULL;
	//max K is 123456
	int amd[246913] = { 0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0, }; // is 0,1,2,...36 prime?

	for (int i = 26; i < 246913; i++)
	{
		bool zed{ true };

		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				zed = false;
				break;
			}
		}
		if (zed) amd[i] = 1;
	}

	while (true)
	{
		cin >> K;
		if (K == 0) break;
		int count = 0;

		for (int check = K + 1; check <= 2 * K; check++)
		{
			count += amd[check];
		}
		cout << count << endl;
	}
}
