#include <string>

std::string (&func())[10];

typedef std::string strs[10];
strs(&func1());

auto func2() -> std::string (&)[10];

strs strs1;
decltype(strs1)& func3();  // 返回

std::string (&(*pfunc)())[10] = func;  // 函数指针

int main()
{
    auto f1 = func;
    pfunc = func1;

    return 0;
}