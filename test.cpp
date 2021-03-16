#include <iostream>
#include "utility.hpp"

int main()
{
    coord x1(10);
    coord x2(25);
    std::cout << x1.val << "\n";
    coord x3(x1.val +x2.val);
    //std::cout <<(x1 + x2).val << "\n";
    std::cout << x3.val << "\n";
    return 0;
}