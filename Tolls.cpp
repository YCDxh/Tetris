#include"Tolls.h"
//颜色设置
void Color(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//隐藏光标
void HideCursor() {
	CONSOLE_CURSOR_INFO curInfo; //定义光标信息的结构体变量
	curInfo.dwSize = 1; //如果没赋值的话，光标隐藏无效
	curInfo.bVisible = FALSE; //将光标设置为不可见
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
}
//光标跳转
void Goto(int x, int y) {
	COORD pos; //定义光标位置的结构体变量
	pos.X = 2 * x; //横坐标
	if (y == 0)
		pos.Y = y;
	else
		pos.Y = y - 1;

	//纵坐标	初始为(1,1)
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorPosition(handle, pos); //光标位置
}