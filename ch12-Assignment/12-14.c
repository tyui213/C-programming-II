#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_FILENAME_LEN 100

int* load_binary_file(const char* filename, int* out_count) {
    FILE* fp = NULL;
    errno_t err;
    int n = 0;
    int* arr = NULL;

    *out_count = 0;

    err = fopen_s(&fp, filename, "rb");
    if (err != 0 || fp == NULL) {
        fprintf(stderr, "오류: %s 파일을 열 수 없습니다.\n", filename);
        return NULL;
    }

    if (fread_s(&n, sizeof(int), sizeof(int), 1, fp) != 1 || n <= 0) {
        fprintf(stderr, "오류: %s 파일에서 유효한 개수를 읽지 못했습니다.\n", filename);
        fclose(fp);
        return NULL;
    }

    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        fclose(fp);
        return NULL;
    }

    if (fread_s(arr, n * sizeof(int), sizeof(int), n, fp) != n) {
        fprintf(stderr, "오류: %s 파일에서 데이터를 읽는 데 실패했습니다.\n", filename);
        fclose(fp);
        free(arr);
        return NULL;
    }

    fclose(fp);
    *out_count = n;
    printf("정수 %d개를 읽었습니다.\n", n);
    return arr;
}

int save_binary_file(const char* filename, const int* arr, int n) {
    FILE* fp = NULL;
    errno_t err;

    err = fopen_s(&fp, filename, "wb");
    if (err != 0 || fp == NULL) {
        fprintf(stderr, "오류: %s 2진 파일을 열 수 없습니다.\n", filename);
        return -1;
    }

    if (fwrite(&n, sizeof(int), 1, fp) != 1) {
        fprintf(stderr, "오류: 파일에 개수 쓰기 실패\n");
        fclose(fp);
        return -1;
    }

    if (fwrite(arr, sizeof(int), n, fp) != n) {
        fprintf(stderr, "오류: 파일에 데이터 쓰기 실패\n");
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 0;
}

int compare_int(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    char file1[MAX_FILENAME_LEN];
    char file2[MAX_FILENAME_LEN];
    char file_out[MAX_FILENAME_LEN];

    int* arr1 = NULL;
    int* arr2 = NULL;
    int* combined_arr = NULL;

    int count1 = 0;
    int count2 = 0;
    int total_count = 0;

    printf("첫 번째 파일명? ");
    if (scanf_s("%99s", file1, (unsigned)sizeof(file1)) != 1) return 1;
    arr1 = load_binary_file(file1, &count1);
    if (arr1 == NULL) return 1;

    printf("두 번째 파일명? ");
    if (scanf_s("%99s", file2, (unsigned)sizeof(file2)) != 1) {
        free(arr1);
        return 1;
    }
    arr2 = load_binary_file(file2, &count2);
    if (arr2 == NULL) {
        free(arr1);
        return 1;
    }

    total_count = count1 + count2;
    combined_arr = (int*)malloc(total_count * sizeof(int));
    if (combined_arr == NULL) {
        fprintf(stderr, "결합 배열 메모리 할당 실패\n");
        free(arr1);
        free(arr2);
        return 1;
    }

    memcpy_s(combined_arr, total_count * sizeof(int),
        arr1, count1 * sizeof(int));

    memcpy_s(combined_arr + count1, (total_count - count1) * sizeof(int),
        arr2, count2 * sizeof(int));

    qsort(combined_arr, total_count, sizeof(int), compare_int);

    printf("저장할 파일명? ");
    if (scanf_s("%99s", file_out, (unsigned)sizeof(file_out)) != 1) {
        free(arr1);
        free(arr2);
        free(combined_arr);
        return 1;
    }

    if (save_binary_file(file_out, combined_arr, total_count) == 0) {
        printf("정수 %d개를 저장했습니다.\n", total_count);
    }

    free(arr1);
    free(arr2);
    free(combined_arr);

    return 0;
}
