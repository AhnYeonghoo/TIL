#include "Histogram.h"
Histogram::Histogram(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}
	testText = input;
	cout << testText << endl;
}
void Histogram::put(string input)
{
	testText.append(input);
	cout << input;
}
void Histogram::putc(char input)
{
	testText += input;
	cout << input;
}

void Histogram::print()
{
	int alNum = testText.length();
	for (int i = 0; i < testText.length(); i++)
	{
		if (isalpha(testText[i]) == 0)
			alNum--;
	}
	cout << endl << endl;
	cout << "ÃÑ ¾ËÆÄºª ¼ö " << alNum << endl << endl;

	alNum = 0;
	for (int i = 0; i < 26; i++)
	{
		char cFind = 'a' + i;
		for (int j = 0; j < testText.length(); j++)
		{
			if (testText[j] == cFind)
				alNum++;
		}
		cout << cFind << " (" << alNum << ")	: ";
		for (int i = 0; i < alNum; i++)
			cout << '*';
		cout << endl;
		alNum = 0;
	}
}
