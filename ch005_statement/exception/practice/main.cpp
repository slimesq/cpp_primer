#include <exception>
#include <iostream>
#include <stdexcept>

int main()
{
    int dividend{};
    int divisor{};

    while (1)
    {
        try
        {
            std::cin >> dividend >> divisor;
            if (divisor == 0)
            {
                throw std::runtime_error("The divisor cannot be 0.");
            }
            std::cout << dividend / divisor;
            break;
        }
        catch (std::exception err)
        {
            std::cout << err.what() << "\nTry Again? Enter y or n:\n";
            char c{};
            std::cin >> c;
            if (!std::cin || c == 'n')
            {
                break;
            }
        }
    }
    return 0;
}