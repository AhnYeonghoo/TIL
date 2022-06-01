#include <iostream>
#include <string>
#include "foo.h"
#include "goo.h"


namespace Hoo {

    const char h = 'a';

    namespace Koo {
        const int h_k = 5;
    }
}

namespace Yoo::Roo {

    const float y_r = 1.22;
}

namespace Doo = Hoo::Koo;
int main() {

    std::cout <<"Foo : " <<Foo::doSomething(1, 5) << std::endl;
    std::cout << "Goo: " << Goo::doSomething(1, 5) << std::endl;
    std::cout << "Hoo::h: " << Hoo::h << std::endl;
    std::cout << "Hoo::Koo::h_r: " << Hoo::Koo::h_k << std::endl;
    std::cout << "Yoo::Roo::y_r: " << Yoo::Roo::y_r << std::endl;
    std::cout << "Doo::h_k: " << Doo::h_k << std::endl;

    char name[20];
    std::cout << "Name: ";
    name[0] = 'a';
    std::cout << "Hello " << name << "!! " << std::endl;

    using namespace std;

    // name[1] = "d";
    // cout << "Name: ";
    // cout << "Hello" << name << "!!" << endl;
    // return 0;
}