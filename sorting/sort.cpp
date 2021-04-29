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

void pmp::merge(std::vector<int>& to_sort, int l, int m, int r)
{
    //std::cout << "begin merge: " << l << " " << m << " " << r << std::endl;

    int n1 = m-l+1;
    int n2 = r-m;

    int temp[n1+n2];

    //copy to_sort to temp arrays

    int i = l;
    int j = m+1;
    int k = 0;
    while((i<=m) && (j<=r))
    {
        if(to_sort[i] <= to_sort[j])
        {
            temp[k] = to_sort[i];
            i++;
        }
        else
        {
            temp[k] = to_sort[j];
            j++;
        }
        k++;
    }

    if(j>r) //all elements from m to r have been placed in temp arr so copy remaining from l to m
    {
        while(i<=m)
        {
            temp[k] = to_sort[i];
            i++;
            k++;
        }
    }
    else //all elements from l to m have been placed in temp arr so copy remaining from m+1 to r
    {
        while(j<=r)
        {
            temp[k] = to_sort[j];
            j++;
            k++;
        }
    }

    for(int i = 0; i<k; i++)
    {
        to_sort[i+l] = temp[i];
    }
}

void pmp::m_sort(std::vector<int>& to_sort, int l, int r)
{
    if (l>=r) return;
    int m = l+(r-l)/2;
    m_sort(to_sort, l,m);
    m_sort(to_sort, m+1,r);
    merge(to_sort, l , m, r);
}

void pmp::merge_sort(std::vector<int>& to_sort)
{
    int l = 0;
    int r = to_sort.size()-1;
    
    m_sort(to_sort, l, r);
}

void pmp::heapify(std::vector<int>& to_sort, int heapsize, int parent)
{
    int largest = parent;
    int left = 2*parent + 1;
    int right = 2*parent + 2;
    if(left<heapsize && to_sort[left] > to_sort[largest]) largest = left;
    if (right<heapsize && to_sort[right] > to_sort[largest]) largest = right;

    if(largest!=parent)
    {
        std::swap(to_sort[largest], to_sort[parent]);
        heapify(to_sort, heapsize, largest);
    }
}

void pmp::heap_sort(std::vector<int>& to_sort)
{
    int non_leaf_node_max = to_sort.size()/2-1;
    int heapsize = to_sort.size();
    for (int i = non_leaf_node_max; i>=0; i--) heapify(to_sort, heapsize, i);

    
    while(heapsize)
    {
        std::swap(to_sort[0],to_sort[--heapsize]);
        heapify(to_sort, heapsize, 0);
    }
}