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
	//�ֻ��� ���ӿ� �ʿ��� ����

	printf("����忡 ���Ű� ȯ���մϴ�!\n");
	printf("ī���뿡�� �� �����Ͻ� �ݾ��� �Է����ּ���! : ");
	scanf("%d", &totalBetting);
	tempBetting = totalBetting;	//tempBetting�� ó�� �־��� �ݾ��� �����ϴ� ����
	printf("�� �������� 2���� ������ �����մϴ�!\n");

	while(1)
	{
		printf("\n���ٿ� ������ �Ͻǲ��� 1����, �ֻ��� ������ �Ͻǲ��� 2���� �����ּ���!\n");
		printf("������ �����Ͻ÷��� 3���� �����ּ���!\n");
		scanf("%d", &gameSelect);	//���� ���ϱ�

		if (gameSelect == 1) {
			printf("���ٿ� ������ �����ϼ̽��ϴ�! ��ø� ��ٷ��ּ���!\n");
			printf("������ �ݾ��� �Է��Ͻÿ� : ");
			scanf("%d", &betting);

			while (1)
			{
				srand(time(NULL));
				random = rand() % 100 + 1;
				//���ٿ� ���ӿ� �ʿ��� ����

				if (totalBetting <= 0)
				{
					printf("�ܾ��� �����մϴ�. ī���븦 �����ϴ�.\n");
					break;
				}

				else if (betting > totalBetting)
				{
					printf("���� ������ �ʰ��߽��ϴ�. ���� �ݾ��� �ٽ� �������ּ���.\n");
					break;
				}	//���� �ݾ��� ���� ������ �ʰ��ϸ� �ݺ����� ����
			
				else
				{
					count = 0;
					while(1)
					{
						count++;
						printf("1~100�� ���� �Է��Ͻÿ�: ");
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
			
			printf("����� ���� �� �� �ݾ��� %d, ���� �� �� �ݾ��� %d�Դϴ�.\n", tempBetting, totalBetting);
			printf("���� : %d\n", random);
			printf("���� ���ߴ� �� �ɸ� Ƚ��: %d\n", count);
			tempBetting = totalBetting;

		}
	
		else if(gameSelect == 2){
			printf("�ֻ��� ������ �����ϼ̽��ϴ�! ��ø� ��ٷ��ּ���!\n");
			while (1)
			{

				if (totalBetting <= 0)
				{
					printf("�ܾ��� �����մϴ�. ī���븦 �����ϴ�.\n");
					break;
				}

				do
				{
					printf("������ �ݾ��� �Է��Ͻÿ� : ");
					scanf("%d", &betting);

					if (betting > totalBetting)
					{
						printf("���� ������ �ʰ��߽��ϴ�. ���� �ݾ��� �ٽ� �������ּ���.\n");
					}
				} while (betting > totalBetting);	//���� �ݾ��� ���� ������ �ʰ��ϸ� �ݺ����� ����

				srand(time(NULL));
				dice1 = rand() % 6 + 1;
				dice2 = rand() % 6 + 1;
				dice3 = rand() % 6 + 1;
				//random���� ���� : 1~6����

				sum = dice1 + dice2 + dice3;

				printf("Up/Down�� �����Ͻÿ�(���� 1, �ٿ��� 2) : ");
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
					printf("�ֻ����� �����ϴ�.\n");
				}

				if (userUpDown == dealerUpDown)
				{
			
					winCount++;
					totalBetting += betting;
					printf("Win!\n����� �ܾ��� %d�Դϴ�.\n", totalBetting);
				}
				//�̱�� �̱� Ƚ�� ���� �� �ܾ� ���

				else
				{
					loseCount++;
					totalBetting -= betting;
					printf("Lose!\n����� �ܾ��� %d�Դϴ�.\n", totalBetting);
				}
				//���� �� Ƚ�� ���� �� �ܾ� ���

				printf("�ֻ���1 : %d, �ֻ���2 : %d, �ֻ���3 : %d\n", dice1, dice2, dice3);

				printf("\n��� �����Ϸ��� 1, �����Ϸ��� 0�� �Է��Ͻÿ� : ");
				scanf("%d", &YesNo);

				if (YesNo == 0)
				{
					break;
				}
				//��� ���� ���� Ȯ�� : YesNo�� 0�� �� �ݺ��� ����
			}

			winRate = (double)winCount / (winCount + loseCount) * 100;
			//winCount�� loseCount�� ��� int���̹Ƿ� �ڷ��� ��ȯ�� �Ͽ� (double)���·� ����Ѵ�.

			printf("����� ���� �� �� �ݾ��� %d, ���� �� �� �ݾ��� %d�Դϴ�.\n", tempBetting, totalBetting);
			printf("�¸�Ƚ�� : %d, �й�Ƚ�� : %d\n", winCount, loseCount);
			printf("�·� : %.1lf%%\n", winRate);
			tempBetting = totalBetting;
		}	

		else if (gameSelect == 3)
		{
			printf("������ �����մϴ�.");
			break;
		}

		else
		{
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
		}

	}
	printf("\n��ſ� �ð��Ǽ̽��ϱ�? �ȳ��� ���ʽÿ�!\n");

	return 0;
}