#include <iostream> // 기본 입출력을 위한 import
#include <fstream> // 파일 입출력을 위한 import
#include <string> // string 클래스 사용을 위한 import 
#include <cctype> // 대소문자 판별을 위한 모듈 import

using namespace std; // 권장되진 않지만 편의를 위해 이름공간 선언

string remove_special_character(string s); // 특수문자 제거와 대문자를 소문자로 교체하는 함수

// 1. 파일을 읽어들인다.
// 2. 파일의 내용을 string 형으로 한 줄씩 읽는다.
// 3. 읽은 문자열에 특수문자가 있는지와 특수문자가 아니면 영어인지
// 확인하고 영어면 대문자인지 확인한다. 
// 4. 특수문자면 띄어쓰기로 바꾼다. 대문자면 소문자로 바꾼다
// 5. 해당 과정을 거쳐가며 해당 내용을 새로운 문자열에 저장한다.
// 6. 문자열 변수는 2개 필요.


int main() 
{
	string file_input; // 파일에서 읽은 내용을 저장하기 위한 변수
	string change_string = ""; // 바뀐 문자열을 저장하기 위한 변수
	
	ifstream file; // 파일 읽기 위한 객체 생성
	ofstream result; // output.txt 파일 생성을 위한 객체 생성
	
	file.open("input.txt");

	// input.txt 파일 없을 경우 대비한 예외처리
	if (file.fail())
	{
		cerr << "Not found file" << endl;
		exit(100);
	}

	// ofstream은 파일이 없으면 생성하기 때매 예외처리 불필요
	result.open("output.txt");
	
	if (file.is_open()) // 파일 열려있다면
	{
		while (!(file.eof())) // 파일의 끝까지
		{
			getline(file, file_input); // 파일의 내용 읽은 후 string 변수에 저장
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

// 현재 대소문자 치환 해결 중..