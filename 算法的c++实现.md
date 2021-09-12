# 算法的c++实现

- [1. 插入排序](#1-插入排序)
- [2. 快速排序](#2-快速排序)
- [3. 堆排序](#3-堆排序)

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

## 3. 堆排序

```cpp
#include <iostream>
#include <cassert>
using namespace std;
int* generate_random_array(int n, int rangeL, int rangeR);
void heap_sort(int li[], int len);

int main()
{
    int* li = generate_random_array(50, 0, 99);
    heap_sort(li, 50);
    cout << endl;
    return 0;
}
/// <summary>
/// 向下调整函数
/// </summary>
/// <param name="li">列表</param>
/// <param name="len">列表长度</param>
/// <param name="low">堆的根节点位置</param>
/// <param name="high">堆的最后一个元素位置</param>
void sift(int li[], int low, int high)
{
    int i = low;//i最开始指向根节点
    int j = 2 * i + 1;//j是i节点的左孩子
    int tmp = li[low];//将堆顶元素缓存
    while (j <= high)//只要j位置有数
    {
        if (j + 1 <= high && li[j + 1] > li[j])//如果有右孩子并且比较大
            ++j;//j指向右孩子
        if (li[j] > tmp)//比较大孩子和堆顶元素的大小
        {
            li[i] = li[j];//i仅代表一个空位，数据在tmp里
            i = j;//i下移
            j = 2 * i + 1;//j下移
        }
        else
            break;
    }
    li[i] = tmp;//循环结束后将tmp填到空位上
}
/// <summary>
/// 堆排序
/// </summary>
/// <param name="li">列表</param>
/// <param name="len">列表长度</param>
void heap_sort(int li[], int len)
{
    for (int i = len / 2 - 1; i > -1; i--)//从末位父节点向前循环，到堆顶为止
    {
        sift(li, i, len - 1);
        //至此，堆建好了
    }
    for (int i = len - 1; i > -1; i--)//i指向当前堆的最后一个元素
    {
        int temp = li[0];
        li[0] = li[i];
        li[i] = temp;
        //前移一位(后面的位置用来存放排好序的数)
        sift(li, 0, i - 1);//再次通过向下调整找出最大的数
    }
    for (int i = 0; i < len; i++)
    {
        cout << li[i] << ' ';
    }
}

/// <summary>
/// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR] 闭区间
/// </summary>
/// <param name="n">随机数个数</param>
/// <param name="rangeL">随机区间左值</param>
/// <param name="rangeR">随机区间右值</param>
/// <returns></returns>
int* generate_random_array(int n, int rangeL, int rangeR)
{
    assert(rangeL <= rangeR);//断言，不满足就报错

    int* arr = new int[n]; // 创建一个 n个元素的数组
    srand(time(NULL)); // 随机种子
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    return arr;
}
```
