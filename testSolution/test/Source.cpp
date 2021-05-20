#include <iostream>
using namespace std;

struct Student
{
	string name;
	int age;
	float grade;
};
struct Teacher
{
	int id;
	int classid;
	struct Student* stulist;
};


int main()
{
	struct Student s0[3] =
	{
		{"zhangsan",19,89},
		{"lisi",17,87},
		{"wangwu",21,98}
	};
	struct Student* p = s0;
	cout << p->age << endl;
	cout << (p + 1)->age << endl;
	cout << (p + 2)->age << endl;
	cout << (*p).age << endl;
	cout << p[1].age << endl;

	struct Teacher t1 =
	{
		007,
		399,
		p
	};
	return 0;
}

