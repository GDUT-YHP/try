#pragma once
/*此文件存放该项目所有符号声明和函数定义以及头文件的引用*/
/*This file stores all symbol declarations and function definitions and references to header files of the project*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW  3 
#define COL  3


void MainMemu();
void initCheckerBoard(char checkerborard[ROW][COL], int row, int col);   //初始化棋盘
void Display(char checkerborard[ROW][COL], int row, int col);            //绘制当前棋盘
void PlayerMove(char checkerborard[ROW][COL], int row, int col);
void ComputerMove(char checkerborard[ROW][COL], int row, int col);
char IsOver(char checkerborard[ROW][COL], int row, int col);
int IsFUll(char checkerBorard[ROW][COL], int row, int col);
void StartGame();
void ExitGame();