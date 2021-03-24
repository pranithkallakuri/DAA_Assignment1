#include "contour.hpp"
#include <set>
#include<algorithm>
#include <vector>

void search_tree(std::vector<std::pair<long long int, lru>>& nodes, ctree* root, long long int left, long long int right)
{
    if(root==NULL) return;

    if(root->x >= left && root->x <= right)
    {
        if(root->lson == NULL && root->rson == NULL)
            nodes.push_back({root->x, root->side});
        search_tree(nodes, root->lson, left, right);
        search_tree(nodes, root->rson, left, right);
    }

    if(left > root->x)
        search_tree(nodes, root->rson, left, right);

    if(right < root->x)
        search_tree(nodes, root->lson, left, right);

}

std::set<interval> contour(std::set<edge> H, std::vector<stripe> S){
     std::vector<long long int> bottom_int;
     std::vector<long long int> top_int;
     for(stripe s: S){
         bottom_int.push_back(s.y_interval.bottom.val);
         top_int.push_back(s.y_interval.top.val);
     }
     std::set<interval> contours;
     for(edge h: H){
         for(interval sub_h : contour_pieces(h, S, bottom_int, top_int)){
            contours.insert(sub_h);
         }
     }
     return contours;
}
std::vector<interval> contour_pieces(edge h, std::vector<stripe> S, std::vector<long long int>bottom_int, std::vector<long long int> top_int){
    int index;
    if(h.side == edgetype::bottom){
       auto it = lower_bound(top_int.begin(), top_int.end(), h.coord_val.val);
       index = it - top_int.begin();
    }
    else{
        auto it = lower_bound(bottom_int.begin(), bottom_int.end(), h.coord_val.val) ;
        index = it - bottom_int.begin();
    }
    // index
    std::vector<std::pair<long long int, lru>> nodes; 
    search_tree(nodes, S[index].tree, h.int_val.bottom.val, h.int_val.top.val);
    std::vector<interval> contours;
    if(nodes.size() == 0) return contours;
    if(nodes[0].second == lru::l)
        contours.push_back(interval(coord(h.int_val.bottom.val), coord(nodes[0].first)));

    for(int i = 2; i < (int)nodes.size(); i++)
    {
        if(nodes[i].second == lru::l && nodes[i-1].second == lru::r)
            contours.push_back(interval(coord(nodes[i-1].first), coord(nodes[i].first)));
    }
    int last_ind = (int)nodes.size()-1;
    if(nodes[last_ind].second == lru::r)
        contours.push_back(interval(coord(nodes[last_ind].first), coord(h.int_val.top.val)));

    return contours;
}