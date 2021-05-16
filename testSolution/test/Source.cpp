#include <iostream>
using namespace std;
int main()
{
	cout << "Please input three numbers" << endl;
	int h[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> h[i];
	}
	
}
int top_down(int a[])
{
	int len = sizeof(a) / sizeof(a[0]);
	if (len == 1)
		return a[0];
	top_down()
}