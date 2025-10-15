/*
학번: 202511241
이름: 최정민
프로그램명:18번
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10



void receive(int set[]);
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

void receive(int set[]);
void show(int set[], int count);
void assignment18();

int main()
{
    assignment18();
    return 0;
}

void assignment18()
{
    int set[SIZE] = { 0 };
    receive(set);
}

void receive(int set[])
{
    int count = 0;
    int input;
    int exists;

    while (count < SIZE)
    {
        printf("배열에 추가할 원소?");
        scanf("%d", &input);


        exists = 0;
        for (int i = 0; i < count; i++)
        {
            if (set[i] == input)
            {
                exists = 1;
                break;
            }
        }

        if (exists)
        {
            printf("해당 원소가 이미 [0]에 존재합니다.\n");
        }
        else
        {
            set[count++] = input;
            show(set, count);
        }
    }
}

void show(int set[], int count)
{
    printf("{ ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", set[i]);
    }
    printf("}\n");
}