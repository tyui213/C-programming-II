#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
�ۼ���: ������
*/

int main()
{
	int arr[10];
	int first;
	int common_difference;

	printf("ù ��° ��?");
	scanf("%d", &first);

	printf("����?");
	scanf("%d", &common_difference);

	arr[0] = first;

	for (int i = 1; i < 10; i++)
	{
		arr[i] = arr[i - 1] + common_difference;
	}
	printf("��������:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	return 0;
}