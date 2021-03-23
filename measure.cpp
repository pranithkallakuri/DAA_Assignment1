#include "measure.hpp"
#include "utility.hpp"
#include <iostream>
void print_tree(ctree* tree){
    if(tree==NULL) return;
    print_tree(tree->lson);
    std::cout<<tree->x<<" ";
    print_tree(tree->rson);
}
unsigned long long int measure(std::vector<stripe> S)
{
    unsigned long long int area = 0;
    //std::cout<<"hello\n";
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
        std::cout << "------------------------------\n";
        /*unsigned long long int x_measure = 0;
        for(auto x : s.x_union)
        {
            x_measure += (x.top.val - x.bottom.val);
        }*/
        area += s.x_measure * (s.y_interval.top.val - s.y_interval.bottom.val);
        std::cout << "x_measure = " << s.x_measure << "\n";
        std::cout << "y_measure = " << "(" << s.y_interval.top.val << " - " << s.y_interval.bottom.val << ")" << "\n";
        std::cout << "area = " << area << "\n";
        std::cout << "Inorder traversal = ";
        print_tree(s.tree);
        std::cout << "\n";
    }
    // std::cout<<"hello\n";
    return area;
}