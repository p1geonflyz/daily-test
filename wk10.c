#include<stdio.h>

int main(void)
{
	int a[10] = { 0, };
	int* b;
	b = &a;

	printf("Q1. 배열에 정수 10개를 입력하시오\n");
	
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("입력된 정수 10개를 출력합니다\n");
	
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);
	}

	printf("\nQ2. 포인터를 이용하여 1차원 정수 배열에 저장된 값을 역순으로 출력하시오\n");
	
	for (int i = 9; i >= 0; i--)
	{
		printf("%3d", *(b+i));
	}
	
	return 0;
}

