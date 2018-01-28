#ifndef BASESORT_H
#define BASESORT_H

#include <vector>

using namespace std;

namespace Sorting
{
    class BaseSort
    {
    public:
        virtual vector<int> sort(vector<int> list)
        {
            return list;
        }
        
        BaseSort() {};
        ~BaseSort() {};
    };
}

#endif /* BASESORT_H */