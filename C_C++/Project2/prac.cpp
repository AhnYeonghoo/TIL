#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <cstring>
#define ZERO 0 

int temp()
{
	/*
	using namespace std;
	
	string s1 = "penquin";
	string s2, s3;
	
	cout << "string ��ü�� string ��ü�� ������ �� �ִ�: s2 = s1\n";
	s2 = s1;
	cout << "s1: " << s1 << ", s2: " << s2 << endl;
	cout << "string ��ü�� c��Ÿ�� ���ڿ��� ������ �� �ִ�.\n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2 = " << s2 << endl;
	cout << "string ��ü���� ������ �� �ִ�. s3 = s1 + s2 \n";
	s3 = s1 + s2;
	cout << "s3: " << s3 << endl;
	cout << "string ��ü���� �߰��� �� �ִ�.\n";
	s1 += s2;
	cout << "s1 += s2 --> s1 = " << s1 << endl;
	s2 += " for a day";
	cout << "s2 += \" for a day\" --> s2 =  " << s2 << endl;
	
	char ch1[20];
	char ch2[20] = "jaguar";
	string st1;
	string st2 = "panther";
	st1 = st2;
	strcpy(ch1, ch2);
	st1 += " paste";
	strcat(ch1, " juice");
	
	int len1 = st1.size();
	int len2 = strlen(ch1);
	cout << st1 << " ���ڿ����� " << len1 << "���� ���ڰ� ����ִ�.\n";
	cout << ch1 << " ���ڿ�����" << len2 << "���� ���ڰ� ����ִ�.\n";
	
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";
	cout << "����̰��� ���� �� ���� �Է��Ͻÿ�: ";
	cin >> charr1;
	cout << "����̰��� �� �ٸ� �� ���� �Է��Ͻÿ�: ";
	cin >> str1;
	cout << "�Ʒ� �������� ��� ����̰��Դϴ�:\n";
	cout << charr1 << " " << charr2 << " "
		<< str1 << " " << str2 << endl;
	cout << charr2 << "���� �� ��° ����: "
		<< charr2[2] << endl;
	cout << str2 << "���� �� ��° ����: " << str2[2] << endl;
	

	int year;
	cout << "���� ��ô� ����Ʈ�� ��� �����ϼ̽��ϱ�?\n";
	(cin >> year).get();
	cout << "���� ��ô� ���ø� ������ �ֽðڽ��ϱ�?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "����Ʈ ���� ����: " << year << endl;
	cout << "����: " << address << endl;
	cout << "����� �Ϸ�Ǿ����ϴ�.\n";

	
	const int ARSIZE = 20;
	char name[ARSIZE];
	char dessert[ARSIZE];
	cout << "�̸��� �Է�: \n";
	cin.get(name, ARSIZE).get();
	cout << "�����ϴ� ����Ʈ: \n";
	cin.get(dessert, ARSIZE).get();
	cout << "���ִ� " << dessert;
	cout << " ����Ʈ�� �غ��ϰڽ��ϴ�. " << name << "�� \n";
	

	
	const int size = 15;
	char name1[size];
	char name2[size] = "C++owboy";
	cout << "�ȳ��ϼ���. ���� " << name2;
	cout << "�Դϴ�. �Ƿ����� ������?\n";
	cin >> name1;
	cout << "��, " << name1 << "��! ����� �̸��� ";
	cout << strlen(name1) << "�� �Դϴٸ�\n";
	cout << sizeof(name1) << "����Ʈ ũ���� �迭�� ����Ǿ����ϴ�.\n";
	cout << "�̸��� " << name1[0] << "�ڷ� �����ϴ±���.\n";
	name2[3] = '\0';
	cout << "�� �̸��� ó�� �� ���ڴ� ������ �����ϴ�: ";
	cout << name2 << endl;
	
	
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;
	
	cout << "int�� " << sizeof(int) << " ����Ʈ��." << endl;
	cout << "short�� " << sizeof n_short << " ����Ʈ��" << endl;
	cout << "long�� " << sizeof n_long << " ����Ʈ��" << endl;
	cout << "longlong�� " << sizeof n_llong << " ����Ʈ��" << endl;
	cout << endl;
	
	cout << "�ִ밪: " << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "long long: " << n_llong << endl;
	cout << "int�� �ּҰ�: " << INT_MIN << endl;
	cout << "char�� ��Ʈ ��= " << CHAR_BIT << endl;
	cout << endl;
	
	short dohee = SHRT_MAX;
	unsigned short insuk = dohee;

	cout << "������ ���˿��� " << dohee << "���� ����ְ�,";
	cout << " �μ����� ���¿��� " << insuk << "���� ����ִ�. " << endl;
	dohee += 1;
	insuk += 1;
	cout << "������ �ܰ�� " << dohee << "���� �Ǿ���, ";
	cout << "�μ����� �ܰ�� " << insuk << "���� �Ǿ���." << endl;
	dohee = ZERO;
	
	insuk = ZERO;
	cout << "������ ���¿��� " << dohee << "���� ����ְ�, ";
	cout << "�μ����� ���¿��� " << insuk << "���� ����ִ�. " << endl;
	cout << "�� ���� ���¿��� 1���� �����Ѵ�. " << endl << "���� ";
	dohee -= 1;
	insuk -= 1; 
	cout << "������ �ܰ�� "  << dohee << "���� �Ǿ���, ";
	cout << "�μ����� �ܰ�� " << insuk << "���� �Ǿ���. " << endl;
	
	cout << endl;
	
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << chest << endl;
	cout << waist << endl;
	cout << inseam << endl;
	cout << hex;
	cout << waist;
	cout << oct;
	cout << inseam;
	
	char ch;
	cout << "���ϴ� ���� �ϳ��� �Է��Ͻÿ�: " << endl;
	cin >> ch;
	cout << "�����մϴ�. ";
	cout << "����� �Է��Ͻ� ���ڴ� " << ch << "�Դϴ�. " << endl;
	
	

	char ch = 'M';
	int i = ch;
	cout << ch << "�� ASCII �ڵ�� " << i << "�Դϴ�." << endl;

	cout << "�� ���� �ڵ忡 1�� ���غ��ڽ��ϴ�." << endl;
	ch += 1;
	i = ch;
	cout << ch << "�� ASCII �ڵ�� " << i << "�Դϴ�. " << endl;
	cout << "cout.put(ch)�� ����Ͽ� char�� ���� ch�� ȭ�鿡 ���: ";
	cout.put(ch);
	
	cout.put('!');
	cout << endl << "����" << endl;
	

	cout << "\a��ȣ�� \"ȭ���� ����\" ������ ��� ���õǾ����ϴ�.\n";
	cout << "8�ڸ� ��й�ȣ�� �Է��Ͻÿ�:________ \b\b\b\b\b\b\b\b\b";
	long code;
	cin >> code; 
	cout << "\a�Է��Ͻ� ��й�ȣ�� " << code << "�Դϴ�. \n";
	cout << "\a��й�ȣ�� �½��ϴ�! z3 ��ȹ�� �����Ͻʽÿ�!\n";
	

	cout.setf(ios_base::fixed, ios_base::floatfield);
	
	float tub = 10.0 / 3.0;
	double mint = 10.0 / 3.0;
	const float million  = 1.0e6;
	
	cout << "tub= " << tub;
	cout << ", a million tubs = " << million * tub;
	cout << ", \n ten million tubs = ";
	cout << 10 * million * tub << endl;
	cout << "mint = " << mint << " and a million mints = ";
	cout << million * mint << endl;
	
	
	float a = 2.34E+22F;
	float b = a + 1.0f;
	cout << "a = " << a << endl;
	cout << "b - a = " << b - a << endl;
	
float hats, heads;
cout.setf(ios_base::fixed, ios_base::floatfield);
cout << "���� �ϳ� �Է��Ͻÿ�: ";
cin >> hats;
cout << "�ٸ� ���� �Է��Ͻÿ�: ";
cin >> heads;

cout << "hats = " << hats << "; heads = " << heads << endl;
cout << "hats + heads = " << hats + heads << endl;
cout << "hats - heads = " << hats - heads << endl;
cout << "hats * heads = " << hats * heads << endl;
cout << "hats / heads = " << hats / heads << endl;

	const int Lbs_per_stn = 14;
	int lbs;

	cout << "����� ü���� �Ŀ�� ������ �Է��Ͻʽÿ�: ";
	cin >> lbs;
	int stone = lbs / Lbs_per_stn;
	int pounds = lbs % Lbs_per_stn;
	cout << lbs << " �Ŀ��� " << stone
		<< " ����, " << pounds << " �Ŀ���Դϴ�.\n";
	
	
int auks, bats, coots;
auks = 19.99 + 11.99;

bats = (int)19.99 + (int)11.99;
coots = int(19.99) + int(11.99);
cout << "�ٴٿ��� = " << auks << ", ���� = " << bats;
cout << "�������� = " << coots << endl;


	
int yams[3];
yams[0] = 7;
yams[1] = 8;
yams[2] = 6;

int yamcosts[3] = { 200, 300, 50 };
cout << "���� �հ�= ";
cout << yams[0] + yams[1] + yams[2] << endl;
cout << yams[1] << "���� ����ִ� ������ ";
cout << "���� " << yamcosts[1] << "�� �� �Դϴ�.\n";
int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1]; 
total = total + yams[2] * yamcosts[2];
cout << "�� ������ �� ������ " << total << "�� �Դϴ�.\n";
cout << "\nyams �迭�� ũ��� " << sizeof yams;
cout << "����Ʈ�Դϴ�.\n";
cout << "���� �ϳ��� ũ��� " << sizeof yams[0];
cout << "����Ʈ�Դϴ�.\n";

	*/
	return 0;
}