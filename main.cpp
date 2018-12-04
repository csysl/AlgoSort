#include "Sort.h"
#include "Rand.h"

int main() {
    using namespace std;
    using namespace mysort;

    int v[]{1, 6, 4, 5, 7};

    BubbleSort(v, v + 5, true);//冒泡排序


    //sort(v,v+5);
    for (auto i:v)
        cout << i << " ";
    cout << endl;

    return 0;
}