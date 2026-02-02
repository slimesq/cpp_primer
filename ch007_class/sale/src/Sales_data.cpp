#include "Sales_data.h"
#include <istream>

Sales_data::Sales_data(std::istream& is)
{
    read(is, *this);  // read函数的作用是从is中读取一条交易信息然后存入this对象中
}
Sales_data& Sales_data::combine(Sales_data const& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// Sales_data 的非成员接口函数
Sales_data add(Sales_data const& lhs, Sales_data const& rhs)
{
    Sales_data sum = lhs;  // 把lhs的数据成员拷贝给sum
    sum.combine(rhs);
    return lhs;
}
std::ostream& print(std::ostream& os, Sales_data const& item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();

    return os;
}
std::istream& read(std::istream& is, Sales_data& item)
{
    double price{0};
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}