#include <stdio.h>

#define MAX_FILENAME_LEN 100
#define MAX_LINE_LEN 1024

int print_file_with_lines(const char* filename) {
    FILE* file_ptr = NULL;
    char line_buffer[MAX_LINE_LEN];
    int line_number = 1;
    errno_t err;

    err = fopen_s(&file_ptr, filename, "r");

    if (err != 0 || file_ptr == NULL) {
        fprintf(stderr, "오류: '%s' 파일을 열 수 없습니다.\n", filename);
        return -1;
    }

    while (fgets(line_buffer, MAX_LINE_LEN, file_ptr) != NULL) {
        printf("%d: %s", line_number, line_buffer);
        line_number++;
    }

    fclose(file_ptr);

    return 0;
}

int main(void) {
    char filename[MAX_FILENAME_LEN];

    printf("파일명? ");

    if (scanf_s("%99s", filename, (unsigned)sizeof(filename)) != 1) {
        fprintf(stderr, "입력 오류.\n");
        return 1;
    }

    print_file_with_lines(filename);

    return 0;
}
