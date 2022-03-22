#include <iostream>
#include <string>
#include <typeinfo>
#include <fstream>
using namespace std;

int temmpmain()
{
	/*
	// ascii¿¡¼­ 97Àº 'a'
	char i = 97;
	char j = 'a';
	
	// print char values
	cout << "char values" << endl;
	cout << "i: " << i << endl;
	cout << "j: " << j << endl;
	 
	// print integer values
	cout << "integer values " << endl;
	cout << "i: " << static_cast<int>(i) << endl;
	cout << "j: " << static_cast<int>(j) << endl;

	return 0;
	
	// C style string case
	char c_string_1[] = "Hello CBNU 1";
	char c_string_2[20] = "Hello CBNU 2";
	const char *c_string_3 = "Hello CBNU 3";
	//print C style
	cout << "C style" << endl;
	cout << "type 1: " << c_string_1 << endl;
	cout << "type 2: " << c_string_2 << endl;
	cout << "type 3: " << c_string_3 << endl;
	
	// CPP style string case
	string s = "Hello CBNU string type";
	// print string values
	cout << "integer values" << endl;
	cout << "s: " << s << endl;
	return 0;
	
	
	// C style String input/output
	char c_string[] = "Hello CNUB C Style";
	cout << "text: " << c_string << endl;
	cout << "type: " << typeid(c_string).name() << endl;
	cout << "long: " << sizeof(c_string) << endl;
	
	for (int i = 0; i < sizeof(c_string); i++) {
		if (c_string[i] == '\0') {
			cout << "Have NULL" << endl;
			break;
		}
		else if (i == sizeof(c_string) - 1) {
			cout << "Not have NULL" << endl;
		}
	}
	
	// CPP Style String input/output
	string s_string = "Hello CNUB CPP Style";
	cout << "text: " << s_string << endl;
	cout << "type: " << typeid(s_string).name() << endl;
	cout << "long: " << s_string.size() << endl;
	
	for (int i = 0; i < s_string.size(); i++) {
		if (s_string[i] == '\0') {
			cout << "have NULL" << endl;
			break;
		}
		else if (i == s_string.size() - 1) {
			cout << "Not have NULL" << endl;
		}
	}
	

	// C style String input/output
	char c_string[20];
	cout << "C style String input : ";
	cin.getline(c_string, 20);
	cout << "C style String output: " << c_string << endl;

	// CPP style String input/output
	string s_string;
	cout << "CPP style String input: ";
	getline(cin, s_string);
	cout << "CPP style String output: " << s_string << endl;
	

	string s = "1";
	string s1 = "Hello ";
	string s2 = "CBNU ";
	string s3 = "CPP ";
	string s4 = "Style";
	
	// string add & change
	s = s1 + s2;
	cout << "string add & change: " << s << endl;
	
	// string insert
	s.insert(2, s3);
	cout << "string insert : " << s << endl;

	// string erase
	s.erase(2, 4);
	cout << "string erase: " << s << endl;
	
	// string substr
	cout << "string substr: " << s.substr(1, 5) << endl;
	return 0;
	

	string word1 = "I like C++ and i love C++ word!";
	string word2 = "C++";
	
	cout << "length: " << word1.length() << " / size: " << word1.size() << endl;
	cout << "Find 'i' : " << word1.find('i') << endl;
	cout << "Find word2 string: " << word1.find(word2, 3) << endl;
	cout << "Find 'li': " << word1.find("li", 7) << endl;
	
	string word3 = "CPP";
	string word4 = "JAVA";
	
	cout << "String Compare: " << word3.compare(word4) << endl;
	
	int index = word1.find(word2);
	if (index != string::npos) {
		word1.replace(index, word2.length(), word4);
	}
	cout << "string Replace: " << word1 << endl;
	return 0;
	
	

	ifstream ifs;
	string s;	
	string full_s = "";

	ifs.open("input.txt");

	if (ifs.is_open()) {
		while (!ifs.eof()) {
			getline(ifs, s);
				cout << "File read : " << s << endl;
				full_s = full_s + s;
		}
	}

	ifs.close();
	
	cout << "Full text" << endl;
	cout << full_s;
	return 0;


 	*/
	
	ofstream ofs;
	
	ofs.open("output.txt");
	
	if (ofs.is_open()) {
		for (int i = 0; i < 10; i++) {
			ofs << i << " ";
		}
		ofs << '\n';

		string s;
		cout << "text input : ";
		getline(cin, s);
		ofs << s;
		
		string S = "Hello CPP";
		ofs << S;
	}
	
	ofs.close();
	cout << "file output";
	return 0;

}