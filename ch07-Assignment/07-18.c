/*
�й�: 202511241
�̸�: ������
���α׷���:18��
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
        printf("�迭�� �߰��� ����?");
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
            printf("�ش� ���Ұ� �̹� [0]�� �����մϴ�.\n");
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