#include <iostream>
#include <cstdlib>
#include <typeinfo>

int main() {

    size_t nSize = 5;
    int arr[nSize] = {1, 2, 3, 4, 5};
    size_t nIdx = 0;
    printf("arr's memory address:%p\n", arr);

    for (nIdx = 0; nIdx < nSize; nIdx++) {
        printf("IDX:%d\t%dtelement's type:%s memory adress: %p\n", nIdx, arr[nIdx],
        typeid(arr[nIdx]).name(), &arr[nIdx]);
    }
    
    printf("%d\n", sizeof(arr)/sizeof(*arr));
    return EXIT_SUCCESS;
}