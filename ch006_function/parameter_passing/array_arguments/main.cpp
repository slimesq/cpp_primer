#include <iostream>

void print(int (&arr)[10])
{
    for (auto elem : arr)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void print2(int const* beg, int const* end)
{
    while (beg != end)
    {
        std::cout << *beg++ << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr1[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(arr1);

    int* begin{std::begin(arr1)};
    int* end{std::end(arr1)};
    print2(begin, end);

    /*
        int* arr2{new int[10]{
            10,
            9,
            8,
            7,
            6,
            5,
            4,
            3,
            2,
            1,
        }};
        print(arr2);    // error
        int* begin2{std::begin(arr2)};  // error
    */

    return 0;
}