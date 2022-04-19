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
	
	cout << "string 객체를 string 객체에 대입할 수 있다: s2 = s1\n";
	s2 = s1;
	cout << "s1: " << s1 << ", s2: " << s2 << endl;
	cout << "string 객체에 c스타일 문자열을 대입할 수 있다.\n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2 = " << s2 << endl;
	cout << "string 객체들을 결합할 수 있다. s3 = s1 + s2 \n";
	s3 = s1 + s2;
	cout << "s3: " << s3 << endl;
	cout << "string 객체들을 추가할 수 있다.\n";
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
	cout << st1 << " 문자열에는 " << len1 << "개의 문자가 들어있다.\n";
	cout << ch1 << " 문자열에는" << len2 << "개의 문자가 들어있다.\n";
	
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";
	cout << "고양이과의 동물 한 종을 입력하시오: ";
	cin >> charr1;
	cout << "고양이과의 또 다른 한 종을 입력하시오: ";
	cin >> str1;
	cout << "아래 동물들은 모두 고양이과입니다:\n";
	cout << charr1 << " " << charr2 << " "
		<< str1 << " " << str2 << endl;
	cout << charr2 << "에서 세 번째 글자: "
		<< charr2[2] << endl;
	cout << str2 << "에서 세 번째 글자: " << str2[2] << endl;
	

	int year;
	cout << "지금 사시는 아파트에 언네 입주하셨습니까?\n";
	(cin >> year).get();
	cout << "지금 사시는 도시를 말씀해 주시겠습니까?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "아파트 입주 연도: " << year << endl;
	cout << "도시: " << address << endl;
	cout << "등록이 완료되었습니다.\n";

	
	const int ARSIZE = 20;
	char name[ARSIZE];
	char dessert[ARSIZE];
	cout << "이름을 입력: \n";
	cin.get(name, ARSIZE).get();
	cout << "좋아하느 디저트: \n";
	cin.get(dessert, ARSIZE).get();
	cout << "맛있는 " << dessert;
	cout << " 디저트를 준비하겠습니다. " << name << "님 \n";
	

	
	const int size = 15;
	char name1[size];
	char name2[size] = "C++owboy";
	cout << "안녕하세요. 저는 " << name2;
	cout << "입니다. 실례지만 성함이?\n";
	cin >> name1;
	cout << "아, " << name1 << "씨! 당신의 이름은 ";
	cout << strlen(name1) << "자 입니다만\n";
	cout << sizeof(name1) << "바이트 크기의 배열로 저장되었습니다.\n";
	cout << "이름이 " << name1[0] << "자로 시작하는군요.\n";
	name2[3] = '\0';
	cout << "제 이름의 처음 세 문자는 다음과 같습니다: ";
	cout << name2 << endl;
	
	
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;
	
	cout << "int는 " << sizeof(int) << " 바이트다." << endl;
	cout << "short는 " << sizeof n_short << " 바이트다" << endl;
	cout << "long은 " << sizeof n_long << " 바이트다" << endl;
	cout << "longlong은 " << sizeof n_llong << " 바이트다" << endl;
	cout << endl;
	
	cout << "최대값: " << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "long long: " << n_llong << endl;
	cout << "int의 최소값: " << INT_MIN << endl;
	cout << "char의 비트 수= " << CHAR_BIT << endl;
	cout << endl;
	
	short dohee = SHRT_MAX;
	unsigned short insuk = dohee;

	cout << "도희의 계죄에는 " << dohee << "원이 들어있고,";
	cout << " 인숙이의 계좌에도 " << insuk << "원이 들어있다. " << endl;
	dohee += 1;
	insuk += 1;
	cout << "도희의 잔고는 " << dohee << "원이 되었고, ";
	cout << "인숙이의 잔고는 " << insuk << "원이 되었다." << endl;
	dohee = ZERO;
	
	insuk = ZERO;
	cout << "도희의 계좌에는 " << dohee << "원이 들어있고, ";
	cout << "인숙이의 계좌에도 " << insuk << "원이 들어있다. " << endl;
	cout << "각 각의 계좌에서 1원씩 인출한다. " << endl << "이제 ";
	dohee -= 1;
	insuk -= 1; 
	cout << "도희의 잔고는 "  << dohee << "원이 되었고, ";
	cout << "인숙이의 잔고는 " << insuk << "원이 되었다. " << endl;
	
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
	cout << "원하는 문자 하나를 입력하시오: " << endl;
	cin >> ch;
	cout << "감사합니다. ";
	cout << "당신이 입력하신 문자는 " << ch << "입니다. " << endl;
	
	

	char ch = 'M';
	int i = ch;
	cout << ch << "의 ASCII 코드는 " << i << "입니다." << endl;

	cout << "이 문자 코드에 1을 더해보겠습니다." << endl;
	ch += 1;
	i = ch;
	cout << ch << "의 ASCII 코드는 " << i << "입니다. " << endl;
	cout << "cout.put(ch)를 사용하여 char형 변수 ch를 화면에 출력: ";
	cout.put(ch);
	
	cout.put('!');
	cout << endl << "종료" << endl;
	

	cout << "\a암호명 \"화려한 외출\" 작전이 방금 개시되었습니다.\n";
	cout << "8자리 비밀번호를 입력하시오:________ \b\b\b\b\b\b\b\b\b";
	long code;
	cin >> code; 
	cout << "\a입력하신 비밀번호는 " << code << "입니다. \n";
	cout << "\a비밀번호가 맞습니다! z3 계획을 진행하십시오!\n";
	

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
cout << "수를 하나 입력하시오: ";
cin >> hats;
cout << "다른 수를 입력하시외: ";
cin >> heads;

cout << "hats = " << hats << "; heads = " << heads << endl;
cout << "hats + heads = " << hats + heads << endl;
cout << "hats - heads = " << hats - heads << endl;
cout << "hats * heads = " << hats * heads << endl;
cout << "hats / heads = " << hats / heads << endl;

	const int Lbs_per_stn = 14;
	int lbs;

	cout << "당신의 체중을 파운드 단위로 입력하십시오: ";
	cin >> lbs;
	int stone = lbs / Lbs_per_stn;
	int pounds = lbs % Lbs_per_stn;
	cout << lbs << " 파운드는 " << stone
		<< " 스톤, " << pounds << " 파운드입니다.\n";
	
	
int auks, bats, coots;
auks = 19.99 + 11.99;

bats = (int)19.99 + (int)11.99;
coots = int(19.99) + int(11.99);
cout << "바다오리 = " << auks << ", 박쥐 = " << bats;
cout << "감동오리 = " << coots << endl;


	
int yams[3];
yams[0] = 7;
yams[1] = 8;
yams[2] = 6;

int yamcosts[3] = { 200, 300, 50 };
cout << "고구마 합계= ";
cout << yams[0] + yams[1] + yams[2] << endl;
cout << yams[1] << "개가 들어있는 포장은 ";
cout << "개당 " << yamcosts[1] << "원 씩 입니다.\n";
int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1]; 
total = total + yams[2] * yamcosts[2];
cout << "세 포장의 총 가격은 " << total << "원 입니다.\n";
cout << "\nyams 배열의 크긴느 " << sizeof yams;
cout << "바이트입니다.\n";
cout << "원소 하나의 크기는 " << sizeof yams[0];
cout << "바이트입니다.\n";

	*/
	return 0;
}