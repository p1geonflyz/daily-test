#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

int main(void)
{
	int user;
	int count = 0;
	int random;
	int totalBetting, gameSelect;
	int betting, userUpDown, dice1, dice2, dice3, sum, dealerUpDown, YesNo, tempBetting;
	int winCount = 0, loseCount = 0;
	double winRate = 0;
	//주사위 게임에 필요한 변수

	printf("광운랜드에 오신걸 환영합니다!\n");
	printf("카지노에서 쓸 충전하실 금액을 입력해주세요! : ");
	scanf("%d", &totalBetting);
	tempBetting = totalBetting;	//tempBetting은 처음 있었던 금액을 저장하는 변수
	printf("이 곳에서는 2가지 게임이 존재합니다!\n");

	while(1)
	{
		printf("\n업다운 게임을 하실꺼면 1번을, 주사위 게임을 하실꺼면 2번을 눌러주세요!\n");
		printf("게임을 종료하시려면 3번을 눌러주세요!\n");
		scanf("%d", &gameSelect);	//게임 정하기

		if (gameSelect == 1) {
			printf("업다운 게임을 선택하셨습니다! 잠시만 기다려주세요!\n");
			printf("배팅할 금액을 입력하시오 : ");
			scanf("%d", &betting);

			while (1)
			{
				srand(time(NULL));
				random = rand() % 100 + 1;
				//업다운 게임에 필요한 변수

				if (totalBetting <= 0)
				{
					printf("잔액이 부족합니다. 카지노를 나갑니다.\n");
					break;
				}

				else if (betting > totalBetting)
				{
					printf("예산 범위를 초과했습니다. 배팅 금액을 다시 설정해주세요.\n");
					break;
				}	//배팅 금액이 예산 범위를 초과하면 반복문이 끝남
			
				else
				{
					count = 0;
					while(1)
					{
						count++;
						printf("1~100의 값을 입력하시오: ");
						scanf("%d", &user);

						if (user < random)
						{
							printf("UP\n");
						}

						else if (user > random)
						{
							printf("DOWN\n");
						}

						else
						{
							printf("OK\n");
							break;
						}
					}

					if (count <= 5)
					{
						printf("GREAT!\n");
						totalBetting += 2*betting;
						break;
					}

					else if ((count > 5) && (count <= 10))
					{
						printf("GOOD\n");
						totalBetting += betting;;
						break;
					}

					else
					{
						printf("BAD\n");
						totalBetting -= betting;
						break;
					}
					
				}
			}
			
			printf("당신의 가기 전 총 금액은 %d, 나온 후 총 금액은 %d입니다.\n", tempBetting, totalBetting);
			printf("정답 : %d\n", random);
			printf("숫자 맞추는 데 걸린 횟수: %d\n", count);
			tempBetting = totalBetting;
		}
	
		else if(gameSelect == 2){
			printf("주사위 게임을 선택하셨습니다! 잠시만 기다려주세요!\n");
			while (1)
			{

				if (totalBetting <= 0)
				{
					printf("잔액이 부족합니다. 카지노를 나갑니다.\n");
					break;
				}

				do
				{
					printf("배팅할 금액을 입력하시오 : ");
					scanf("%d", &betting);

					if (betting > totalBetting)
					{
						printf("예산 범위를 초과했습니다. 배팅 금액을 다시 설정해주세요.\n");
					}
				} while (betting > totalBetting);	//배팅 금액이 예산 범위를 초과하면 반복문이 끝남

				srand(time(NULL));
				dice1 = rand() % 6 + 1;
				dice2 = rand() % 6 + 1;
				dice3 = rand() % 6 + 1;
				//random으로 설정 : 1~6까지

				sum = dice1 + dice2 + dice3;

				printf("Up/Down을 선택하시오(업은 1, 다운은 2) : ");
				scanf("%d", &userUpDown);

				if (sum >= 11)
				{
					dealerUpDown = 1;
				}

				else
				{
					dealerUpDown = 2;
				}

				for (int i = 10; i > 1; i--)
				{
					//Sleep(i * 1000);
					printf("주사위를 굴립니다.\n");
				}

				if (userUpDown == dealerUpDown)
				{
			
					winCount++;
					totalBetting += betting;
					printf("Win!\n당신의 잔액은 %d입니다.\n", totalBetting);
				}
				//이기면 이긴 횟수 증가 및 잔액 계산

				else
				{
					loseCount++;
					totalBetting -= betting;
					printf("Lose!\n당신의 잔액은 %d입니다.\n", totalBetting);
				}
				//지면 진 횟수 증가 및 잔액 계산

				printf("주사위1 : %d, 주사위2 : %d, 주사위3 : %d\n", dice1, dice2, dice3);

				printf("\n계속 진행하려면 1, 종료하려면 0을 입력하시오 : ");
				scanf("%d", &YesNo);

				if (YesNo == 0)
				{
					break;
				}
				//계속 진행 여부 확인 : YesNo가 0일 시 반복문 나감
			}

			winRate = (double)winCount / (winCount + loseCount) * 100;
			//winCount와 loseCount는 모두 int형이므로 자료형 변환을 하여 (double)형태로 출력한다.

			printf("당신의 가기 전 총 금액은 %d, 나온 후 총 금액은 %d입니다.\n", tempBetting, totalBetting);
			printf("승리횟수 : %d, 패배횟수 : %d\n", winCount, loseCount);
			printf("승률 : %.1lf%%\n", winRate);
			tempBetting = totalBetting;
		}	

		else if (gameSelect == 3)
		{
			printf("게임을 종료합니다.");
			break;
		}

		else
		{
			printf("잘못 입력하셨습니다.\n");
		}

	}
	printf("\n즐거운 시간되셨습니까? 안녕히 가십시오!\n");

	return 0;
}
