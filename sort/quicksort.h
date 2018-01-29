#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "basesort.h"
#include <algorithm>

using namespace std;

namespace Sorting
{
    class QuickSort : public BaseSort
    {
    public:
        vector<int> sort(vector<int> list)
        {
            int n = list.size();
            quicksort(list, 0, n - 1);
            return list;
        }
    private:
        void quicksort(vector<int> &list, int left, int right)
        {
            if (left < right)
            {
                int pivot = partition(list, left, right);
                
                quicksort(list, left, pivot - 1);
                quicksort(list, pivot + 1, right);
            }
        }
        /*
         * Selects a pivot, moves items smaller to the left of the pivot and
         * moves items larger to the right of the pivot, then returns the
         * index of the pivot.
         */
        int partition(vector<int>& list, int left, int right)
        {
            // Select a pivot using the "median of threes" method
            int middleIdx = left + (right - left) / 2;
            int one = list[left];
            int two = list[middleIdx];
            int three = list[right];
            int median = max(min(one, two), min(max(one, two), three));
            if (one == median)
            {
                int temp = list[middleIdx];
                list[middleIdx] = one;
                list[left] = temp;
            }
            else if (three == median)
            {
                int temp = list[middleIdx];
                list[middleIdx] = three;
                list[right] = temp;
            }
            // else (two == median) do nothing because the three are already sorted

            
            int pivot = list[middleIdx];
            
            while (left < right)
            {
                while (list[left] < pivot)
                    left++;
                
                while (list[right] > pivot)
                    right--;
                
                if (list[left] == list[right])
                    left++;
                else if (left < right)
                {
                    int temp = list[left];
                    list[left] = list[right];
                    list[right] = temp;
                }
            }
            return right;
        }
    };
}

#endif /* QUICKSORT_H */