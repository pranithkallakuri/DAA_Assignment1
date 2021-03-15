#include "stripes.hpp"
#include "utility.hpp"
#include <climits>
void stripes(std::vector<edge> V, interval x_ext, std::set<interval> L, std::set<interval> R, std::set<coord> P, std::vector<stripe> S){
    if(V.size()==1){
        auto it = V.begin();
        if((*it).side == left){ 
            L.insert((*it).int_val);
            R.clear();
        }
        else {
            R.insert((*it).int_val);
            L.clear();
        }
        P.insert(coord(LLONG_MAX));
        P.insert(coord((*it).int_val.bottom));
        P.insert(coord((*it).int_val.bottom));
        P.insert(coord(LLONG_MIN));
        for()
    }
    else{
        
    }
}