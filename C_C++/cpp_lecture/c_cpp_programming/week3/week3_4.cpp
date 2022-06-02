#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::ifstream ifs;
    std::string s;
    std::string full_s = "";

    ifs.open("input.txt");
    
    if (ifs.is_open()) {
        while(!ifs.eof()) {
            getline(ifs, s);
            std::cout << "File read: " << s << std::endl;
            full_s += s;
        }
    }

    ifs.close();

    std::cout << "Full text " << std::endl;
    std::cout << full_s << std::endl;
}