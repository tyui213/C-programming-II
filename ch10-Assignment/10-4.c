/*
�й�: 202511241
�̸� : ������
���α׷���: 4������ �� 1��
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

    printf("����: ");
    scanf("%d", &input_date.year);

    printf("��: ");
    scanf("%d", &input_date.month);

    printf("��: ");
    scanf("%d", &input_date.day);

    print_date(input_date);

    return 0;
}

void print_date(DATE d) {
    printf("%d/%d/%d\n", d.year, d.month, d.day);
}