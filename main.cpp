#include "Sort.h"
#include <iostream>

using namespace std;
using namespace MySort;

int main() {

    uint64_t arr[]{3,5,1,9,6,8,7,2,4,0,15};
    CountingSort(arr,arr+11,true);
    for(auto i:arr)cout<<i<<" ";cout<<endl;

    //SortReal s = MySort::CountingSort;
    SortInt s = MySort::CountingSort;
    for (int i = 0; i < 10; ++i)
        SortTestInt(s,true);
    // 47,12,26,25,20ms,19ms,32ms

    return 0;
}