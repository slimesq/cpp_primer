#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::istream& readInts(std::istream& is)
{
    int ival;
    /**直到遇到文件结束才终止读取, 但如果输入错误, 例如输入了一个非整数,
                        也会进入循环。第一个表达式的结果是不用于判断,
                        第二个表达式的结果是一个布尔值, 表示是否到达文件末尾。*/
    while (is >> ival, !is.eof())
    {
        if (is.fail())
        {
            std::cerr << "Input error, try again: " << std::endl;
            is.clear();
            is.ignore(100, '\n');
            continue;
        }
        if (is.bad())
        {
            throw std::runtime_error("IO stream corrupted");
        }

        std::cout << ival << std::endl;
    }
    is.clear();
    return is;
}

void test1()
{
    std::cout << "Enter some integers,press Ctrl+Z end: " << std::endl;
    readInts(std::cin);
}

void test2()
{
    std::cin.tie(
        &std::cout);  // 仅仅是用来展示: 标准库已经将cin和cout关联在一起, 每次输入都会刷新cout缓冲区
    // old_tie 指向当前关联到cin的流(如果有的话)
    std::ostream* old_tie = std::cin.tie(nullptr);  // std::cin不再与其他流关联
    // 将cin与cerr关联; 这不是一个好主意,因为cin应该关联到cout
    std::cin.tie(&std::cerr);
    std::cin.tie(old_tie);  // 重建cin和cout之间的正常关联
}

std::vector<std::string> readFile(std::string const& filename)
{
    std::ifstream is(filename);
    if (!is)
    {
        std::cerr << "Could not open file: " << filename << std::endl;
        return {};
    }

    std::vector<std::string> result;
    std::string line;
    while (std::getline(is, line))
    {
        result.push_back(line);
    }
    return result;
}

void test3()
{
    auto lines = readFile("D:\\FirstFillet.brep");
    for (auto& line : lines)
    {
        std::cout << line << std::endl;
    }
}

void test4()
{
    // 在这几条语句中,file1都被截断
    std::ofstream out("file1");  // 隐含以输出模式打开文件并截断文件
    std::ofstream out2("file1", std::fstream::out);  // 隐含地截断文件
    std::ofstream out3("file1", std::ofstream::out | std::ofstream::trunc);  // 显式地指定截断文件

    // 为了保留文件内容,我们必须显式指定app模式
    std::ofstream app("file2", std::ofstream::app);                        // 隐含为输出模式
    std::ofstream app2("file2", std::ofstream::out | std::ofstream::app);  // 显式指定输出和追加模式

    std::ofstream ofs;                      // 未指定文件打开模式
    ofs.open("file3");                      // 隐含以输出模式打开文件并截断文件
    ofs.close();                            // 关闭ofs,以便我们将其用于其他文件
    ofs.open("file3", std::ofstream::app);  // 模式为输出和追加
    ofs.close();
}

int main()
{
    // test1();
    // test2();
    test3();
    return 0;
}