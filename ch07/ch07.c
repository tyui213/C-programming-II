//학번:202511241
//이름:최정민
//프로그램명 ch07실습
//날짜 0910


#include<stdio.h>

void copy_array(int from[], int to[], int sz);

#ifdef _DEBUG
int test_copy_array(void);
#endif _DEBUG


int main()
{
	printf("hello");

	return 0;
}
#ifdef _DEBUG
int test_copy_array(void)
{
#define LEN 5
	int x[LEN] = { 1,2,3,4,5 };
	int y[LEN] = { 0 };

	int size = sizeof(y) / sizeof(y[0]);

	copy_array(x, y, LEN);

	for (int i = 0; i < LEN;)
	{
		if (y[i] != x[i])
		{
			return -1;
		}

	}

	return 0;
}
#endif _DEBUG


void copy_array(int from[], int to[], int sz)
{
	int i = 0;

	for (int i = 0; i < sz; i++)
	{
		to[i] = from[i];
	}
}