#include <vector>
#include <set>
#include <algorithm>
#include <climits>
#include "utility.hpp"
#include "stripes.hpp"
#include <iostream>

void rectangle_dac(std::vector<rectangle> RECT, std::vector<stripe>& S)
{
    //std::cout << "RECT.size() = " << RECT.size() << "\n";
    std::vector<std::vector<long long int>> sorted; 
    std::vector<edge> VRX;
    for(int i = 0; i < RECT.size(); i++)
    {
        sorted.push_back({RECT[i].x_left.val, 0, i});
        sorted.push_back({RECT[i].x_right.val, 1, i});
    }

    std::sort(sorted.begin(), sorted.end(), [](const std::vector<long long int>& lhs, const std::vector<long long int>& rhs){
        if(lhs[0] == rhs[0])
            return lhs[1] < rhs[1];
        else
            return lhs[0] < rhs[0];
    });
    
    for(int i = 0; i < sorted.size(); i++)
    {
        rectangle r = RECT[sorted[i][2]];
        interval int1(r.y_bottom, r.y_top);

        edge e(int1, coord(sorted[i][0]), (edgetype)(sorted[i][1]));
        VRX.push_back(e);
    }
    
    // for(rectangle r : RECT)
    // {
    //     interval i_left(r.y_bottom, r.y_top);
    //     interval i_right(r.y_bottom, r.y_top);

    //     edge e_left(i_left, r.x_left, edgetype::left);
    //     edge e_right(i_right, r.x_right, edgetype::right);
    //     VRX.push_back(e_left);
    //     VRX.push_back(e_right);
    // }

    // std::sort(VRX.begin(), VRX.end(), [](const edge& lhs, const edge& rhs){ 
    //     if(lhs.coord_val.val == rhs.coord_val.val)
    //     {
    //         return lhs.side == edgetype::left;
    //     }
    //     else
    //         return lhs.coord_val.val < rhs.coord_val.val;
    // }); //sorting is segfaulting
    //std::cout << "seg\n";
    // for (edge e : VRX)
    // {
    //     std::cout << "-------------------------------\n";
    //     std::cout << ">>>edge<<<\n";
    //     std::cout << "interval = (" << e.int_val.bottom.val << ", " << e.int_val.top.val << ")\n";
    //     std::cout << "coord_val = (" << e.coord_val.val << ")\n";

    // }
    // std::cout << "-------------------------------\n";
    // std::cout<<"VRX.size() = " << VRX.size() << "\n";
    interval x_ext(coord(LLONG_MIN), coord(LLONG_MAX));

    std::vector<interval> LEFT, RIGHT;
    std::vector<coord> POINTS;
    //std::cout<<"bfr stripes\n";
    stripes(VRX, x_ext, LEFT, RIGHT, POINTS, S);
    //std::cout<<"afr stripes\n";
}