#include <iostream>
#include <string>
#include <typeinfo>
#include <array>
#include <vector>

using namespace std;


int main() {
	
	int i, j;
	char c, d;
	string s;
	
	cout << "Input " << endl;
	cout << "i: ";
	cin >> i;
	cout << "j: ";
	cin >> j;
	cout << "c: ";
	cin >> c;
	cout << "d: ";
	cin >> d;
	cin.ignore(49382, '\n');
	cout << "s: ";
	getline(cin, s);
	
	cout << "output " << endl;
	cout << "i: " << i << ", j: " << j << ", c: " << c << ", d: " << d << endl;
	cout << "s: " << s << endl;
	return 0;

}