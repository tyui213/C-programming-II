/*
�й�: 202511241
�̸� : ������
���α׷���: 10-1��
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 20


typedef struct
{
	char id[MAX];
	char pw[MAX];

}LOGIN;


void assignment1001();
void loginprint(LOGIN login);
LOGIN inputLogin(LOGIN login);



int main()
{
	assignment1001();

	return 0;
}

void assignment1001()
{
	LOGIN login = { 0 };

	login = inputLogin(login);
	loginprint(login);

	return;
}

LOGIN inputLogin(LOGIN login)
{
	printf("ID?");
	scanf("%s", login.id);

	printf("PW?");
	scanf("%s", login.pw);

	if (strlen(login.id) > 20)
	{
		printf("�ִ� 20���ڱ��� �Է� �����մϴ�.");
	}

	if (strlen(login.pw) > 20)
	{
		printf("�ִ� 20���ڱ��� �Է� �����մϴ�.");
	}
	return login;

}

void loginprint(LOGIN login)
{
	printf("ID: %s\n", login.id);
	printf("PW: ");

	for (int i = 0; i < strlen(login.pw); i++)
	{
		printf("*");

	}
	printf("\n");
	return;
}