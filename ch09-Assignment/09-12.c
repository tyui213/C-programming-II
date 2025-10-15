/*
�й�: 202511241
�̸�: ������
���α׷���:12�� ���� �� 3������ 
��¥: 2025-10-10
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 128

typedef struct text {
	char str[MAX];
	int n;
} Text;

void assignment12();
Text input_text(Text text);
void rotate_text(Text text, char* result);
void print_text(char* result);

int main()
{
	assignment12();

	return 0;
}

void assignment12()
{
	Text text = { 0 };
	char result[MAX];

	text = input_text(text);

	if (text.n == 0)
	{
		return;
	}

	rotate_text(text, result);

	print_text(result);

	return;
}

Text input_text(Text text)
{
	if (text.str == 0)
	{
		printf("���ڿ�? ");
		fgets(text.str, MAX, stdin);

		text.str[strcspn(text.str, "\n")] = '\0';
	}

	printf("�̵��� ���ڼ�? ");
	scanf("%d", &text.n);

	return text;
}

void rotate_text(Text text, char* result)
{
	int len = strlen(text.str);

	strncpy(result, text.str + len - text.n, text.n);
	strncpy(result + text.n, text.str, len - text.n);
	result[len] = '\0';

	return;
}

void print_text(char* result)
{
	printf("%s", result);

	return;
}