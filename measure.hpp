#ifndef __MEASURE
#define __MEASURE
#include <vector>
#include "utility.hpp"
#include <set>

/**
 * @brief The function "measure" computes the union of the area of all rectangles. That is, it computes the total area covered by the input iso-rectangles
 * 
 * @param[in] S The list of stripes that are created from the input list of rectangles.
 * 
 * @returns The total area covered by the iso-rectangles. 
 */
unsigned long long int measure(std::vector<stripe> S);

#endif