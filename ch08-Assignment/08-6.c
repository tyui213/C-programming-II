/*
학번: 202511241
이름: 최정민
프로그램명: 5번
날짜: 2025-10-10
*/
#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>

#define ARRAY_SIZE 10

void get_min_max(const int arr[], int size, int* p_max, int* p_min);
void print_array(const int arr[], int size);

int main(void) {
    int numbers[ARRAY_SIZE] = { 23, 45, 82, 12, 99, 83, 23, 50, 72, 37 };
    int max_val;
    int min_val;

    print_array(numbers, ARRAY_SIZE);

    get_min_max(numbers, ARRAY_SIZE, &max_val, &min_val);

    printf("최댓값: %d\n", max_val);
    printf("최솟값: %d\n", min_val);

    return 0;
}

void get_min_max(const int arr[], int size, int* p_max, int* p_min) {
    *p_max = arr[0];
    *p_min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > *p_max) {
            *p_max = arr[i];
        }
        if (arr[i] < *p_min) {
            *p_min = arr[i];
        }
    }
}

void print_array(const int arr[], int size) {
    printf("배열: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}