#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Please, provide one argument !" << std::endl;
        return 1;
    }
    std::cout << ScalarConverter::convert(av[1]) << std::endl;
    return 0;
}
