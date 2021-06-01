#include <iostream>
using namespace std;

class Person
{
public:
	void get()
	{
		cout << m_age << endl;
		cout << m_id << endl;
	}
	//无参构造函数
	Person()
	{
		cout << "无参" << endl;
	}
	//有参构造函数
	Person(int age, int id)
	{
		m_age = age;
		m_id = id;
		cout << "有参" << endl;
	}
	//拷贝构造函数，常用于游戏中构造分身
	Person(const Person& p)
	{
		m_age = p.m_age;
		cout << "拷贝" << endl;
	}

	~Person()
	{
		cout << "析构" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "赋值构造函数" << endl;
	}
private:
	int m_age = 0;
	int m_id = 1;
};
//构造函数可以有多个(重载)，但只会有一个被调用
Person test()
{
	Person p2 = Person(10, 8);
	cout << &p2 << endl;
	return p2;
}
int main()
{
	Person p1 = test();
	cout << &p1 << endl;
	return 0;
}

