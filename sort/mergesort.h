#ifndef MERGESORT_H
#define MERGESORT_H

#include "basesort.h"

using namespace std;

namespace Sorting
{
    class MergeSort : public BaseSort
    {
    public:
        virtual vector<int> sort(vector<int> list) override
        {
            vector<int> out(list);
            mergeSort(out, 0, out.size() - 1);
            return out;
        }
        
    private:
        void mergeSort(vector<int> &list, int L, int R)
        {
            if (L < R)
            {
                int M = L + (R - L) / 2;
                
                mergeSort(list, L, M);
                mergeSort(list, M + 1, R);
                
                merge(list, L, M, R);
            }
        }
        
        void merge(vector<int> &list, int L, int M, int R)
        {
            int sizeLeft = M - L;
            int sizeRight = R - M + 1;
            vector<int> left;
            left.reserve(sizeLeft);
            vector<int> right;
            right.reserve(sizeRight);
            
            // Create temporary left and right lists
            for (int i = L; i <= R; ++i)
            {
                if (i <= M)
                    left.push_back(list[i]);
                else
                    right.push_back(list[i]);
            }
            
            // Update list with smallest elements from left and right
            int leftIdx = 0;
            int rightIdx = 0;
            int outIdx = L;
            while (leftIdx < left.size() && rightIdx < right.size())
            {
                if (left[leftIdx] <= right[rightIdx])
                {
                    list[outIdx++] = left[leftIdx++];
                }
                else
                {
                    list[outIdx++] = right[rightIdx++];
                }
            }
            
            // Fill in rest of elements in left, if any
            while (leftIdx < left.size())
            {
                list[outIdx++] = left[leftIdx++];
            }
            
            // Fill in rest of elements in right, if any
            while (rightIdx < right.size())
            {
                list[outIdx++] = right[rightIdx++];
            }
        }
    };
}

#endif /* MERGESORT_H */