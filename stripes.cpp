#include "stripes.hpp"
#include "utility.hpp"
#include <climits>
#include <iostream>
void merge(std::vector<interval>& L, std::vector<interval>& R,std::vector<interval> L1, std::vector<interval> R1,std::vector<interval> L2, std::vector<interval> R2,std::vector<coord>& P,std::vector<coord> P1,std::vector<coord> P2,
std::vector<stripe>& S,std::vector<stripe> S1,std::vector<stripe> S2, interval x_ext ,coord xm)
{
    // std::set<interval> LR ,R2_LR , L1_LR;
    // for(auto it=L1.begin(); it!=L1.end();it++)
    // {
    //     if(R2.find(*it)!=R2.end())
    //     {
    //         LR.insert(*it);
    //     }
    // }

    // Computing LR
    std::vector<interval> LR;
    //int p1=0;
    long long int j=0; long long int i = 0;
    while(i < L1.size() && j < R2.size())
    {
        if(L1[i] < R2[j]) i++;
        else if (R2[j] < L1[i]) j++;
        else
        {
            LR.push_back(L1[i]);
            i++;
            j++;
        }
    }
    std::cout << "merging--- L1 n L2 --DONE\n";
    // computing L
    // for(auto it=L1.begin(); it != L1.end(); it++)
    // {
    //     if(LR.find(*it) == LR.end())
    //     {
    //         L.insert(*it);
    //         L1_LR.insert(*it);
    //     }
    // }

    j=0; i =0;
    // {1,2,3,4,5} {-1, 1, 3, 5, 7, 8}   OUT {2, 4}

    std::vector<interval> L1_LR;
    while(i < L1.size())
    {
        while(j >= LR.size() && i < L1.size())
        { 
            L1_LR.push_back(L1[i]);
            i++;
        }
        //if( i >= L1.size()) break;
        while(i < L1.size() && j < LR.size() && L1[i] < LR[j])
        {
            L1_LR.push_back(L1[i]);
            i++;
        }
        while(i < L1.size() && j < LR.size() && LR[j] < L1[i])
            j++;

        if(i < L1.size() && j < LR.size() && L1[i] == LR[j])
        {
            i++;
            j++;
        }                
    }
    std::cout << "merging--- L1-LR --DONE\n";
    // for(auto it=L2.begin(); it != L2.end(); it++)
    // {
    //     L.insert(*it);
    // }
    j = 0; i = 0;
    while( i < L1_LR.size() && j < L2.size())
    {
        if(L1_LR[i] < L2[j])
        {
            L.push_back(L1_LR[i]);
            i++;
        }
        else if(L2[j] < L1_LR[i])
        {
            L.push_back(L2[j]);
            j++;
        }
        else
        {
            L.push_back(L2[j]);
            i++; j++;
        }
    }

    while(i < L1_LR.size())
    {
        L.push_back(L1_LR[i]);
        i++;
    }

    while(j < L2.size())
    {
        L.push_back(L2[j]);
        j++;
    }
    std::cout << "merging--- L1_lR u L2 --DONE\n";
    // Computing R

    // for(auto it=R2.begin(); it != R2.end(); it++)
    // {
    //     if(LR.find(*it) == LR.end())
    //     {
    //         R.insert(*it);
    //         R2_LR.insert(*it);
    //     }
    // }
    // for(auto it=R1.begin(); it != R1.end(); it++)
    // {
    //     R.insert(*it);
    // }
    std::vector<interval> R2_LR;

    j=0; i =0;
    //std::cout << "R2.size = " << R2.size() << " LR.size = " << LR.size() << "\n"; 
    while(i < R2.size())
    {
        //std::cout << "HERE0\n";
        //std::cout << "i = " << i << " " << "j = " << j << "\n";
        while(j >= LR.size() && i < R2.size())
        {
            R2_LR.push_back(R2[i]);
            i++;
        }
        //if( i >= L1.size()) break;
        //std::cout << "HERE1\n";
        while(i < R2.size() && j < LR.size() && R2[i] < LR[j])
        {
            R2_LR.push_back(R2[i]);
            i++;
        }
        //std::cout << "HERE2\n";
        while(i < R2.size() && j < LR.size() && LR[j] < R2[i])
            j++;
        //std::cout << "HERE3\n";
        if(i < R2.size() && j < LR.size() && R2[i] == LR[j])
        {
            i++;
            j++;
        }                
    }
    std::cout << "merging--- R2-LR --DONE\n";

    // for(auto it=L2.begin(); it != L2.end(); it++)
    // {
    //     L.insert(*it);
    // }
    j = 0; i = 0;
    while( i < R2_LR.size() && j < R1.size())
    {
        if(R2_LR[i] < R1[j])
        {
            R.push_back(R2_LR[i]);
            i++;
        }
        else if(R1[j] < R2_LR[i])
        {
            R.push_back(R1[j]);
            j++;
        }
        else
        {
            R.push_back(R1[j]);
            i++; j++;
        }
    }

    while(i < R2_LR.size())
    {
        R.push_back(R2_LR[i]);
        i++;
    }

    while(j < R1.size())
    {
        R.push_back(R1[j]);
        j++;
    }

    std::cout << "merging--- R1 U R2_LR --DONE\n";

    // Computing P
    // for(auto it=P1.begin(); it != P1.end(); it++)
    // {
    //     P.insert(*it);
    // }
    // for(auto it=P2.begin(); it != P2.end(); it++)
    // {
    //     P.insert(*it);
    // }
    j = 0; i = 0;
    while( i < P1.size() && j < P2.size())
    {
        if(P1[i] < P2[j])
        {
            P.push_back(P1[i]);
            i++;
        }
        else if(P2[j] < P1[i])
        {
            P.push_back(P2[j]);
            j++;
        }
        else
        {
            P.push_back(P2[j]);
            i++; j++;
        }
    }

    while(i < P1.size())
    {
        P.push_back(P1[i]);
        i++;
    }

    while(j < P2.size())
    {
        P.push_back(P2[j]);
        j++;
    }
    std::cout << "Printing P = P1 U P2" << "\n";
    std::cout << "P1 = \n";
    for(coord p : P1)
    {
        std::cout << p.val << "| ";
    }
    std::cout << "\nP2 = \n";
    for(coord p : P2)
    {
        std::cout << p.val << "| ";
    }
    std::cout << "\nP = \n";
    for(coord p : P)
    {
        std::cout << p.val << "| ";
    }
    std::cout << "merging--- P1 U P2 --DONE\n";
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
void stripes(std::vector<edge> V, interval x_ext, std::vector<interval>& L, std::vector<interval>& R, std::vector<coord>& P, std::vector<stripe>& S){
    if(V.size()==1){
        auto it = V.begin();
        if((*it).side == edgetype::left){ 
            L.push_back((*it).int_val);
            R.clear();
        }
        else {
            R.push_back((*it).int_val);
            L.clear();
        }
        P.push_back(coord(LLONG_MIN));
        P.push_back((*it).int_val.bottom);
        P.push_back((*it).int_val.top);
        P.push_back(coord(LLONG_MAX));
        
        auto itr = partition(P);
        for(interval s_int : itr){
            //std::cout << "itr_interval[i] = (" << s_int.bottom.val << ", " << s_int.top.val << ")\n";
            interval ix = x_ext;
            interval iy = s_int;
            std::vector<interval> phi;
            S.push_back(stripe(ix, iy, phi));
        }
        int cnt = 0;
        /* We find x_union from the partition intervals instead of the rectangle edges*/
        itr.erase(--itr.end());
        itr.erase(itr.begin());
        for(auto itr_s = S.begin(); itr_s != S.end(); itr_s++){
            // auto top = (*itr_s).y_interval.top;
            // auto bottom = (*itr_s).y_interval.bottom;
            
            if((*itr_s).y_interval == (*it).int_val)
            {
                std::cout << "count = " << cnt++ << "\n";
                if((*it).side == edgetype::left){
                    (*itr_s).x_union.push_back(interval((*it).coord_val, x_ext.top));
                    (*itr_s).x_measure = (unsigned long long int)(x_ext.top.val - (*it).coord_val.val);
                    //std::cout << "coord_val = " << (*it).coord_val.val << "\n";
                    (*itr_s).tree = (ctree *)malloc(sizeof(ctree));
                    (*itr_s).tree->x = (*it).coord_val.val;
                    (*itr_s).tree->side = lru::l;
                    (*itr_s).tree->lson = NULL;
                    (*itr_s).tree->rson = NULL;
                    printf("base case left tree ");
                    printf("%lld\n", (*itr_s).tree->x);
                }
                else {
                    (*itr_s).x_union.push_back(interval(x_ext.bottom, (*it).coord_val));
                    (*itr_s).x_measure = (unsigned long long int)((*it).coord_val.val - x_ext.bottom.val);
                    //std::cout << "coord_val = " << (*it).coord_val.val << "\n";
                    (*itr_s).tree = (ctree *)malloc(sizeof(ctree));
                    (*itr_s).tree->x = (*it).coord_val.val;
                    (*itr_s).tree->side = lru::r;
                    (*itr_s).tree->lson = NULL;
                    (*itr_s).tree->rson = NULL;
                    printf("base case right tree ");
                    printf("%lld\n", (*itr_s).tree->x);
                }
            }
        }
        std::cout << "----------------------------\n";
        std::cout << "START OF BASE CASE\n";
        int lllll = 0;
        for(stripe& s : S)
        {
            std::cout << "------------------------------\n";
            std::cout << "Stripe " << lllll++ << "\n";
            if(s.tree != NULL) std::cout << "ctree.x = " << (s.tree->x) << "\n";
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
        std::vector<interval> L1;
        std::vector<interval> L2;
        std::vector<interval> R1;
        std::vector<interval> R2;
        std::vector<coord> P1;
        std::vector<coord> P2;
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
