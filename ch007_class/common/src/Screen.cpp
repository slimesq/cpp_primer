#include "Screen.h"
#include <istream>

void Screen::some_member() const
{
    ++access_ctr;  //  保存一个计数值,用于记录成员函数被调用的次数
}

Screen& Screen::set(char c)
{
    contents[cursor] = c;  // 设置当前光标所在位置的新值
    return *this;          // 将this对象作为左值返回
}

Screen& Screen::set(pos row, pos col, char ch)
{
    contents[row * width + col] = ch;  // 设置给定位置的新值
    return *this;                      // 将this对象作为左值返回
}

Screen::pos Screen::size() const
{
    return height * width;
}