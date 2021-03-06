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

// edge::edge(const edge& other)
// {
//     this->int_val = interval(coord(other.int_val.bottom.val), coord(other.int_val.top.val));
//     this->coord_val = coord(other.coord_val.val);
//     this->side = other.side;
// }

ctree::ctree(long long int x, lru side, ctree* lson, ctree* rson) : x(x), side(side), lson(lson), rson(rson) {}

// bool edge::operator<(const edge& other) const
// {
//     if(this->coord_val == other.coord_val)
//     {
//         return ((int)this->side - (int)edgetype::left) == 0;
//     }
//     else
//         return this->coord_val < other.coord_val;
// }
// edge& edge::operator=(const edge& other)
// {
//     this->int_val.bottom = other.int_val.bottom;
//     this->int_val.top = other.int_val.top;
//     this->coord_val.val = other.coord_val.val;
//     this->side = other.side;
//     return *this;
// } 

stripe::stripe(interval x_interval, interval y_interval, std::vector<interval> x_union) : x_interval(x_interval), y_interval(y_interval), x_union(x_union) {}



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

std::vector<interval> partition(std::vector<coord> Y)
{
    std::vector<interval> vect;
    coord prev = *Y.begin();
    for(auto it = ++Y.begin(); it != Y.end(); ++it)
    {
        coord bottom = prev;
        coord top = *it;
        interval i(bottom, top);
        vect.push_back(i);       // need to check
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


void blacken(std::vector<stripe>& S, std::vector<interval> J){
    // for(auto it = S.begin(); it!= S.end(); it++){
    //     for(interval i : J){
    //         if((*(it)).y_interval.bottom>=i.bottom && (*(it)).y_interval.top<=i.top){
    //             (*it).x_union.clear();
    //             (*(it)).x_union.insert((*it).x_interval);
    //             break;
    //         }
    //     }
    // }

    //Iterate over each edge
    auto s_it = S.begin();
    bool in = 0;
    auto i = J.begin();
    while(i != J.end())
    {
        while((*i).bottom > (*s_it).y_interval.bottom) s_it++;

        if((*i).bottom <= (*s_it).y_interval.bottom) in = 1;
        if((*i).top < (*s_it).y_interval.top) in = 0;
        if(in == 1)
        {
            (*s_it).x_union.clear();
            (*s_it).x_union.push_back((*s_it).x_interval);     // need to check
            (*s_it).x_measure = (unsigned long long int)((*s_it).x_interval.top.val - (*s_it).x_interval.bottom.val);
            (*s_it).tree = NULL; 
            s_it++;
        }
        else i++; 
    }
}

std::vector<stripe> copy(std::vector<stripe> Sdash, std::vector<coord> P, interval interval_val){
    int lll = 0;
    //for(stripe s : Sdash)
    //{
    //    std::cout << "------------------------------\n";
     //   std::cout<<"X interval ("<<s.x_interval.bottom.val <<" , "<<s.x_interval.top.val<<")\n";
    //    std::cout<<"y interval ("<<s.y_interval.bottom.val <<" , "<<s.y_interval.top.val<<")\n";
    //    std::cout << "Stripe " << lll++ << "\n";
    //    for(interval x : s.x_union)
    //    {
    //        std::cout << "(" << x.bottom.val << ", " << x.top.val << ")\n";
    //    }
    //}
    //std::cout << "########################################\n";
    //std::cout<<"Partition details size:- " << P.size()<<"\n";
    //for(coord c : P){
    //    std::cout<<c.val<<"\n";
   // }
    //std::cout<<"##################Parition ended\n";
    std::vector<stripe> S;
    std::vector<interval> it_P = partition(P);
    lll =0;
    for(interval s_int : it_P)
    {
        //std::cout << "y_interval width = " << "(" << s_int.bottom.val << ", " << s_int.top.val << ")" << "\n";
        interval ix = interval_val;
        interval iy = s_int;
        std::vector<interval> phi;
        S.push_back(stripe(ix, iy, phi));
    }
    int idash =0;
    //std::cout<<"S Size "<<S.size()<<"\n";
    //std::cout<<"Sdash Size "<<Sdash.size()<<"\n";
    for(int i=0;i<S.size(); ){
        while(i<S.size() && S[i].y_interval.bottom.val>=Sdash[idash].y_interval.bottom.val && S[i].y_interval.top.val <= Sdash[idash].y_interval.top.val){
            S[i].x_union = Sdash[idash].x_union;
            S[i].x_measure = Sdash[idash].x_measure;
            S[i].tree = Sdash[idash].tree;
            i++;
            //std::cout << "i = " << i << "\n";
            //std::cout<<"upcoming s y interval ("<<S[i].y_interval.bottom.val<<" , "<<S[i].y_interval.top.val<<")\n";
        }
        idash++;
        //std::cout << "idash = " << idash << "\n";
        //std::cout<<"upcoming sdash y interval ("<<Sdash[i].y_interval.bottom.val<<" , "<<Sdash[i].y_interval.top.val<<")\n";
    }
    //std::cout<<"Size of S- "<<S.size()<<"\n";
    //int lllll = 0;
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

std::vector<stripe> concat(std::vector<stripe> S_left, std::vector<stripe> S_right, std::vector<coord> P, interval x_ext){
    //std::cout<<"S_left details\n";
    int abcde=0;
    //for(stripe s : S_left){
     //   std::cout<<"S_left "<<abcde++<<"\n";
     //   for(interval i : s.x_union){
     //       std::cout<<"( "<<i.bottom.val << " , "<<i.top.val<<")\n";
      //  }
    //}
   //std::cout<<"S_right details\n";
    abcde=0;
    //for(stripe s : S_right){
     //   std::cout<<"S_rightt "<<abcde++<<"\n";
        //for(interval i : s.x_union){
        //    std::cout<<"( "<<i.bottom.val << " , "<<i.top.val<<")\n";
        //}
    //}
    std::vector<stripe> S;
    std::vector<interval> it_P = partition(P);
    for(interval s_int : it_P){
            interval ix = x_ext;
            interval iy = s_int;
            std::vector<interval> phi;
            S.push_back(stripe(ix, iy, phi));
        }
    for(int i=0; i<S.size(); i++){
        std::vector<interval> phi;
        if(S_left[i].x_union.size() == 0)
        {
            phi = S_right[i].x_union;
            S[i].x_union = phi;
            S[i].x_measure = S_right[i].x_measure;
            S[i].tree = S_right[i].tree;
            //std::cout<<"x_union of Stripe "<<i<<"\n";
            //for(interval i : S[i].x_union){
            //    std::cout<<"( "<<i.bottom.val<<" , "<<i.top.val<<")\n";
            //}
            //std::cout<<"x_union of Stripe "<<i<<" ends\n";
            continue;
        }
        if(S_right[i].x_union.size() == 0)
        {
            phi = S_left[i].x_union;
            S[i].x_union = phi;
            S[i].x_measure = S_left[i].x_measure;
            S[i].tree = S_left[i].tree;
            //std::cout<<"x_union of Stripe "<<i<<"\n";
            //for(interval i : S[i].x_union){
            //    std::cout<<"( "<<i.bottom.val<<" , "<<i.top.val<<")\n";
            //}
            //std::cout<<"x_union of Stripe "<<i<<" ends\n";
            continue;
        }
        auto it_left = S_left[i].x_union.end();
        auto it_right = S_right[i].x_union.begin();
        it_left--;
        if((*it_left).top != (*it_right).bottom){
            for(interval i : S_left[i].x_union){
                phi.push_back(i);                 // need to check
            }
            for(interval i : S_right[i].x_union){
                phi.push_back(i);                 // need to check
            }
        }
        else{
            for(auto it = S_left[i].x_union.begin() ; it!= --(S_left[i].x_union.end()) ; it++){
                phi.push_back(*it);              // need to check
            }
            for(auto it = ++(S_right[i].x_union.begin()) ; it!= (S_right[i].x_union.end()) ; it++){
                phi.push_back(*it);                // need to check
            }
            phi.push_back(interval((*it_left).bottom, (*it_right).top));   // need to check
        }
        S[i].x_union = phi;
        S[i].x_measure = S_left[i].x_measure + S_right[i].x_measure;
        //ctree treee(S_left[i].x_interval.top.val, lru::u, S_left[i].tree, S_right[i].tree);
        //S[i].tree = &treee;
        S[i].tree = (ctree *)malloc(sizeof(ctree));
        S[i].tree->x = S_left[i].x_interval.top.val;
        S[i].tree->side = lru::u; 
        S[i].tree->lson = S_left[i].tree;
        S[i].tree->rson = S_right[i].tree;
        //std::cout<<"x_union of Stripe "<<i<<"\n";
        //for(interval i : S[i].x_union){
         //   std::cout<<"( "<<i.bottom.val<<" , "<<i.top.val<<")\n";
        //}
       // std::cout<<"x_union of Stripe "<<i<<" ends\n";
        
    }
    //std::cout<<"Concat details(Only x_union)-----------\n";
    //int abc =0;
    //for(stripe s: S){
       // std::cout<<"Stripe " <<abc++ <<"\n";
      //  for(interval i : s.x_union){
      //      std::cout<<"( " << i.bottom.val << ", "<<i.top.val <<" )\n";
       // }
    //}
    //std::cout<<"Concat ended-------------------\n";
    return S;
}



