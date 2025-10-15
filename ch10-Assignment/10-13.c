/*
학번: 202511241
이름 : 최정민
프로그램명: 13번 문제
*/

#include <stdio.h>

void assignment13();

int main()
{
    assignment13();
    return 0;
}

typedef struct
{
    int x;
    int y;
} POINT;

typedef struct
{
    POINT bottomLeft;
    POINT topRight;
} RECT;

void print_rect(RECT r)
{
    printf("[RECT 좌하단점:(%d, %d) 우상단점:(%d, %d)]\n",
        r.bottomLeft.x, r.bottomLeft.y, r.topRight.x, r.topRight.y);
}

void assignment13()
{
    RECT rect;

    printf("직사각형의 좌하단점(x,y)? ");
    scanf_s("%d %d", &rect.bottomLeft.x, &rect.bottomLeft.y);

    printf("직사각형의 우상단점(x,y)? ");
    scanf_s("%d %d", &rect.topRight.x, &rect.topRight.y);

    print_rect(rect);
}