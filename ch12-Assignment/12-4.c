#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_STR_LEN 100

struct LOGIN {
    char id[MAX_STR_LEN];
    char pw[MAX_STR_LEN];
};

int load_logins(struct LOGIN users[], int max_size) {
    FILE* fp = NULL;
    errno_t err;
    int count = 0;

    err = fopen_s(&fp, "password.txt", "r");
    if (err != 0 || fp == NULL) {
        fprintf(stderr, "password.txt 파일을 열 수 없습니다.\n");
        return 0;
    }

    while (count < max_size &&
        fscanf_s(fp, "%99s %99s",
            users[count].id, (unsigned)sizeof(users[count].id),
            users[count].pw, (unsigned)sizeof(users[count].pw)) == 2) {
        count++;
    }

    fclose(fp);
    return count;
}

int find_user(const struct LOGIN users[], int count, const char* input_id) {
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].id, input_id) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    struct LOGIN users[MAX_USERS];
    int user_count = 0;
    char input_id[MAX_STR_LEN];
    char input_pw[MAX_STR_LEN];
    int user_index;

    user_count = load_logins(users, MAX_USERS);
    if (user_count == 0) {
        return 1;
    }

    while (1) {
        printf("ID? ");
        if (scanf_s("%99s", input_id, (unsigned)sizeof(input_id)) != 1) {
            break;
        }

        user_index = find_user(users, user_count, input_id);

        if (user_index == -1) {
            printf("아이디를 찾을 수 없습니다.\n");
        }
        else {
            printf("Password? ");
            if (scanf_s("%99s", input_pw, (unsigned)sizeof(input_pw)) != 1) {
                break;
            }

            if (strcmp(users[user_index].pw, input_pw) == 0) {
                printf("로그인 성공\n");
            }
            else {
                printf("로그인 실패\n");
            }
        }
    }

    return 0;
}
