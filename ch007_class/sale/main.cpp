#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data sd("hello");
    print(std::cout, sd) << std::endl;
    sd.combine(std::string("const Sales_data &"));
    // sd.combine(std::string("const Sales_data &"),1,1);  // 不会进行类类型的隐式转换。

    Sales_data item = {"978", 25, 15.99};

    Sales_data total;           // 保存当前求和结果的变量
    if (read(std::cin, total))  // 读入第一笔交易
    {
        Sales_data trans;              // 保存下一条交易数据的变量
        while (read(std::cin, trans))  // 读入剩余的交易
        {
            if (total.isbn() == trans.isbn())  // 检查isbin
            {
                total.combine(trans);  // 更新变量total当前的值
            }
            else
            {
                print(std::cout, total) << std::endl;  // 输出结果
                total = trans;                         // 处理下一本书
            }
        }
        print(std::cout, total) << std::endl;  // 输出最后一条交易
    }
    else
    {
        std::cerr << "No data?!" << std::endl;  // 没有输入任何信息，通知用户
    }

    return 0;
}