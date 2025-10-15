#include <stdio.h>
#define SIZE 10

void assignment02();
void print_array(double* arr);

int main()
{
	assignment02();

	return 0;
}

void assignment02()
{
	double arr[SIZE] = { 1.0, 8.0, 4.0, 7.0, 10.0, 6.0, 2.0, 3.0, 5.0, 9.0 };
	print_array(arr);

	return;
}

void print_array(double* arr)
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("%.2lf ", arr[i]);
	}

	return;
}