/*
학번: 202511241
이름 : 최정민
프로그램명: 8번
*/

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#define MAX_NAME_LENGTH 50

void assignment08();

int main()
{
    assignment08();
    return 0;
}

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int price;
    int stock;
} PRODUCT;

void print_product(const PRODUCT* product)
{
    printf("[%s %d원 재고: %d]\n", product->name, product->price, product->stock);
}

void assignment08()
{
    PRODUCT item;

    printf("제품명? ");
    fgets(item.name, MAX_NAME_LENGTH, stdin);
    item.name[strcspn(item.name, "\n")] = '\0';

    printf("가격? ");
    scanf_s("%d", &item.price);

    printf("재고? ");
    scanf_s("%d", &item.stock);

    print_product(&item);
}