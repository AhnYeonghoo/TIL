#include <iostream> // �⺻ ������� ���� import
#include <fstream> // ���� ������� ���� import
#include <string> // string Ŭ���� ����� ���� import 
#include <cctype> // ��ҹ��� �Ǻ��� ���� ��� import

using namespace std; // ������� ������ ���Ǹ� ���� �̸����� ����

 // Ư������ ���ſ� �빮�ڸ� �ҹ��ڷ� ��ü�ϴ� �Լ�

// 1. ������ �о���δ�.
// 2. ������ ������ string ������ �� �پ� �д´�.
// 3. ���� ���ڿ��� Ư�����ڰ� �ִ����� Ư�����ڰ� �ƴϸ� ��������
// Ȯ���ϰ� ����� �빮������ Ȯ���Ѵ�. 
// 4. Ư�����ڸ� ����� �ٲ۴�. �빮�ڸ� �ҹ��ڷ� �ٲ۴�
// 5. �ش� ������ ���İ��� �ش� ������ ���ο� ���ڿ��� �����Ѵ�.
// 6. ���ڿ� ������ 2�� �ʿ�.


int main() 
{
	string file_input; // ���Ͽ��� ���� ������ �����ϱ� ���� ����
	
	ifstream file; // ���� �б� ���� ��ü ����
	ofstream result; // output.txt ���� ������ ���� ��ü ����
	
	file.open("test.txt");

	// input.txt ���� ���� ��� ����� ����ó��
	//if (file.fail())
	//{
	//	cerr << "Not found file" << endl;
	//	exit(100);
	//}

	// ofstream�� ������ ������ �����ϱ� ���� ����ó�� ���ʿ�
	result.open("output.txt");
	
	
	if (file.is_open()) // ���� �����ִٸ�
	{
		while (!(file.eof())) // ������ ������
		{
			getline(file, file_input); // ������ ���� ���� �� string ������ ����
			for (int i = 0; i < file_input.size(); i++)
			{
				if ((0x21 <= file_input[i] && 0x2F >= file_input[i]) || (0x3A <= file_input[i] && 0x40 >= file_input[i]) || (0x5B <= file_input[i] && 0x60 >= file_input[i]) || (0x7B <= file_input[i] && 0x7E >= file_input[i]))
				{
					result << file_input.replace(i, i, " ");

				}
				else if ((0x41 <= file_input[i] && file_input[i] <= 0x5A) || (0x61 <= file_input[i] && file_input[i] <= 0x7A))
				{
					if (isupper(file_input[i]) != 0)
					{
						file_input[i] = tolower(file_input[i]);
						result << file_input[i];
					
					}
					else
					{
						result << file_input[i];
						
					}
				}
				else
				{
					result << file_input[i];

				}
			}
		}
	}
	
	ifstream result_output;
	result.open("output.txt");
	string find, temp;
	short select;
	cout << "selection sort(1. up / 2. down): ";
	cin >> select;
	cout << endl;
	cout << "find: ";
	cin >> find;
	result_output >> temp;
	cout << "result: ";
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp.find(find[i]);
		cout << endl;
	}

	file.close();
	result.close();
	return 1;
	
	
	
	
	
}



