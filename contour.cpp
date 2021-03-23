#include "contour.hpp"
#include <set>
#include<algorithm>
#include <vector>
 std::set<interval> contour(std::set<edge> H, std::vector<stripe> S){
     std::vector<long long int> bottom_int;
     std::vector<long long int> top_int;
     for(stripe s: S){
         bottom_int.push_back(s.y_interval.bottom.val);
         top_int.push_back(s.y_interval.top.val);
     }
     std::set<interval> contours;
     for(edge h: H){
         for(interval sub_h : contour_pieces(h, S, bottom_int, top_int)){
            contours.insert(sub_h);
         }
     }
     return contours;
 }
 std::set<interval> contour_pieces(edge h, std::vector<stripe> S, std::vector<long long int>bottom_int, std::vector<long long int> top_int){
     int index;
     if(h.side == edgetype::bottom){
        auto it = lower_bound(top_int.begin(), top_int.end(), h.coord_val.val);
        index = it - top_int.begin();
     }
     else{
         auto it = lower_bound(bottom_int.begin(), bottom_int.end(), h.coord_val.val) ;
         index = it - bottom_int.begin();
     }
     // index 
 }