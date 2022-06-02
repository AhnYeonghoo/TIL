#include <iostream>
#include <string>

int main() {

    char c_string[20];
    std::cout << "C style Stromg input: ";
    std::cin.getline(c_string, 20);
    std::cout << "C style String output: " << c_string << std::endl;
    
    // CPP style string in/out
    std::string s_string;
    std::cout << "CPP style String input: ";
    getline(std::cin, s_string);
    std::cout << "CPP style String output: " << s_string << std::endl;
}