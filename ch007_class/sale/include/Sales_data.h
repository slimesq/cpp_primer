#pragma once
#include <iostream>
#include <string>

class Sales_data
{
    friend Sales_data add(Sales_data const&, Sales_data const&);
    friend std::ostream& print(std::ostream&, Sales_data const&);
    friend std::istream& read(std::istream&, Sales_data&);

public:
    Sales_data() = default;

    Sales_data(std::string const& s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n)
    {
        std::cout << "受委托的构造函数:"
                  << "bookNo = " << bookNo << std::endl;
    }
    Sales_data(std::string const& s) : Sales_data(s, 0, 0)
    {
        std::cout << "委托构造函数: const string&" << std::endl;
    }
    Sales_data(std::istream& is) : Sales_data("", 0, 0)
    {
        std::cout << "委托构造函数: istream&" << std::endl;
        read(is, *this);  // read函数的作用是从is中读取一条交易信息然后存入this对象中
    }

    inline std::string isbn() const
    {
        return bookNo;
    }
    Sales_data& combine(Sales_data const&);

private:
    inline double avg_price() const
    {
        if (units_sold)
            return revenue / units_sold;
        else
            return 0;
    }

private:
    // 数据成员
    std::string bookNo;
    unsigned units_sold{0};
    double revenue{0.0};
};

// 在MSVC中即使没有如下声明,也可以编译和使用,但是最好要有,因为其他编译器可能不允许这样做。友元声明只用于控制访问权限，并非真正的函数声明.
// Sales_data 的非成员接口函数
Sales_data add(Sales_data const&, Sales_data const&);
std::ostream& print(std::ostream&, Sales_data const&);
std::istream& read(std::istream&, Sales_data&);