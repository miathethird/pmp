#pragma once
#include <vector>
#include <iostream>
namespace pmp
{
    void quick_sort(std::vector<int>& to_sort);
    int partition(std::vector<int>& to_sort, int left, int pivot);
    void q_sort(std::vector<int>& to_sort, int left, int right);
} // namespace pmp