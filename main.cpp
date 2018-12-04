#include <iostream>
#include "Sort.h"
#include "Rand.h"
#include <algorithm>

int main() {
    using namespace std;
    using namespace mysort;

    int v[]{1,6,4,5,7};
    sort(v,v+5);
    for(auto i:v)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}