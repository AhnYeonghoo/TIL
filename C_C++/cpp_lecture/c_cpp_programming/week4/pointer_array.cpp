#include <iostream>

int main() {

    const char *ptr_arr[3];
    ptr_arr[0] = "Hello";
    ptr_arr[1] = "C";
    ptr_arr[2] = "word";

    for (int i = 0; i < 3; i++) {
        std::cout << "*ptr_arr[" << i << "]: " << *ptr_arr[i] << std::endl;
    }
    char(*arr_ptr)[3];
    char temp1[3] = {'a', 'b', 'c'};
    char temp2[3] = {'d', 'e', 'f'};

    std::cout << &temp1 << std::endl;
    std::cout << &temp2 << std::endl;

    arr_ptr = &temp1;
    std::cout << arr_ptr << ", " << &arr_ptr << std::endl;
    std::cout << std::endl;
    arr_ptr = &temp2;

    std::cout << arr_ptr << ", " << &arr_ptr << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << (*arr_ptr)[i];
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int num_01 = 10, num_02 = 20, num_03 = 30;
    int *arr[3] = {&num_01, &num_02, &num_03};

    for (int i = 0; i < 3; i++) {
        std::cout << arr[i] << std::endl;
        std::cout << *arr[i] << std::endl;
    }
        return 0;
}