#include "game.h"
/*全局变量的引用*/
extern int row;
extern int col;

/*主菜单*/
void MainMemu()
{
	system("cls");
	int UserChoice = 0;
	printf("-------------豪好玩N子棋---------------------------\n\n");

	printf("-------------1、开始游戏---------------------------\n");
	printf("-------------2、退   出----------------------------\n");
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
		printf("请从（1/2）选择哦~~\n");
		printf("按任意键继续");
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
		//玩家下棋过程
		PlayerMove(checkerBoard, ROW, COL);
		Display(checkerBoard, ROW, COL);
	    result = IsOver(checkerBoard, ROW, COL);
		if (result != 'C')
		{
			break;
		}

		//电脑下棋
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
		printf("玩家赢了");

	}
	else if (result == 'x')
	{
		system("cls");
		printf("本机赢啦哈哈，你这个小辣鸡");

	}
	else
	{
		system("cls");
		printf("勉强能平局");
	}	 



}


char IsOver(char checkerborard[ROW][COL], int row, int col)
{

	//判断行
	for (int  i = 0; i < row; i++)
	{
		if (checkerborard[i][0] == checkerborard[i][1] && checkerborard[i][1] == checkerborard[i][2] && checkerborard[i][1] != ' ')
		{
			return checkerborard[i][1];
		}
	}

	//判断列
	for (int i = 0; i < col; i++)
	{
		if (checkerborard[0][i] == checkerborard[1][i] && checkerborard[1][i] == checkerborard[2][i] && checkerborard[1][i] != ' ')
		{
			return checkerborard[1][i];
		}
	}

	//判断对角线
	if (checkerborard[0][0] == checkerborard[1][1] && checkerborard[1][1] == checkerborard[2][2]&& checkerborard[1][1] != ' ')
	{
		return checkerborard[1][1];
	}
	if (checkerborard[0][2] == checkerborard[1][1] && checkerborard[1][1] == checkerborard[2][0] && checkerborard[1][1] != ' ')
	{
		return checkerborard[1][1];
	}
	//判断平局与是否继续
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

/*玩家下棋
@
@*/
void PlayerMove(char checkerBorard[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("请玩家选择棋子位置： ");

	while (1)
	{
		scanf_s("%d %d", &x, &y);
		//判断坐标合法性
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (checkerBorard[x - 1][y - 1] == ' ')
			{
				checkerBorard[x - 1][y - 1] = 'u';
				break;

			}
			else
			{
				printf("该位置已被占用,请重新输入： ");
				continue;

			}
		}

		else
		{
			printf("位置不合法，请重新输入： ");
			continue;
		}
	}


}

/*呆呆电脑下棋
@
@*/
void ComputerMove(char checkerborard[ROW][COL], int row, int col)
{
	printf("本机对弈中......\n");

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


/*退出游戏
@ none
@*/
void ExitGame()
{
	printf("你特么敢不玩？你知道我做了多久没啊，一点爱心都没有！信不信我抽你，给我玩！");
	system("pause");
	MainMemu();
}


/*
* @ref : 初始化棋盘，将二维数组所有值赋值为空格
* @char checkerborard[ROW][COL]   数组
* @row  数组行数
* @col  数组列数
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


/*绘制棋盘
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