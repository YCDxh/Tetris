#include"Tetris.h"
#include"Tolls.h"
int main() {
	int i;
	HideCursor();
	struct diamonds diamonds[20];
	Map_Print();
	Diamonds_Run(diamonds);
	Goto(8, 22);
	return 0;
}