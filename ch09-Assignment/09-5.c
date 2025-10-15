/*
�й�: 202511241
�̸�: ������
���α׷���: 9�� ���� �� 2���L��
��¥: 20251010
*/

#include <stdio.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

void assignment0905();

int main() {
    assignment0905();
    return 0;
}



int strcmp_ic(const char* lhs, const char* rhs)
{
    while (*lhs && *rhs)
    {
        char c1 = tolower((unsigned char)*lhs);
        char c2 = tolower((unsigned char)*rhs);

        if (c1 != c2)
            return c1 - c2;

        lhs++;
        rhs++;
    }

    return tolower((unsigned char)*lhs) - tolower((unsigned char)*rhs);
}

void assignment0905()
{
    char str1[100], str2[100];

    printf("ù ��° ���ڿ� ? ");
    fgets(str1, sizeof(str1), stdin);

    printf("�� ��° ���ڿ� ? ");
    fgets(str2, sizeof(str2), stdin);

    for (int i = 0; str1[i]; i++)
    {
        if (str1[i] == '\n')
        {
            str1[i] = '\0';
            break;
        }
    }
    for (int i = 0; str2[i]; i++)
    {
        if (str2[i] == '\n')
        {
            str2[i] = '\0';
            break;
        }
    }

    int result = strcmp_ic(str1, str2);

    if (result < 0)
        printf("\"%s\"�� \"%s\"���� �۽��ϴ�.\n", str1, str2);
    else if (result > 0)
        printf("\"%s\"�� \"%s\"���� Ů�ϴ�.\n", str1, str2);
    else
        printf("%s�� %s�� �����ϴ�.\n", str1, str2);

}