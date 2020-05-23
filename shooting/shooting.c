/*シューティングゲーム*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include"calc.h"
#include"oprate.h"
#define SIZE 15

int main() {
	int cx = 14, cy = 14;
	int ex = 0, ey = 0;
	int myLife = 3;
	int enemyLife = 10;
	int win_flag = 0;
	int cnt = 0;
	int flag = 0;
	int next = 0;

	while(1) {
		/*始まる前の準備*/
		srand((unsigned int)time(NULL));
		next = 0;
		win_flag = 0;
		myLife = 3;
		enemyLife = 10;
		cx = 14, cy = 14;
		ex = 0; ey = 0;
		init_0();

		/*オープニング*/
		flag = opening();
		if (flag == 1)
			break;

		/*メインループ*/
		while (1) {
			//自機の移動
			if (_kbhit()) {
				int key = _getch();
				if (key == 'a' || key == 'd')
					cx = move(cx, key, SIZE);
				else if (key == ' ')
					bullet_gene(0, cx);
			}

			//敵機の移動
			ex = enemy_move(ex, SIZE);
			if (cnt % 3 == 0)
				bullet_gene(1, ex);

			//弾の移動
			bullet_move();

			//ライフダウン
			myLife = isHit(0, myLife, cx);
			enemyLife = isHit(1, enemyLife, ex);

			//画面更新
			update(cx, cy, ex, ey, myLife, enemyLife, SIZE);

			//死亡判定
			if (myLife == 0) {
				win_flag = 2;
				break;
			}
			else if (enemyLife == 0) {
				win_flag = 1;
				break;
			}

			//ターンカウント増加
			cnt++;
		}

		ending(win_flag);
		Sleep(5000);

		next = new_game();
		if (next == 1)
			break;
	}

	system("cls");
	printf("See You Next Time!!\n");

	return 0;
}