#ifndef __STRIPES
#define __STRIPES
#include<vector>
#include<set>
#include "utility.hpp"
/** @file */

/**
 * @brief A wrapper function that merges two stripes after the divide part. It basically includes all the steps in the conquer part.
 * 
 * @param[in] L1 Contains the y-projections of all left edges in the left frame whose partner is not in the same frame. 
 * @param[in] R1 Contains the y-projections of all right edges in the left frame whose partner is not in the same frame. 
 * @param[in] L2 Contains the y-projections of all left edges in the right frame whose partner is not in the same frame.
 * @param[in] R2 Contains the y-projections of all right edges in the right frame whose partner is not in the same frame.
 * @param[in] P1 Contains the y-projections of all endpoints of line-segments in the left frame plus the frame boundaries in the y-direction.
 * @param[in] P2 Contains the y-projections of all endpoints of line-segments in the right frame plus the frame boundaries in the y-direction.
 * @param[in] S1 Contains all the stripes in the left frame.
 * @param[in] S2 Contains all the stripes in the right frame.
 * @param[in] x_ext Contains the boundares of the merged frame in the x-direction.
 * @param[in] xm Contains the x-coordinate of the median edge in the merged frame
 * 
 * @param[out] L Contains the Union of L1 and L2
 * @param[out] R Contains the Union of R1 and R2
 * @param[out] P Contains the Union of P1 and P2
 * @param[out] S Contains the newly merged stripes in the merged frame
 */
void merge(std::vector<interval>& L, std::vector<interval>& R,std::vector<interval> L1, std::vector<interval> R1,std::vector<interval> L2, std::vector<interval> R2,std::vector<coord>& P,std::vector<coord> P1,std::vector<coord> P2,
std::vector<stripe>& S,std::vector<stripe> S1,std::vector<stripe> S2, interval x_ext ,coord xm);


/**
 * @brief The main function that computes the stripes for the input rectangles (denoted by vertical edges). It is called recursively until
 * only one edge is present in a stripe. The base case then handles that case.
 * 
 * @param[in] V The sorted list of all Vertical edges of each rectangle
 * @param[in] x_ext The boundaries of the initial frame in the x-direction (-INF to +INF)
 * 
 * @param[out] L Contains the y-projections of all left edges whose partner is not in V
 * @param[out] R Symmetric to L (for right edges)
 * @param[out] P Contains the y-projections of all endpoints of the line segments in V plus the frame boundaries in the y-directions,
 * namely -INF to +INF
 * @param[out] S The list of stripes computed from the input frame.
 */
void stripes(std::vector<edge> V, interval x_ext, std::vector<interval>& L, std::vector<interval>& R, std::vector<coord>& P, std::vector<stripe>& S);

#endif