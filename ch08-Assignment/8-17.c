/*
학번: 202511241
이름: 최정민
프로그램명:17
날짜: 2025.10.10
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

void assignment17();
int input_array();
int add_to_multiset(int n, int* index);
void print_array(int* index);

static int arr[SIZE] = { 0 };

int main()
{
	assignment17();

	return 0;
}

void assignment17()
{
	int index = 0;
	while (index < SIZE)
	{
		int n = input_array();
		index = add_to_multiset(n, &index);
		print_array(index);
	}

	return;
}

void print_array(int index)
{
	for (int i = 0; i < index; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return;
}

int add_to_multiset(int n, int* index)
{
	if (*index < SIZE)
	{
		arr[*index] = n;
		(*index)++;
	}

	return *index;
}

int input_array()
{
	int n = 0;
	printf("배열에 추가할 원소? ");
	scanf("%d", &n);

	return n;
}