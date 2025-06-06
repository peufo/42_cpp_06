#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

struct Data
{
    std::string pseudo;
    std::string password;
};

class Serializer
{
private:
protected:
public:
    virtual ~Serializer() = 0;
    Serializer();
    Serializer(const Serializer &src);
    virtual Serializer &operator=(const Serializer &src) = 0;
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif
