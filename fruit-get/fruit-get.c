/*果物集めゲーム*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "fruit.h"
#include "player.h"
#include "oprate.h"

int main(void) {
	int cx = 8, cy = 14;
	int key;
	int score = 0;
	int op = 0;
	int flag = 0;
	int e_o_s = 0;

	/*オープニング*/
	opening();
	/*オープニングここまで*/

	//メインループ
	while (1) {
		score = 0;
		flag = 0;
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
				//果物の移動
				fruit_move();

				//取得時の加点
				score = fruit_get(score, cx);
				
				/*果物生成*/
				fruit_gene();
				/*果物生成ここまで*/
			}

			/*キャラクタの移動*/
			//キャラクタの操作
			if (_kbhit()) {
				key = _getch();
				switch (key) {
				case 'a':
				case '4':
				case 'd':
				case '6':
					cx = player_move(cx, key);
					break;
				case 27:
					flag = 1;
					break;
				}
			}

			//escキーによる終了
			if (flag == 1)
				break;
			/*移動ここまで*/

			/*表示*/
			//プレイ画面
			system("cls");
			
			show(cx, cy, score);
			/*表示ここまで*/
		}

		end_sen();

		flag = 1;

		//続行か終了か
		system("cls");
		op = 0;
		
		op = ending(op);
		if (op == 1)
			break;

		fruit_reset();
	}

	printf("See you next time!!!!!!\n");
	Sleep(6000);
	return 0;
}