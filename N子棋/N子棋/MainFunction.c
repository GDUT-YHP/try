#include "game.h"
/*ȫ�ֱ���������*/
extern int row;
extern int col;

/*���˵�*/
void MainMemu()
{
	system("cls");
	int UserChoice = 0;
	printf("-------------������N����---------------------------\n\n");

	printf("-------------1����ʼ��Ϸ---------------------------\n");
	printf("-------------2����   ��----------------------------\n");
	scanf_s("%d", &UserChoice);
	switch (UserChoice)
	{
	case 1:
		StartGame();
		break;
	case 2:
		ExitGame();
		break;
	default:
		printf("��ӣ�1/2��ѡ��Ŷ~~\n");
		printf("�����������");
		system("pause");
		MainMemu();

		break;

	}
}


void StartGame()
{
	char checkerBoard[ROW][COL];
	char result = 0;
	initCheckerBoard(checkerBoard, ROW, COL);
	Display(checkerBoard, ROW, COL);

	while (1)
	{
		//����������
		PlayerMove(checkerBoard, ROW, COL);
		Display(checkerBoard, ROW, COL);
	    result = IsOver(checkerBoard, ROW, COL);
		if (result != 'C')
		{
			break;
		}

		//��������
		ComputerMove(checkerBoard, ROW, COL);
		Display(checkerBoard, ROW, COL);
		result = IsOver(checkerBoard, ROW, COL);
		if (result != 'C')
		{
			break;
		}

	}


	if (result == 'u')
	{
		system("cls");
		printf("���Ӯ��");

	}
	else if (result == 'x')
	{
		system("cls");
		printf("����Ӯ�������������С����");

	}
	else
	{
		system("cls");
		printf("��ǿ��ƽ��");
	}	 



}


char IsOver(char checkerborard[ROW][COL], int row, int col)
{

	//�ж���
	for (int  i = 0; i < row; i++)
	{
		if (checkerborard[i][0] == checkerborard[i][1] && checkerborard[i][1] == checkerborard[i][2] && checkerborard[i][1] != ' ')
		{
			return checkerborard[i][1];
		}
	}

	//�ж���
	for (int i = 0; i < col; i++)
	{
		if (checkerborard[0][i] == checkerborard[1][i] && checkerborard[1][i] == checkerborard[2][i] && checkerborard[1][i] != ' ')
		{
			return checkerborard[1][i];
		}
	}

	//�ж϶Խ���
	if (checkerborard[0][0] == checkerborard[1][1] && checkerborard[1][1] == checkerborard[2][2]&& checkerborard[1][1] != ' ')
	{
		return checkerborard[1][1];
	}
	if (checkerborard[0][2] == checkerborard[1][1] && checkerborard[1][1] == checkerborard[2][0] && checkerborard[1][1] != ' ')
	{
		return checkerborard[1][1];
	}
	//�ж�ƽ�����Ƿ����
	int ret = IsFUll(checkerborard, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	else
	{
		return 'C';
	}
}

int IsFUll(char checkerBorard[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (checkerBorard[i][j] == ' ')
			{
				return 0;
			}

		}
	}
	return  1;
}

/*�������
@
@*/
void PlayerMove(char checkerBorard[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("�����ѡ������λ�ã� ");

	while (1)
	{
		scanf_s("%d %d", &x, &y);
		//�ж�����Ϸ���
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (checkerBorard[x - 1][y - 1] == ' ')
			{
				checkerBorard[x - 1][y - 1] = 'u';
				break;

			}
			else
			{
				printf("��λ���ѱ�ռ��,���������룺 ");
				continue;

			}
		}

		else
		{
			printf("λ�ò��Ϸ������������룺 ");
			continue;
		}
	}


}

/*������������
@
@*/
void ComputerMove(char checkerborard[ROW][COL], int row, int col)
{
	printf("����������......\n");

	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;

		if (checkerborard[x][y] == ' ')
		{
			checkerborard[x][y] = 'x';
			break;
		}
	}


}


/*�˳���Ϸ
@ none
@*/
void ExitGame()
{
	printf("����ô�Ҳ��棿��֪�������˶��û����һ�㰮�Ķ�û�У��Ų����ҳ��㣬�����棡");
	system("pause");
	MainMemu();
}


/*
* @ref : ��ʼ�����̣�����ά��������ֵ��ֵΪ�ո�
* @char checkerborard[ROW][COL]   ����
* @row  ��������
* @col  ��������
*/
void initCheckerBoard(char checkerborard[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			checkerborard[i][j] = ' ';
		}
	}
}


/*��������
@ none
@ none
@*/
void Display(char checkerborard[ROW][COL], int row, int col)
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf(" %c ", checkerborard[i][j]);
			if (j < row - 1)
			{
				printf("|");
			}

		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < row; j++)
			{
				printf("___");
				if (j < row - 1)
				{
					printf("|");
				}

			}
		}
		printf("\n");

	}

}