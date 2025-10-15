/*
�й�: 202511241
�̸�: ������
���α׷���: 5��
��¥: 2025-10-10
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

    printf("ù ��° ��? ");
    scanf("%d", &first_term);

    printf("����? ");
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
    printf("��������: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}