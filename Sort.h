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

typedef void (*Sort)(double *, double *, bool);

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

    /*
     * 对排序结果进行测试,
     */
    template<typename T>
    void ResultCheck(T *begin_, T *end_, bool TAG = false) {
        if (!TAG) {
            for (auto it = begin_; it < end_ - 1; ++it)
                if (*it > *(it + 1)) {
                    std::cout << "Result is wrong!\n";
                    return;
                }
        } else if (TAG) {
            for (auto it = begin_; it < end_ - 1; ++it)
                if (*it < *(it + 1)) {
                    std::cout << "Result is wrong!\n";
                    return;
                }
        }
        std::cout << "Result is right!\n";
    }

    /*
     * 对排序进行测试，输出排序所用时间，并对排序结果进行检测
     */
    void SortTest(Sort s, bool TAG = false) {
        std::random_device r;
        std::default_random_engine e(r());
        std::uniform_int_distribution<uint64_t> u1(100001, 100001);
        std::uniform_real_distribution<double> u2(1, 1000);
        uint64_t len = u1(e);
        std::cout << "The length of array: " << len << std::endl;
        double *arr = new double[len];
        for (auto i = 0; i < len; ++i)
            arr[i] = u2(e);
        auto start = std::chrono::high_resolution_clock::now();
        s(arr, arr + len, TAG);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); //毫秒输出
        std::cout <<"The run time: "<< std::setprecision(11) << duration.count() << "ms\n";
        ResultCheck(arr, arr + len, TAG);
        delete[] arr;
        std::cout<<"*****************\n";
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
        T *tmp = nullptr;
        if (end_ - begin_ > 0)tmp = new T[end_ - begin_];   //为了实现非递归的归并排序，否则可以直接写成T *tmp=new T[end_ - begin_];
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
                } else if (*it1 >= *it2) {
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
                } else if (*it1 <= *it2) {
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
            for (uint64_t i = 2; (i >> 1) <= (end_ - begin_); i <<= 1) {
                for (item_ = begin_; item_ < end_; item_ += i) {
                    if (item_ + i > end_) {//长度不够的额外处理
                        uint64_t tag = i;
                        while (tag > end_ - item_)tag >>= 1;
                        Merge(item_, item_ + tag, end_);
                        continue;
                    }
                    Merge(item_, item_ + (i >> 1), item_ + i);
                }
            }
        } else if (TAG) {
            for (uint64_t i = 2; (i >> 1) <= (end_ - begin_); i <<= 1) {
                for (item_ = begin_; item_ < end_; item_ += i) {
                    if (item_ + i > end_) {//长度不够的额外处理
                        uint64_t tag = i;
                        while (tag > end_ - item_)tag >>= 1;
                        Merge(item_, item_ + tag, end_, true);
                        continue;
                    }
                    Merge(item_, item_ + (i >> 1), item_ + i, true);
                }
            }
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

    //堆排序调整函数
    template<typename T>
    void AdjustHeap(T *begin_, T *end_, int64_t father, bool TAG = false) {
        /*
         * now_:当前节点的指针
         */
        int64_t len = end_ - begin_;
        if (!TAG) {
            for (auto child = (father << 1) + 1; child < len; child = (child << 1) + 1) {
                //找到两个子节点最大的哪一个
                if ((child + 1 < len) && (begin_[child] < begin_[child + 1]))
                    ++child;
                if (begin_[child] > begin_[father]) {
                    swap(begin_[child], begin_[father]);
                    father = child;
                } else
                    break;
            }

        } else if (TAG) {
            for (auto child = (father << 1) + 1; child < len; child = (child << 1) + 1) {
                if ((child + 1 < len) && (begin_[child] > begin_[child + 1]))
                    ++child;
                if (begin_[child] < begin_[father]) {
                    swap(begin_[child], begin_[father]);
                    father = child;
                } else
                    break;
            }
        }
    };

    /*
     *堆排序
     */
    template<typename T>
    inline void HeapSort(T *begin_, T *end_, bool TAG = false) {
        int64_t len = end_ - begin_;
        if (!TAG) {
            for (int64_t i = (len >> 1) - 1; i >= 0; --i) {  //从第一个有叶子节点的节点开始调整堆
                AdjustHeap(begin_, end_, i); //初始化最大堆
            }
            while (len--) {
                swap(begin_[0], begin_[len]);
                AdjustHeap(begin_, begin_ + len, 0);
            }
        } else if (TAG) {
            for (int64_t i = (len >> 1) - 1; i >= 0; --i) {  //从第一个有叶子节点的节点开始调整堆
                AdjustHeap(begin_, end_, i, true); //初始化最大堆
            }
            while (len--) {
                swap(begin_[0], begin_[len]);
                AdjustHeap(begin_, begin_ + len, 0, true);
            }
        }
    };

    /*
     * 计数排序
     */
    template<typename T>
    inline void CountingSort(T *begin_, T *end_, bool TAG = false) {
        if (!TAG) {

        } else if (TAG) {

        }
    };

    /*
     * 桶排序
     */
    template<typename T>
    inline void BucketSort(T *begin_, T *end_, bool TAG = false) {
        if (!TAG) {

        } else if (TAG) {

        }
    };

    /*
     * 基数排序
     */
    template<typename T>
    inline void RadixSort(T *begin_, T *end_, bool TAG = false) {
        if (!TAG) {

        } else if (TAG) {

        }
    };


}

#endif //ALGOSORT_SORT_H
