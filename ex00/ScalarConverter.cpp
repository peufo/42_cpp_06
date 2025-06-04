#include "ScalarConverter.hpp"

#define cit std::string::const_iterator

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    (void)src;
}

input_type ScalarConverter::getInputType(const std::string &str)
{
    std::string::const_iterator i = str.begin();

    while (i != str.end() && std::isspace(*i))
        i++;
    while (i != str.end() && (*i == '+' || *i == '-'))
        i++;
    if (i == str.end() || !std::isdigit(*i))
        return input_type::NONE;
    while (i != str.end() && std::isdigit(*i))
        i++;
    if (i == str.end())
        return input_type::INTEGER;
    i++;
    if (i == str.end() || *i != '.')
        return input_type::INTEGER;
    while (i != str.end() && std::isdigit(*i))
        i++;
    if (*i == 'f')
        return input_type::FLOAT;
    return input_type::DOUBLE;
}

std::string convertChar(const std::string &str, input_type t)
{

    if (str.length() == 1 && std::isprint(str[0]))
        return "'" + 'A' + "'";

    int value = static_cast<int>('3');

    if (str.length() != 1)
        return "Impossible"
}

std::string ScalarConverter::convert(const std::string &str)
{
    std::stringstream ss;
    input_type t = getInputType(str);

    ss << "char:\t" << convertChar(str, t) << '\n';
    return "prout" + str;
}
