#ifndef __CONTOUR
#define __CONTOUR
#include <set>
#include <vector>
#include "utility.hpp"
std::set<interval> contour_pieces(edge h, std::vector<stripe> S, std::vector<long long int> bottom_int, std::vector<long long int> top_int);
std::set<interval> contour(std::set<edge> H, std::vector<stripe> S);
#endif