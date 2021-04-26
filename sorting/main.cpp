//#include <vector>
#include "sort.h"
#include <algorithm>

int main()
{
    std::vector<int> to_sort = {76,75,74,73,72,71,96,95,94,91,44,55,66,77,88,99,80};
    std::vector<int> to_sort2 = {76,75,74,73,72,71,96,95,94,91,44,55,66,77,88,99,80};
    //std::vector<int> to_sort = {11,10,9,8,7,6,5,4,3,2,1};
    pmp::quick_sort(to_sort);
    std::sort(to_sort2.begin(), to_sort2.end());
    for(int i : to_sort) std::cout << i << " ";
    std::cout << std::endl;
    for(int i : to_sort2) std::cout << i << " ";
    return 0;
}