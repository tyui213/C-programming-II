#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARRAY_SIZE 20 

void fill_array(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

int get_user_value() {
    int value;
    printf("배열의 원소에 저장할 값? ");
    scanf("%d", &value);
    return value;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numbers[ARRAY_SIZE]; 
    int user_value;

    user_value = get_user_value();
    fill_array(numbers, ARRAY_SIZE, user_value);
    print_array(numbers, ARRAY_SIZE);

    return 0;
}