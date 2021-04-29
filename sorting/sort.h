#pragma once
#include <vector>
#include <iostream>
namespace pmp
{
    void quick_sort(std::vector<int>& to_sort);
    int partition(std::vector<int>& to_sort, int left, int pivot);
    void q_sort(std::vector<int>& to_sort, int left, int right);
    void merge_sort(std::vector<int>& to_sort);
    void m_sort(std::vector<int>& to_sort, int l, int r);
    void merge(std::vector<int>& to_sort, int l, int m, int r);
    void heap_sort(std::vector<int>& to_sort);
    void heapify(std::vector<int>& to_sort, int heapsize, int parent);
} // namespace pmp