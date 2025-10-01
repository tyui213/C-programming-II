#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void 등비수열()
{
	double num1;
	double num2;
	double arr[10];

	printf("첫 번째 항?");
	scanf("%lf", &num1);
	printf("등비?");
	scanf("%lf", &num2);

	arr[0] = num1;

	for (int i = 1; i < 10; i++) 
	{
		arr[i] = arr[i - 1] * num2;
	}
	
	printf("등비수열:");

	for (int i = 0; i < 10; i++)
	{
		printf("%g ", arr[i]);
	}
}


int main()
{
	등비수열();
	return 0;
}