/*
학번: 202511241
이름 : 최정민
프로그램명: 17번 문제
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
    printf("%s %s %s %d초\n", s.title, s.artist, s.genre, s.duration);
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
        printf("검색 결과가 없습니다.\n");
    }
}

{
    Song songs[MAX_SONGS] =
    {
        {"I'm Fine", "방탄소년단", "hip-hop", 209},
        {"봄날", "방탄소년단", "hip-hop", 274},
        {"Awake", "방탄소년단", "ballad", 226},
        {"별 보러 가자", "박보검", "ballad", 316},
        {"Love Scenario", "iKON", "hip-hop", 213},
        {"밤편지", "아이유", "ballad", 240}
    };
    int songCount = 6;

    char keyword[50];
    while (1)
    {
        printf("\n키워드(제목/아티스트)? ");
        fgets(keyword, sizeof(keyword), stdin);
        keyword[strcspn(keyword, "\n")] = '\0';

        if (strcmp(keyword, "!") == 0) break;

        searchSongs(songs, songCount, keyword);
    }
}