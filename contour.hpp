#ifndef __CONTOUR
#define __CONTOUR
#include <set>
#include <vector>
#include "utility.hpp"
/** @file */

/**
 * @brief Stores all the nodes b/w a starting and ending point from the binary search tree
 * 
 */
void search_tree(std::vector<std::pair<long long int, lru>>& nodes, ctree* root, long long int left, long long int right);

/**
 * @brief
 * 
 * @param[in] h A single horizontal rectangle edge
 * @param[in] S The list of stripes
 * @param[in] bottom_int The x-coordinates of all the bottom edges of each stripe
 * @param[in] top_int The x-coordinates of all the top edges of each stripe
 * 
 * @returns A set of intervals that are part of the contour of the input rectangles
 */
std::vector<interval> contour_pieces(edge h, std::vector<stripe> S, std::vector<long long int> bottom_int, std::vector<long long int> top_int);

/**
 * @brief 
 * 
 * @param[in] H The set of horizontal rectangle edges.
 * @param[in] S The list of stripes computed from the function "rectangle_dac"
 * 
 * @returns A set of intervals that denote the horizontal edges present on the contour of the input rectangles
 */
std::vector<edge> contour(std::vector<edge> H, std::vector<stripe> S);
#endif