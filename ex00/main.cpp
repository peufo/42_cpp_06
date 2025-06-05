#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::cout << ScalarConverter::convert(av[1]) << std::endl;
        return 0;
    }
    std::cerr << "No argument provided, default tests run:\n"
              << std::endl;
    std::cout << ScalarConverter::convert("0") << std::endl;
    std::cout << ScalarConverter::convert("nan") << std::endl;
    std::cout << ScalarConverter::convert("42.0f") << std::endl;
    // std::cout << ScalarConverter::convert("-inf") << std::endl;
    // std::cout << ScalarConverter::convert("inf") << std::endl;
    // std::cout << ScalarConverter::convert("'0'") << std::endl;
    // std::cout << ScalarConverter::convert("a") << std::endl;
    // std::cout << ScalarConverter::convert("'a'") << std::endl;
    // std::cout << ScalarConverter::convert("200000000000000000000000000000000000000.0") << std::endl;
    // std::cout << ScalarConverter::convert("400000000000000000000000000000000000000.0") << std::endl;
    // std::cout << ScalarConverter::convert("-200000000000000000000000000000000000000.0") << std::endl;
    // std::cout << ScalarConverter::convert("-400000000000000000000000000000000000000.0") << std::endl;
    // std::cout << ScalarConverter::convert("") << std::endl;
    // std::cout << ScalarConverter::convert(" ") << std::endl;
    // std::cout << ScalarConverter::convert("\b") << std::endl;
    // std::cout << ScalarConverter::convert("a") << std::endl;
    // std::cout << ScalarConverter::convert("jonas") << std::endl;
    // std::cout << ScalarConverter::convert("  --42.f") << std::endl;
    // std::cout << ScalarConverter::convert("42.0") << std::endl;
    // std::cout << ScalarConverter::convert(" -42.") << std::endl;
    return 0;
}
