//#include <vector>
#include "sort.h"
#include <algorithm>
#include <random>
#include <exception>

int main()
{
    std::vector<int> to_sort;
    //std::default_random_engine generator; //not true random
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(-9999,9999);
    for(int i = 0; i<100000; i++)
    {
        to_sort.push_back(distribution(generator));
    }

    //pmp::quick_sort(to_sort);
    //pmp::merge_sort(to_sort);
    pmp::heap_sort(to_sort);



    for(int i = 0; i<to_sort.size()-1; i++)
    {

        try{
            if(to_sort[i] > to_sort[i+1]) throw std::logic_error("sorting failed");
        }
        catch (const std::logic_error& e)
        {
            std::cout << e.what() << std::endl;
            throw e;
        }
    }
    
    return 0;
}