/*
�й� 202511241
�̸� ������
���α׷��� ���� 9-1
��¥ 0924
*/

#include<stdio.h>

int main(void)
{
	char str1[10] = { 'a','b','c' };
	char str2[10] = "abc";
	char str[] = "abc";//str3�� ũ�Ⱑ 4�� �迭
	char str4[10] = "very long string";//������ ��� �����÷ο�
	int size = sizeof(str1) / sizeof(str1[0]);
	int i;
	printf("str1 =");
	for (i = 0;i < size;i++)
		printf("%c", str1[i]);//�迭 ó�� for������ ����� �� �ִ�
	printf("%n");

	printf("str2 = %s\n", str2);//���� �迭�� ���� printf �Լ��� ���ڷ� ������ �� �ִ�.

	printf("str3 = ");
	printf(str3);
	printf("\n");

	printf("str4 = %s\n", str4);
	
	return 0;       

}