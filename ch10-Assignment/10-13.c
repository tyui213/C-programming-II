/*
�й�: 202511241
�̸� : ������
���α׷���: 13�� ����
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
    printf("[RECT ���ϴ���:(%d, %d) ������:(%d, %d)]\n",
        r.bottomLeft.x, r.bottomLeft.y, r.topRight.x, r.topRight.y);
}

void assignment13()
{
    RECT rect;

    printf("���簢���� ���ϴ���(x,y)? ");
    scanf_s("%d %d", &rect.bottomLeft.x, &rect.bottomLeft.y);

    printf("���簢���� ������(x,y)? ");
    scanf_s("%d %d", &rect.topRight.x, &rect.topRight.y);

    print_rect(rect);
}