/*
학번: 202511241
이름: 최정민
프로그램명:15번
날짜: 2025-10-10
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void assignment15();

int main()
{
    assignment15();
    return 0;
}

void sort_array(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void assignment15()
{
    int x[10];
    srand((unsigned)time(NULL));

    for (int i = 0; i < 10; i++)
    {
        x[i] = rand() % 100;
    }

    printf("정렬 전: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");

    sort_array(x, 10);

    printf("정렬 후: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}