#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include"oprate.h"

#define ENTER 13

void update(int cx, int cy, int ex, int ey, int myLife, int enemyLife, int size) {
	//画面消去
	system("cls");

	//プレイ画面
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j == cx && i == cy)
				printf("◎");
			else if (j == ex && i == ey)
				printf("△");
			else if (isBullet(j, i))
				printf("┃");
			else
				printf("  ");
		}
		printf("\n");
	}

	//ライフ
	printf("MyLife:");
	for (int i = 0; i < myLife; i++)
		printf("■");
	printf("\n");
	printf("EnemyLife:");
	for (int i = 0; i < enemyLife; i++)
		printf("■");
	printf("\n");

	return;
}

void ending(int flag) {
	switch (flag) {
	case 1:
		printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
		printf("!!!!!!!!YOU WIN!!!!!!!!!!!!!!\n");
		printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
		break;
	case 2:
		printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
		printf("        YOU LOSE...          \n");
		printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
		break;
	}
	return;
}

int opening() {
	int op = 0;
	int flag = 0;

	do {
		while (1) {
			//カーソル移動
			if (_kbhit()) {
				int op_o = _getch();
				switch (op_o) {
				case 'w':
					op--;
					break;
				case 's':
					op++;
					break;
				case ENTER:
					flag = 1;
					break;
				}
				op = (op + 3) % 3;
			}

			if (flag == 1) {
				flag = 0;
				break;
			}

			//画面表示
			printf("==========シューティングゲーム==========\n");
			printf("%sSTART\n", (op == 0) ? "◎" : "  ");
			printf("%sRULE\n", (op == 1) ? "◎" : "  ");
			printf("%sEND\n", (op == 2) ? "◎" : "  ");

			//画面消去
			system("cls");
		}

		switch (op) {
		case 1:
			do {
				printf("=====ルール=====\n");
				printf("1.弾を出して、相手を攻撃し、相手のライフをなくせば勝利\n");
				printf("2.Aで左移動、Dで右移動、スペースキーで弾を出せる\n");
				printf("Any Key Plese...\n");
				system("cls");

				if (_kbhit()) {
					flag = 1;
					int key = _getch();
					break;
				}
			} while (flag == 0);
			flag = 0;
			break;
		case 2:
			return 1;
		}
	} while (op == 1);
	return 0;
}

int new_game() {
	int op = 0;
	while (1) {
		printf("%sNEW GAME\n", (op == 0) ? "◎" : "  ");
		printf("%sEND\n", (op == 1) ? "◎" : "  ");
		system("cls");
		if (_kbhit()) {
			int key = _getch();
			switch (key) {
			case 'w':
				op--;
				break;
			case 's':
				op++;
				break;
			case ENTER:
				return op;
			}
		}
	}
}