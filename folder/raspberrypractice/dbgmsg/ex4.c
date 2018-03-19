#include <stdio.h>
void f1(void);
void f2(void);
void f3(void);

int main(void)
{
	printf("file name:%s\n", __FILE__);   // 소스 파일명출력
	printf("function name:%s [%d]\n", __func__, __LINE__); // 함수의 이름, 소스 줄 번호 출력
	printf("datetime:%s %s\n", __DATE__, __TIME__); // 전처리기 수행 시간 출력
	f1();
	f2();
	f3();
	return 0;
}

void f1(void)
{
	printf("%s [%d]\n", __func__, __LINE__);
}

void f2(void)
{
	printf("%s [%d]\n", __func__, __LINE__);
}

void f3(void)
{
	printf("%s [%d]\n", __func__, __LINE__);
}

