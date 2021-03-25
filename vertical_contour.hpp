#ifndef __V_CONTOUR
#define __V_CONTOUR
#include<vector>
#include "utility.hpp"
/** @file */

/**
 * @brief Returns the vertical contours of the set of input rectangles by taking the horizontal contours as input
 * 
 * @param[in] S The vector of stripes formed by the stripes sub-routine/function. See stripes.hpp
 * @param[in] contour The list of horizontal contours that have been obtanied by calling contour_pieces subroutine
 * See contour.hpp
 * 
 * @returns A vector of vertical edges which are part of the contour.
 */
std::vector<edge> vertical(std::vector<stripe> S, std::vector<edge> contour);

#endif