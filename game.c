#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

int main(void)
{
	int user;
	int count = 0;
	srand(time(NULL));
	int random = rand() % 100 + 1;
	//���ٿ� ���ӿ� �ʿ��� ����

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
	printf("���ٿ� ������ �Ͻǲ��� 1����, �ֻ��� ������ �Ͻǲ��� 2���� �����ּ���! ");
	scanf("%d", &gameSelect);	//���� ���ϱ�

	if (gameSelect == 1) {
		printf("���ٿ� ������ �����ϼ̽��ϴ�! ��ø� ��ٷ��ּ���!\n");
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

			count++;
			printf("1~100�� ���� �Է��Ͻÿ� : ");
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
				printf("BINGO!\n");
				break;
			}

		}

		if (count <= 5)
		{
			printf("GREAT!\n");
		}

		else if ((count > 5) && (count <= 10))
		{
			printf("GOOD\n");
		}

		else
		{
			printf("BAD\n");
		}

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
				Sleep(i * 200);
				printf("�ֻ����� �����ϴ�.\n");
			}

			if (userUpDown == dealerUpDown)
			{
			
				winCount++;
				totalBetting += betting;
				printf("Win!\n����� �ܾ��� %d�Դϴ�.", totalBetting);
			}
			//�̱�� �̱� Ƚ�� ���� �� �ܾ� ���

			else
			{
				loseCount++;
				totalBetting -= betting;
				printf("Lose!\n����� �ܾ��� %d�Դϴ�.", totalBetting);
			}
			//���� �� Ƚ�� ���� �� �ܾ� ���

			printf("��� �����Ϸ��� 1, �����Ϸ��� 0�� �Է��Ͻÿ� : ");
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
		printf("�·� : %.1lf%%", winRate);
	}	

	printf("��ſ� �ð��Ǽ̽��ϱ�? �ȳ��� ���ʽÿ�!\n");

	return 0;
}