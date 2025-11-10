#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define MAX_STR_LEN 100

struct CONTACT {
    char name[MAX_STR_LEN];
    char phone[MAX_STR_LEN];
};

int count_contacts(const char* filename) {
    FILE* fp = NULL;
    errno_t err;
    int count = 0;
    char name_buf[MAX_STR_LEN];
    char phone_buf[MAX_STR_LEN];

    err = fopen_s(&fp, filename, "r");
    if (err != 0 || fp == NULL) {
        return 0;
    }

    while (fscanf_s(fp, "%99s %99s",
        name_buf, (unsigned)sizeof(name_buf),
        phone_buf, (unsigned)sizeof(phone_buf)) == 2) {
        count++;
    }

    fclose(fp);
    return count;
}

void load_contacts(const char* filename, struct CONTACT* contacts_array, int count) {
    FILE* fp = NULL;
    errno_t err;

    err = fopen_s(&fp, filename, "r");
    if (err != 0 || fp == NULL) {
        return;
    }

    for (int i = 0; i < count; i++) {
        fscanf_s(fp, "%99s %99s",
            contacts_array[i].name, (unsigned)sizeof(contacts_array[i].name),
            contacts_array[i].phone, (unsigned)sizeof(contacts_array[i].phone));
    }

    fclose(fp);
}

void save_contacts(const char* filename, const struct CONTACT* contacts_array, int count) {
    FILE* fp = NULL;
    errno_t err;

    err = fopen_s(&fp, filename, "w");
    if (err != 0 || fp == NULL) {
        fprintf(stderr, "오류: %s 파일 저장에 실패했습니다.\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf_s(fp, "%s %s\n", contacts_array[i].name, contacts_array[i].phone);
    }

    fclose(fp);
}

int search_contact(const struct CONTACT* contacts_array, int count, const char* search_name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts_array[i].name, search_name) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    char filename[MAX_STR_LEN];
    int contact_count = 0;
    struct CONTACT* contacts = NULL;
    struct CONTACT* temp_ptr = NULL;

    char search_name[MAX_STR_LEN];
    char new_phone[MAX_STR_LEN];
    char choice[10];
    int found_index;

    printf("연락처 파일명? ");
    if (scanf_s("%99s", filename, (unsigned)sizeof(filename)) != 1) return 1;

    contact_count = count_contacts(filename);
    printf("%d개의 연락처를 로딩했습니다.\n", contact_count);

    if (contact_count > 0) {
        contacts = (struct CONTACT*)malloc(contact_count * sizeof(struct CONTACT));
        if (contacts == NULL) {
            fprintf(stderr, "메모리 할당 실패\n");
            return 1;
        }
        load_contacts(filename, contacts, contact_count);
    }
    else {
        contacts = NULL;
    }

    while (1) {
        printf("이름( . 입력 시 종료)? ");
        if (scanf_s("%99s", search_name, (unsigned)sizeof(search_name)) != 1) break;

        if (strcmp(search_name, ".") == 0) break;

        found_index = search_contact(contacts, contact_count, search_name);

        if (found_index != -1) {
            printf("%s의 전화번호 %s로 전화를 겁니다....\n",
                contacts[found_index].name, contacts[found_index].phone);
        }
        else {
            printf("연락처를 찾을 수 없습니다. 연락처를 등록하시겠습니까(y/n)? ");
            if (scanf_s("%9s", choice, (unsigned)sizeof(choice)) != 1) break;

            if (tolower(choice[0]) == 'y') {
                printf("전화번호? ");
                if (scanf_s("%99s", new_phone, (unsigned)sizeof(new_phone)) != 1) break;

                temp_ptr = (struct CONTACT*)realloc(contacts, (contact_count + 1) * sizeof(struct CONTACT));
                if (temp_ptr == NULL) {
                    fprintf(stderr, "메모리 재할당 실패\n");
                    free(contacts);
                    return 1;
                }
                contacts = temp_ptr;

                strcpy_s(contacts[contact_count].name, (unsigned)sizeof(contacts[contact_count].name), search_name);
                strcpy_s(contacts[contact_count].phone, (unsigned)sizeof(contacts[contact_count].phone), new_phone);

                contact_count++;
            }
        }
    }

    save_contacts(filename, contacts, contact_count);
    printf("%s로 %d개의 연락처를 저장했습니다.\n", filename, contact_count);

    free(contacts);
    return 0;
}
