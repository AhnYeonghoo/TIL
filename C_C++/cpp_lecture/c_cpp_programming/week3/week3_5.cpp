#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::ofstream ofs;

    ofs.open("output.txt");
    
    if (ofs.is_open()) {
        for (int i = 0; i < 10; i++) {
            ofs << i << " ";
        }
        ofs << '\n';

        std::string s;
        std::cout << "text input: ";
        getline(std::cin, s);
        ofs << s;

        std::string S = "Hello CPP";
        ofs << S;
    }
    ofs.close();
    std::cout << "File output";
}