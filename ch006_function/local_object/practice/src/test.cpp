#include <test.h>
#include <iostream>

extern const int conInt{10};

double myAdd(double val1, double val2)
{                                 // val1 和 val2 是形参
    double result = val1 + val2;  // result 是普通局部变量
    static unsigned iCnt;  // iCnt 是静态局部变量,没有初始化的话,会默认初始化0
    ++iCnt;
    std::cout << "该函数已经累计执行了" << iCnt << "次" << std::endl;
    return result;
}