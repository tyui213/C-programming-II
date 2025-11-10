#include <stdio.h>

int main(void) {
    int numbers[5] = { 10, 20, 30, 40, 50 };
    int* ptr = numbers;
    int i;

    printf("배열 원소의 값과 주소:\n");

    for (i = 0; i < 5; i++) {
        printf("Value: %d, Address: %p\n", *(ptr + i), (ptr + i));
    }

    return 0;
}