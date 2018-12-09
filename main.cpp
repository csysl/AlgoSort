#include "Sort.h"
#include "Rand.h"
#include <iostream>

int main() {
    using namespace std;
    using namespace MySort;

    int v[]{1, 6, 4, 5, 3, 10, 0, 9,2,11,7};
    cout << "Origin array: ";for (auto i:v)cout << i << " ";cout << endl;

    int v1[]{1, 6, 4, 5, 3, 10, 0, 9,2,11,7};
    BubbleSort(v1, v1 + 11);//冒泡排序
    cout << "BubbleSort: ";for (auto i:v1)cout << i << " ";cout << endl;

    int v2[]{1, 6, 4, 5, 3, 10, 0, 9,2,11,7};
    SelectionSort(v2, v2 + 11);//
    cout << "SelectionSort: ";for (auto i:v2)cout << i << " ";cout << endl;

    int v3[]{1, 6, 4, 5, 3, 10, 0, 9,2,11,7};
    InsertionSort(v3, v3 + 11);//
    cout << "InsertionSort: ";for (auto i:v3)cout << i << " ";cout << endl;

    int v4[]{1, 6, 4, 5, 3, 10, 0, 9,2,11,7};
    ShellSort(v4, v4 + 9);//
    cout << "ShellSort: ";for (auto i:v4)cout << i << " ";cout << endl;

    int v5[]{1, 6, 4, 5, 3, 10, 0, 9,2,11,7};
    MergeSort1(v5, v5 + 11);//
    cout << "MergeSort1: ";for (auto i:v5)cout << i << " ";cout << endl;

//    int v6[]{1, 6, 4, 5, 3, 10, 0, 9,2,11,7};
//    MergeSort2(v6, v6 + 11);//
//    cout << "MergeSort2: ";for (auto i:v6)cout << i << " ";cout << endl;



//    Sort s=MySort::MergeSort1;
//    SortTest(s);


    return 0;
}