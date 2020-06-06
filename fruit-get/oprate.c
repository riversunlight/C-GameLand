#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define ENTER 13

void rule(void) {
	int key = 0;
	printf("============================RULE===========================\n");
	printf("1.落ちてくる果物を取って得点ゲット!減点されるものもあるので注意!\n");
	printf("2,みかん(〇) 10点 リンゴ(●) 20点  パイナップル(■)30点 スイカ(☆) 40点\n");
	printf("3,毒キノコ(△) -10点 爆弾(x) -40点\n");
	printf("4.aで左移動、dで右移動  端から端へワープ可能(逆にやりづらいかもしれません)\n");
	printf("Any key plese...\n");
	while (1) {
		if (_kbhit()) {
			key = _getch();
			system("cls");
			break;
		}
	}
}

void option(void) {
	int key;
	int flag = 1;
	int op = 0;
	do {
		while (flag) {
			printf("=====OPTION=====\n");
			printf("%sアイテムの出やすさ\n", (op == 0) ? "◎" : "  ");
			printf("%s戻る\n", (op == 1) ? "◎" : "  ");
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
				case ENTER:
					flag = 0;
					break;
				}
				op = (op + 2) % 2;
			}
		}
		flag = 1;
	} while (op != 1);
}

void opening(void) {
	int flag = 1;
	int op = 0;
	int key;

	do {
		while (flag) {
			printf("==========果物集めゲーム==========\n");
			printf("%sSTART\n", (op == 0) ? "        ◎" : "          ");
			printf("%sOPTION\n", (op == 1) ? "        ◎" : "          ");
			printf("%sRULE\n", (op == 2) ? "        ◎" : "          ");
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
				op = (op + 3) % 3;
			}
			system("cls");
		}
		switch (op) {
		case 1:
			option();
			flag = 1;
			break;
		case 2:
			rule();
			flag = 1;
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
			case ENTER:
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