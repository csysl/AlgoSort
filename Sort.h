//
// Created by 92582 on 2018/12/4.
//

#ifndef ALGOSORT_SORT_H
#define ALGOSORT_SORT_H

#include <bits/stdc++.h>

namespace mysort {
    /*
     * 冒泡排序,tag为false默认升序，为true为降序
     */
    template<typename T>
    inline void BubbleSort(T *rbegin, T *rend, bool TAG = false) {
        //unsigned long long n = 0;
        bool transtag;
        for (auto i = rbegin; i < rend - 1; ++i) {
            transtag = false;
            for (auto j = rbegin; j < rend - 1 - (i - rbegin); ++j) {
                if (!TAG) {
                    if (*j > *(j + 1)) {
                        std::swap(*j, *(j + 1));
                        transtag = true;
                        //++n;
                    }
                } else if (TAG) {
                    if (*j < *(j + 1)) {
                        std::swap(*j, *(j + 1));
                        transtag = true;
                        //++n;
                    }
                }
            }
            if (!transtag) {
                //std::cout << "The time complexity of bubble_sort is O(" << n << ")\n";
                return;
            }

        }
        //std::cout << "Time complexity is O(" << n << ")\n";
        return;
    };
    /*
     * 选择排序
     */
    template <typename T>
    inline void SelectionSort(T *rbegin, T *rend, bool TAG = false){

    }
    /*
     * 快速排序
     */
    template<typename T>
    inline void QuickSort(T *rbegin, T *rend, bool TAG = false) {

    };


}

#endif //ALGOSORT_SORT_H
