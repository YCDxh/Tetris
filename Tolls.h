#pragma once
#include<iostream>
#include<Windows.h>
#include<stdlib.h>
using namespace std;
//得分记录
int Tetris_Score();
//颜色设置
void Color(int c);
//隐藏光标
void HideCursor();
//光标跳转
void Goto(int x, int y);
