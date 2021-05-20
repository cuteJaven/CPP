# c++ 基础中级

## 指针

**指针的作用**：可以通过指针间接访问内存

- 内存编号都是从零开始记录的，一般由十六进制的数表示
- 可以利用指针变量保存地址
语法：`数据类型* 变量名;`

```cpp
int a = 10;
int* p = &a;
*p = 100 //a被修改为100
```

在 32 位操作系统下，占 4 个字节；在 64 位操作系统下，占 8 个字节。
与变量类型无关

### 空指针和野指针

空指针：指针编号指向内存中编号为 0 的空间
用途：初始化指针变量
注意：空指针指向的内存是不可以访问的

```cpp
int* p = NULL;
//0~255编号是系统占用的，普通程序无法访问
```

野指针：指针变量指向非法的内存空间

```cpp
int* p = (int*)0x1100;
```

### const 修饰指针

分为三种情况：

1. const 修饰指针：常量指针
2. const 修饰常量：指针常量
3. const 既修饰指针，又修饰常量

```cpp
//可以修改p的指向，无法利用p修改所指内存的数据
const int* p;
//可以利用p修改所指内存的数据，无法修改p的指向
int* const p;
//两者都不可以
const int* const p;
```

> 个人理解：`int*`赋予了指针修改`int`型变量的能力，`p`赋予了指针修改指向的能力
> `const`修饰谁，谁就被限制了

### 指针和数组

因为数组是连续的内存空间，所以用指针获取数组的首地址后，便可以增删改查了

```cpp
int arr[] = { 1,2,3,4,5 };
int* p = arr;
for (int i = 0; i < 5; i++)
{
    cout << *p << ' ';
    p++;//p是int*类型，++就直接后移一位，不用+4
}
```

### 指针和函数

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

## 结构体

结构体属于用户自定义的数据类型，允许用户存储不同的数据类型
语法：`struct 结构体名 {结构体成员列表};`
通过结构体创建变量的方式有三种：

- struct 结构体名 变量名
- struct 结构体名 变量名 = {成员 1 值，成员 2 值}
- 定义结构体时顺便创建变量

```cpp
struct Student
{
    string name;
    int age;
    float grade;
}s3;

int main()
{   //第一种定义方法
    struct Student s1;
    s1.age = 22;
    s1.grade = 100;
    s1.name = "Javen";
    cout << "age:" << s1.age << "grade:" << s1.grade << "name:" << s1.name << endl;
    //第二种定义方法
    struct Student s2 =
    {
        "Tom",
        10,
        100.0
    };
    cout << "age:" << s2.age << "grade:" << s2.grade << "name:" << s2.name << endl;
    //第三种定义方法
    cout << "age:" << s3.age << "grade:" << s3.grade << "name:" << s3.name << endl;
    return 0;
}
```

### 结构体数组

语法：`struct 结构体名 数组名[元素个数] = { {},{},...,{} };`

```cpp
struct Student s0[3]=
{
    {"张三",19,89},
    {"李四",17,87},
    {"王五",21,98}
};
```

### 结构体指针

利用操作符`->`可以通过结构体指针访问结构体属性

```cpp
struct Student* p = s0;
cout << p->age << endl;//张三的age
cout << (p + 1)->age << endl;//李四的age
cout << (p + 2)->age << endl;//王五的age
cout << (*p).age << endl;//还是张三的age
cout << p[1].age << endl;//还是李四的age
```

### 结构体嵌套结构体

```cpp
struct Teacher
{
    int id;
    int classid;
    struct Student* stulist;
};
struct Teacher t1 =
{
    007,
    399,
    p
};
```

**遗留问题**：结构体中如何嵌套结构体数组？

### 结构体做函数参数

在给函数传递结构体时可以用**形参**传递也可以用**指针**传递，在变量占用空间很大时（例如数组）传递指针会仅占用数个字节，大大节省空间

### 结构体中 const 使用场景

用于指针型函数参数，将导致指针处于只读状态，防止误操作
> const int* p; // 可以修改 p 的指向，无法利用 p 修改所指内存的数据
