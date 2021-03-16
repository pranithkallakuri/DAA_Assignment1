#include <vector>
#include <set>
#include <algorithm>
#include <climits>
#include "utility.hpp"
#include "stripes.hpp"
#include <iostream>

void rectangle_dac(std::vector<rectangle> RECT, std::vector<stripe>& S)
{
    std::vector<edge> VRX;
    for(rectangle r : RECT)
    {
        interval i_left(r.y_bottom, r.y_top);
        interval i_right(r.y_bottom, r.y_top);

        edge e_left(i_left, r.x_left, left);
        edge e_right(i_right, r.x_right, right);
        VRX.push_back(e_left);
        VRX.push_back(e_right);
    }
    //std::cout<<"Here\n";
    std::sort(VRX.begin(), VRX.end());
    interval x_ext(coord(LLONG_MIN), coord(LLONG_MAX));

    std::set<interval> LEFT, RIGHT;
    std::set<coord> POINTS;
    std::cout<<"bfr stripes\n";
    stripes(VRX, x_ext, LEFT, RIGHT, POINTS, S);
    std::cout<<"afr stripes\n";
}