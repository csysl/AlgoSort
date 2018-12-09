#include "Sort.h"
#include "Rand.h"
#include <iostream>

using namespace std;
using namespace MySort;

int main() {

    Sort s = MySort::ShellSort;
    for (int i = 0; i < 10; ++i)SortTest(s);


    return 0;
}