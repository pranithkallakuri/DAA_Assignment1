#ifndef __CONTOUR
#define __CONTOUR
#include <set>
#include <vector>
#include "utility.hpp"
std::set<interval> contour_pieces(edge h, std::vector<stripe> S);
std::set<interval> contour(std::set<edge> H, std::vector<stripe> S);
#endif