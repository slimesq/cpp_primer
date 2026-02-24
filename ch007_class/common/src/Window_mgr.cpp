#include "Screen.h"


void Window_mgr::clear(ScreenIndex i)
{
    // s是一个Screen的引用,指向我们想要清空的那个屏幕
    Screen& s{screens[i]};
    // 将那个指定的Screen设置为空白
    s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(Screen const& s)
{
    screens.push_back(s);
    return screens.size() - 1;
}