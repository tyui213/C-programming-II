/*
이름 최정민
학번 202511241
프로그램명 9-2번 별 2개 문제
날짜 2025-10-10
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STRING_LENGTH 256

void remove_space(char* str);

int main(void) {
    char text[MAX_STRING_LENGTH];

    printf("문자열? ");

    if (fgets(text, sizeof(text), stdin) != NULL) {
        remove_space(text);
        printf("공백 문자 제거후: %s\n", text);
    }

    return 0;
}

void remove_space(char* str) {
    int read_index = 0;
    int write_index = 0;

    while (str[read_index] != '\0') {
        char c = str[read_index];

        if (c != ' ' && c != '\t' && c != '\n' && c != '\v' && c != '\f' && c != '\r') {
            str[write_index] = str[read_index];
            write_index++;
        }
        read_index++;
    }

    str[write_index] = '\0';
}