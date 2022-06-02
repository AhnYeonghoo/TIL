#include <iostream>
#include <string>

int main() {

    char i = 97;
    char j = 'a';
    
    // print char values
    std::cout << "char values " << std::endl;
    std::cout << "i: " << i << std::endl;
    std::cout << "j: " << j << std::endl;
    
    // print Integer values
    std::cout << "Integer values" << std::endl;
    std::cout << "i: " << static_cast<int>(i) << std::endl;
    std::cout << "j: " << static_cast<int>(j) << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    
    // C style string case
    char c_string_1[] = "Hello CBNU 1";
    char c_string_2[20] = "Hello CBNU 2";
    char *c_string_3 = "Hello CBNU 3";
    // print C style
    std::cout << "C style" << std::endl;
    std::cout << "Type1 : " << c_string_1 << std::endl;
    std::cout << "Type2 : " << c_string_2 << std::endl;
    std::cout << "Type3 : " << c_string_3 << std::endl;

    //CPP style string case

    string s = "Hello World";

    std::cout << s << std::endl;

    return 0;
}