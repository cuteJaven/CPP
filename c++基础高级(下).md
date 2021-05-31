# c++ 基础高级（下）

- [1. 类和对象](#1-类和对象)
  - [1.1. 封装](#11-封装)
    - [1.1.1. 封装的意义](#111-封装的意义)
      - [1.1.1.1. 封装的第一层意义](#1111-封装的第一层意义)
      - [1.1.1.2. 封装的第二层意义](#1112-封装的第二层意义)
    - [1.1.2. struct 和 class 的区别](#112-struct-和-class-的区别)
    - [1.1.3. 成员属性设置为私有](#113-成员属性设置为私有)
  - [1.2. 对象的初始化和清理](#12-对象的初始化和清理)
    - [1.2.1. 构造函数和析构函数](#121-构造函数和析构函数)
    - [1.2.2. 构造函数的分类及调用](#122-构造函数的分类及调用)
    - [1.2.3. 拷贝构造函数的调用时机](#123-拷贝构造函数的调用时机)

## 1. 类和对象

C++ 面向对象的三大特性为：**封装**、**继承**、**多态**
C++ 认为万事万物皆为对象，对象上有其属性和行为

### 1.1. 封装

#### 1.1.1. 封装的意义

封装是 C++ 面向对象三大特性之一
封装的意义：

- 将属性和行为作为一个整体，表现生活中的事物
- 将属性和行为加以权限控制

##### 1.1.1.1. 封装的第一层意义

在设计类的时候，属性和行为写在一起，表现事物
语法：

```cpp
//示例一：设计一个圆类，求圆的周长
#include <iostream>
using namespace std;
constexpr double PI = 3.14;
class Circle
{
    //访问权限
public:
    //属性
    double radius;
    //行为
    double cal_C()
    {
        return 2 * PI * radius;
    }
};
int main()
{
    //通过圆类，创建具体的圆(实例化)
    Circle c1;
    //给圆对象的属性进行赋值
    c1.radius = 10.0;
    cout << "圆的周长：" << c1.cal_C() << endl;
    return 0;
}
```

##### 1.1.1.2. 封装的第二层意义

类在设计时，可以把属性和行为放在不同的权限下加以控制
访问权限由三种：

1. public     公共权限
2. protected  保护权限    // 可父子继承
3. private    私有权限    // 不可继承

#### 1.1.2. struct 和 class 的区别

struct 默认权限公有，class 默认权限私有

#### 1.1.3. 成员属性设置为私有

优点：

1. 可以自己控制读写权限
2. 对于写权限，我们可以检测数据的有效性（函数内用 if)

```cpp
class Person
{
public:
    void put_name(string name)
    {
        m_name = name;
    }
    void get_name()
    {
        cout << m_name << endl;
    }

private:
    string m_name;
    int m_age = 0;
    string m_lover;
};

int main()
{
    Person p1;
    p1.put_name("张三");
    p1.get_name();
    return 0;
}
```

**练习案例一**：设计立方体类

```cpp
#include <iostream>
using namespace std;

class Cube
{
public:
    void init()
    {
        cout << "请输入长：" << endl;
        cin >> m_length;
        cout << "请输入宽：" << endl;
        cin >> m_width;
        cout << "请输入高：" << endl;
        cin >> m_hight;
    }
    void is_equal(Cube c2)
    {
        if (m_length == c2.m_length && m_width == c2.m_width && m_hight == c2.m_hight)
            cout << "Those two are equal." << endl;
        else
            cout << "They are not equal." << endl;
    }
private:
    //长
    int m_length = 0;
    //宽
    int m_width = 0;
    //高
    int m_hight = 0;
    int cal_S()
    {
        int S = m_length * m_width + m_length * m_hight + m_width * m_hight;
        return 2 * S;
    }
    int cal_V()
    {
        return m_length * m_width * m_hight;
    }
};
int main()
{
    Cube c1;
    Cube c2;
    c1.init();
    c2.init();
    c1.is_equal(c2);
    return 0;
}
```

当类的长度过长时，我们可以将类拆分成独立的文件，按以下步骤

1. 新建`.h`文件，键入`#pragma once`，防止头文件重复包含
2. 将类完整粘贴到文件中，删除每一个函数的内容保留声明及变量，并添加分号
3. 新建`.cpp`文件，包含刚才的`.h`文件，将类完整粘贴到文件中
4. 仅保留函数部分，其余全部删除，然后为每个函数添加作用域
5. 返回源文件，包含制作好的`.h`，完成

### 1.2. 对象的初始化和清理

#### 1.2.1. 构造函数和析构函数

一个对象或变量如果没有初始状态，对其使用后果是未知的
使用完一个对象或变量，没有及时清理，也会遗留安全隐患

**如果我们不提供构造和析构，编译器会提供**
**编译器提供的构造函数和析构函数是空实现**

构造函数语法：`类名(){}`
1. 构造函数没有返回值也不写 void
2. 函数名称与类名相同
3. 构造函数可以有参数，因此可以发生重载
4. 程序在调用对象的时候会自动调用构造，无需手动调用，而且仅调用一次

析构函数语法：`~类名(){}`
1. 析构函数没有返回值也不写 void
2. 函数名称与类名相同，在名称前加上`~`
3. 析构函数不可以有参数，因此不可以发生重载
4. 程序在自动销毁前会自动调用析构，无需手动调用，而且仅调用一次

```cpp
class Person
{
public:
    Person()
    {
        cout << "这里是构造函数" << endl;
    }
    ~Person()
    {
        cout << "这里是析构函数" << endl;
    }
};
```

#### 1.2.2. 构造函数的分类及调用

两种分类方式：
- 按参数分为：有参构造和无参构造
- 按类型分为：普通构造和拷贝构造

三种调用方式：
- 括号法
- 显示法
- 隐式转换法

```cpp
class Person
{
public:
    //无参构造函数
    Person() {}
    //有参构造函数
    Person(int age)
    {
        m_age = age;
    }
    //拷贝构造函数，常用于游戏中构造分身
    Person(const Person& p)
    {
        m_age = p.m_age;
    }
private:
    int m_age = 0;
};
//构造函数可以有多个(重载)，但只会有一个被调用
void test()
{
    //括号法
    Person p1;
    Person p2(10);
    Person p3(p2);
    //显示法
    Person p4;
    Person p5 = Person(10);//匿名对象，执行结束立即被回收
    Person p6 = Person(p5);
    //隐式转换法
    Person p7;
    Person p8 = 10;
    Person p9 = p8;
}
```

#### 1.2.3. 拷贝构造函数的调用时机
