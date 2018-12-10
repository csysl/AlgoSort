#include "Sort.h"
#include <iostream>

using namespace std;
using namespace MySort;

int main() {

    cout<<INT64_MAX<<" "<<INT32_MAX<<endl;

    //SortReal s = MySort::CountingSort;
    SortInt s = MySort::CountingSort;
    for (int i = 0; i < 10; ++i)
        SortTestInt(s);
    // 47,12,26,25,20ms,19ms,32ms

    return 0;
}