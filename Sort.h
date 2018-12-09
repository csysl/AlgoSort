//
// Created by 92582 on 2018/12/4.
//

#ifndef ALGOSORT_SORT_H
#define ALGOSORT_SORT_H

#include <utility>
#include <random>
#include <chrono>
#include <iomanip>
#include <iostream>

typedef void (*Sort)(double*,double*,bool);

namespace MySort {
    /*
     * TAG:
     * false:升序;  true:降序
     */
    template<typename T>
    void swap(T &a, T &b) {
        T tmp(std::move(a));
        a = std::move(b);
        b = std::move(tmp);
    }
    void SortTest(Sort s){
        std::random_device r;
        std::default_random_engine e(r());
        std::uniform_int_distribution<uint64_t > u1(1000000,10000000);
        std::uniform_real_distribution<double> u2(1,1000);
        uint64_t len=u1(e);
        double *arr=new double[len];
        for(auto i=0;i<len;++i)
            arr[i]=u2(e);
        auto start = std::chrono::high_resolution_clock::now();
        s(arr,arr+len,false);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); //毫秒输出
        std::cout << std::setprecision(11) << duration.count() << "ms\n";
        delete[] arr;
    }
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
                        swap(*j, *(j + 1));
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
                        swap(*j, *(j + 1));
                        transtag = true;
                    }
                if (!transtag)
                    return;
            }
        }
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
                swap(*tag, *i);
            }
        } else if (TAG) {
            for (auto i = begin_; i < end_ - 1; ++i) {
                tag = i;
                for (auto j = i + 1; j < end_; ++j)
                    if (*j > *tag)
                        tag = j;
                swap(*tag, *i);
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
                    swap(*tag, *(tag - 1));
                    --tag;
                }
            }
        } else if (TAG) {
            for (auto i = begin_ + 1; i < end_; ++i) {
                tag = i;
                while (tag > begin_ && *tag > *(tag - 1)) {
                    swap(*tag, *(tag - 1));
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
            for (auto t = (end_ - begin_) >> 1; t > 0; t >>= 1)
                for (auto i = begin_ + t; i < end_; i += t) {
                    tag = i;
                    while (tag > begin_ && *tag < *(tag - t)) {
                        swap(*tag, *(tag - t));
                        --tag;
                    }
                }
        } else if (TAG) {
            for (auto t = (end_ - begin_) >> 1; t > 0; t >>= 1)
                for (auto i = begin_ + t; i < end_; i += t) {
                    tag = i;
                    while (tag > begin_ && *tag > *(tag - t)) {
                        swap(*tag, *(tag - t));
                        --tag;
                    }
                }
        }
    };

    /*
     * 归并排序
     */
    template<typename T>
    void Merge(T *begin_, T *middle_, T *end_, bool TAG = false) {
        T *tmp = new T[end_ - begin_];
        if (!TAG) {
            auto it1 = begin_, it2 = middle_;  //it1,it2销毁了原先的内存，但是函数末尾move函数产生了新内存
            for (uint64_t ind = 0; ind < (end_ - begin_); ++ind) {
                if (it1 == middle_) {
                    std::move(it2, end_, tmp + ind);
                    break;
                }
                if (it2 == end_) {
                    std::move(it1, middle_, tmp + ind);
                    break;
                }
                if (*it1 < *it2) {
                    tmp[ind] = *it1;
                    ++it1;
                } else {
                    tmp[ind] = *it2;
                    ++it2;
                }
            }

        } else if (TAG) {
            auto it1 = begin_, it2 = middle_;
            for (uint64_t ind = 0; ind < (end_ - begin_); ++ind) {
                if (it1 == middle_) {
                    std::move(it2, end_, tmp + ind);
                    break;
                }
                if (it2 == end_) {
                    std::move(it1, middle_, tmp + ind);
                    break;
                }
                if (*it1 > *it2) {
                    tmp[ind] = *it1;
                    ++it1;
                } else {
                    tmp[ind] = *it2;
                    ++it2;
                }
            }
        }
        std::move(tmp, tmp + (end_ - begin_), begin_);
        delete[]tmp;
    }

    //递归实现
    template<typename T>
    inline void MergeSort1(T *begin_, T *end_, bool TAG = false) {
        T *middle_ = nullptr;
        if (!TAG) {
            if (begin_ < end_ - 1) {
                middle_ = begin_ + ((end_ - begin_) >> 1);
                MergeSort1(begin_, middle_);
                MergeSort1(middle_, end_);
                Merge(begin_, middle_, end_);
            }
        } else if (TAG) {
            if (begin_ < end_ - 1) {
                middle_ = begin_ + ((end_ - begin_) >> 1);
                MergeSort1(begin_, middle_, true);
                MergeSort1(middle_, end_, true);
                Merge(begin_, middle_, end_, true);
            }
        }
        middle_ = nullptr;
    };

    //非递归实现
    template<typename T>
    inline void MergeSort2(T *begin_, T *end_, bool TAG = false) {
        T *item_ = nullptr;
        if (!TAG) {
            for (uint64_t i = 2; i <= (end_ - begin_); i <<= 1) {
                for (item_ = begin_; item_ < end_; item_ += i) {
                    Merge(item_, item_ + (i >> 1), item_ + i);
                }
            }
        } else if (TAG) {

        }
        item_ = nullptr;
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
