#include "utility.hpp"
#include<vector>
#include<map>
#include<iostream>
#include <queue>
#include <algorithm>
//#include <bits/stdc++.h>
std::vector<edge> vertical(std::vector<stripe> S, std::vector<edge> contour){
    
    // std::vector<edge> contours;
    // for(stripe s : S)
    // {
    //     long long int left_end = 0, right_end = 0;
    //     ctree* node = s.tree;
    //     ctree* prev = NULL;
    //     while(node != NULL)
    //     {
    //         prev = node;
    //         node = node->lson;
    //     }
    //     if(prev != NULL && prev->side != lru::u)
    //     {
    //         left_end = prev->x;
    //         contours.push_back(edge(s.y_interval, left_end, edgetype(0)));
    //     }

    //     node = s.tree;
    //     prev = NULL;
    //     while(node != NULL)
    //     {
    //         prev = node;
    //         node = node->rson;
    //     }
    //     if(prev != NULL && prev->side != lru::u)
    //     {
    //         right_end = prev->x;
    //         if(right_end != left_end)
    //             contours.push_back(edge(s.y_interval, right_end, edgetype(0)));
    //     }
    // }

    // return contours;
    std::map
    <
        long long int, std::priority_queue
        <
            std::pair<long long int, long long int>, 
            std::vector
            <
                std::pair<long long int, long long int>
            >, 
            std::greater
            <
                std::pair<long long int, long long int>
            >
        >
    > t1;
    for(edge e : contour)
        t1[e.coord_val.val].push({e.int_val.bottom.val, e.int_val.top.val});

    std::cout << "t1 size = " << t1.size() << "\n";
    std::vector<edge> updated_contours;
    for(auto m : t1)
    {
        auto pq = m.second;
        std::cout << "m.second.size() = " << pq.size() << "\n";
        while(pq.size() != 0)
        {
            std::pair<long long int, long long int> top = pq.top();
            pq.pop();
            long long int left = top.first, right = top.second;
            while(pq.size() != 0 && right >= pq.top().first)
            {
                right = std::max(right, pq.top().second);
                pq.pop();
            }
            updated_contours.push_back(edge(interval(coord(left), coord(right)), m.first, (edgetype)(0)));
            //std::cout << "PUSHED\n";
        }
    }

    std::cout << "updated_contours size = " << updated_contours.size() << "\n";
    std::map<long long int, std::set<long long int>> cnt;

    for(edge h: updated_contours){
       cnt[h.int_val.top.val].insert(h.coord_val.val);
       cnt[h.int_val.bottom.val].insert(h.coord_val.val);
    }
    std::vector<edge> contours;
    for(auto x : cnt){
       auto s_itr = cnt[x.first].begin();
       while(s_itr != cnt[x.first].end())
       {
           if((++s_itr) == cnt[x.first].end()) break;
           --s_itr;
           std::cout << "bottom = " << *s_itr << " ";
           long long int bottom = *s_itr;
           ++s_itr;
           long long int top = *s_itr;
           std::cout << "top = " << *s_itr << "\n";
           contours.push_back(edge(interval(coord(bottom), coord(top)), x.first, (edgetype)(0)));
           
           ++s_itr;
       }
   }
   std::cout << "HERE\n";
   return contours;
}