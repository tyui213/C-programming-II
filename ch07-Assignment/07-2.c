#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void ������()
{
	double num1;
	double num2;
	double arr[10];

	printf("ù ��° ��?");
	scanf("%lf", &num1);
	printf("���?");
	scanf("%lf", &num2);

	arr[0] = num1;

	for (int i = 1; i < 10; i++) 
	{
		arr[i] = arr[i - 1] * num2;
	}
	
	printf("������:");

	for (int i = 0; i < 10; i++)
	{
		printf("%g ", arr[i]);
	}
}


int main()
{
	������();
	return 0;
}