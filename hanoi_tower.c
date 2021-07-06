#include<stdio.h>

int main(void) {
    int n;  //원반개수 n개를 저장할 변수 n
    printf("<<하노이의 탑>>\n");
    printf("원반개수: ");
    scanf_s("%d", &n);  //원반개수 n을 입력받음
    Hanoi(1, 3, n); //하노이의 탑은 결국 모든 원반이 1번 기둥에서 3번으로 가야 종료됨
    
}

int Hanoi(int from, int to, int n) //from번 기둥에서 to번 기둥으로 n개의 원반을 이동
{   
    
    if (n == 1)
    {
        printf("%d번기둥에서 %d번기둥으로\n", from, to);
        
        return 0;
    }   //원반은 한번에 1개씩 이동

    Hanoi(from, 6 - from - to, n - 1);
    printf("%d번기둥에서 %d번기둥으로\n", from, to);
    Hanoi(6 - from - to, to, n - 1);
    return 0;
    //재귀함수를 이용하여, n=1일 때 Hanoi의 원반이 비로소 움직이는 것을 구현한다.
}