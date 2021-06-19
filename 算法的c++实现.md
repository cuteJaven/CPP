# 算法的c++实现

- [1. 插入排序](#1-插入排序)
- [2. 快速排序](#2-快速排序)

## 1. 插入排序

```cpp
// c++实现插入排序
#include <iostream>
using namespace std;
void quick_sort(int* arr, int len);
int main()
{
    int l[] = { 9,8,7,6,5,4,3,2,1 };
    int len = sizeof(l) / sizeof(l[0]);
    quick_sort(l, len);
    for (int i = 0; i < len; i++)
    {
        cout << l[i] << ' ';
    }
}
void quick_sort(int* arr, int len)
{
    if (len == 1)   //递归到数组长度为1时停止
        return;
    quick_sort(arr, len - 1);
    int temp = *(arr + len - 1);    //记录排好序的数组之后一位数字
    for (int i = 0; i < len - 1; i++)
    {
        if (*(arr + len - 2 - i) > temp)    //从最后一位开始比较，大的往后放
        {
            *(arr + len - 1 - i) = *(arr + len - 2 - i);
        }
        else
        {
            *(arr + len - 1 - i) = temp;    //大的都放后面了，temp归位
            break;
        }
        if (i == len - 2)   //全都比temp大，则temp放首位
        {
            *(arr + len - 2 - i) = temp;
        }
    }
}
```

## 2. 快速排序

```cpp
//c++实现快速排序
#include <iostream>
#include <cassert>
using namespace std;

// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR] 闭区间
int* generateRandomArray(int n, int rangeL, int rangeR) {
    assert(rangeL <= rangeR);

    int* arr = new int[n]; // 创建一个 n个元素的数组

    srand(time(NULL)); // 随机种子
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    return arr;
}
//left为一次partition中最左边那个数的角标，right为一次partition中最右边那个数的角标
int partition(int* li, int left, int right)
{   //将left的值作为要归位的数，左右反复横跳比较大小，小的往左扔大的往右扔，直到归位
    int mid = *(li+left);
    while (left < right)
    {
        while (left < right && *(li+right) >= mid)
            --right;
        if (left >= right)
            break;
        *(li+left) = *(li+right);
        ++left;
        if (left >= right)
            break;
        while (left < right && *(li+left) <= mid)
            ++left;
        if (left >= right)
            break;
        *(li+right) = *(li+left);
        --right;
    }
    *(li + left) = mid;
    return left;
}

void quick_sort(int* li, int left, int right)
{
    int mid = partition(li, left, right);
    int left2 = ++mid;
    int right1 = --mid;
    if (left < right1)
        quick_sort(li, left, right1);
    if (left2 < right)
        quick_sort(li, left2, right);
}
int main()
{
    int* li = generateRandomArray(10, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << *(li + i) << ' ';
    }
    cout << endl;
    quick_sort(li, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << *(li + i) << ' ';
    }
    return 0;
}
```
