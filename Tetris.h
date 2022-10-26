// -俄罗斯方块 函数定义
#pragma once
#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<ctime>
#include<conio.h>
#include<fstream>
#define UP 72 //方向键：上
#define DOWN 80 //方向键：下
#define LEFT 75 //方向键：左
#define RIGHT 77 //方向键：右
#define SPACE 32 //直接掉落
#define ESC 27 //暂停
using namespace std;
//地图坐标 声明
extern int map[50][50];
//方块坐标结构体
struct diamonds
{
	int x;
	int y;
};
//地图及玩家信息打印
int Map_Print();

//方块打印
int Diamonds_Print(int flag,struct diamonds diamonds[]);

//方块随机生成
int Diamonds_Random(int star,struct diamonds diamonds[]);

//方块移动
int Diamonds_Run(struct diamonds diamonds[]);

//方块旋转
int Diamonds_Revolve(struct diamonds diamonds[]);

//判断
int Diamonds_Judge(int x,int y,int flag, struct diamonds diamonds[]);

//方块消除
int Diamonds_Remove(struct diamonds diamonds[]);

//方块更新
int Diamonds_UpData(struct diamonds diamonds[]);

//玩家信息存储
int Score_Input();