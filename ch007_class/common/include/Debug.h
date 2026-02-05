#pragma once
#include <string>

class Debug
{
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b)
    {
    }

    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o)
    {
    }

    constexpr bool any() const
    {
        // std::string i{"10000"}; // error: 非字面值类型
        return hw || io || other;
    }

    void set_io(bool b)
    {
        io = b;
    }
    void set_hw(bool b)
    {
        hw = b;
    }
    void set_other(bool b)
    {
        hw = b;
    }

private:
    bool hw;     // 硬件错误,而非IO错误
    bool io;     // IO错误
    bool other;  // 其他错误
};