#include <iostream>
using namespace std;

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
	Person p1;
	Person p2(10);
	Person p3(p2);
}
int main()
{
	Person p1;
	return 0;
}

