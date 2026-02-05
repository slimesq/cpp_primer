#include "Screen.h"
#include "Debug.h"
#include <iostream>

class Y;
class X
{
    Y* py{nullptr};
};

class Y
{
    X x;
};

class X1
{
public:
    X1(std::string const& _str) : str(_str)
    {
    }
    // X1(std::string _str = "") : str(_str)
    // {
    // }

private:
    std::string str;
};

class NoDefault
{
public:
    NoDefault(std::string const&);
    // 还有其他成员,但是没有其他的构造函数了
};

struct A
{  // 默认情况下my_mem是public的
    NoDefault my_mem;
};
// A a;  // error 不能为A合成构造函数
struct B
{
    // B()// error : b_member没有初始值
    // {
    // }
    NoDefault b_member;
};
// std::vector<NoDefault> vec(10);

/*
typedef double Money;
typedef double Money;
std::string bal;
class Account
{
public:
    Money balance()
    {
        return bal;
    };

private:
    // typedef double Money;  // error: 不能重新定义Money,虽然有的编译器不报错。

    Money bal;
};
*/

struct Data
{
    int val;
    // std::string str;
    char const* str;
};

constexpr int add(int a, int b)
{
    return a + b;
}

class Account
{
public:
    void calculate()
    {
        amount += amount * interestRate;
    }

    static double rate()
    {
        return interestRate;
    }

    static void rate(double);

private:
    std::string owner;
    double amount;
    static double interestRate;
    static double ininRate();
};
double Account::interestRate{ininRate()};
void Account::rate(double newReate)
{
    interestRate = newReate;
}

class Bar
{
public:
    // ...
private:
    static Bar mem1;  // 正确:静态成员可以是不完全类型
    Bar* mem2;        // 正确:指针成员可以是不完全类型
    // Bar mem3;           // 错误: 数据成员必须是完全类型
};

class Example
{
public:
    static double rate;
    static int const vecSzie{20};
    // static int constexpr vecSzie{20};
    static std::vector<double> vec;
};

int main()
{
    Screen myScreen(5, 3);
    Screen const blank(5, 3);
    myScreen.set('#').display(std::cout);  // 调用非常量版本
    blank.display(std::cout);              // 调用常量版本

    // X1 x1("11111111");
    // X1 x2;

    constexpr Debug io_sub(false, true, false);  // 调试IO
    if (io_sub.any())                            // 等价与if(true)
        std::cerr << "print appropriate error messages " << std::endl;
    constexpr Debug prod(false);  // 无调试

    if (prod.any())  // 等价与if(false)
        std::cerr << "print an error message" << std::endl;

    constexpr Data data{1, "123"};

    int z = add(1, 2);
    int x{1}, y{2};
    int z1 = add(x, y);

    return 0;
}