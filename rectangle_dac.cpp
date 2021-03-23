#include <vector>
#include <set>
#include <algorithm>
#include <climits>
#include "utility.hpp"
#include "stripes.hpp"
#include <iostream>

void rectangle_dac(std::vector<rectangle> RECT, std::vector<stripe>& S)
{
    std::cout << "RECT.size() = " << RECT.size() << "\n";
    std::vector<edge> VRX;
    for(rectangle r : RECT)
    {
        interval i_left(r.y_bottom, r.y_top);
        interval i_right(r.y_bottom, r.y_top);

        edge e_left(i_left, r.x_left, edgetype::left);
        edge e_right(i_right, r.x_right, edgetype::right);
        VRX.push_back(e_left);
        VRX.push_back(e_right);
    }

    
    std::sort(VRX.begin(), VRX.end());
    for (edge e : VRX)
    {
        std::cout << "-------------------------------\n";
        std::cout << ">>>edge<<<\n";
        std::cout << "interval = (" << e.int_val.bottom.val << ", " << e.int_val.top.val << ")\n";
        std::cout << "coord_val = (" << e.coord_val.val << ")\n";

    }
    std::cout << "-------------------------------\n";
    std::cout<<"VRX.size() = " << VRX.size() << "\n";
    interval x_ext(coord(LLONG_MIN), coord(LLONG_MAX));

    std::vector<interval> LEFT, RIGHT;
    std::vector<coord> POINTS;
    std::cout<<"bfr stripes\n";
    stripes(VRX, x_ext, LEFT, RIGHT, POINTS, S);
    std::cout<<"afr stripes\n";
}