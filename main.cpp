#include "Sort.h"
#include "Rand.h"
#include <iostream>

int main() {
    using namespace std;
    using namespace MySort;

    int v[]{1, 6, 4, 5, 3, 10, 0, 9};
    cout << "Origin array: ";for (auto i:v)cout << i << " ";cout << endl;

    int v1[]{1, 6, 4, 5, 3, 10, 0, 9};
    BubbleSort(v1, v1 + 8);//冒泡排序
    cout << "BubbleSort: ";for (auto i:v1)cout << i << " ";cout << endl;

    int v2[]{1, 6, 4, 5, 3, 10, 0, 9};
    SelectionSort(v2, v2 + 8);//
    cout << "SelectionSort: ";for (auto i:v2)cout << i << " ";cout << endl;

    int v3[]{1, 6, 4, 5, 3, 10, 0, 9};
    InsertionSort(v3, v3 + 8);//
    cout << "InsertionSort: ";for (auto i:v3)cout << i << " ";cout << endl;

    int v4[]{1, 6, 4, 5, 3, 10, 0, 9};
    ShellSort(v4, v4 + 8);//
    cout << "ShellSort: ";for (auto i:v4)cout << i << " ";cout << endl;


    return 0;
}