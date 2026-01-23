#include <iostream>

void error_msg(std::initializer_list<std::string> il)
{
    for (auto beg{il.begin()}; beg != il.end(); ++beg)
    {
        std::cout << *beg << " ";
    }
    std::cout << std::endl;

    for (auto& elem : il)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int add(std::initializer_list<int> il)
{
    int res{};
    for (auto elem : il)
    {
        res += elem;
    }
    return res;
}

int main()
{
    std::string const str1{"123"};
    std::string const str2{"456"};
    std::string str3{str1 + str2};
    error_msg({str1, str2, str3});
    std::cout << add({1, 2, 3, 4, 5}) << std::endl;
    std::cout << add({1, 2, 3}) << std::endl;

    return 0;
}