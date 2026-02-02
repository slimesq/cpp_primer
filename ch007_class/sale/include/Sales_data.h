#pragma once
#include <string>

std::string::size_type i;

class Sales_data
{
    friend Sales_data add(Sales_data const&, Sales_data const&);
    friend std::ostream& print(std::ostream&, Sales_data const&);
    friend std::istream& read(std::istream&, Sales_data&);

public:
    Sales_data() = default;
    Sales_data(std::string const& s) : bookNo(s)
    {
    }
    Sales_data(std::string const& s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n)
    {
    }
    Sales_data(std::istream& is);

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

// 在MSVC中即使没有如下声明,也可以编译和使用,但是最好要有,因为其他编译器可能不允许这样做。
// Sales_data 的非成员接口函数
Sales_data add(Sales_data const&, Sales_data const&);
std::ostream& print(std::ostream&, Sales_data const&);
std::istream& read(std::istream&, Sales_data&);