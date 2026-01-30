#include <test.h>
#include <iostream>

extern int const conInt;

int main()
{
    std::cout << "conInt = " << conInt << std::endl;


    double num1, num2;
    std::cout << "请输入两个数:";
    while (std::cin >> num1 >> num2)
    {
        std::cout << num1 << "与" << num2 << "的求和结果是:" << myAdd(num1, num2) << std::endl;
    }

    return 0;
}