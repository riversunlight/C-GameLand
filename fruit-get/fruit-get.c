/*果物集めゲーム*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "fruit.h"
#include "player.h"
#include "oprate.h"
#include "ranking.h"

int main(void) {
	int cx = 8, cy = 14;
	int key;
	int score = 0;
	int op = 0;
	int rank;
	int flag = 0;
	int e_o_s = 1;
	int open;
	int op_flag = 0;

	//スコアの読み込み
	rank_read();

	/*すべてのループ*/
	do {
		flag = 0;
		/*オープニング*/
		do {
			int num;
			open = opening(op_flag);
			if (open == -1) {//ENDキーによる終了
				flag = 1;
				break;
			}
			op_flag = 0;
			num = open / 100;
			switch (num) {
			case 1:
				e_o_s = open % 100;
				op_flag = 1;
				break;
			}
		} while (open != 0);
		/*オープニングここまで*/

		//ENDキーによる終了
		if (flag == 1)
			break;

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
					fruit_gene(e_o_s);
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

			/*ゲーム終了後の処理*/
			fruit_reset();

			end_sen();

			flag = 1;

			//続行か終了か
			system("cls");
			op = 0;
			
			//ランキングの更新
			rank = ranking_update(score);
			op = ending(op, rank);
			if (op == 1)
				break;

		}
	} while (1);

	printf("See you next time!!!!!!\n");
	Sleep(6000);
	return 0;
}