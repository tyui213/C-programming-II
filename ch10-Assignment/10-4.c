/*
학번: 202511241
이름 : 최정민
프로그램명: 4번문제 별 1개
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    int year;
    int month;
    int day;
} DATE;

void print_date(DATE d);

int main(void) {
    DATE input_date;

    printf("연도: ");
    scanf("%d", &input_date.year);

    printf("월: ");
    scanf("%d", &input_date.month);

    printf("일: ");
    scanf("%d", &input_date.day);

    print_date(input_date);

    return 0;
}

void print_date(DATE d) {
    printf("%d/%d/%d\n", d.year, d.month, d.day);
}