#include<stdio.h>
test_io(void);
int main(int argc, char* argv[])
{
	printf("Hello, World!\n");

	fprintf(stderr, "Hello,World!\n");

	fprintf(stdout, "Hello, World!\n");
	test_io();

	return 0;
}
#define FNAME "BTS.txt"

int test_io(void)
{
	int x = 0;

	int res = fscanf(stdin, "%d", &x);
	fprintf(stdout, "입력값: %d,반환값:%d\n", x, res);

	FILE* fBTS = NULL;

	fBTS = fopen("c:/Temp/BTS.txt", "w");
		//if (fBTS == NULL)
	{
		fprintf(stderr, "파일 오픈 실패\n");

	};
	else
		(
		int res = fscanf(fBTS, "%d", &x);
		fprintf(stdout, "입력값: %d,반환값:%d\n", x, res);
		fprintf(fBTS, "입력값:%d 반환값:%d\n", x, res);
			)
			fflush(fBTS);
			fclose(fBTS);
}