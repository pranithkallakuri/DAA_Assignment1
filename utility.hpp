#ifndef __UTILITY
#define __UTILITY

#include <vector>
#include <set>
class coord
{
    public:
    long long int val;

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

class point
{
    public:
    coord x, y;

    point(coord x, coord y);
};

class interval
{
    public:
    coord bottom, top;

    interval(coord bottom, coord top);
    bool operator<(const interval& other) const;
    bool operator==(const interval& other) const;
    
};

class line_segment
{
    public:
    interval int_val;
    coord coord_val;

    line_segment(interval int_val, coord coord_val);
};

class rectangle
{
    public:
    coord x_left;
    coord x_right;
    coord y_bottom;
    coord y_top;

    rectangle(coord l, coord r, coord b, coord t);
};

enum edgetype{left, right, bottom, top};
// edgetype val = left;

class edge
{
    public:
    interval int_val;
    coord coord_val;
    edgetype side;

    edge(interval int_val, coord coord_val, edgetype side);
    bool operator<(const edge& other) const;
};

enum lru{l, r, u};

class ctree
{
    public:
    long long int x;
    lru side;
    ctree *lson = NULL;
    ctree *rson = NULL;
    ctree(long long int x, lru side, ctree* lson, ctree* rson);
};

class stripe
{
    public:
    interval x_interval, y_interval;    
    std::vector<interval> x_union;
    unsigned long long int x_measure = 0;
    ctree *tree = NULL;

    stripe(interval x_interval, interval y_interval, std::vector<interval> x_union);
};


//std::vector<rectangle> union_(std::vector<rectangle> R);

std::set<coord> y_set(std::vector<rectangle> R);

std::vector<interval> partition(std::vector<coord> Y);

//std::vector<coord> x_proj(std::vector<point> points);

//std::vector<interval> intervals(std::vector<coord> coords);

std::vector<stripe> copy(std::vector<stripe> S, std::vector<coord> P, interval interval_val);


void blacken(std::vector<stripe>& S_left, std::vector<interval> R2_LR);


std::vector<stripe> concat(std::vector<stripe> S_left, std::vector<stripe> S_right, std::vector<coord> P, interval x_ext);

#endif