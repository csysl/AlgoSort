//
// Created by 92582 on 2018/12/4.
//

#ifndef ALGOSORT_SORT_H
#define ALGOSORT_SORT_H

#include <utility>  //move
#include <random>   //random_device;default_random_engine;uniform_int_distribution
#include <chrono>   //time
#include <iomanip>  //setprecision
#include <iostream> //cout;endl;
#include <cstring>  //memset
#include <limits>   //

typedef void (*SortReal)(double *, double *, bool);

typedef void (*SortInt)(uint64_t *, uint64_t *, bool);

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

    //获取a,b之间的一个随机数整数
    uint64_t GetRand(uint64_t a, uint64_t b) {
        std::random_device r;
        std::default_random_engine e(r());
        std::uniform_int_distribution<uint64_t> u(a, b);
        return u(e);
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
     * 对排序进行测试，输出排序所用时间，并对排序结果进行检测,测试序列为浮点数
     */
    void SortTestReal(SortReal s, bool TAG = false) {
        std::random_device r;
        std::default_random_engine e(r());
        std::uniform_int_distribution<uint64_t> u1(1000001, 1000001);
        std::uniform_real_distribution<double> u2(1000, 100000);
        uint64_t len = u1(e);
        std::cout << "The length of array: " << len << std::endl;
        double *arr = new double[len];
        for (auto i = 0; i < len; ++i)
            arr[i] = u2(e);
        auto start = std::chrono::high_resolution_clock::now();
        s(arr, arr + len, TAG);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); //毫秒输出
        std::cout << "The run time: " << std::setprecision(11) << duration.count() << "ms\n";
        ResultCheck(arr, arr + len, TAG);
        delete[] arr;
        std::cout << "*****************\n";
    };

    /*
     * 对排序进行测试，输出排序所用时间，并对排序结果进行检测,测试序列为正整数
     */
    void SortTestInt(SortInt s, bool TAG = false) {
        std::random_device r;
        std::default_random_engine e(r());
        std::uniform_int_distribution<uint64_t> u1(100001, 100001);
        std::uniform_int_distribution<uint64_t> u2(1000000, 10000000);
        uint64_t len = u1(e);
        std::cout << "The length of array: " << len << std::endl;
        uint64_t *arr = new uint64_t[len];
        for (auto i = 0; i < len; ++i)
            arr[i] = u2(e);
        auto start = std::chrono::high_resolution_clock::now();
        s(arr, arr + len, TAG);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); //毫秒输出
        std::cout << "The run time: " << std::setprecision(11) << duration.count() << "ms\n";
        ResultCheck(arr, arr + len, TAG);
        delete[] arr;
        std::cout << "*****************\n";
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
                    std::copy(it2, end_, tmp + ind);
                    break;
                }
                if (it2 == end_) {
                    std::copy(it1, middle_, tmp + ind);
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
                    std::copy(it2, end_, tmp + ind);
                    break;
                }
                if (it2 == end_) {
                    std::copy(it1, middle_, tmp + ind);
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
        std::copy(tmp, tmp + (end_ - begin_), begin_);
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
    };

    /*
     * 快速排序
     */
    template<typename T>
    inline void QuickSort(T *begin_, T *end_, bool TAG = false) {
        if (!TAG) {
            if (end_ > begin_) {
                auto middle_ = GetRand(0, end_ - begin_ - 1);
                T *p = begin_ + middle_, *right_ = end_ - 1, *left_ = begin_;  //标记基准值位置指针和左右指针
                T key_ = *p;
                while (left_ < right_) {
                    while (right_ > p) {
                        if (*right_ < key_) {
                            swap(*right_, *p);
                            p = right_;
                            break;
                        }
                        --right_;
                    }
                    while (left_ < p) {
                        if (*left_ > key_) {
                            swap(*left_, *p);
                            p = left_;
                            break;
                        }
                        ++left_;
                    }
                }
                QuickSort(begin_, p);
                QuickSort(p + 1, end_);
            }
        } else if (TAG) {
            if (end_ > begin_) {
                auto middle_ = GetRand(0, end_ - begin_ - 1);
                T *p = begin_ + middle_, *right_ = end_ - 1, *left_ = begin_;  //标记基准值位置指针和左右指针
                T key_ = *p;
                while (left_ < right_) {
                    while (right_ > p) {
                        if (*right_ > key_) {
                            swap(*right_, *p);
                            p = right_;
                            break;
                        }
                        --right_;
                    }
                    while (left_ < p) {
                        if (*left_ < key_) {
                            swap(*left_, *p);
                            p = left_;
                            break;
                        }
                        ++left_;
                    }
                }
                QuickSort(begin_, p, true);
                QuickSort(p + 1, end_, true);
            }
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
        T max_ = 0, min_ = UINT64_MAX;
        uint64_t len_;
        if (!TAG) {
            for (auto it = begin_; it < end_; ++it) {  //找到最大最小值
                max_ = max_ > (*it) ? max_ : (*it);
                min_ = min_ < (*it) ? min_ : (*it);
            }
            len_ = max_ - min_ + 1;
            T *countArray = new T[len_];
            std::memset(countArray, 0, sizeof(T) * len_); //新建计数数组并全部置为0
            for (auto it = begin_; it < end_; ++it)   //计数数组记录元素的个数，元素的值-min_=下标
                ++countArray[(*it) - min_];
            for (uint64_t i = 0; i < len_ - 1; ++i)
                countArray[i + 1] += countArray[i];   //计数数组保存小于等于当前值的总数，目的是为了处理相同值，保持算法稳定
            --end_;
            for (uint64_t ind_ = len_ - 1; ind_ >= 0;) {
                if (ind_ == 0) {
                    if (countArray[ind_] > 0) {  //倒序循环到第一个元素时特殊处理
                        *end_ = ind_ + min_;
                        --countArray[ind_];
                        --end_;
                        continue;
                    }
                    break;
                } else if (countArray[ind_] - countArray[ind_ - 1] > 0) {
                    *end_ = ind_ + min_;
                    --countArray[ind_];
                    --end_;
                    continue;
                }
                --ind_;
            }
            delete[]countArray;
        } else if (TAG) {
            for (auto it = begin_; it < end_; ++it) {  //找到最大最小值
                max_ = max_ > (*it) ? max_ : (*it);
                min_ = min_ < (*it) ? min_ : (*it);
            }
            len_ = max_ - min_ + 1;
            T *countArray = new T[len_];
            std::memset(countArray, 0, sizeof(T) * len_); //新建计数数组并全部置为0
            for (auto it = begin_; it < end_; ++it)   //计数数组记录元素的个数，元素的值-min_=下标
                ++countArray[(*it) - min_];
            for (uint64_t i = 0; i < len_ - 1; ++i)
                countArray[i + 1] += countArray[i];   //计数数组保存小于等于当前值的总数，目的是为了处理相同值，保持算法稳定
            for (uint64_t ind_ = len_ - 1; ind_ >= 0;) {
                if (ind_ == 0) {
                    if (countArray[ind_] > 0) {  //倒序循环到第一个元素时特殊处理
                        *begin_ = ind_ + min_;
                        --countArray[ind_];
                        ++begin_;
                        continue;
                    }
                    break;
                } else if (countArray[ind_] - countArray[ind_ - 1] > 0) {
                    *begin_ = ind_ + min_;
                    --countArray[ind_];
                    ++begin_;
                    continue;
                }
                --ind_;
            }
            delete[]countArray;
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
     * 基数排序,只实现正整数
     * 需要一个临时数组，需要得到位数
     * (1)遍历序列找出最大的数(为的是确定最大的数是几位数)；
        (2)开辟一个与数组大小相同的临时数组tmp；
        (3)用一个count数组统计原数组中某一位(从低位向高位统计)相同的数据出现的次数；
        (4)用一个index数组计算原数组中某一位(从最低位向最高位计算)相同数据出现的位置；
        (5)将桶中数据从小到大用tmp数组收集起来；
        (6)重复(3)(4)(5)直到所有位都被统计并计算过，用tmp收集起来；
        (7)将tmp数组拷回到原数组中；
     */
    template<typename T>
    inline void RadixSort(T *begin_, T *end_, bool TAG = false) {
        //using namespace std;
        int64_t len_ = end_ - begin_;
        T *tmp_ = new T[len_]();  //临时数组
        T max_ = 0;
        for (int64_t i = 0; i < len_; ++i)max_ = max_ > begin_[i] ? max_ : begin_[i];  //找到最大值，为了确定有几位
        int64_t digit_ = 1, radix_ = 1;
        while (max_ /= 10)++digit_;//获取最大数字的位数
        if (!TAG) {
            while (digit_--) { //所有位数桶排序
                int count_[10] = {0};
                //统计数组,记录每位0-9出现的个数
                for (int64_t i = 0; i < len_; ++i) {
                    int ind = begin_[i] / radix_ % 10;
                    ++count_[ind];
                }
                //将将各个桶中的数字个数，转化成各个桶中最后一个数字的下标索引
                for (int64_t i = 1; i < 10; ++i) {
                    count_[i] = count_[i-1] + count_[i];
                }
                //将按当前位的排序结果存放到tmp数组中
                for (int64_t i = len_-1; i >=0; --i) {
                    int ind = begin_[i] / radix_ % 10;
                    tmp_[--count_[ind]] = begin_[i];
                }
                /**
                 * 或者可以使用正序，转化为各个桶中第一个数字的下标
                //将将各个桶中的数字个数，转化成各个桶中第一个数字的下标索引
                int index_[10]={0};
                for (int64_t i = 1; i < 10; ++i) {
                    index_[i] = count_[i-1] + index_[i - 1];
                }
                //将按当前位的排序结果存放到tmp数组中
                for (int64_t i = 0; i < len_; ++i) {
                    int ind = begin_[i] / radix_ % 10;
                    tmp_[index_[ind]++] = begin_[i];
                }
                 */
                //将按该位的排序结果复制给原数组
                std::copy(tmp_, tmp_ + len_, begin_);
                radix_ *= 10;
            }
        } else if (TAG) {
            while (digit_--) { //所有位数桶排序
                int count_[10] = {0};
                //统计数组,记录每位0-9出现的个数
                for (int64_t i = 0; i < len_; ++i) {
                    int ind = begin_[i] / radix_ % 10;
                    ++count_[ind];
                }
                //cout<<"sss: ";for(auto i:count_)cout<<i<<" ";cout<<endl;
                //将将各个桶中的数字个数，转化成各个桶中最后一个数字的下标索引
                for (int64_t i = 9; i > 0; --i) {
                    count_[i-1] = count_[i-1] + count_[i];
                }
                //cout<<"sss: ";for(auto i:count_)cout<<i<<" ";cout<<endl;
                //将按当前位的排序结果存放到tmp数组中
                for (int64_t i = len_-1; i >=0; --i) {
                    int ind = begin_[i] / radix_ % 10;
                    tmp_[--count_[ind]] = begin_[i];
                }
                /**
                 * 或者可以使用正序，转化为各个桶中第一个数字的下标
                //将将各个桶中的数字个数，转化成各个桶中第一个数字的下标索引
                int index_[10]={0};
                for (int64_t i = 9; i >0; --i) {
                    index_[i-1] = count_[i] + index_[i];
                }
                //将按当前位的排序结果存放到tmp数组中
                for (int64_t i = 0; i < len_; ++i) {
                    int ind = begin_[i] / radix_ % 10;
                    tmp_[index_[ind]++] = begin_[i];
                }
                 */
                //将按该位的排序结果复制给原数组
                std::copy(tmp_, tmp_ + len_, begin_);
                radix_ *= 10;
            }
        }
        delete[]tmp_;
    };


}

#endif //ALGOSORT_SORT_H
