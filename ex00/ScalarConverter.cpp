#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    (void)src;
}

bool iterator_match(
    std::string::const_iterator i,
    std::string::const_iterator end,
    const std::string &str)
{
    for (
        std::string::const_iterator s = str.begin();
        s != str.end() && i != end;
        s++, i++)
    {
        if (*i != *s)
            return false;
    }
    return true;
}

t_input ScalarConverter::getInputType(const std::string &str)
{
    std::string pseudo[] = {"inf", ""};

    std::string::const_iterator i = str.begin();

    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
        return CHAR;
    while (i != str.end() && std::isspace(*i))
        i++;
    if (i == str.end())
        return NONE;
    if (iterator_match(i, str.end(), "nan"))
        return PSEUDO;
    if (i != str.end() && (*i == '+' || *i == '-'))
        i++;
    if (iterator_match(i, str.end(), "inf"))
        return PSEUDO;
    if (i == str.end() || !std::isdigit(*i))
        return NONE;
    while (i != str.end() && std::isdigit(*i))
        i++;
    if (i == str.end() || *i != '.')
        return INTEGER;
    i++;
    while (i != str.end() && std::isdigit(*i))
        i++;
    return FLOAT;
}

t_values getValuesFrom(char c)
{
    return (t_values){
        .c = c,
        .i = static_cast<int>(c),
        .f = static_cast<float>(c),
        .d = static_cast<double>(c)};
}
t_values getValuesFrom(int i)
{
    return (t_values){
        .c = static_cast<char>(i),
        .i = i,
        .f = static_cast<float>(i),
        .d = static_cast<double>(i)};
}
t_values getValuesFrom(double d)
{
    return (t_values){
        .c = static_cast<char>(d),
        .i = static_cast<int>(d),
        .f = static_cast<float>(d),
        .d = d};
}

std::string convertChar(char c, t_input t)
{
    if (t == NONE || t == PSEUDO)
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
        values = getValuesFrom(str[1]);
        break;
    case INTEGER:
        values = getValuesFrom(std::atoi(str.c_str()));
        break;
    case FLOAT:
    case PSEUDO:
        values = getValuesFrom(std::atof(str.c_str()));
        break;
    default:
        break;
    }

    ss << "string:\t\"" << str << "\"\n";
    ss << "char:\t" << convertChar(values.c, t) << "\n";
    ss << "int:\t";
    if (t == NONE || t == PSEUDO)
        ss << "Impossible" << "\n";
    else
        ss << values.i << "\n";
    if (t == NONE)
        ss << "float:\tImpossible\ndouble:\tImpossible\n";
    else
    {
        ss << std::fixed << std::setprecision(1);
        ss << "float:\t" << values.f << "f\n";
        ss << "double:\t" << values.d << "\n";
    }
    return ss.str();
}
