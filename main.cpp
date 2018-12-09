#include "Sort.h"
#include <iostream>

using namespace std;
using namespace MySort;

int main() {

    Sort s = MySort::HeapSort;
    for (int i = 0; i < 10; ++i)SortTest(s);
    // 47,12,26,25,20ms,19ms,32ms

    return 0;
}