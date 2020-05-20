//j1902 安部滉人　春休み課題

/*-----------1対1ボールバトルゲーム-----------*/
/*全画面モード推奨*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define ENTER 13

int main(void) {
	int px = 5, py = 14;                //プレイヤーの座標
	int ex = 18, ey = 14;               //相手の座標
	int bx = 0,by = 0;                  //ボールの座標
	int b_dir = 0;                      //ボールの移動方向
	int point_p = 0, point_e = 0;       //ポイント
	int MAP_X = 25, MAP_Y = 25;         //マップの広さ
	int x, y;                           //画面表示
	int op = 0, op_o = 0;               //オープニングの選択
	int com, man;                       //じゃんけんの手
	int diff;                           //勝敗判定
	int p;                              //移動
	int surve = 1;                      //サーブ用のフラグ(1がサーブ待機)
	int surve_right = 0;                //サーブ権(0が自分、1があいて)
	int sp_p = 0, sp_e = 0;             //スペシャルカウント
	int i, j;                           //スペシャルカウントの表示
	int jumping = 0;                    //ジャンプ用のフラグ(1がジャンプ中)
	int toss = 0;                       //トス用のフラグ(1がトス中)
	int toss_time;                      //トスされた時間
	int finish_time;                    //床についたとき
	int play_none = 0;                  //プレイが続いているか(1がつづいていない)
	int time_count = 0;                 //時間の計測
	int end = 0;                        //エンディングの種類 

	int hist_px[100000];                //pxの軌跡
	int hist_py[100000];                //pyの軌跡
	int hist_bx[100000];                //bxの軌跡
	int hist_by[100000];                //byの軌跡

	double v_p = 0, v_b = 0;             //落下
	double px_d, py_d;                  //プレイヤーの座標(double型)
	double by_d;                        //ボールの座標(double型)

    //オープニング
	do {
		while (1) {
			printf("-----------1対1ボールバトルゲーム-----------\n\n");

			//選択の表示
			op_o = 0;
			switch (op) {
			case 0:
				printf("  ◎START    OPTION    RULES");
				break;
			case 1:
				printf("    START  ◎OPTION    RULES");
				break;
			case 2:
				printf("    START    OPTION  ◎RULES");
				break;
			}

			//選択の判断
			if (_kbhit()) {
				op_o = _getch();
				switch (op_o) {
				case 'a':
					op -= 1;
					break;
				case 'f':
					op += 1;
					break;
				}
			}

			if (op_o == ENTER) {
				system("cls");
				break;
			}
			//値の調整
			op = (op + 3) % 3;

			system("cls");
		}
		switch (op) {
		//設定
		case 1:
			while (1) {
				printf("=====設定=====\n");
				printf("勝利得点\n");
				printf("スペシャルカウント(最大6)\n");
				printf("リプレイ\n");
				printf("ハンデ\n");
				system("cls");
				if (_kbhit()) {
					system("cls");
					break;
				}
			}
			break;
		//ルール説明
		case 2:
			while (1) {
				printf("=====ルール=====\n");
				printf("①相手より先に勝利得点に到達することが勝利条件\n");
				printf("②スパイクを打つことでスペシャルカウントを増やせる\n");
				printf("③スペシャルカウントを最大数ためるとスペシャルスパイクを打つことができる\n");
				printf("④移動はAまたは4(左)とFまたは6(右)、ジャンプはスペース、トスはJまたは5、スパイクとサーブはエンター\n");
				printf("⑤コートからはみ出して落ちると一発負け\n");
				printf("Any key plese...(エンター以外)\n");
				system("cls");
				if (_kbhit()) {
					system("cls");
					break;
				}
			}
		}
	} while (op != 0);

	//サーブ決め
	//自分の手	
	printf("サーバー決めじゃんけん!!!\n");
	printf("出す手を選んでね (1 => グー　2 => チョキ 3 =>　パー)\n");
	do {
		scanf_s("%d", &man);
		man -= 1;
		if (man < 0 || man >= 3)
			printf("1か2か3を入力してください。\n");
	} while (man < 0 || man >= 3);

	//相手の手
	do {
		com = rand() % 3;
	} while (com == man);

	//勝敗判定
	diff = (com - man + 3) % 3;

	system("cls");

	//勝敗表示
	printf("あなた:");
	switch (man) {
	case 0:
		printf("グー\t");
		break;
	case 1:
		printf("チョキ\t");
		break;
	case 2:
		printf("パー\t");
		break;
	}

	printf("あいて:");
	switch (com) {
	case 0:
		printf("グー\t");
		break;
	case 1:
		printf("チョキ\t");
		break;
	case 2:
		printf("パー\t");
		break;
	}

	switch (diff) {
	case 1:
		printf("あなたのサーブ\n");
		surve_right = 0;
		break;
	case 2:
		printf("相手のサーブ\n");
		surve_right = 1;
		break;
	}

	//ゲーム開始
	printf("Any key plese...(エンター以外)");
	while (1) {
		if (_kbhit()) {
			system("cls");
			break;
		}
	}

	do {
		//サーブ

		//サーブ時のセット
		switch (surve_right % 2) {
		case 0:
			b_dir = 0;
			bx = px;
			by = py - 3;
			break;
		case 1:
			b_dir = 1;
			bx = ex;
			by = ey - 3;
			break;
		}

		//初期化(double型のby)
		by_d = by;

		//ポイント・サーブ権・スペシャルカウントの表示
		printf("\n\n\n");
		printf("\t\t\t\t\t\t    ");
		switch (surve_right) {
		case 0:
			printf("●サーブ\n");
			break;
		case 1: 
			printf("　　　　　　　　　　 　          　サーブ●\n");
			break;
		}
		printf("\t\t\t\t\t\t    ");
		printf("サーブにより開始\n");
		printf("\t\t\t\t\t\t    ");
		printf("あなた　　　　　　　　　　 　          　あいて\n");
		printf("\t\t\t\t\t\t    ");
		printf("スペシャルカウント\n");
		printf("\t\t\t\t\t\t    ");
		for (i = 0; i < 5; i++) {
			if (i < sp_p)
				printf("■");
			else
				printf("  ");
		}
		printf("　　　　　            　　　");
		for (j = 0; j < 5; j++) {
			if (j >= sp_e)
				printf("  ");
			else
				printf("■");
		}
		printf("\n");
		printf("\t\t\t\t\t\t    ");
		printf("%d                    :                       %d\n", point_p, point_e);

		//コートの表示
		for (y = 0; y <= MAP_Y; y++) {
			printf("\t\t\t\t\t\t    ");
			for (x = 0; x <= MAP_X; x++) {
				if (x == px && y == py - 2)
					printf("▲");
				else if (x == px && y == py - 1)
					printf("■");
				else if (x == px && y == py)
					printf("八");
				else if (x == ex && y == ey - 2)
					printf("○");
				else if (x == ex && y == ey - 1)
					printf("■");
				else if (x == ex && y == ey)
					printf("ル");
				else if (x == bx && y == by)
					printf("●");
				else if (x == 13 && y >= 7 && y < 15)
					printf("□");
				else if (x > 1 && x < 25 && y == 15)
					printf("□");
				else
					printf("  ");
			}
			printf("\n");
		}

		//打つまで待つ
		if (surve == 1) {
			//サーブ権が自分
			if (!surve_right) {
				while (1) {
					if (_getch() == ENTER) {
						surve = 0;
						v_b = 3;
						break;
					}
				}
			}
			//サーブ権が相手
			else{
				Sleep(1500);
				v_b = 3;
			}
		}

		//試合
		while (1) {
			/*プレイヤーの移動*/
			//左右の移動とジャンプ
			if (_kbhit()) {
				p = _getch();
				printf("%d", p);

				switch (p) {
				case 'f':
				case '6':
					if (px <= 11)
						px++;
					break;
				case 'a':
				case '4':
					if (px >= 1)
						px--;
					break;
				case '5':
				case 'j':
					if (toss == 0) {
						toss = 1;
						toss_time = time_count;
					}
					break;
				case ' ':
					if (jumping == 0) {
						px_d = px, py_d = py;
						jumping = 1;
						v_p = 5;
					}
					break;
				}
			}

			//落下
			if (jumping == 1) {
				py_d -= v_p;
				v_p -= 3;
				py = py_d;
				if (px > 1 && py >= 14) {
					jumping = 0;
					py = 14;
					v_p = 0;
				}
			}

			/*コートはみ出し*/
			//はみ出したとき
			if (px < 2) {
				jumping = 1;
				py_d = py;
			}

			//一番下に行ったら負け
			if (py >= 25) {
				end = 1;
				break;
			}

			/*プレイヤーの移動ここまで*/

			/*ボールの移動*/
			if (time_count % 2) {
				//横(x)方向
				switch (b_dir) {
				case 0:
					bx++;
					break;
				case 1:
					bx--;
					break;
				}

				//縦(y)方向(落下)
				by_d -= v_b;
				v_b -= 0.5;
				by = by_d;
		        
				//床についたとき
				if (by >= 14) {
					//床貫通しないように
					by = 14;
					//跳ね返る
					v_b *= -1;
					//得点を加算
					if (b_dir == 0)
						point_p++;
					else
						point_e++;
					//次のプレイへ
					finish_time = time_count;
					play_none = 1;
					surve_right++;
					surve_right %= 2;
				}

			}

			//トス
			if (toss == 1)
				printf("%d%d  %d%d", px, bx, py, by);
			if (toss == 1 && (toss_time || toss_time + 1 || toss_time + 2) == time_count && bx == (px || px - 1 || px + 1) && by == (py - 4 || py - 5 || py - 6)){
				b_dir += 1;
				b_dir %= 2;
				v_b = 3;
			}

			//プレイを次へ(床についてから6カウント分)
			if (play_none == 1) {
				surve = 1;
				if (time_count - finish_time == 6) {
					//勝敗判定
					if (point_p == 5)
						end = 2;

					if (point_e == 5)
						end = 3;
					
					//次のプレイへ
					if(point_p != 5 && point_e != 5)
					  system("cls");

					play_none = 0;
					break;
				}
			}

			//画面消去
			system("cls");

			//ポイント・サーブ権・スペシャルカウントの表示
			printf("\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t    ");
			printf("あなた　　　　　　　　     　　 　     　あいて\n");
			printf("\t\t\t\t\t\t    ");
			printf("スペシャルカウント\n");
			printf("\t\t\t\t\t\t    ");
			for (i = 0; i < 5; i++) {
				if (i < sp_p)
					printf("■");
				else
					printf("  ");
			}
			printf("　　　　     　      　　　");
			for (j = 0; j < 5; j++) {
				if (j >= sp_e)
					printf("  ");
				else
					printf("■");
			}
			printf("\n");
			printf("\t\t\t\t\t\t    ");
			printf("%d                    :                       %d\n", point_p, point_e);

			//コートの表示
			for (y = 0; y <= MAP_Y; y++) {
				printf("\t\t\t\t\t\t    ");
				for (x = 0; x <= MAP_X; x++) {
					if (x == px && y == py - 2)
						printf("▲");
					else if (x == px && y == py - 1)
						printf("■");
					else if (x == px && y == py)
						printf("八");
					else if (x == px && y == py -3 && toss == 1)
						printf("TT");
					else if (x == ex && y == ey - 2)
						printf("○");
					else if (x == ex && y == ey - 1)
						printf("■");
					else if (x == ex && y == ey)
						printf("ル");
					else if (x == bx && y == by)
						printf("●");
					else if (x == 13 && y >= 7 && y < 15)
						printf("□");
					else if (x > 1 && x < 25 && y == 15)
						printf("□");
					else
						printf("  ");
				}
				printf("\n");
			}

			//時間を増やす
			time_count++;

			//奇跡の代入
			hist_px[time_count] = px, hist_py[time_count] = py;
			hist_bx[time_count] = bx, hist_py[time_count] = by;

			//トスのフラグを下げる
			if (toss == 1){
				if(time_count - toss_time >= 4)
				    toss = 0;
			}
		}
		printf("\n\n\n");
		switch (end) {
		case 1:
			printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
			printf("\t\t\t\t\t\t                       YOU    LOSE   (FALLEN)\n");
			printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
			break;
		case 2:
			printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
			printf("\t\t\t\t\t\t                       YOU    WIN   (You got 5 point!)\n");
			printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
			break;
		case 3:
			printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
			printf("\t\t\t\t\t\t                       YOU    LOSE   (You lost 5 point...)\n");
			printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
			break;;
		}
	} while (point_p < 5 && point_e < 5 && end == 0);

	Sleep(10000);

    return 0;
}