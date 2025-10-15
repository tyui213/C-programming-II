/*
이름 최정민 
학번 202511241
프로그램명 9-1번 별 1개 문제 
날짜 2025-10-10
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STR_LEN 256

int count_whitespace(const char* str);

int main(void) {
    char input_str[MAX_STR_LEN];
    int whitespace_count = 0;

    printf("문자열: ");

   
    if (fgets(input_str, sizeof(input_str), stdin) != NULL) {
        whitespace_count = count_whitespace(input_str);
        printf("공백 문자의 개수: %d\n", whitespace_count);
    }

    return 0;
}

int count_whitespace(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r') {
            count++;
        }
    }
    return count;
}