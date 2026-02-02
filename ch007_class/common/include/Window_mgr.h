#include "Screen.h"
#include <vector>

class Window_mgr
{
private:
    // 这个Window_mgr追踪的Screen
    // 默认情况下,一个Window_mgr包含一个标准尺寸的空白Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};