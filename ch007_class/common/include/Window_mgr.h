#include <vector>

class Screen;

class Window_mgr
{
public:
    // 窗口中每个屏幕的编号
    using ScreenIndex = std::vector<Screen>::size_type;
    // 按照编号将指定的Screen设置为空白
    void clear(ScreenIndex);

    // 向窗口添加一个Screen,返回它的编号
    ScreenIndex addScreen(const Screen&);

private:
    // 这个Window_mgr追踪的Screen
    // 默认情况下,一个Window_mgr包含一个标准尺寸的空白Screen
    std::vector<Screen> screens{};
};