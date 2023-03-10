#pragma once
using namespace std;
template<typename T>
class Sequence
{
public:
    virtual T GetFirst()                                              const = 0;
    virtual T GetLast()                                               const = 0;
    virtual T Get(int index)                                          const = 0;
    virtual int GetLength()                                           const = 0;
    virtual void Remove(int index) = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, int index) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list)                    const = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const = 0;
    virtual Sequence<T>* QuickSort() = 0;
    virtual Sequence<T>* QuickSort(int (*cmp)(T, T)) = 0;
    virtual Sequence<T>* ShellSort() = 0;
    virtual Sequence<T>* ShellSort(int (*cmp)(T, T)) = 0;
    virtual Sequence<T>* MergeSort() = 0;
    virtual Sequence<T>* MergeSort(int (*cmp)(T, T)) = 0;
    virtual Sequence<T>* ShakerSort() = 0;
    virtual Sequence<T>* ShakerSort(int (*cmp)(T, T)) = 0;
    virtual void Swap(int index1, int index2) = 0;
};


