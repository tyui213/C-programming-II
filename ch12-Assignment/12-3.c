#include <stdio.h>
#include <ctype.h>

#define MAX_FILENAME_LEN 100
#define MAX_LINE_LEN 1024
#define ALPHABET_COUNT 26

int process_file_and_count_chars(const char* filename) {
    FILE* file_ptr = NULL;
    errno_t err;
    int alphabet_counts[ALPHABET_COUNT] = { 0 };
    char line_buffer[MAX_LINE_LEN];
    int c;

    err = fopen_s(&file_ptr, filename, "r");
    if (err != 0 || file_ptr == NULL) {
        fprintf(stderr, "오류: '%s' 파일을 열 수 없습니다.\n", filename);
        return -1;
    }

    while (fgets(line_buffer, MAX_LINE_LEN, file_ptr) != NULL) {
        printf("%s", line_buffer);
    }
    printf("\n");

    rewind(file_ptr);

    while ((c = fgetc(file_ptr)) != EOF) {
        if (isalpha(c)) {
            c = tolower(c);
            alphabet_counts[c - 'a']++;
        }
    }

    fclose(file_ptr);

    for (int i = 0; i < ALPHABET_COUNT; i++) {
        if (alphabet_counts[i] > 0) {
            printf("%c:%d ", (char)(i + 'a'), alphabet_counts[i]);
        }
    }
    printf("\n");

    return 0;
}

int main(void) {
    char filename[MAX_FILENAME_LEN];

    printf("파일명? ");
    if (scanf_s("%99s", filename, (unsigned)sizeof(filename)) != 1) {
        fprintf(stderr, "입력 오류.\n");
        return 1;
    }

    process_file_and_count_chars(filename);

    return 0;
}
