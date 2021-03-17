#include "stripes.hpp"
#include "utility.hpp"
#include <climits>
#include <iostream>
void merge(std::set<interval>& L, std::set<interval>& R,std::set<interval> L1, std::set<interval> R1,std::set<interval> L2, std::set<interval> R2,std::set<coord>& P,std::set<coord> P1,std::set<coord> P2,
std::vector<stripe>& S,std::vector<stripe> S1,std::vector<stripe> S2, interval x_ext ,coord xm)
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
        R.insert(*it);
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
    
    //std::cout << "WHAT THE GOWTHAM\n";

    // Computing S_left
    std::vector<stripe> S_left;
    std::vector<stripe> S_right;
    S_left = copy(S1, P, interval(x_ext.bottom, xm));
    //std::cout << "WHAT THE GOWTHAM2\n";
    S_right = copy(S2, P, interval(xm, x_ext.top));
    std::cout<<"before blacken only S_right\n";
    for(int i=0;i<S_right.size(); i++)
    {
        std::cout<<"Stripe_right "<<i<<"\n";
        std::cout<<"x-int ("<<S_right[i].x_interval.bottom.val<< " , "<<S_right[i].x_interval.top.val<<")\n";
    }
    blacken(S_left,R2_LR);
    //std::cout << "WHAT THE GOWTHAM3\n";
    blacken(S_right,L1_LR);
    //std::cout << "WHAT THE GOWTHAM4\n";
    S = concat(S_left, S_right, P, x_ext);

}
void stripes(std::vector<edge> V, interval x_ext, std::set<interval>& L, std::set<interval>& R, std::set<coord>& P, std::vector<stripe>& S){
    if(V.size()==1){
        auto it = V.begin();
        if((*it).side == edgetype::left){ 
            L.insert((*it).int_val);
            R.clear();
        }
        else {
            R.insert((*it).int_val);
            L.clear();
        }
        P.insert(coord(LLONG_MAX));
        P.insert((*it).int_val.bottom);
        P.insert((*it).int_val.top);
        P.insert(coord(LLONG_MIN));
        
        auto itr = partition(P);
        for(interval s_int : itr){
            //std::cout << "itr_interval[i] = (" << s_int.bottom.val << ", " << s_int.top.val << ")\n";
            interval ix = x_ext;
            interval iy = s_int;
            std::set<interval> phi;
            S.push_back(stripe(ix, iy, phi));
        }
        int cnt = 0;
        /* We find x_union from the partition intervals instead of the rectangle edges*/
        itr.erase(--itr.end());
        itr.erase(itr.begin());
        for(auto itr_s = S.begin(); itr_s != S.end(); itr_s++){
            // auto top = (*itr_s).y_interval.top;
            // auto bottom = (*itr_s).y_interval.bottom;
            
            if( (itr.find((*itr_s).y_interval) != itr.end()) )
            {
                std::cout << "count = " << cnt++ << "\n";
                if((*it).side == edgetype::left){
                    (*itr_s).x_union.insert(interval((*it).coord_val, x_ext.top));
                    (*itr_s).x_measure = (unsigned long long int)(x_ext.top.val - (*it).coord_val.val);
                     (*itr_s).tree = &ctree((*it).coord_val.val, lru::left, NULL, NULL);
                }
                else {
                    (*itr_s).x_union.insert(interval(x_ext.bottom, (*it).coord_val));
                    (*itr_s).x_measure = (unsigned long long int)((*it).coord_val.val - x_ext.bottom.val);
                    (*itr_s).tree = &ctree((*it).coord_val.val, lru::right, NULL, NULL);
                }
            }
        }
        std::cout << "----------------------------\n";
        std::cout << "START OF BASE CASE\n";
        int lllll = 0;
        for(stripe s : S)
        {
            std::cout << "------------------------------\n";
            std::cout << "Stripe " << lllll++ << "\n";
            std::cout << "x_interval = (" << s.x_interval.bottom.val << ", " << s.x_interval.top.val << ")\n";
            std::cout << "y_interval = (" << s.y_interval.bottom.val << ", " << s.y_interval.top.val << ")\n";
            for(interval x : s.x_union)
            {
                std::cout << "(" << x.bottom.val << ", " << x.top.val << ")\n";
            }
        }
        std::cout << "END OF BASE CASE\n";
        std::cout << "----------------------------\n";
    }
    else{
        std::cout << "inelse\n";
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

        coord xm(0);
        // logic for xm
        long long int cntr =1;
        std::cout << "wtf\n";
        std::cout << "V.size() = " << V.size() << "\n";
        long long int valuee = (V[(V.size())/2 - 1 ].coord_val.val + V[(V.size())/2].coord_val.val) / 2;
        xm.val = valuee;
        std::cout << "xm = " << xm.val << "\n";
        for(int i=0; i < V.size();i++){
            if(i<V.size()/2) V1.push_back(V[i]);
            else V2.push_back(V[i]);
        }
        std::cout << "v1.size()" << V1.size() << "\n";
        std::cout << "v2.size()" << V2.size() << "\n";
        stripes(V1, interval(x_ext.bottom, xm), L1, R1, P1, S1);
        stripes(V2, interval(xm, x_ext.top), L2, R2, P2, S2);
        std::cout<<"P1 before merge\n";
        for(coord c : P1){
            std::cout<<c.val<<"\n";
        }
        std::cout<<"P1 done\n";

        std::cout<<"P2 before merge\n";
        for(coord c : P2){
            std::cout<<c.val<<"\n";
        }
        std::cout<<"P2 done\n";
        
        std::cout<<"merging....................\n";
        merge(L, R, L1, R1, L2, R2, P, P1, P2, S, S1, S2, x_ext, xm);
        std::cout<<"merging done :) ....................\n";
        std::cout<<"P after merge\n";
        for(coord c : P){
            std::cout<<c.val<<"\n";
        }
        std::cout<<"P done\n";
    }
}
