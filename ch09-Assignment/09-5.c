/*
학번: 202511241
이름: 최정민
프로그램명: 9번 문제 별 2개묹제
날짜: 20251010
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

    printf("첫 번째 문자열 ? ");
    fgets(str1, sizeof(str1), stdin);

    printf("두 번째 문자열 ? ");
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
        printf("\"%s\"가 \"%s\"보다 작습니다.\n", str1, str2);
    else if (result > 0)
        printf("\"%s\"가 \"%s\"보다 큽니다.\n", str1, str2);
    else
        printf("%s와 %s는 같습니다.\n", str1, str2);

}