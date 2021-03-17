#include "utility.hpp"
#include <iostream>

coord::coord(long long int val) : val(val) {}

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
// coord coord::operator+(const coord& other) const{
//     long long int a1 = this-> val;
//     long long int a2 = other.val;
//     long long int sum = a1+a2;
//     coord x(sum);
//     return x;
// }

// coord coord::operator-(const coord& other) const{
//     return (coord(this->val - other.val));
// }

bool coord::operator<=(const coord& other) const{
    return (this->val <= other.val);
}

bool coord::operator>=(const coord& other) const{
    return (this->val >= other.val);
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
    if(this->coord_val == other.coord_val)
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


void blacken(std::vector<stripe>& S, std::set<interval> J){
    // std::set<coord> D;
    // std::set<coord> T;
    // for(interval i : J){
    //     D.insert(i.bottom);
    //     T.insert(i.top);
    // }
    // for(stripe s : S){
    //     auto it_top = T.upper_bound(s.y_interval.top);
    //     if(it_top == T.end()){
    //         auto it_top_sub = T.lower_bound(s.y_interval.top);
    //         if((*it_top_sub)==s.y_interval.top){
    //             it_top = it_top_sub;
    //         }
    //         else continue;
    //     }
    //     auto it_down = D.upper_bound(s.y_interval.bottom);
    //     if(it_down == D.begin()){
    //         continue;
    //     }
    //     else it_down = --(it_down);

    // }
    for(auto it = S.begin(); it!= S.end(); it++){
        for(interval i : J){
            if((*(it)).y_interval.bottom>=i.bottom && (*(it)).y_interval.top<=i.top){
                (*it).x_union.clear();
                (*(it)).x_union.insert((*it).x_interval);
                break;
            }
        }
    }
}

std::vector<stripe> copy(std::vector<stripe> Sdash, std::set<coord> P, interval interval_val){
    int lll = 0;
    for(stripe s : Sdash)
    {
        std::cout << "------------------------------\n";
        std::cout<<"X interval ("<<s.x_interval.bottom.val <<" , "<<s.x_interval.top.val<<")\n";
        std::cout<<"y interval ("<<s.y_interval.bottom.val <<" , "<<s.y_interval.top.val<<")\n";
        std::cout << "Stripe " << lll++ << "\n";
        for(interval x : s.x_union)
        {
            std::cout << "(" << x.bottom.val << ", " << x.top.val << ")\n";
        }
    }
    std::cout << "########################################\n";
    std::cout<<"Partition details size:- " << P.size()<<"\n";
    for(coord c : P){
        std::cout<<c.val<<"\n";
    }
    std::cout<<"##################Parition ended\n";
    std::vector<stripe> S;
    std::set<interval> it_P = partition(P);
    lll =0;
    for(interval s_int : it_P){
            interval ix = interval_val;
            interval iy = s_int;
            std::set<interval> phi;
            S.push_back(stripe(ix, iy, phi));
        }
        int idash =0;
        std::cout<<"S Size"<<S.size()<<"\n";
        for(int i=0;i<S.size(); ){
            while(i<S.size() && S[i].y_interval.bottom.val>=Sdash[idash].y_interval.bottom.val && S[i].y_interval.top.val <= Sdash[idash].y_interval.top.val){
                S[i].x_union = Sdash[idash].x_union;
                i++;
                //std::cout<<"upcoming s y interval ("<<S[i].y_interval.bottom.val<<" , "<<S[i].y_interval.top.val<<")\n";
            }
            idash++;
            //std::cout<<"upcoming sdash y interval ("<<Sdash[i].y_interval.bottom.val<<" , "<<Sdash[i].y_interval.top.val<<")\n";
        }
        //std::cout<<"Size of S- "<<S.size()<<"\n";
        int lllll = 0;
        //for(stripe s : S)
        //{
        //   std::cout << "------------------------------\n";
        //    std::cout << "Stripe " << lllll++ << "\n";
        //    for(interval x : s.x_union)
        //    {
        //        std::cout << "(" << x.bottom.val << ", " << x.top.val << ")\n";
        //    }
        //}
        return S;
}

std::vector<stripe> concat(std::vector<stripe> S_left, std::vector<stripe> S_right, std::set<coord> P, interval x_ext){
    std::cout<<"S_left details\n";
    int abcde=0;
    for(stripe s : S_left){
        std::cout<<"S_left "<<abcde++<<"\n";
        for(interval i : s.x_union){
            std::cout<<"( "<<i.bottom.val << " , "<<i.top.val<<")\n";
        }
    }
    std::cout<<"S_right details\n";
    abcde=0;
    for(stripe s : S_right){
        std::cout<<"S_rightt "<<abcde++<<"\n";
        for(interval i : s.x_union){
            std::cout<<"( "<<i.bottom.val << " , "<<i.top.val<<")\n";
        }
    }
    std::vector<stripe> S;
    std::set<interval> it_P = partition(P);
    for(interval s_int : it_P){
            interval ix = x_ext;
            interval iy = s_int;
            std::set<interval> phi;
            S.push_back(stripe(ix, iy, phi));
        }
    for(int i=0; i<S.size(); i++){
        std::set<interval> phi;
        if(S_left[i].x_union.size() == 0)
        {
            phi = S_right[i].x_union;
            S[i].x_union = phi;
            std::cout<<"x_union of Stripe "<<i<<"\n";
            for(interval i : S[i].x_union){
                std::cout<<"( "<<i.bottom.val<<" , "<<i.top.val<<")\n";
            }
            std::cout<<"x_union of Stripe "<<i<<" ends\n";
            continue;
        }
        if(S_right[i].x_union.size() == 0)
        {
            phi = S_left[i].x_union;
            S[i].x_union = phi;
            std::cout<<"x_union of Stripe "<<i<<"\n";
            for(interval i : S[i].x_union){
                std::cout<<"( "<<i.bottom.val<<" , "<<i.top.val<<")\n";
            }
            std::cout<<"x_union of Stripe "<<i<<" ends\n";
            continue;
        }
        auto it_left = S_left[i].x_union.end();
        auto it_right = S_right[i].x_union.begin();
        it_left--;
        if((*it_left).top != (*it_right).bottom){
            for(interval i : S_left[i].x_union){
                phi.insert(i);
            }
            for(interval i : S_right[i].x_union){
                phi.insert(i);
            }
        }
        else{
            for(auto it = S_left[i].x_union.begin() ; it!= --(S_left[i].x_union.end()) ; it++){
                phi.insert(*it);
            }
            for(auto it = ++(S_right[i].x_union.begin()) ; it!= (S_right[i].x_union.end()) ; it++){
                phi.insert(*it);
            }
            phi.insert(interval((*it_left).bottom, (*it_right).top));
        }
        S[i].x_union = phi;
        std::cout<<"x_union of Stripe "<<i<<"\n";
        for(interval i : S[i].x_union){
            std::cout<<"( "<<i.bottom.val<<" , "<<i.top.val<<")\n";
        }
        std::cout<<"x_union of Stripe "<<i<<" ends\n";
        
    }
    std::cout<<"Concat details(Only x_union)-----------\n";
    int abc =0;
    for(stripe s: S){
        std::cout<<"Stripe " <<abc++ <<"\n";
        for(interval i : s.x_union){
            std::cout<<"( " << i.bottom.val << ", "<<i.top.val <<" )\n";
        }
    }
    std::cout<<"Concat ended-------------------\n";
    return S;
}



