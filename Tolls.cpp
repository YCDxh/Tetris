#include"Tolls.h"
//��ɫ����
void Color(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//���ع��
void HideCursor() {
	CONSOLE_CURSOR_INFO curInfo; //��������Ϣ�Ľṹ�����
	curInfo.dwSize = 1; //���û��ֵ�Ļ������������Ч
	curInfo.bVisible = FALSE; //���������Ϊ���ɼ�
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
	SetConsoleCursorInfo(handle, &curInfo); //���ù����Ϣ
}
//�����ת
void Goto(int x, int y) {
	COORD pos; //������λ�õĽṹ�����
	pos.X = 2 * x; //������
	if (y == 0)
		pos.Y = y;
	else
		pos.Y = y - 1;

	//������	��ʼΪ(1,1)
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
	SetConsoleCursorPosition(handle, pos); //���λ��
}