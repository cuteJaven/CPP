#include <iostream>
using namespace std;

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
int main()
{
	Person p1;
	return 0;
}

