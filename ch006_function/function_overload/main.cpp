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

int f(int, int);

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int divi(int a, int b)
{
    return a / b;
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

    /*
        int i{10};
        int *pI{&i};
        void *pvoid{static_cast<void *>(pI)};
        void *pvoid1{pI};
        char *pc1{static_cast<char *>(pvoid)};
        char *pc{reinterpret_cast<char *>(pI)};

        int const *cPi{&i};
        char *pc2{reinterpret_cast<char *>(const_cast<int *>(cPi))};

        double d{10.0};
        const double *pd(&d);
        double pd1{reinterpret_cast<double*>(pd)};  // error :const去除只能有const来完成。
    */

    /*
        int i1, i2, i3;
        int* const pInt1[2]{&i1, &i2};  // 数组中的每个指针都不允许修改指向。
        int const* pInt2[2]{&i1, &i2};  // 数组中的每个指针都不允许修改指向的值。
        pInt2[1] = &i3;
        // *(pInt2[1]) = 3;// error
        // pInt1[1] = &i3;    // error
    */

    /*
        int const v2{0};
        int v1{v2};
        int i{1};
        int *p1{&v1};
        int const *p2{&v2}, *const p3{&i};
        // p1 = p3;  // error: p3的类型为 int cosnt* const
        p2 = p3;
    */

    /*
        int const i{42};
        auto j{i};
        auto const &k{i};
        auto *p{&i};
        auto const j2{i}, &k2{i};
        std::cout << typeid(i).name() << std::endl;
        std::cout << typeid(j).name() << std::endl;
        std::cout << typeid(k).name() << std::endl;
        std::cout << typeid(p).name() << std::endl;
        std::cout << typeid(j2).name() << std::endl;
        std::cout << typeid(k2).name() << std::endl;
    */

    // std::vector<decltype(f) *> fvec{add, sub, mul, divi};
    std::vector<int (*)(int, int)> fvec{add, sub, mul, divi};
    for (auto const &f : fvec)
    {
        std::cout << "result = " << f(10, 5) << std::endl;
    }

    return 0;
}