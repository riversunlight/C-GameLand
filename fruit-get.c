/*果物集めゲーム*/

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 15
#define ENTER 13
#define ESC 27

enum fruit {
	EMPTY,     //(空白)
	ORANGE,    //〇
	APPLE,     //●
	PAINAPPLE, //■
	W_MERON,   //☆
	BOM,       //×
	P_KINOKO   //△
};

int main() {
	int cx = 8, cy = 14;
	int key;
	int r;
	int score = 0;
	int op = 0;
	int kudamono[SIZE][SIZE] = { 0 };
	int flag = 1;

	/*オープニング*/
	do {
		while (flag) {
			printf("==========果物集めゲーム==========\n");
			printf("%sSTART\n", (op == 1) ? "          " : "        ◎");
			printf("%sRULE\n", (op == 0)?"          " : "        ◎");
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
				case 13:
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
	/*オープニングここまで*/

	//メインループ
	while (1) {
		score = 0;
		//カウントダウン
		for (int i = 3; i > 0; i--) {
			printf("開始まで%d", i);
			Sleep(1000);
			system("cls");
		}
		printf("スタート!!!!!");
		Sleep(1000);
		system("cls");
		srand(time(NULL));

		for (int cnt = 0; cnt < 1000; cnt++) {

			//果物関連
			if (cnt % 3 == 0) {
				/*果物の移動*/
				//ひとつづつ下げる
				for (int i = 0; i < SIZE; i++)
					for (int j = SIZE - 1; j > 0; j--) {
						kudamono[i][j] = kudamono[i][j - 1];
						kudamono[i][j - 1] = EMPTY;
					}
				/*果物の移動ここまで*/

				/*取得時の加点*/
				for (int i = 0; i < SIZE; i++) {
					if (kudamono[i][14] != EMPTY && cx == i)
						switch (kudamono[i][14]) {
						case ORANGE:
							score += 10;
							break;
						case APPLE:
							score += 20;
							break;
						case PAINAPPLE:
							score += 30;
							break;
						case W_MERON:
							score += 40;
							break;
						case BOM:
							score -= 40;
							break;
						case P_KINOKO:
							score -= 10;
							break;
						}
				}
				/*取得時の加点ここまで*/

				/*果物生成*/
				for (int i = 0; i < SIZE; i++) {
					r = rand() % 2000;
					if (r >= 0 && r <= 15)
						kudamono[i][0] = ORANGE;
					else if (r >= 16 && r <= 24)
						kudamono[i][0] = APPLE;
					else if (r >= 25 && r <= 30)
						kudamono[i][0] = PAINAPPLE;
					else if (r >= 31 && r <= 34)
						kudamono[i][0] = W_MERON;
					else if (r >= 34 && r <= 37)
						kudamono[i][0] = BOM;
					else if (r >= 38 && r <= 41)
						kudamono[i][0] = P_KINOKO;
				}
				/*果物生成ここまで*/
			}

			/*キャラクタの移動*/
			//キャラクタの操作
			if (_kbhit()) {
				key = _getch();
				switch (key) {
				case 'a':
				case '4':
					cx--;
					break;
				case 'd':
				case '6':
					cx++;
					break;
				case ESC:
					flag = 1;
					break;
				}
			}
			//ワープ
			cx = (cx + SIZE) % SIZE;

			//escキーによる終了
			if (flag == 1)
				break;
			/*移動ここまで*/

			/*表示*/
			//プレイ画面
			system("cls");
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++)
					if (i == cy && j == cx)
						printf("◎");
					else
						switch (kudamono[j][i]) {
						case EMPTY:
							printf("  ");
							break;
						case ORANGE:
							printf("〇");
							break;
						case APPLE:
							printf("●");
							break;
						case PAINAPPLE:
							printf("■");
							break;
						case W_MERON:
							printf("☆");
							break;
						case BOM:
							printf("×");
							break;
						case P_KINOKO:
							printf("△");
							break;
						}
				printf("\n");
			}

			//得点の表示
			printf("SCORE: %5d\n", score);
			/*表示ここまで*/
		}

		printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
		printf("                     !!!!!終了!!!!!\n");
		printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
		flag = 1;
		Sleep(5000);

		//続行か終了か
		system("cls");
		op = 0;
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

		if (op == 1)
			break;

		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				kudamono[i][j] = EMPTY;
	}

	printf("See you next time!!!!!!\n");
	Sleep(6000);
	return 0;
}