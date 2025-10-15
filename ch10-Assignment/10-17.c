/*
�й�: 202511241
�̸� : ������
���α׷���: 17�� ����
*/

#include <stdio.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct
{
    char title[50];
    char artist[50];
    char genre[20];
    int duration;
} Song;


int main()
{
}


void printSong(Song s)
{
    printf("%s %s %s %d��\n", s.title, s.artist, s.genre, s.duration);
}

void searchSongs(Song songs[], int count, char keyword[])
{
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strstr(songs[i].title, keyword) || strstr(songs[i].artist, keyword))
        {
            printSong(songs[i]);
            found = 1;
        }
    }
    if (!found)
    {
        printf("�˻� ����� �����ϴ�.\n");
    }
}

{
    Song songs[MAX_SONGS] =
    {
        {"I'm Fine", "��ź�ҳ��", "hip-hop", 209},
        {"����", "��ź�ҳ��", "hip-hop", 274},
        {"Awake", "��ź�ҳ��", "ballad", 226},
        {"�� ���� ����", "�ں���", "ballad", 316},
        {"Love Scenario", "iKON", "hip-hop", 213},
        {"������", "������", "ballad", 240}
    };
    int songCount = 6;

    char keyword[50];
    while (1)
    {
        printf("\nŰ����(����/��Ƽ��Ʈ)? ");
        fgets(keyword, sizeof(keyword), stdin);
        keyword[strcspn(keyword, "\n")] = '\0';

        if (strcmp(keyword, "!") == 0) break;

        searchSongs(songs, songCount, keyword);
    }
}