#include"Tetris.h"
#include"Tolls.h"
//��ͼ��Ϣ��ӡ	
//	������
// ����
int map[50][50] = {};
int X;
int Y;
int Score = 0;
//��ͼ��ӡ
int Map_Print() {
//	ԭ��������
	//	�� 20 * 2, �� 20
	Color(8);
	int i, j;
	// ��ͼ����
	for (i = 1; i <= 20; i++) {
		map[i][20] = -1;//�ײ��ж���
		for (j = 0; j <= 9; j ++) {
			cout << "��";
			map[j][i] = 1;//��
		}
		cout << endl;
	}
	// UI����
	Color(7);
	Goto(15, 2);	cout << "�÷�";
	Goto(19, 3);	cout << Score;//�˴�����score;
	Goto(15, 6);	cout << "������";
	Goto(19, 8);	cout << "������";//�˴�����""δ����""
	Goto(15, 11);	cout << "����";
	Goto(19, 12);	cout << "����";//�˴�����""����"";
	Goto(15, 15);	cout << "��һ��";
	Goto(1, 25);
	return 0;
}
//��ʼ������Ϣ
int Diamonds_Random(int star, struct diamonds diamonds[20]) {
	int i;
	// ��ε��������������
	// ͨ������ switch
// ��ͻ  ��ͻ   ��һ��ͻ ��һ��ͻ  ��һ   ����    ���� 
// 0-20  21-40   41-55    56-70    71-80   81-90   91-100
	i = star;
	if (i > 90) {	//����
		diamonds[1].x = 1; diamonds[1].y = 1;
		diamonds[2].x = 1; diamonds[2].y = 2;
		diamonds[3].x = 2; diamonds[3].y = 1;
		diamonds[4].x = 2; diamonds[4].y = 2;
	}
	else if (i > 80) {	//����
		diamonds[1].y = 0; diamonds[2].y = 1;
		diamonds[3].y = 2; diamonds[4].y = 3;
		diamonds[1].x = diamonds[2].x = diamonds[3].x = diamonds[4].x = 1;
	}
	else if (i > 70) {	//��һ
		diamonds[1].x = 0; diamonds[1].y = 1;
		diamonds[2].x = 1; diamonds[2].y = 1;
		diamonds[3].x = 2; diamonds[3].y = 1;
		diamonds[4].x = 1; diamonds[4].y = 2;
	}
	else if (i > 55) {	//��һ��ͻ
		diamonds[1].x = 1; diamonds[1].y = 1;
		diamonds[2].x = 1; diamonds[2].y = 2;
		diamonds[3].x = 1; diamonds[3].y = 3;
		diamonds[4].x = 2; diamonds[4].y = 3;
	}
	else if (i > 40) {	//��һ��ͻ
		diamonds[1].x = 2; diamonds[1].y = 1;
		diamonds[2].x = 2; diamonds[2].y = 2;
		diamonds[3].x = 2; diamonds[3].y = 3;
		diamonds[4].x = 1; diamonds[4].y = 3;
	}
	else if (i > 20) {	//��ͻ
		diamonds[1].x = 0; diamonds[1].y = 2;
		diamonds[2].x = 1; diamonds[2].y = 1;
		diamonds[3].x = 1; diamonds[3].y = 2;
		diamonds[4].x = 2; diamonds[4].y = 1;
	}
	else {	//��ͻ
		diamonds[1].x = 0; diamonds[1].y = 1;
		diamonds[2].x = 1; diamonds[2].y = 1;
		diamonds[3].x = 1; diamonds[3].y = 2;
		diamonds[4].x = 2; diamonds[4].y = 2;
	}

	return 1;
}

//�����ӡ
int Diamonds_Print(int flag, struct diamonds diamonds[20]) {
	int i, t;
	if (flag == 1) {
		Color(7);
		for (i = 1; i <= 4; i++) {
//			if (Y == 0)
//				Y + diamonds[i].y;
			Goto(X + diamonds[i].x, Y + diamonds[i].y);
			printf("��");
		}
	}
	else if (flag == 0) {
		Color(8);
		for (i = 1; i <= 4; i++) {
			Goto(X + diamonds[i].x, Y + diamonds[i].y);
			printf("��");
		}
	}
	else {
		Color(7);
		for (i = 1; i <= 4; i++) {
			t = diamonds[i].x;
			diamonds[i].x = diamonds[i].y;
			diamonds[i].y = 3 - t;
		}
		Diamonds_Print(1, diamonds);
	}

	return 1;
}

//�������
int Diamonds_Run(struct diamonds diamonds[20]) {
	int i, j, flag = 0;
	j = 19999;
	X = 3;	Y = 0;
	while (1) {

		if (j == 20000) {
			Goto(10, 6);
			j = 0;
			if (diamonds[1].x < 0 || !Diamonds_Judge(X, Y + 1, 1, diamonds)) {
				if (!Diamonds_UpData(diamonds)) {
					Score_Input();
					return 0;
				}
			}
		}
		if (_kbhit()) {
			flag = _getch();
			switch (flag) {
			case UP:
				//��ת
				Diamonds_Judge(X, Y, 2, diamonds);
				j -= int(double(j) * (1.0 / 3));
				break;
			case DOWN:
				//�ӿ�����
				if (!Diamonds_Judge(X, Y + 1, 1, diamonds)) {
					if (!Diamonds_UpData(diamonds)) {
						Score_Input();
						return 0;

					}
				}
				break;
			case LEFT:
				Diamonds_Judge(X - 1, Y, 1, diamonds);
				j -= int(double(j) * (1.0 / 3));
				break;
			case RIGHT:
				Diamonds_Judge(X + 1, Y, 1, diamonds);
				j -= int(double(j) * (1.0 / 3));
				break;
			case SPACE:
				while (Diamonds_Judge(X, Y + 1, 1, diamonds));
				j = 19999;
				break;
			default://������ͬescһ��
				//��ͣ
//				getchar();
				break;
			}
			Diamonds_Print(1, diamonds);
		}
		j++;
	}
	return 1;
}

//�ж�
int Diamonds_Judge(int x, int y, int flag, struct diamonds diamonds[20]) {
	int i;
	Diamonds_Print(0, diamonds);
	if (flag == 1) {//������
		for (i = 1; i <= 4; i++) {
			if (map[diamonds[i].x + x][diamonds[i].y + y] != 1) {
				Diamonds_Print(1, diamonds);
				return 0;
			}
			//���������
		}
		X = x;	Y = y;
		Diamonds_Print(1, diamonds);
	}
	else {//��ת
		for (i = 1; i <= 4; i++) {
			if (map[diamonds[i].y + X][Y + 3 - diamonds[i].x] != 1)
				return 0;
		}
		Diamonds_Print(2, diamonds);
	}
	return 1;
}

// �������
int Diamonds_UpData(struct diamonds diamonds[20]) {
	int i, temp, j;
	srand((int)time(0));
	static int next = rand() % 101;
	j = next;
	next = rand() % 101;
	int ok[5][2] = {};
	if (diamonds[1].x >= 0) {
		Diamonds_Print(1, diamonds);
		for (i = 1; i <= 4; i++) {
			map[diamonds[i].x + X][diamonds[i].y + Y] = 2;
			if (map[diamonds[i].x + X][diamonds[i].y + Y] == 2 && Y <= 1)
				return 0;
		}
	}
	Diamonds_Remove(diamonds);
	X = 3;	Y = 0;
	Score += 10;
	Diamonds_Random(next, diamonds);
	for (i = 1; i <= 4; i++) {
		Color(8);
		Goto(15, 16 + i);
		cout << "��������";
	}
	for (i = 1; i <= 4; i++) {
		Color(j);
		Goto(15 + diamonds[i].x, 17 + diamonds[i].y);
		cout << "��";
	}
	Diamonds_Random(j, diamonds);
	Goto(19, 3);
	Color(rand() % 10);
	cout << Score;
	return 1;
}

//��������
int Diamonds_Remove(struct diamonds diamonds[20]) {
	int i, j, a, b, level = 1;
	for (i = 20; i >= 1; i--) {
		for (j = 0; j <= 9; j++) {
			if (map[j][i] == 1)
				break;
		}
		if (j == 10) {
			level *= 2;
			for (a = 0; a <= 9; a++) {
				for (b = i; b >= 2; b--) {
					map[a][b] = map[a][b - 1];
					Goto(a, b);
					if (map[a][b] == 1) {
						Color(8);
						cout << "��";
					}
					else {
						Color(7);
						cout << "��";
					}
				}
			}
			i++;
		}
	}
	if (level != 1) {
		Score += level * 100;
	}
	return 1;
}

//��Ϣ�洢
int Score_Input() {
	ofstream outfile;
	ifstream infile;
	int data;
	infile.open("������¼.txt");
	infile >> data;
	system("cls");
	Color(3);
	Goto(5, 10);
	cout << "��ʷ��ߵ÷�: " << data;
	Goto(5, 12);
	Color(3);
	cout << "��ǰ�÷�:" << Score;
	infile.close();
	outfile.open("������¼.txt");
	if (Score > int(data))
		outfile << Score << endl;
	else
		outfile << data << endl;
	outfile.close();
	return 1;
}
