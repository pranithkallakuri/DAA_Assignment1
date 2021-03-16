#include "measure.hpp"
#include "utility.hpp"
#include <iostream>
unsigned long long int measure(std::vector<stripe> S)
{
    unsigned long long int area = 0;
    std::cout<<"hello\n";
    for(stripe s : S)
    {
        unsigned long long int x_measure = 0;
        for(auto x : s.x_union)
            x_measure += (x.top.val - x.bottom.val);
        area += x_measure * (s.y_interval.top.val - s.y_interval.bottom.val);
    }
    std::cout<<"hello\n";
    return area;
}