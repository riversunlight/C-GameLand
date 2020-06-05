#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define ENTER 13


void opening(void) {
	int flag = 1;
	int op = 0;
	int key;

	do {
		while (flag) {
			printf("==========果物集めゲーム==========\n");
			printf("%sSTART\n", (op == 1) ? "          " : "        ◎");
			printf("%sRULE\n", (op == 0) ? "          " : "        ◎");
			if (_kbhit()) {
				key = _getch();
				switch (key) {
				case 'w':
				case '8':
					op--;
					break;
				case 's':
				case '2':
					op++;
					break;
				case ENTER:
					flag = 0;
					break;
				}
				op = (op + 2) % 2;
			}
			system("cls");
		}
		switch (op) {
		case 1:
			//ルール表示
			printf("1.落ちてくる果物を取って得点ゲット!減点されるものもあるので注意!\n");
			printf("2,みかん(〇) 10点 リンゴ(●) 20点  パイナップル(■)30点 スイカ(☆) 40点\n");
			printf("3,毒キノコ(△) -10点 爆弾(x) -40点\n");
			printf("4.aで左移動、dで右移動  端から端へワープ可能(逆にやりづらいかもしれません)\n");
			while (1) {
				if (_kbhit()) {
					key = _getch();
					flag = 1;
					system("cls");
					break;
				}
			}
			break;
		}
	} while (op);
}

int ending(int op) {
	int flag = 1;
	int key;
	while (1) {
		printf("%snew game\n", (op == 0) ? "◎" : "  ");
		printf("%send\n", (op == 1) ? "◎" : "  ");
		system("cls");
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case 'w':
				op--;
				break;
			case 's':
				op++;
				break;
			case 13:
				flag = 0;
				break;
			}
			op = (op + 2) % 2;
			if (flag == 0)
				break;
		}
	}
	return op;
}

void end_sen(void){
	printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
	printf("                     !!!!!終了!!!!!\n");
	printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
	Sleep(5000);
}