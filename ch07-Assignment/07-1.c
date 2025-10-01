#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
작성자: 최정민
*/

int main()
{
	int arr[10];
	int first;
	int common_difference;

	printf("첫 번째 항?");
	scanf("%d", &first);

	printf("공차?");
	scanf("%d", &common_difference);

	arr[0] = first;

	for (int i = 1; i < 10; i++)
	{
		arr[i] = arr[i - 1] + common_difference;
	}
	printf("등차수열:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	return 0;
}