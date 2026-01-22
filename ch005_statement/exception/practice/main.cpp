#include <exception>
#include <iostream>
#include <stdexcept>

int main()
{
    int dividend{};
    int divisor{};
    std::cin >> dividend >> divisor;

    try
    {
        if (divisor == 0)
        {
            throw std::runtime_error("The divisor cannot be 0.");
        }
        std::cout << dividend / divisor;
    }
    catch (std::exception err)
    {
        std::cout << err.what() << std::endl;
    }
    return 0;
}