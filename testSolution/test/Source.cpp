#include <iostream>
using namespace std;
int main()
{
	int a = 100, i = 0;
	int j, k, l;
	do
	{
		j = a % 10;
		k = (a - j) / 10 % 10;
		l = a - (a % 100) / 100;
		if ((j ^ 3 + k ^ 3 + l ^ 3) == a)
		{
			cout << a << endl;
			i++;
		}
		a++;
	} while (a < 1000);
	cout << i << endl;
}