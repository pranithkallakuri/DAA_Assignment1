#include "stripes.hpp"
#include "utility.hpp"
#include <climits>
void stripes(std::vector<edge> V, interval x_ext, std::set<interval> L, std::set<interval> R, std::set<coord> P, std::vector<stripe> S){
    if(V.size()==1){
        auto it = V.begin();
        if((*it).side == left){ 
            L.insert((*it).int_val);
            R.clear();
        }
        else {
            R.insert((*it).int_val);
            L.clear();
        }
        P.insert(coord(LLONG_MAX));
        P.insert(coord((*it).int_val.bottom));
        P.insert(coord((*it).int_val.bottom));
        P.insert(coord(LLONG_MIN));
        for(interval s_int : partition(P)){
            interval ix = x_ext;
            interval iy = s_int;
            std::vector<interval> phi;
            S.push_back(stripe(ix, iy, phi));
        }
        std::vector<interval> phi;
        for(stripe int_s : S){
            auto top = int_s.y_interval.top;
            auto bottom = int_s.y_interval.bottom;
            auto itr = partition(P);
            if( (itr.find(interval(bottom, top)) != itr.end()) )
            {
                if((*it).side == left){
                    int_s.x_union.insert(interval(coord((*it).coord_val), coord(x_ext.top)));
                }
                else {
                    int_s.x_union.insert(interval(coord(x_ext.bottom), coord((*it).coord_val)));
                }
            }
        }
    }
    else{
        std::vector<edge> V1;
        std::vector<edge> V2;
        std::set<interval> L1;
        std::set<interval> L2;
        std::set<interval> R1;
        std::set<interval> R2;
        std::set<coord> P1;
        std::set<coord> P2;
        std::vector<stripe> S1;
        std::vector<stripe> S2;
        std::vector<stripe> S_left;
        std::vector<stripe> S_right;
        long long int xm;
        // logic for xm
        long long int cntr =1;
        if(V[(V.size())/2].coord_val != V[(V.size())/2 + 1].coord_val){
            xm =( V[(V.size())/2].coord_val + V[(V.size())/2 + 1].coord_val )/2;
        }
        else{
            // to be continued
        }
        stripes(V1, interval(coord(x_ext.bottom), coord(xm)), L1, R1, P1, S1);
        stripes(V1, interval(coord(xm), coord(x_ext.top)), L2, R2, P2, S2);
        merge(L, R, L1, R1, L2, R2, P, P1, P2, S, S1, S2, S_left, S_right, x_ext, xm);
    }
}

void merge(std::set<interval> L, std::set<interval> R,std::set<interval> L1, std::set<interval> R1,std::set<interval> L2, std::set<interval> R2,std::set<coord> P,std::set<coord> P1,std::set<coord> P2,
std::vector<stripe> S,std::vector<stripe> S1,std::vector<stripe> S2,std::vector<stripe> S_left,std::vector<stripe> S_right , interval x_ext ,long long int xm)
{
    std::set<interval> LR ,R2_LR , L1_LR;
    for(auto it=L1.begin(); it!=L1.end();it++)
    {
        if(R2.find(*it)!=R2.end())
        {
            LR.insert(*it);
        }
    }
    // computing L
    for(auto it=L1.begin(); it != L1.end(); it++)
    {
        if(LR.find(*it) == LR.end())
        {
            L.insert(*it);
            L1_LR.insert(*it);
        }
    }
    for(auto it=L2.begin(); it != L2.end(); it++)
    {
        L.insert(*it);
    }

    // Computing R

    for(auto it=R2.begin(); it != R2.end(); it++)
    {
        if(LR.find(*it) == LR.end())
        {
            R.insert(*it);
            R2_LR.insert(*it);
        }
    }
    for(auto it=R1.begin(); it != R1.end(); it++)
    {
        L.insert(*it);
    }

    // Computing P
    for(auto it=P1.begin(); it != P1.end(); it++)
    {
        P.insert(*it);
    }
    for(auto it=P2.begin(); it != P2.end(); it++)
    {
        P.insert(*it);
    }

    // Computing S_left
    S_left = copy(S1, P, interval(coord(x_ext.bottom), coord(xm)));
    S_right = copy(S2, P, interval(coord(xm), coord(x_ext.bottom)));

    blacken(S_left,R2_LR);
    blacken(S_right,L1_LR);

    S = concat(S_left, S_right, P, x_ext);


}