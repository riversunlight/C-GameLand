#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "ranking.h"
#define ENTER 13

void rule(void) {
	int key = 0;
	system("cls");
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

int item_easy(void) {
	int key;
	int flag = 1;
	int op = 0;
	while (flag) {
		printf("===アイテムの出やすさ===\n");
		printf("%s出やすい\n", (op == 0)? "◎" : "  ");
		printf("%s普通\n", (op == 1) ? "◎" : "  ");
		printf("%s出にくい\n", (op == 2) ? "◎" : "  ");
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
			op = (op + 3) % 3;
		}
	}

	return 100 + op;
}

int option(void) {
	int key;
	int flag = 1;
	int num = 1;
	int op = 0;
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

	switch (op) {
	case 0:
		num = item_easy();
		break;
	}

	return num;
}

int opening(int cho) {
	int flag = 1;
	int op = 0;
	int key;
	int num = 0;

	if (cho == 1) {
		flag = 0;
		op = 1;
	}

	do {
		while (flag) {
			system("cls");
			printf("==========果物集めゲーム==========\n");
			printf("%sSTART\n", (op == 0) ? "        ◎" : "          ");
			printf("%sOPTION\n", (op == 1) ? "        ◎" : "          ");
			printf("%sRANKING\n", (op == 2) ? "        ◎" : "          ");
			printf("%sRULE\n", (op == 3) ? "        ◎" : "          ");
			printf("%sEND\n", (op == 4) ? "        ◎" : "          ");
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
				op = (op + 5) % 5;
			}
		}
		system("cls");
		switch (op) {
		case 1:
			num = option();
			flag = 1;
			break;
		case 2:
			rank_show();
			flag = 1;
			break;
		case 3:
			rule();
			flag = 1;
			break;
		case 4:
			num = -1;
			break;
		}
	} while (op == 2 || op == 3);

	return num;
}

int ending(int op, int rank) {
	int flag = 1;
	int key;
	while (1) {
			printf("RANK IN: %d RANK", rank + 1);
			for (int j = 4; j > rank; j--)
				printf("!");
			printf("\n");

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