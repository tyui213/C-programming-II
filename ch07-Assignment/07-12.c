/*
�й�: 202511241
�̸�: ������
���α׷���: 12��
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
	printf("���� �¼�: [");
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

	printf("������ �¼���?");
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
	printf("�� �¼��� �����߽��ϴ�.\n");

	return;
}