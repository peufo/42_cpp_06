#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <ctime>

Base *generate(void)
{
    double random = static_cast<double>(std::rand()) / RAND_MAX;
    if (random < 0.33)
        return new A();
    if (random < 0.66)
        return new B();
    return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Base pointer is class A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Base pointer is class B" << std::endl;
    else
        std::cout << "Base pointer is class C" << std::endl;
}
void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "Base ref     is class A" << std::endl;
        return;
    }
    catch (...)
    {
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "Base ref     is class B" << std::endl;
        return;
    }
    catch (...)
    {
    }
    try
    {
        C &el = dynamic_cast<C &>(p);
        (void)el;
        std::cout
            << "Base ref     is class C" << std::endl;
        return;
    }
    catch (...)
    {
    }
}

int main()
{
    std::srand(std::time(NULL));
    for (int i = 0; i < 10; i++)
    {
        Base *ptr = generate();
        Base &ref = *ptr;
        identify(ptr);
        identify(ref);
        std::cout << std::endl;
        delete ptr;
    }
}
