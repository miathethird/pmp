#include "sort.h"

int pmp::partition(std::vector<int>& to_sort, int leftptr, int right)
{
    int pivot = to_sort[right];
    int rightptr = right-1;

    while(true)
    {
        while(to_sort[leftptr] <= pivot && leftptr<=rightptr) leftptr++;
        while(rightptr > leftptr && to_sort[rightptr] > pivot) rightptr--;
        if(leftptr < rightptr) std::swap(to_sort[leftptr],to_sort[rightptr]);
        else break;
    }
    std::swap(to_sort[leftptr],to_sort[right]);

    return leftptr;
}

void pmp::q_sort(std::vector<int>& to_sort, int left, int right)
{
    if(right-left <= 0) return;
    int pivot = partition(to_sort, left, right);
    q_sort(to_sort, left, pivot-1);
    q_sort(to_sort, pivot+1, right);
}

void pmp::quick_sort(std::vector<int>& to_sort)
{
    q_sort(to_sort, 0, to_sort.size()-1);
}