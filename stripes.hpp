#ifndef __STRIPES
#define __STRIPES
#include<vector>
#include<set>
#include "utility.hpp"

void merge(std::vector<interval>& L, std::vector<interval>& R,std::vector<interval> L1, std::vector<interval> R1,std::vector<interval> L2, std::vector<interval> R2,std::vector<coord>& P,std::vector<coord> P1,std::vector<coord> P2,
std::vector<stripe>& S,std::vector<stripe> S1,std::vector<stripe> S2, interval x_ext ,coord xm);

void stripes(std::vector<edge> V, interval x_ext, std::vector<interval>& L, std::vector<interval>& R, std::vector<coord>& P, std::vector<stripe>& S);

#endif