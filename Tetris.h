// -����˹���� ��������
#pragma once
#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<ctime>
#include<conio.h>
#include<fstream>
#define UP 72 //���������
#define DOWN 80 //���������
#define LEFT 75 //���������
#define RIGHT 77 //���������
#define SPACE 32 //ֱ�ӵ���
#define ESC 27 //��ͣ
using namespace std;
//��ͼ���� ����
extern int map[50][50];
//��������ṹ��
struct diamonds
{
	int x;
	int y;
};
//��ͼ�������Ϣ��ӡ
int Map_Print();

//�����ӡ
int Diamonds_Print(int flag,struct diamonds diamonds[]);

//�����������
int Diamonds_Random(int star,struct diamonds diamonds[]);

//�����ƶ�
int Diamonds_Run(struct diamonds diamonds[]);

//������ת
int Diamonds_Revolve(struct diamonds diamonds[]);

//�ж�
int Diamonds_Judge(int x,int y,int flag, struct diamonds diamonds[]);

//��������
int Diamonds_Remove(struct diamonds diamonds[]);

//�������
int Diamonds_UpData(struct diamonds diamonds[]);

//�����Ϣ�洢
int Score_Input();