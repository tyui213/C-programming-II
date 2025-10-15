/*
학번: 202511241
이름: 최정민
프로그램명: 12번
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10


void arr(char a[]);
void array(char a[]);
void assignment12();

int main()
{
	assignment12();
	return 0;
}

void assignment12()
{

	static char a[SIZE] = { 'O','O','O','O','O','O','O','O','O','O' };

	arr(a);

	while (a[9] != 'X')
	{
		array(a);
		arr(a);
	}

	return;
}

void arr(char a[])
{
	printf("현재 좌석: [");
	for (int i = 0; i < 10; i++)
	{
		printf(" %c", a[i]);
	}
	printf(" ]\n");

	return;
}

void array(char a[])
{
	int sit = 0, count = 0;

	printf("예매할 좌석수?");
	scanf("%d", &sit);

	for (int i = 0; i < 10 && count < sit; i++)
	{
		if (a[i] == 'O')
		{
			a[i] = 'X';
			printf("%d ", i + 1);
			count++;
		}
	}
	printf("번 좌석을 예매했습니다.\n");

	return;
}