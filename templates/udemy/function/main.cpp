#include <iostream>
#include "max.h"
#include "sqr.h"
#include "add.h"


int main()
{
    std::cout << "Hello World" << std::endl;

    auto result1 = Max(3,5);
    auto result2 = Max(1.3, 8.5);

    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;
    
    auto result3 = Sqr(5);
    auto result4 = Sqr(6.2);

    std::cout << result3 << std::endl;
    std::cout << result4 << std::endl;

    auto result5 = Add(2,3);

    std::cout << result5 << std::endl;
}