#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define MAX_FILENAME_LEN 100

void fill_array_random(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

int save_to_text(const char* filename, const int* arr, int n) {
    FILE* fp = NULL;
    errno_t err;

    err = fopen_s(&fp, filename, "w");
    if (err != 0 || fp == NULL) {
        fprintf(stderr, "오류: %s 텍스트 파일을 열 수 없습니다.\n", filename);
        return -1;
    }

    fprintf_s(fp, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf_s(fp, "%d\n", arr[i]);
    }

    fclose(fp);
    return 0;
}

int save_to_binary(const char* filename, const int* arr, int n) {
    FILE* fp = NULL;
    errno_t err;

    err = fopen_s(&fp, filename, "wb");
    if (err != 0 || fp == NULL) {
        fprintf(stderr, "오류: %s 2진 파일을 열 수 없습니다.\n", filename);
        return -1;
    }

    fwrite(&n, sizeof(int), 1, fp);
    fwrite(arr, sizeof(int), n, fp);

    fclose(fp);
    return 0;
}

int main(void) {
    int n = 0;
    int* data_array = NULL;
    char base_filename[MAX_FILENAME_LEN];
    char txt_filename[MAX_FILENAME_LEN];
    char dat_filename[MAX_FILENAME_LEN];

    srand((unsigned)time(NULL));

    printf("정수의 개수? ");
    if (scanf_s("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "유효하지 않은 개수입니다.\n");
        return 1;
    }

    printf("파일명? ");
    if (scanf_s("%99s", base_filename, (unsigned)sizeof(base_filename)) != 1) {
        fprintf(stderr, "파일명을 입력하세요.\n");
        return 1;
    }

    data_array = (int*)malloc(n * sizeof(int));
    if (data_array == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        return 1;
    }

    fill_array_random(data_array, n);

    strcpy_s(txt_filename, sizeof(txt_filename), base_filename);
    strcat_s(txt_filename, sizeof(txt_filename), ".txt");

    strcpy_s(dat_filename, sizeof(dat_filename), base_filename);
    strcat_s(dat_filename, sizeof(dat_filename), ".dat");

    if (save_to_text(txt_filename, data_array, n) == 0 &&
        save_to_binary(dat_filename, data_array, n) == 0) {
        printf("%s와 %s를 생성했습니다.\n", txt_filename, dat_filename);
    }

    free(data_array);
    return 0;
}
