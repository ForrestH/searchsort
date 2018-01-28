#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "basesort.h"

using namespace std;

namespace Sorting
{
    class HeapSort : public BaseSort
    {
    public:
        vector<int> sort(vector<int> list)
        {
            list.insert(list.begin(), 0);
            buildMaxHeap(list);
            int size = list.size();
            for (int lastIdx = size; lastIdx >= 2; --lastIdx)
            {
                // Swap root of heap with last idx
                int temp = list[1];
                list[1] = list[lastIdx];
                list[lastIdx] = temp;
                maxHeapify(list, 1, lastIdx - 1);
            }
            list.erase(list.begin());
            return list;
        }
    private:
        void maxHeapify(vector<int> &list, int parentIdx, int lastIdx)
        {
            int temp = list[parentIdx];
            int childIdx = parentIdx * 2;
            
            while (childIdx <= lastIdx)
            {
                // Set childIdx to largest of the two children
                if (childIdx < lastIdx && list[childIdx + 1] > list[childIdx])
                    childIdx++;
                
                // Break out of loop if parent is larger than either child
                if (temp > list[childIdx])
                    break;
                
                // Otherwise, swap larger child with parent
                // and repeat with children of the swapped child
                else // temp <= list[childIdx]
                {
                    list[childIdx / 2] = list[childIdx];
                    childIdx *= 2;
                }
            }
            list[childIdx / 2] = temp;
            
            return;
        }
        
        void buildMaxHeap(vector<int> &list)
        {
            // Do heapify on every parent node
            // (last parent node in binary tree is n/2)
            int n = list.size();
            for (int i = (n/2); i > 0; --i)
            {
                maxHeapify(list, i, n);
            }
        }
    };
}

#endif /* HEAPSORT_H */