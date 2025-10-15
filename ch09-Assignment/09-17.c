/*
학번: 202511241
이름: 최정민
프로그램명:17번문제 별 3개문제
날짜: 2025-10-10
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
    printf("[ 0.종료 1.추가 2.수정 3.목록 ] 선택? ");
}

void printSongs(char songs[][MAX_TITLE_LENGTH], int count)
{
    printf("<< 노래 목록 >>\n");
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
                printf("더 이상 추가할 수 없습니다.\n");
                continue;
            }
            printf("노래 제목? ");
            fgets(songs[count], MAX_TITLE_LENGTH, stdin);
            songs[count][strcspn(songs[count], "\n")] = '\0';
            count++;
            printSongs(songs, count);
        }
        else if (choice == 2)
        {
            char target[MAX_TITLE_LENGTH], newTitle[MAX_TITLE_LENGTH];
            printf("찾을 노래 제목? ");
            fgets(target, MAX_TITLE_LENGTH, stdin);
            target[strcspn(target, "\n")] = '\0';

            int index = findSongIndex(songs, count, target);
            if (index == -1)
            {
                printf("노래를 찾을 수 없습니다.\n");
            }
            else
            {
                printf("수정할 제목? ");
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
            printf("잘못된 선택입니다.\n");
        }
    }
}