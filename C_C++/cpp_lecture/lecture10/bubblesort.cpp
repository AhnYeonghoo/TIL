#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template <typename T>
void print_vector(std::vector<T>& vec)
{
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++)
    {
        cout << *itr << endl;
    }
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec)
{
    for (const auto& elem : vec)
    {
        cout << elem << endl;
    }
}

int main()
{
    int arr[] {3, 2, 10, 9, 6, 1};
    int N = 6;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }

    for (const auto& ele : arr)
    {
        cout << ele << endl;
    }

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    for (std::vector<int>::size_type i = 0; i < vec.size(); i++)
    {
        std::cout << "Vec " << i + 1 << " element :: " << vec[i] << std::endl;
    }

    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
    {
        cout << *itr << endl;
    }

    std::vector<int>::iterator itr = vec.begin() + 2;
    cout << *itr << endl;

    cout << "start" << endl;
    print_vector(vec);
    cout << "----------------" << endl;

    vec.insert(vec.begin() + 2, 15);
    print_vector(vec);

    cout << "--------------" << endl;
    vec.erase(vec.begin() + 3);
    print_vector(vec);

    cout << "reverse vec print" << endl;
    std::vector<int>::reverse_iterator r_iter = vec.rbegin();
    for (; r_iter != vec.rend(); r_iter++)
    {
        cout << *r_iter << endl;
    }

    for (int ele : vec) 
    {
        cout << ele << endl;
    }
    return 0;
}