#pragma once
/*���ļ���Ÿ���Ŀ���з��������ͺ��������Լ�ͷ�ļ�������*/
/*This file stores all symbol declarations and function definitions and references to header files of the project*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW  3 
#define COL  3


void MainMemu();
void initCheckerBoard(char checkerborard[ROW][COL], int row, int col);   //��ʼ������
void Display(char checkerborard[ROW][COL], int row, int col);            //���Ƶ�ǰ����
void PlayerMove(char checkerborard[ROW][COL], int row, int col);
void ComputerMove(char checkerborard[ROW][COL], int row, int col);
char IsOver(char checkerborard[ROW][COL], int row, int col);
int IsFUll(char checkerBorard[ROW][COL], int row, int col);
void StartGame();
void ExitGame();