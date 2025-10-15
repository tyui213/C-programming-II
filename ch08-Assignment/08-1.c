#include <stdio.h>


void assignment01();

int main()
{
    assignment01();
    return 0;
}

void assignment01()
{
    double x[3] = { 1.1, 2.2, 3.3 };


    for (int i = 0; i < 3; i++)
    {
        printf("x[%d]ÀÇ ÁÖ¼Ò: %p\n", i, (x + i));
    }
}