/*
학번: 202511241
이름: 최정민
프로그램명: 5번
날짜: 2025-10-10
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARRAY_SIZE 10

void arith_seq(int arr[], int size, int first_term, int common_diff);
void print_sequence(const int arr[], int size);

int main(void) {
    int first_term;
    int common_diff;
    int sequence[ARRAY_SIZE];

    printf("첫 번째 항? ");
    scanf("%d", &first_term);

    printf("공차? ");
    scanf("%d", &common_diff);

    arith_seq(sequence, ARRAY_SIZE, first_term, common_diff);
    print_sequence(sequence, ARRAY_SIZE);

    return 0;
}

void arith_seq(int arr[], int size, int first_term, int common_diff) {
    arr[0] = first_term;
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i - 1] + common_diff;
    }
}

void print_sequence(const int arr[], int size) {
    printf("등차수열: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}