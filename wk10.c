#include<stdio.h>

int main(void)
{
	int a[10] = { 0, };
	int* b;
	b = &a;

	printf("Q1. �迭�� ���� 10���� �Է��Ͻÿ�\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("�Էµ� ���� 10���� ����մϴ�\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);
	}

	printf("\nQ2. �����͸� �̿��Ͽ� 1���� ���� �迭�� ����� ���� �������� ����Ͻÿ�\n");
	for (int i = 9; i >= 0; i--)
	{
		printf("%3d", *(b+i));
	}
	return 0;
}