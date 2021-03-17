#ifndef __STRIPES
#define __STRIPES
#include<vector>
#include<set>
#include "utility.hpp"

void merge(std::set<interval>& L, std::set<interval>& R,std::set<interval> L1, std::set<interval> R1,std::set<interval> L2, std::set<interval> R2,std::set<coord>& P,std::set<coord> P1,std::set<coord> P2,
std::vector<stripe>& S,std::vector<stripe> S1,std::vector<stripe> S2, interval x_ext ,coord xm);

void stripes(std::vector<edge> V, interval x_ext, std::set<interval>& L, std::set<interval>& R, std::set<coord>& P, std::vector<stripe>& S);

#endif