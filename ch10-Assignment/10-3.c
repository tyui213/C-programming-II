/*
�й�: 202511241
�̸� : ������
���α׷���: 3������ �� 2������  
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct
{
	char ID[20];
	char PW[20];

}LOGIN;

void assignment1003();
LOGIN inputarray(LOGIN login);
int findLogin(LOGIN* login, LOGIN* loginCheak, int idx);

int main()
{
	assignment1003();

	return 0;
}

void assignment1003()
{
	LOGIN loginCheak[MAX] = { 0 };

	LOGIN login[MAX] =
	{
		{"guest", "idontknow"}
	};

	for (int i = 0; i < MAX; i++)
	{

		loginCheak[i] = inputarray(loginCheak[i]);
		if (findLogin(login, loginCheak, i) == 0)
		{
			printf("�α��� ����\n");

		}
		else
		{
			printf("Ʋ��\n");
		}
	}

	return;
}

LOGIN inputarray(LOGIN login)
{
	printf("\nID? ");
	scanf("%s", login.ID);

	printf("PW? ");
	scanf("%s", login.PW);

	return login;
}

int findLogin(LOGIN* login, LOGIN* loginCheak, int idx)
{
	for (int i = 0; i < MAX; i++)

	{

		if (strcmp(loginCheak[idx].ID, login[i].ID) == 0 && strcmp(loginCheak[idx].PW, login[i].PW) == 0)
		{
			return 0;
		}
	}

	return 1;
}