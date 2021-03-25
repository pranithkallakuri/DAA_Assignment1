#ifndef __UTILITY
#define __UTILITY
/** @file */

#include <vector>
#include <set>

/**
 * class 'coord'. Contains a single number which depicts the 
 * position of either an x or y co-ordinate on the 2D cartesian plane.
 * 
 */
class coord
{
    public:
    long long int val; /**< The long long int val stores the numebr */

    /**
     * @brief Constructor for the coord class
     * @param[in] val The long long integer value the coord object takes
     */
    coord(long long int val);

    bool operator<(const coord& other) const;
    bool operator>(const coord& other) const;
    bool operator==(const coord& other) const;
    bool operator!=(const coord& other) const;
    // coord operator+(const coord& other) const;
    // coord operator-(const coord& other) const;
    bool operator<=(const coord& other) const;
    bool operator>=(const coord& other) const;
};


/**
 * A class to store a point. Obviously a point consists of 2 coords 
 */
class point
{
    public:
    coord x; /**< The x coordinate of the point */
    coord y; /**< The y coordinate of the point */

    /**
     * @brief Constructor for the point class
     * @param[in] x The x coordinate of the point
     * @param[in] y The y coordinate of the point
     */
    point(coord x, coord y);
};

/**
 * A class to store an interval.
 * An interval consists of two coordinates that denoting the edges of an interval
 */
class interval
{
    public:
    coord bottom; /**< The bottom coordinate of the interval */
    coord top; /**< The top cordinate of the interval */

    /**
     * @brief Constructor for the interval class
     * @param[in] bottom The bottom end of the interval
     * @param[in] top The top end of the interval 
     */
    interval(coord bottom, coord top);
    bool operator<(const interval& other) const;
    bool operator==(const interval& other) const;
    
};

/**
 * A line segment class. Denotes either a horizontal or vertical line segment.
 * As given below you can notice that a single interval and a single coordinate is enough
 * to completely denote the position of a line segment
 */
class line_segment
{
    public:
    interval int_val; /**< The interval b/w which the line-segment is present */
    coord coord_val; /**< The coordinate on which the line-segment is present */

/**
 * @brief Constructor for the line_segment class.
 * @param[in] int_val The interval b/w which line-segment id present.
 * @param[out] coord_val The coordinate on which the line-segment is present.
 */
    line_segment(interval int_val, coord coord_val);
};

/**
 * A rectangle class. Encapsulates the input coords into a rectangle. 
 */
class rectangle
{
    public:
    coord x_left; /**< The left x coordinate of the rectangle */ 
    coord x_right; /**< The right x co-ordinate of the rectangle */
    coord y_bottom; /**< The bottom y coordinate of the rectangle */
    coord y_top; /**< The top y coordinate of the rectangle */

    /**
     * @brief Constructor for the rectangle class
     * @param[in] l the left x coordinate of the rectangle
     * @param[in] r the right x coordinate of the rectangle
     * @param[in] b the bottom y coordinate of the rectangle
     * @param[in] t the top y coordinate of the rectangle 
     */
    rectangle(coord l, coord r, coord b, coord t);
};

/**
 * An enum type.
 * Denotes the position of an edge.
 */
enum edgetype{left, right, bottom, top};
// edgetype val = left;

/**
 * An edge class. Denotes the edge of a rectangle.
 * It is basically a line-segment with an added member to denote the side of the edge
 */
class edge
{
    public:
    interval int_val; /**< The interval denoting the edge */
    coord coord_val; /**< The coordinate the edge is on */
    edgetype side; /**< The side of the edge (left/right/bottom/top) */

    /**
     * @brief Constructor for the edge class.
     * @param[in] int_val The interval denoting the edge
     * @param[in] coord_val The coordinate the edge is on
     * @param[in] side The side of the edge (left/right/bottom/top)
     */
    edge(interval int_val, coord coord_val, edgetype side);

    // bool operator<(const edge& other) const;
    // edge& operator=(const edge& other);
};

/**
 * An enum type.
 * Denotes the side of an x_union coord present in the 
 * binary search tree used to query free sub-intervals in a stripe
 * Given below are the explanations of each node. Here "node" refers
 * to the nodes in the sub-interval binary search tree.
 */
enum lru{
    l, /**< The node contains the left coordinate of the x_union */
    r, /**< The node contains the right coordinate of the x_union */
    u /**< The node is an internal node of the binary */
};

/**
 * A ctree class. Denotes a node in the sub-interval binary search tree
 */
class ctree
{
    public:
    long long int x; /**< The value of the x_union coordinate */
    lru side; /**< The side of the  coordinate selected (left/right/undefined) */
    ctree *lson = NULL; /**< A pointer to the left child of the tree. By default it is NULL */
    ctree *rson = NULL; /**< A pointer to the right child of the tree. By default it is NULL */

    /**
     * @brief Constructor to the ctree class
     * @param[in] x The coord left/right of each of the x_unions 
     * @param[in] side The side of the coordinate
     * @param[in] lson The left child of the node we are creating
     * @param[in] rson The right child of the node we are creating
     */
    ctree(long long int x, lru side, ctree* lson, ctree* rson);
};

/**
 * The stripe class
 */
class stripe
{
    public:
    interval x_interval; /**< The x coordinate bounds of the stripe */
    interval y_interval; /**< The y coordinate bounds of the stripe */  
    std::vector<interval> x_union; /** The list of intervals in a stripe that are covered by a rectangle */
    unsigned long long int x_measure = 0; /** The combined length of x_union */
    ctree *tree = NULL; /**< A node of the subinterval query binary seach tree */

    /**
     * @param[in] x_interval The x_interval of the stripe
     * @param[in] y_inteval The y_interval of the stripe
     * @param[in] x_union The x_union intervals in a stripe. Usually empty when first created.
     */
    stripe(interval x_interval, interval y_interval, std::vector<interval> x_union);
};


//std::vector<rectangle> union_(std::vector<rectangle> R);


/**
 * @brief the y_set function takes a list of rectangles as input and outputs a set of coordinates
 * that denote the union of the endpoints of each rectangle
 * 
 * @param[in] R A list of rectangles
 * 
 * @returns A set of coordinates 
 */
std::set<coord> y_set(std::vector<rectangle> R);

/**
 * @brief The partition function takes in a list of y coordinates as input and returns a list of y-intervals 
 * that join adjacent y coordinates.
 * 
 * @param[in] Y A list of y coordinates
 * 
 * @returns A list of y-intervals
 */
std::vector<interval> partition(std::vector<coord> Y);

//std::vector<coord> x_proj(std::vector<point> points);

//std::vector<interval> intervals(std::vector<coord> coords);


/**
 * @brief Extends/Copies the stripes not present on one side onto the other and merges them.
 * 
 * @param[in] S The list of stripes on the other side
 * @param[in] P A list of y-coordinates
 * @param[in] interval_val The x bounds of the newly created stripes
 * 
 * @returns A list of newly created stripes
 */
std::vector<stripe> copy(std::vector<stripe> S, std::vector<coord> P, interval interval_val);


/**
 * @brief Updates the x_unions of the newly merged stripes which were obtanined from copy
 * 
 * @param[in] S_left The merged list of stripes
 * @param[in] R2_LR The list of lone intervals that are present on the other side
 */
void blacken(std::vector<stripe>& S_left, std::vector<interval> R2_LR);

/**
 * @brief Concatenates the two newly merged stripes by updating their x_intervals and x_unions
 * 
 * @param[in] S_left The stripes on the left side
 * @param[in] S_right The stripes on the right side
 * @param[in] P The list of all y-coordinates
 * @param[in] x_ext The new x_interval of the merged stripes
 * 
 * @returns A list of stripes
 */
std::vector<stripe> concat(std::vector<stripe> S_left, std::vector<stripe> S_right, std::vector<coord> P, interval x_ext);

#endif