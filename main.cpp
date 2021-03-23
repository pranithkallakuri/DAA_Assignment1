#include<iostream>
#include <vector>
#include <set>
#include "utility.hpp"
#include "rectangle_dac.hpp"
#include "measure.hpp"

int main(){
    // create R
    int number_of_rectangles;
    std::cin >> number_of_rectangles;

    std::vector<rectangle> R;

    for(int i = 0;i < number_of_rectangles; i++) 
    {
        long long int x_left, x_right, y_bottom, y_top;
        std::cin >> x_left >> x_right >> y_bottom >> y_top;
        //rectangle r(coord(x_left), coord(x_right), coord(y_bottom), coord(y_top));
        R.push_back(rectangle(coord(x_left), coord(x_right), coord(y_bottom), coord(y_top)));
    }
    std::vector<stripe> S;
    rectangle_dac(R, S);
    
    //std::cout<<"Before measure\n";
    std::cout<<"Measure is: "<< measure(S) << "\n";
    return 0;
}