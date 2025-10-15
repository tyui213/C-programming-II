/*
�й�: 202511241
�̸�: ������
���α׷���:17������ �� 3������
��¥: 2025-10-10
*/

#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_SONGS 20
#define MAX_TITLE_LENGTH 41  


void assignment0917();

int main()
{
    assignment0917();
    return 0;
}

void printMenu()
{
    printf("[ 0.���� 1.�߰� 2.���� 3.��� ] ����? ");
}

void printSongs(char songs[][MAX_TITLE_LENGTH], int count)
{
    printf("<< �뷡 ��� >>\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", songs[i]);
    }
}

int findSongIndex(char songs[][MAX_TITLE_LENGTH], int count, char* target)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(songs[i], target) == 0)
        {
            return i;
        }
    }
    return -1;
}

void assignment0917()
{
    char songs[MAX_SONGS][MAX_TITLE_LENGTH];
    int count = 0;
    int choice;

    while (1) {
        printMenu();
        scanf_s("%d", &choice);
        getchar();

        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            if (count >= MAX_SONGS)
            {
                printf("�� �̻� �߰��� �� �����ϴ�.\n");
                continue;
            }
            printf("�뷡 ����? ");
            fgets(songs[count], MAX_TITLE_LENGTH, stdin);
            songs[count][strcspn(songs[count], "\n")] = '\0';
            count++;
            printSongs(songs, count);
        }
        else if (choice == 2)
        {
            char target[MAX_TITLE_LENGTH], newTitle[MAX_TITLE_LENGTH];
            printf("ã�� �뷡 ����? ");
            fgets(target, MAX_TITLE_LENGTH, stdin);
            target[strcspn(target, "\n")] = '\0';

            int index = findSongIndex(songs, count, target);
            if (index == -1)
            {
                printf("�뷡�� ã�� �� �����ϴ�.\n");
            }
            else
            {
                printf("������ ����? ");
                fgets(newTitle, MAX_TITLE_LENGTH, stdin);
                newTitle[strcspn(newTitle, "\n")] = '\0';
                strcpy_s(songs[index], MAX_TITLE_LENGTH, newTitle);
            }
        }
        else if (choice == 3)
        {
            printSongs(songs, count);
        }
        else
        {
            printf("�߸��� �����Դϴ�.\n");
        }
    }
}