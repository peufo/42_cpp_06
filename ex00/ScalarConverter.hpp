#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>

typedef enum
{
    NONE,
    INTEGER,
    FLOAT,
    DOUBLE,
} input_type;

class ScalarConverter
{

private:
    static input_type getInputType(const std::string &str);

public:
    static std::string convert(const std::string &str);
    virtual ~ScalarConverter() = 0;
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    virtual ScalarConverter &operator=(const ScalarConverter &src) = 0;
};

#endif
