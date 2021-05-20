#include "Header.h"
int myexchange(int* a)
{
	int temp = *a;
	*a = *(a + 1);
	*(a + 1) = temp;
	return 0;
}