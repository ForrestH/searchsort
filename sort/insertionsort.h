#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <limits>

#include "basesort.h"

using namespace std;

namespace Sorting
{
    class InsertionSort : public BaseSort
    {
    public:
        virtual vector<int> sort(vector<int> list) override
        {
            vector<int> out;
            out.reserve(list.size());
            int size = list.size();
            for (int i = 0; i < size; ++i)
            {
                int minIndex = findIndexOfMin(list);
                out.push_back(list[minIndex]);
                list.erase(list.begin() + minIndex);
            }
            return out;
        }
        
    private:
        int findIndexOfMin(vector<int> list)
        {
            int min = std::numeric_limits<int>::max();
            int minIndex = 0;
            for (int i = 0; i < list.size(); ++i)
            {
                if (list[i] < min)
                {
                    min = list[i];
                    minIndex = i;
                }
            }
            return minIndex;
        }
    };

}

#endif /* INSERTIONSORT_H */