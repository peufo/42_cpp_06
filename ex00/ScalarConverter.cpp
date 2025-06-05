#include "ScalarConverter.hpp"

#define cit std::string::const_iterator

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    (void)src;
}

t_input ScalarConverter::getInputType(const std::string &str)
{
    std::string::const_iterator i = str.begin();

    if (str.length() == 1)
        return CHAR;
    while (i != str.end() && std::isspace(*i))
        i++;
    if (i != str.end() && (*i == '+' || *i == '-'))
        i++;
    if (i == str.end() || !std::isdigit(*i))
        return NONE;
    while (i != str.end() && std::isdigit(*i))
        i++;
    if (i == str.end() || *i != '.')
        return INTEGER;
    i++;
    while (i != str.end() && std::isdigit(*i))
        i++;
    if (*i == 'f')
        return FLOAT;
    return DOUBLE;
}

t_values getValuesFrom(char c)
{
    std::cout << "\nFROM CHAR" << std::endl;
    return (t_values){
        .c = c,
        .i = static_cast<int>(c),
        .f = static_cast<float>(c),
        .d = static_cast<double>(c)};
}
t_values getValuesFrom(int i)
{
    std::cout << "\nFROM INT" << std::endl;
    return (t_values){
        .c = static_cast<char>(i),
        .i = i,
        .f = static_cast<float>(i),
        .d = static_cast<double>(i)};
}
t_values getValuesFrom(double d)
{
    std::cout << "\nFROM DOUBLE" << std::endl;
    return (t_values){
        .c = static_cast<char>(d),
        .i = static_cast<int>(d),
        .f = static_cast<float>(d),
        .d = d};
}

std::string convertChar(char c, t_input t)
{
    if (t == NONE)
        return "Impossible";
    if (std::isprint(c))
        return (std::stringstream() << "'" << c << "'").str();
    return "Non displayable";
}

std::string ScalarConverter::convert(const std::string &str)
{
    std::stringstream ss;
    t_input t = getInputType(str);
    t_values values = {0, 0, 0, 0};
    switch (t)
    {
    case CHAR:
        values = getValuesFrom(str[0]);
        break;
    case INTEGER:
        values = getValuesFrom(std::atoi(str.c_str()));
        break;
    case FLOAT:
    case DOUBLE:
        values = getValuesFrom(std::atof(str.c_str()));
        break;
    default:
        break;
    }

    ss << "input:\t`" << str << "`\n";
    ss << "char:\t" << convertChar(values.c, t) << "\n";
    ss << "int:\t" << values.i << "\n";
    ss << std::fixed << std::setprecision(1);
    ss << "float:\t" << values.f << "f\n";
    ss << "double:\t" << values.d << "\n";
    return ss.str();
}
