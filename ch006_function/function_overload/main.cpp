#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using std::string;

string read();
void print(string const &);
void print(double d)
{
    std::cout << "d = " << d << std::endl;
}
void print(int i)
{
    std::cout << "i = " << i << std::endl;
}

void fooBar(int ival)
{
    // bool read = false;
    // string s = read();  // error: read是一个布尔值,而非函数

    // 不好的习惯:通常来说,在局部作用域中声明函数不是一个好选择
    void print(int);
    // print("Value:");    // error: print(const string &)被隐藏掉了
    print(ival);
    print(3.14);  // 正确: 调用print(int); print(double)被隐藏掉了。
}

void printVector(std::vector<int> vec, int idx)
{
    if (idx == static_cast<int>(vec.size()))
        return;
    std::cout << vec[idx];
#ifndef NDEBUG
    std::cout << " [vector.size = " << vec.size() << "]" << std::endl;
#endif
    printVector(vec, idx + 1);
}

void mainp(long);
void mainp(float);

void testconst(int const topols[])
{
    int tops[1]{1};
    topols = tops;
}

int main()
{
    /* fooBar(2);*/

    /*

     std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
     printVector(vec, 0);
    */

    /*
        assert(std::cin);  // 断言的是“输入流当前状态是否良好”
        string s;
        while (std::cin >> s && s != "sought")
        {
        }
        assert(std::cin);
    */

    /*mainp(3.14);  // error: is
      ambiguous,字面值3.14是double类型,double->float和double->long的级别是相同的(所有算术类型转换的级别都一样);
    */

    /* int val = 3.6 + 3.6 + 3;    // 会尽可能避免精度损失-->3先转化次double,然后再将结果转换的int。
    std::cout << val << std::endl;*/

    /*
        long long ll{100};
        float f1{1.5}, f2{1.6};
        int ll1 = ll + f1 + f2;
        std::cout << ll1 << std::endl;  //  103
    */

    /*  转化成unsigned int
        int i{-10};
        unsigned int ui{1};
        std::cout << i + ui << std::endl;
        std::cout << ui + i << std::endl;
    */

    return 0;
}