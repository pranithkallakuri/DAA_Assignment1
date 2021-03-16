#include "utility.hpp"

coord::coord(long long int inp) : val(val) {}

bool coord::operator<(const coord& other) const
{
    return this->val < other.val;
}

bool coord::operator>(const coord& other) const
{
    return this->val > other.val;
}

bool coord::operator==(const coord& other) const
{
    return (this->val == other.val);
}

bool coord::operator!=(const coord& other) const
{
    return (this->val != other.val);
}
bool coord::operator+(const coord& other) const{
    return (this->val + other.val);
}

point::point(coord x, coord y) : x(x), y(y) {}

interval::interval(coord bottom, coord top) : bottom(bottom), top(top) {}

bool interval::operator<(const interval& other) const
{
    if(this->bottom == other.bottom)
    {
        return this->top < other.top;
    }
    else return this->bottom < other.bottom;
}

bool interval::operator==(const interval& other) const
{
    return (this->bottom == other.bottom) && (this->top == other.top);
}

line_segment::line_segment(interval int_val, coord coord_val) : int_val(int_val), coord_val(coord_val) {}

rectangle::rectangle(coord l, coord r, coord b, coord t) : x_left(l), x_right(r), y_bottom(b), y_top(t) {}

edge::edge(interval int_val, coord coord_val, edgetype side) : int_val(int_val), coord_val(coord_val), side(side) {}

bool edge::operator<(const edge& other) const
{
    if((this->int_val == other.int_val) && (this->coord_val == other.coord_val))
    {
        return this->side == left;
    }
    else
        return this->coord_val < other.coord_val;
} 

stripe::stripe(interval x_interval, interval y_interval, std::set<interval> x_union) : x_interval(x_interval), y_interval(y_interval), x_union(x_union) {}



// std::vector<rectangle> union_(std::vector<rectangle> R)
// {

// }

std::set<coord> y_set(std::vector<rectangle> R)
{
    std::set<coord> s;
    for(rectangle r : R)
    {
        s.insert(r.y_bottom);
        s.insert(r.y_top);
    }
    return s;
}

std::set<interval> partition(std::set<coord> Y)
{
    std::set<interval> vect;
    coord prev = *Y.begin();
    for(auto it = ++Y.begin(); it != Y.end(); ++it)
    {
        coord bottom = prev;
        coord top = *it;
        interval i(bottom, top);
        vect.insert(i);
        prev = top;
    }
    return vect;
}

// std::vector<coord> x_proj(std::vector<point> points)
// {

// }

// std::vector<interval> intervals(std::vector<coord> coords)
// {

// } 

void blacken(std::vector<stripe> S, std::set<interval> J){
    for(stripe s : S){

    }
}
