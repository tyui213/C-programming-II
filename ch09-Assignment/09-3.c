/*
이름 최정민
학번 202511241
프로그램명 9-3번 별 1개 문제
날짜 2025-10-10
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

#define MAX_STR_LEN 256

void toggle_case(char* str);

int main(void) {
    char text[MAX_STR_LEN];

    printf("문자열: ");

    if (fgets(text, sizeof(text), stdin) != NULL) {
        toggle_case(text);
        printf("변환 후: %s", text);
    }

    return 0;
}

void toggle_case(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
        else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}