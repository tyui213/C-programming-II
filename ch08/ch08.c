/*
학번：202511241
이름: 최정민
날짜: 0917
내용: 8장 포인터 실습
*/

#include<stdio.h>

void* swapDouble(double* pa, double* pb);//전방선언
void print_array_double(double arr[], int sz);//전방선언
void printArryDouble(double* arr, int sz);//전방선언
int test_print_arry();//전방선언
int test_function_pointer();//전방선언
int main()
{
	//test_swap;
	test_print_arry();
	test_function_pointer();
	return 0;
}

int test_swap()
{
	printf("Hello,World\n");

	double a = 3.14;
	double b = 5.12;

	double* presult = (double*)swapDouble(&a, &b);
	if (presult == NULL)
	{
		printf("뭔가 잘못되었어!\n");
	}
	else
	{
		printf("a = %lf, b = %lf\n,", a, b);
	}

	double* presult1 = (double*)swapDouble(&a, &b);
	if (presult1 == NULL)
	{
		printf("뭔가 잘못되었어2!\n");
	}
	else
	{
		printf("a = %lf, b = %lf\n,", a, b);
	}

}

void* swapDouble(double* pa, double* pb)
{
	//1. 읿력 값 정상인지 체크: NULL이 아니여야함
	if (pa = NULL || pb == NULL)
	{
		return NULL;
	}
	//2.swap two values
	double tmp = *pa;
	*pa = *pb;
	*pb = tmp;

	return pa;
}

int test_print_arry()
{
	double da[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };

	int size = sizeof(da) / sizeof(da[0]);

	print_array_double(da, size);

	printArryDouble(da, size);

	return 0;
}


// 기능: 1차원 실수 배열을 출력한다.
// 함수명: print_array_double
// 입력: double 타입 1차원 배열 주소
// 출력: 터미널에 배열의 내용을 예쁘게 출력
// 변환: 없음

void print_array_double(double arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("% lf", arr[i]);
	}
	printf("\n");
}


void printArryDouble(double* arr, int sz)
{
	for (int i = 0; i < sz; i++, arr++)
	{
		printf("% lf", *arr);
	}
	printf("\n");
}

int test_function_pointer()
{
	double (*pfunc)(double, double) = NULL;
	double result = 0;

	pfunc = add;

	printf("add(3, 4) = %lf\n", add(3, 0, 4.0));

	add(3, 4);

	double result = (*pfunc) (3.0, 4.0); //7.0?
}

//정수 덧셈 결관 반환
//입력: 두 실수 
//출력: 더한 값
double add(double a, double b)
{
	return a + b;
}
//기능 정수 뺄셈
//입력: 두 정수
//출력: 뺀 값
double sub(double a, double b)
{
	return a - b;
}

//기능: 정수곱셈
//입력: 두 정수
//출력: 곱셈값
double mul(double a, double b)
{
	return a * b;
}