#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

typedef enum
{
    NONE,
    CHAR,
    INTEGER,
    FLOAT,
    PSEUDO
} t_input;

typedef struct
{
    char c;
    int i;
    float f;
    double d;
} t_values;

class ScalarConverter
{

private:
    static t_input getInputType(const std::string &str);

public:
    static std::string convert(const std::string &str);
    virtual ~ScalarConverter() = 0;
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    virtual ScalarConverter &operator=(const ScalarConverter &src) = 0;
};

#endif
