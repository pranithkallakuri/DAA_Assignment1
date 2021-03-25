#include<iostream>
#include <vector>
#include <set>
#include <fstream>
#include "utility.hpp"
#include "rectangle_dac.hpp"
#include "measure.hpp"
#include "contour.hpp"
#include "vertical_contour.hpp"

int main(){
    // create R
    int number_of_rectangles;
    std::cin >> number_of_rectangles;

    std::vector<rectangle> R;
    std::vector<edge> H;

    std::fstream csv_file;
    csv_file.open("points.csv", std::ios::out);
    
    for(int i = 0;i < number_of_rectangles; i++) 
    {
        long long int x_left, x_right, y_bottom, y_top;
        std::cin >> x_left >> x_right >> y_bottom >> y_top;
        //rectangle r(coord(x_left), coord(x_right), coord(y_bottom), coord(y_top));
        R.push_back(rectangle(coord(x_left), coord(x_right), coord(y_bottom), coord(y_top)));
        H.push_back(edge(interval(coord(x_left), coord(x_right)), coord(y_top), edgetype::top));
        H.push_back(edge(interval(coord(x_left), coord(x_right)), coord(y_bottom), edgetype::bottom));
        csv_file << x_left << ", " << x_right << ", " << y_bottom << ", " << y_top << "\n";
    }
    csv_file << "\n";
    std::vector<stripe> S;
    rectangle_dac(R, S);
    
    //std::cout<<"Before measure\n";
    std::cout<<"Measure is: "<< measure(S) << "\n";
    //return 0;
    std::cout<<"Contours:\n";
    std::vector<edge> contours = contour(H, S);
    //Horizontal contours
    for(edge in : contours)
    {
        std::cout << in.int_val.bottom.val << " to " << in.int_val.top.val << " with coord_val = "  
        << in.coord_val.val << " with edgetype = " << in.side <<  "\n"; //2 for bottom, 3 for top;

        csv_file << in.int_val.bottom.val << ", " << in.int_val.top.val << ", " << in.coord_val.val << "\n";

    }
    csv_file << "\n";
    //vertical contours
    for(edge in : vertical(S, contours))
    {
        std::cout << in.int_val.bottom.val << " to " << in.int_val.top.val << " with coord_val = "  
        << in.coord_val.val << " with edgetype = " << in.side <<  "\n"; //2 for bottom, 3 for top;

        csv_file << in.int_val.bottom.val << ", " << in.int_val.top.val << ", " << in.coord_val.val << "\n";
    }

    return 0;
}