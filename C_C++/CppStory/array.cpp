#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;

int main()
{
    size_t  nSize = 5;
    int arr[nSize] = { 1,2 , 3, 4, 5};
    size_t nIdx = 0;
    printf("Arr`s memory address%p\n", arr);
    
    for (nIdx = 0; nIdx < nSize; nIdx++) 
    {
        printf("IDX:%d\t%d\telements type:%s, memory address:%p\n",
        nIdx, arr[nIdx], typeid(arr[nIdx]).name(), &arr[nIdx]);
    }

    return EXIT_SUCCESS;
}