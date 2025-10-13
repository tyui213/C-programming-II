#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_array(int arr[], int size);
int find_max_index(int arr[], int size);
int find_min_index(int arr[], int size);
void print_results(int arr[], int max_idx, int min_idx);

int main() {
    int arr[] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
    int n = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, n);
    int max_idx = find_max_index(arr, n);
    int min_idx = find_min_index(arr, n);

    print_results(arr, max_idx, min_idx);

    return 0;
}

void print_array(int arr[], int size) {
    printf("¹è¿­: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int find_max_index(int arr[], int size) {
    int max_idx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }
    return max_idx;
}

int find_min_index(int arr[], int size) {
    int min_idx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

void print_results(int arr[], int max_idx, int min_idx) {
    printf("ÃÖ´ñ°ª: ÀÎµ¦½º=%d, °ª=%d\n", max_idx, arr[max_idx]);
    printf("ÃÖ¼Ú°ª: ÀÎµ¦½º=%d, °ª=%d\n", min_idx, arr[min_idx]);
}