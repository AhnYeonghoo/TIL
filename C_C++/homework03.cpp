#include <iostream> // �⺻ ������� ���� import
#include <fstream> // ���� ������� ���� import
#include <string> // string Ŭ���� ����� ���� import 
#include <cctype> // ��ҹ��� �Ǻ��� ���� ��� import

using namespace std; // ������� ������ ���Ǹ� ���� �̸����� ����

string remove_special_character(string s); // Ư������ ���ſ� �빮�ڸ� �ҹ��ڷ� ��ü�ϴ� �Լ�

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
	string change_string = ""; // �ٲ� ���ڿ��� �����ϱ� ���� ����
	
	ifstream file; // ���� �б� ���� ��ü ����
	ofstream result; // output.txt ���� ������ ���� ��ü ����
	
	file.open("input.txt");

	// input.txt ���� ���� ��� ����� ����ó��
	if (file.fail())
	{
		cerr << "Not found file" << endl;
		exit(100);
	}

	// ofstream�� ������ ������ �����ϱ� ���� ����ó�� ���ʿ�
	result.open("output.txt");
	
	if (file.is_open()) // ���� �����ִٸ�
	{
		while (!(file.eof())) // ������ ������
		{
			getline(file, file_input); // ������ ���� ���� �� string ������ ����
			change_string += remove_special_character(file_input);
			change_string += "\n";
		}
	}
	result << change_string;

	file.close();
	result.close();
	return 1;
	
	
	
	
	
}

string remove_special_character(string s)
{
	string result = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']' || s[i] == '}' || s[i] == '{' || s[i] == '|' || s[i] == '\'' || s[i] == '"')
		{
			s.replace(i, s[i], ",");
			result.append(s);
		}
		else if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z'))
		{
			if (isupper(s[i]) == 0)
			{
				string temp;
				s[i] = tolower(s[i]);
				temp = s[i];
				s.replace(i, s[i], temp);
				cout << "dd";
			} 
			else
			{
				result += s[i];
			}
		} 
		else
		{
			result += s[i];
		}
	}
	return result;
}

// ���� ��ҹ��� ġȯ �ذ� ��..