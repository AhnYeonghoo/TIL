#include <iostream>

template<typename T>
class Data {
    private:
        T data;
    
    public:
        Data(T dt): data(dt) {}
        T get_data() {
            return this->data;
        }
};

int main() {

    Data<std::string> str_data("C++ lecture");
    Data<int> int_data(12);

    std::cout << str_data.get_data() << std::endl;
    std::cout << int_data.get_data() << std::endl;
    return 0;
}