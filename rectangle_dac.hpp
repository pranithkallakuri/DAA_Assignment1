#ifndef __RECTANGLE_DAC
#define __RECTANGLE_DAC

#include <vector>
#include "utility.hpp"
/** @file */

/**
 * @brief The function rectangle_dac only provides an environment for the recursive divide-and-conquer function "stripes"
 * 
 * @param[in] RECT List of all input rectangles.
 * @param[out] S The list of stripes. 
 */
void rectangle_dac(std::vector<rectangle> RECT, std::vector<stripe>& S);

#endif