#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int arr2d[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    
    for (const auto& arr : arr2d)
    {
        for (const auto& val : arr)
        {
            printf("%d", val);
        }
        print('\n');
    }
    
    
}