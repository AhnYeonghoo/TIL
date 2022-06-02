#include <iostream>
#include <string>

int main() {

    std::string s = "1";
    std::string s1 = "Hello ";
    std::string s2 = "CBNU ";
    std::string s3 = "CPP ";
    std::string s4 = "Style";
    
    // string add & change
    s = s1 + s2;
    std::cout << s << std::endl;

    // string insert
    s.insert(2, s3);
    std::cout << s << std::endl;

    // string erase
    s.erase(2, 4);
    
    // string substr
    std::cout << "string substr: " << s.substr(1, 5) << std::endl;

    std::string word1 = "I like C++ and i love C++ word!";
    std::string word2 = "C++";
    
    std::cout << "Length: " << word1.length() << " / size: " << word1.size() << std::endl;
    std::cout << "Find i : " << word1.find("i") << std::endl;
    std::cout << "Find word2 string : " << word1.find(word2, 3) << std::endl;
    std::cout << "Find li : " << word1.find("li", 5) << std::endl;

    std::string word3 = "CPP";
    std::string word4 = "JAVA";
    std::cout << "String Compare : " << word3.compare(word4) << std::endl;

    int index = word1.find(word2);
    if (index != std::string::npos) {
        word1.replace(index, word2.length(), word4);
    }
    std::cout << "String Replace: " << word1 << std::endl;
}