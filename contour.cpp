#include "contour.hpp"
#include <set>
#include <vector>
 std::set<interval> contour(std::set<edge> H, std::vector<stripe> S){
     std::vector<long long int> bottom_int;
     std::vector<long long int> top_int;
     for(stripe s: S){
         //bottom_int.push_back(s.)
     }
     std::set<interval> contours;
     for(edge h: H){
         for(interval sub_h : contour_pieces(h, S))
            contours.insert(sub_h);
     }
     return contours;
 }
 std::set<interval> contour_pieces(edge h, std::vector<stripe> S){
     if(h.side == edgetype::bottom){

     }
     else{

     }
 }