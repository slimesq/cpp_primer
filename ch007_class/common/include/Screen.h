#pragma once
#include <string>
#include "Window_mgr.h"

class Screen
{
    // Window_mgr的成员可以访问Screen类的私有部分
    // friend class Window_mgr;

    /*  也可以指定Window_mgr中具体的函数作为友元:
        Window_mgr::clear必须在Screen类之前被声明
    */
    friend void Window_mgr::clear(ScreenIndex);

public:
    // typedef std::string::size_type pos;
    using pos = std::string::size_type;
    Screen() = default;  // 因为Screen有另一个构造函数,所以本函数是必须的。

    // cursor 被其类内初始值初始化为0
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {};
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {};
    char get() const  // 隐式内联
    {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;  // 显示内联
    Screen& move(pos r, pos c);             // 能在之后设为内联

    void some_member() const;

    Screen& set(char);
    Screen& set(pos, pos, char);

    // 根据对象是否是const重载了display函数
    Screen& display(std::ostream& os)
    {
        do_display(os);
        return *this;
    }
    Screen const& display(std::ostream& os) const
    {
        do_display(os);
        return *this;
    }

    pos size() const;

private:
    pos cursor{0};            // 鼠标的位置
    pos height{0}, width{0};  // 屏幕的高度和宽度
    std::string contents;     // 保存屏幕内容的数组

    mutable size_t access_ctr{0};  // 即使在一个const对象内也能被修改

    // 该函数负责显示Screen的内容
    void do_display(std::ostream& os) const
    {
        os << contents;
    }
};

inline Screen& Screen::move(pos r, pos c)  // 可以在函数的定义处指定inline
{
    pos row = r * width;  // 计算行的位置
    cursor = row + c;     // 在行内将光标移动导指定的列
    return *this;         // 以左值的形式返回对象
}

char Screen::get(pos r, pos c) const  // 在类的内部声明成inline
{
    pos row = r * width;       // 计算行的位置
    return contents[row + c];  // 返回给定列的字符
}
