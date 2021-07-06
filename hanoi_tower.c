#include<stdio.h>

int main(void) {
    int n;  //���ݰ��� n���� ������ ���� n
    printf("<<�ϳ����� ž>>\n");
    printf("���ݰ���: ");
    scanf_s("%d", &n);  //���ݰ��� n�� �Է¹���
    Hanoi(1, 3, n); //�ϳ����� ž�� �ᱹ ��� ������ 1�� ��տ��� 3������ ���� �����
    
}

int Hanoi(int from, int to, int n) //from�� ��տ��� to�� ������� n���� ������ �̵�
{   
    
    if (n == 1)
    {
        printf("%d����տ��� %d���������\n", from, to);
        
        return 0;
    }   //������ �ѹ��� 1���� �̵�

    Hanoi(from, 6 - from - to, n - 1);
    printf("%d����տ��� %d���������\n", from, to);
    Hanoi(6 - from - to, to, n - 1);
    return 0;
    //����Լ��� �̿��Ͽ�, n=1�� �� Hanoi�� ������ ��μ� �����̴� ���� �����Ѵ�.
}