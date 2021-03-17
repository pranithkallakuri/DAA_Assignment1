#include "measure.hpp"
#include "utility.hpp"
#include <iostream>
unsigned long long int measure(std::vector<stripe> S)
{
    unsigned long long int area = 0;
    //std::cout<<"hello\n";
    int lllll = 0;
    for(stripe s : S)
    {
        std::cout << "------------------------------\n";
        std::cout << "Stripe " << lllll++ << "\n";
        std::cout << "x_interval = (" << s.x_interval.bottom.val << ", " << s.x_interval.top.val << ")\n";
        std::cout << "y_interval = (" << s.y_interval.bottom.val << ", " << s.y_interval.top.val << ")\n";
        for(interval x : s.x_union)
        {
            std::cout << "(" << x.bottom.val << ", " << x.top.val << ")\n";
        }
        std::cout << "------------------------------\n";
        unsigned long long int x_measure = 0;
        for(auto x : s.x_union)
        {
            x_measure += (x.top.val - x.bottom.val);
        }
        area += x_measure * (s.y_interval.top.val - s.y_interval.bottom.val);
        std::cout << "x_measure = " << x_measure << "\n";
        std::cout << "y_measure = " << "(" << s.y_interval.top.val << " - " << s.y_interval.bottom.val << ")" << "\n";
        std::cout << "area = " << area << "\n";
    }
    // std::cout<<"hello\n";
    return area;
}