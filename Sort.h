//
// Created by 92582 on 2018/12/4.
//

#ifndef ALGOSORT_SORT_H
#define ALGOSORT_SORT_H

#include <bits/stdc++.h>

namespace mysort {
    /*
     * TAG:
     * false:升序;  true:降序
     */
    /*
     * 冒泡排序
     */
    template<typename T>
    inline void BubbleSort(T *begin_, T *end_, bool TAG = false) {
        bool transtag;
        if (!TAG) {
            for (auto i = begin_; i < end_ - 1; ++i) {
                transtag = false;
                for (auto j = begin_; j < end_ - 1 - (i - begin_); ++j)
                    if (*j > *(j + 1)) {
                        std::swap(*j, *(j + 1));
                        transtag = true;
                    }
                if (!transtag)
                    return;
            }
        } else if (TAG) {
            for (auto i = begin_; i < end_ - 1; ++i) {
                transtag = false;
                for (auto j = begin_; j < end_ - 1 - (i - begin_); ++j)
                    if (*j < *(j + 1)) {
                        std::swap(*j, *(j + 1));
                        transtag = true;
                    }
                if (!transtag)
                    return;
            }
        }
        return;
    };

    /*
     * 选择排序
     */
    template<typename T>
    inline void SelectionSort(T *begin_, T *end_, bool TAG = false) {
        T *tag;
        if (!TAG) {
            for (auto i = begin_; i < end_ - 1; ++i) {
                tag = i;
                for (auto j = i + 1; j < end_; ++j)
                    if (*j < *tag)
                        tag = j;
                std::swap(*tag, *i);
            }
        } else if (TAG) {
            for (auto i = begin_; i < end_ - 1; ++i) {
                tag = i;
                for (auto j = i + 1; j < end_; ++j)
                    if (*j > *tag)
                        tag = j;
                std::swap(*tag, *i);
            }
        }
    }

    /*
     * 插入排序
     */
    template<typename T>
    inline void InsertionSort(T *begin_, T *end_, bool TAG = false) {
        T *tag;
        if (!TAG) {
            for (auto i = begin_ + 1; i < end_; ++i) {
                tag = i;
                while (tag > begin_ && *tag < *(tag - 1)) {
                    std::swap(*tag, *(tag - 1));
                    --tag;
                }
            }
        } else if (TAG) {
            for (auto i = begin_ + 1; i < end_; ++i) {
                tag = i;
                while (tag > begin_ && *tag > *(tag - 1)) {
                    std::swap(*tag, *(tag - 1));
                    --tag;
                }
            }
        }
    };

    /*
     * 希尔排序
     */
    template<typename T>
    inline void ShellSort(T *begin_, T *end_, bool TAG = false) {
        T *tag;
        if (!TAG) {
            for (auto t = (end_ - begin_) / 2; t > 0; t /= 2)
                for (auto i =begin_+t;i<end_;i+=t){
                    tag = i;
                    while (tag > begin_ && *tag < *(tag - t)) {
                        std::swap(*tag, *(tag - t));
                        --tag;
                    }
                }
        } else if (TAG) {
            for (auto t = (end_ - begin_) / 2; t > 0; t /= 2)
                for (auto i =begin_+t;i<end_;i+=t){
                    tag = i;
                    while (tag > begin_ && *tag > *(tag - t)) {
                        std::swap(*tag, *(tag - t));
                        --tag;
                    }
                }
        }
    };
    /*
     * 归并排序
     */
    template<typename T>
    inline void MergeSort(T *begin_, T *end_, bool TAG = false) {
        if (!TAG) {

        } else if (TAG) {

        }
    };

    /*
     * 快速排序
     */
    template<typename T>
    inline void QuickSort(T *begin_, T *end_, bool TAG = false) {
        if (!TAG) {

        } else if (TAG) {

        }
    };


}

#endif //ALGOSORT_SORT_H
