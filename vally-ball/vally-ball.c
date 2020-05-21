//j1902 安部滉人　春休み課題

/*-----------1対1ボールバトルゲーム-----------*/
/*全画面モード推奨*/
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define ENTER 13

int ran(short int x, short int y);

int main(void) {
	short int px = 4, py = 14;                //プレイヤーの座標
	short int ex = 18, ey = 14;               //相手の座標
	short int bx = 0, by = 0;                 //ボールの座標
	short int b_dir = 0;                      //ボールの移動方向
	short int point_p = 0, point_e = 0;       //ポイント
	short int MAP_X = 25, MAP_Y = 25;         //マップの広さ
	short int key;                            //入力された時を記憶
	short int win_num = 5;                    //勝利得点
	short int x, y;                           //画面表示
	short int op = 0, op_o = 0, op_opt = 0;   //オープニングの選択
	short int com, man;                       //じゃんけんの手
	short int diff;                           //勝敗判定
	short int p;                              //移動
	short int surve = 1;                      //サーブ用のフラグ(1がサーブ待機)
	short int surve_right = 0;                //サーブ権(0が自分、1があいて)
	short int surve_right_p;                  //サーブ権(表示用)
	short int sp_p = 0, sp_e = 0;             //スペシャルカウント
	short int sp_do_p = 0, sp_do_e = 0;       //スペシャルを使うかどうか
	short int sp_max = 5;                     //スペシャルカウントの最大値
	short int sp_kind_p = 1, sp_kind_e = 1;   //スペシャルスパイクの種類(0 => 爆速 -光- 1 => 精密 -落- 3=> 攪乱 -舞-)
	short int sp_kind = 0;                    //スペシャルスパイクの種類
	short int sp_2_sel = 0;                   //精密の選択
	short int seller;                         //精密で座標を選ぶほう(1が自分)
	short int kakuran_time;                   //攪乱を打った時
	short int i, j;                           //for分用
	short int jumping_p = 0;                  //ジャンプ用のフラグ(1がジャンプ中)
	short int jumping_e = 0;                  //ジャンプ用のフラグ(1がジャンプ中)
	short int toss_p = 0, toss_p_print = 0;   //自分のトス用のフラグ(1がトス中)
	short int toss_p_time;                    //自分のトスした時間
	short int toss_e = 0, toss_e_print = 0;   //相手のトス用のフラグ(1がトス中)
	short int toss_e_time;                    //相手のトスされた時間
	short int spaik = 0;                      //スパイク用のフラグ(1がスパイク中)
	short int spaik_time;                     //スパイクを打った時間
	short int spaik_e = 0, spaik_e_time;      //相手のスパイク
	short int spaik_p_print = 0;              //自分のスパイクの表示
	short int spaik_e_print = 0;              //相手のスパイクの表示
	short int s_g_e = 0;                      //相手がスパイクしに行く
	short int finish = 0;                     //終わった時(1が終了)
	short int finish_time;                    //床についたとき
	short int jakka;                          //相手を弱くする
	short int play_none = 0;                  //プレイが続いているか(1がつづいていない)
	short int time_count = 0;                 //時間の計測
	short int end = 0;                        //エンディングの種類 
	short int con_fin = 0;                    //続けるか終わるか(終わる場合はスタート画面へ)
	short int rep = 1;                        //リプレイ
	short int rep_start;                      //リプレイの開始
	short int han_d = 0, han_n = 0;           //ハンデのもらう側と点数
	short int randamu;                        //乱数を保存する変数
	short int s_d;                            //サーブの決め方
	short int s_r;                            //サーブ決め(乱数用)
	short int deuce = 0;                      //デュース(0 =>　あり)
	short int de_pri = 0;                     //デュースの表示
	short int de_adv = 0;                     //デュースでアドバンテージがある方(1 => プレイヤ1　2 => プレイヤ2)
 	
	char name1[21] = "あなた";                //名前
	char name2[21] = "あいて";                //名前

	int hist_px[1000];                //pxの軌跡
	int hist_py[1000];                //pyの軌跡
	int hist_ex[1000];                //exの軌跡
	int hist_ey[1000];                //eyの軌跡
	int hist_bx[1000];                //bxの軌跡
    int hist_by[1000];                //byの軌跡
	int hist_po_p[1000];              //自分のポイント
	int hist_po_e[1000];              //相手のポイント
	int hist_toss_p[1000];            //自分のトスの表示の記憶
	int hist_toss_e[1000];            //相手のトスの表示
	int hist_spaik_p[1000];           //スパイクの表示
	int hist_spaik_e[1000];           //スパイクの表示
	int hist_sp_p[1000];              //スペシャルカウントの記憶(自分)
	int hist_sp_do_p[1000];           //スペシャルの使用(自分)
	int hist_sp_do_e[1000];           //スペシャルの使用(相手)
	int hist_sp_e[1000];              //スペシャルカウントの記憶(相手)
	int hist_sp_kind[1000];           //スペシャル技の種類
	int hist_de_pri[1000];            //デュースの表示
	int hist_de_adv[1000];            //デュースの状態

	double v_p = 0, v_b = 0, v_e = 0;   //落下
	double px_d, py_d;                  //プレイヤーの座標(double型)
	double ex_d, ey_d;                  //相手の座標(double型)
	double by_d;                        //ボールの座標(double型)

	//ここから実装
	do {
		//オープニング
		do {
			while (1) {
				end = 0;
				printf("-----------1対1ボールバトルゲーム(全画面推奨)-----------\n\n");

				//選択の表示
				op_o = 0;

				switch (op) {
				case 0:
					printf("  ◎SINGLE    MULTI    OPTION    RULES      END");
					break;
				case 1:
					printf("    SINGLE  ◎MULTI    OPTION    RULES      END");
					break;
				case 2:
					printf("    SINGLE    MULTI  ◎OPTION    RULES      END");
					break;
				case 3:
					printf("    SINGLE    MULTI    OPTION  ◎RULES      END");
					break;
				case 4:
					printf("    SINGLE    MULTI    OPTION    RULES    ◎END");
					break;
				}

				//選択の判断
				if (_kbhit()) {
					op_o = _getch();
					switch (op_o) {
					case 'a':
						op -= 1;
						break;
					case 'd':
						op += 1;
						break;
					}
				}

				if (op_o == ENTER) {
					system("cls");
					break;
				}
				//値の調整
				op = (op + 5) % 5;

				system("cls");
			}

			switch (op) {
			//設定
			case 2:
				do {
					op_opt = 0;
					while (1) {
						if (_kbhit()) {
							op_o = _getch();
							switch (op_o) {
							case 'w':
								op_opt--;
								break;
							case 's':
								op_opt++;
								break;
							}

							if (op_o == ENTER)
								break;
						}
						op_opt = (op_opt + 7) % 7;

						switch (op_opt) {
						case 0:
							system("cls");
							printf("=====設定=====\n");
							printf("◎プレイヤ名\b\n");
							printf("  勝利得点\n");
							printf("  スペシャル\n");
							printf("  リプレイ\n");
							printf("  ハンデ\n");
							printf("  デュース\n");
							printf("  戻る\n");
							break;
						case 1:
							system("cls");
							printf("=====設定=====\n");
							printf("  プレイヤ名\b\n");
							printf("◎勝利得点\n");
							printf("  スペシャル\n");
							printf("  リプレイ\n");
							printf("  ハンデ\n");
							printf("  デュース\n");
							printf("  戻る\n");
							break;
						case 2:
							system("cls");
							printf("=====設定=====\n");
							printf("  プレイヤ名\b\n");
							printf("  勝利得点\n");
							printf("◎スペシャル\n");
							printf("  リプレイ\n");
							printf("  ハンデ\n");
							printf("  デュース\n");
							printf("  戻る\n");
							break;
						case 3:
							system("cls");
							printf("=====設定=====\n");
							printf("  プレイヤ名\b\n");
							printf("  勝利得点\n");
							printf("  スペシャル\n");
							printf("◎リプレイ\n");
							printf("  ハンデ\n");
							printf("  デュース\n");
							printf("  戻る\n");
							break;
						case 4:
							system("cls");
							printf("=====設定=====\n");
							printf("  プレイヤ名\b\n");
							printf("  勝利得点\n");
							printf("  スペシャル\n");
							printf("  リプレイ\n");
							printf("◎ハンデ\n");
							printf("  デュース\n");
							printf("  戻る\n");
							break;
						case 5:
							system("cls");
							printf("=====設定=====\n");
							printf("  プレイヤ名\b\n");
							printf("  勝利得点\n");
							printf("  スペシャル\n");
							printf("  リプレイ\n");
							printf("  ハンデ\n");
							printf("◎デュース\n");
							printf("  戻る\n");
							break;
						case 6:
							system("cls");
							printf("=====設定=====\n");
							printf("  プレイヤ名\b\n");
							printf("  勝利得点\n");
							printf("  スペシャル\n");
							printf("  リプレイ\n");
							printf("  ハンデ\n");
							printf("  デュース\n");
							printf("◎戻る\n");
							break;
						}
					}

					system("cls");

					printf("=====設定=====\n");
					switch (op_opt) {
					case 0:
						printf("プレイヤ名(1)を入力してください。(10文字以内)\n");
						scanf_s("%s", name1, 11);
						printf("プレイヤ名(2)を入力してください。(10文字以内)\n");
						scanf_s("%s", name2, 11);
						break;
					case 1:
						printf("勝利得点を入力してください。(自然数)\n");
						do {
							scanf_s("%hd", &win_num);
							if (win_num < 1)
								printf("自然数を入力してください。");
							if (win_num <= han_n)
								printf("ハンデの点数(%d)よりも高くしてください。", han_n);
						} while (win_num < 1 || win_num <= han_n);
						break;
					case 2:
						printf("スペシャルカウントのMAXを入力してください。(最大6)\n");
						do {
							scanf_s("%hd", &sp_max);
							if (sp_max < 1 || sp_max > 6)
								printf("1～6の間を入力してください。\n");
						} while (sp_max < 1 || sp_max > 6);
						printf("スペシャルの種類を選んでください。(1 => 爆速 -光- 2 => 精密-落- 3 => 攪乱-舞-)\n");
						do {
							printf("プレイヤ1>");
							scanf_s("%hd", &sp_kind_p);
							if (sp_kind_p != 1 && sp_kind_p != 2 && sp_kind_p != 3)
								printf("1か2か3を入力してください。\n");
						} while (sp_kind_p != 1 && sp_kind_p != 2 && sp_kind_p != 3);
						do {
							printf("プレイヤ2>");
							scanf_s("%hd", &sp_kind_e);
							if (sp_kind_e != 1 && sp_kind_e != 2 && sp_kind_e != 3)
								printf("1か2か3を入力してください。\n");
						} while (sp_kind_e != 1 && sp_kind_e != 2 && sp_kind_e != 3);
						break;
					case 3:
						printf("リプレイしますか?(1 => する　　2 => しない)\n");
						do {
							scanf_s("%hd", &rep);
							if (rep != 1 && rep != 2)
								printf("1か2を入力してください。\n");
						} while (rep != 1 && rep != 2);

						break;
					case 4:
						if (win_num != 1) {
							printf("ハンデをもらうのは？(1 => プレイヤ1  2 => プレイヤ2 3 = > ハンデなし)\n");
							do {
								scanf_s("%hd", &han_d);
								if (han_d != 1 && han_d != 2 && han_d != 3)
									printf("1か2か3を入力してください。\n");
							} while (han_d != 1 && han_d != 2 && han_d != 3);
							if (han_d == 3) {
								han_n = 0;
								break;
							}
							printf("ハンデの点数を入力してください。");
							do {
								scanf_s("%hd", &han_n);
								if (han_n < 1 || han_n >= win_num)
									printf("1から勝利得点(%d)の間を入力してください\n", win_num);
							} while (han_n < 1 || han_n >= win_num);
						}
						else {
							printf("勝利得点が1点の時はハンデをつけることができません。\n");
							printf("Any key plese...");
							//入力待ち
							while(1)
								if (_kbhit()) {
									key = _getch(); //意図しない変数に代入されるのを防ぐ
									break;
								}
						}
						break;
					case 5:
						printf("デュースはどうする？(1 =>　あり 2 => なし)\n");
						do {
							scanf_s("%hd", &deuce);
							if (deuce != 1 && deuce != 2)
								printf("1か2を入力してください。\n");
						} while (deuce != 1 && deuce != 2);
						deuce--;
						break;
					}
					system("cls");
				} while (op_opt != 6);
				break;

			//ルール説明
			case 3:
				while (1) {
					printf("=====ルール=====\n");
					printf("①相手より先に勝利得点に到達することが勝利条件\n");
					printf("②スパイクを打つことでスペシャルカウントを増やせる\n");
					printf("③スペシャルカウントを最大数ためるとスペシャルスパイクを打つことができる\n");
					printf("④プレイヤ1は、右移動 -> a 左移動 ->d ジャンプ -> w トス、サーブ -> s スパイク　-> f\n");
					printf("⑤プレイヤ2は、右移動 -> k 左移動 ->; ジャンプ -> o トス、サーブ -> l スパイク　-> j\n");
					printf("⑥コートからはみ出して落ちると一発負け\n");
					printf("⑦シングルモードでは対戦相手はコンピュータ\n");
					printf("⑧サーブをスパイクすることも可能\n");
					printf("Any key plese...\n");

					//入力されたら次へ
					while (1) {
						if (_kbhit()) {
							key = _getch;  //意図しない変数に代入されるのを防ぐ
							break;
						}
					}

					break;
				}
			case 4:
				system("cls");
				end = 4;
				break;
			}
		} while (op != 0 && op != 1 && op != 4);

		if (end == 4)
			break;

		do {
			//サーブ決め
			printf("サーブはどっち？(1 => %sがサーブ 2 => %sがサーブ 3 => %s)\n", name1, name2, (!op)?"じゃんけんで決める":"ランダムで決める");

			do {
				scanf_s("%hd", &s_d);
				
				if (s_d != 1 && s_d != 2 && s_d != 3)
					printf("1か2か3を入力してください。\n");
			} while (s_d != 1 && s_d != 2 && s_d != 3);

			//乱数の種を変更
			srand((unsigned int)time(NULL));

			//サーブ権のセット
			switch (s_d) {
			case 1:
				surve_right = 0;
				system("cls");
				break;
			case 2:
				surve_right = 1;
				system("cls");
				break;
			case 3:
				if (!op) {
					//画面消去
					system("cls");

					//じゃんけんで決める
					printf("サーバー決めじゃんけん!!!\n");

					//自分の手
					printf("%s出す手を選んでね (1 => グー　2 => チョキ 3 =>　パー)\n", (op == 0) ? "" : "プレイヤ1");
					do {
						scanf_s("%hd", &man);
						man -= 1;
						if (man < 0 || man >= 3)
							printf("1か2か3を入力してください。\n");
					} while (man < 0 || man >= 3);

					//相手の手
					if (op == 0) {
						do {
							com = rand() % 3;
						} while (com == man);
					}
					else {
						printf("プレイヤ2の出す手を選んでね (1 => グー 2 => チョキ 3 => パー)\n");
						do {
							scanf_s("%hd", &com);
							com -= 1;
							if (com < 0 || com >= 3)
								printf("1か2か3を入力してください。\n");
						} while (com < 0 || com >= 3);

					}

					//勝敗判定
					diff = (com - man + 3) % 3;

					//画面消去
					system("cls");

					//勝敗表示
					printf("%s:", name1);
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

					printf("%s:", name2);
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
						printf("%sのサーブ\n", name1);
						surve_right = 0;
						break;
					case 2:
						printf("%sのサーブ\n", name2);
						surve_right = 1;
						break;
					}
				}
				else {
					//ランダムでサーブ権決め
					srand((unsigned int)time(NULL));
					s_r = rand() % 2;
					if (!s_r)
						surve_right = 0;
					else
						surve_right = 1;

					//画面消去
					system("cls");

					//結果表示
					printf("サーブ権抽選の結果:%sのサーブ\n", (!surve_right) ? name1:name2);
				}

				//ゲーム開始
				printf("Any key plese...");
				while (1) {
					if (_kbhit()) {
						key = _getch(); //意図しない変数に代入されるのを防ぐ
						system("cls");
						break;
					}
				}
				break;
			}

			//ハンデの点数を追加
			if (han_d == 1)
				point_p = han_n;
			if (han_d == 2)
				point_p = han_n;

			de_pri = 0;
			de_adv = 0;

			do {
				//デュース判定
				if (point_p == win_num - 1 && point_e == win_num - 1 && deuce == 0)
					de_pri = 1;

				//サーブ

				//座標をリセット
				px = 5, py = 14;
				ex = 18, ey = 14;

				//フラグを下げる
				finish = 0;
				toss_p = 0;
				toss_e = 0;
				spaik = 0;
				end = 0;

				//時を戻す
				time_count = 0;

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

				//表示用のサーブ権
				surve_right_p = surve_right;

				//初期化(double型のby)
				by_d = by;

				//ポイント・サーブ権・スペシャルカウントの表示
				printf("\n\n\n");
				printf("\t\t\t\t\t\t    ");
				printf("サーブにより開始\n");
				printf("\t\t\t\t\t\t    ");
				switch (surve_right_p) {
				case 0:
					printf("●サーブ\n");
					break;
				case 1:
					printf("      　    　　　　　　　　　 　          　サーブ●\n");
					break;
				}
				printf("\t\t\t\t\t\t    ");
				printf("%s　      　　　　　　 　                　%s\n", name1, name2);
				printf("\t\t\t\t\t\t    ");
				printf("スペシャルカウント\n");
				printf("\t\t\t\t\t\t    ");
				if (sp_max == sp_p) {
					if (sp_do_p == 0)
						printf("!!!MAX!!! ");
					else
						printf("!!!!GO!!!!");
				}
				else {
					for (i = 0; i < 5; i++) {
						if (i < sp_p)
							printf("■");
						else
							printf("  ");
					}
				}

				printf("　　　　　             　　　    ");
				if (sp_max == sp_e) {
					if (sp_do_e == 0)
						printf("!!!MAX!!! ");
					else
						printf("!!!!GO!!!!");
				}
				else {
					for (j = 0; j < 5; j++) {
						if (j >= sp_e)
							printf("  ");
						else
							printf("■");
					}
				}

				printf("\n");
				printf("\t\t\t\t\t\t    ");
				if (de_pri)
					switch (de_adv) {
					case 0:
						printf("                      デュース\n");
						break;
					case 1:
						printf("Adv.                      :                        %hd\n", point_e);
						break;
					case 2:
						printf("%hd                         :                        Adv.\n", point_p);
						break;
					}
				else
				    printf("%hd                         :                        %hd\n", point_p, point_e);

				printf("\n");

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

				//座標を表示
				printf("\t\t\t\t\t\t         ");
				printf("(px,py) = (%d, %d)          (ex, ey) = (%d, %d)", px, py, ex, ey);

				//打つまで待つ
				if (surve == 1) {
					//サーブ権が自分
					if (!surve_right) {
						while (1) {
							if (_getch() == 's') {
								surve = 0;
								v_b = 3;
								break;
							}
						}
					}
					else
					{
						if (!op) {
							Sleep(1500);
							v_b = 3;
						}
						else {
							if (_getch() == 'l') {
								v_b = 3;
							}
						}
					}
				}

				//試合
				while (1) {
					//デュース判定
					if (point_p == win_num - 1 && point_e == win_num - 1 && deuce == 0)
						de_pri = 1;

					/*プレイヤーの移動*/
					//左右の移動とジャンプ
					if (sp_2_sel != 1) {
						if (_kbhit()) {
							p = _getch();

							switch (p) {
							case 'd':
								if (px <= 11 && px > 1)
									px++;
								break;
							case 'a':
								if (px >= 1)
									px--;
								break;
							case 's':
								if (toss_p == 0 && b_dir == 1) {
									toss_p = 1;
									toss_p_print = 1;
									toss_p_time = time_count;
								}
								break;
							case 'f':
								if (spaik == 0 && b_dir == 1) {
									spaik = 1;
									spaik_p_print = 1;
									spaik_time = time_count;
								}
								break;
							case 'w':
								if (jumping_p == 0) {
									px_d = px, py_d = py;
									jumping_p = 1;
									v_p = 8;
								}
								break;
							case 'q':
								if (sp_p == sp_max) {
									sp_do_p++;
									sp_do_p %= 2;
								}
								break;
							//二人プレイ用の移動
							case 'k':
								if (op == 1)
									if (ex >= 15)
										ex--;
								break;
							case ';':
								if (op == 1)
									if (ex <= 24)
										ex++;
								break;
							case 'l':
								if (op == 1)
									if (toss_e == 0 && b_dir == 0) {
										toss_e = 1;
										toss_e_print = 1;
										toss_e_time = time_count;
									}
								break;
							case 'j':
								if (op == 1)
									if (spaik_e == 0 && b_dir == 0) {
										spaik_e = 1;
										spaik_e_print = 1;
										spaik_e_time = time_count;
									}
								break;
							case 'o':
								if (op == 1)
									if (jumping_e == 0) {
										ex_d = ex, ey_d = ey;
										jumping_e = 1;
										v_e = 8;
									}
								break;
							case 'p':
								if (op == 1)
									if (sp_e == sp_max) {
										sp_do_e++;
										sp_do_e %= 2;
									}
								break;
							}
						}

						//落下
						if (jumping_p == 1) {
							py_d -= v_p;
							v_p -= 4;
							py = py_d;
							if (px > 1 && py >= 14) {
								jumping_p = 0;
								py = 14;
								v_p = 0;
							}
						}

						/*コートはみ出し*/
						//はみ出したとき
						if (px < 2) {
							jumping_p = 1;
							py_d = py;
						}

						//一番下に行ったら負け
						if (py >= 25) {
							end = 1;
							if(rep == 1)
								system("cls");
							break;
						}


						/*プレイヤーの移動ここまで*/

						/*相手の移動*/
						if (!op) { //一人プレイのときのみ
							if (time_count % 2) {
								if (s_g_e == 1) {
									//スパイクしに行く
									if (ex != 14)
										ex--;
									if (ex == 14 && bx >= 13 && jumping_e == 0) {
										jumping_e = 1;
										v_e = 8;
										ex_d = ex, ey_d = ey;
									}
								}
								else {
									//ボールを追いかける
									if (bx > 13) {
										if (ex > bx && ex > 14)
											ex--;
										if (ex < bx && ex < 25)
											ex++;
									}
									else {
										if (ex > 18)
											ex--;
										if (ex < 18)
											ex++;
									}
								}

							}
							//スパイク(相手)
							if (jumping_e == 1 && (bx > ex - 1 && bx < ex + 1) && by < ey + 3 && by > ey - 5 && b_dir == 0)
								spaik_e = 1, spaik_e_time = time_count, s_g_e = 0, spaik_e_print = 1;

							//トス(相手)
							srand((unsigned int)time(NULL));
							jakka = rand() % 6;

							if ((bx > ex - 1 && bx < ex + 1) && by < ey + 3 && by > ey - 5 && b_dir == 0 && jakka != 0 && spaik_e != 1)
								toss_e = 1, toss_e_time = time_count, toss_e_print = 1;
						}

						//落下
						if (jumping_e == 1) {
							ey_d -= v_e;
							v_e -= 4;
							ey = ey_d;
							if (ex < 24 && ey >= 14) {
								jumping_e = 0;
								ey = 14;
								v_e = 0;
							}
						}

						/*コートはみ出し*/
						//はみ出したとき
						if (ex > 24) {
							jumping_e = 1;
							ey_d = ey;
						}

						//一番下に行ったら負け
						if (ey >= 25) {
							end = 4;
							if(rep == 1)
								system("cls");
							break;
						}

					}
					/*相手の移動ここまで*/

					/*ボールの移動*/
					if (sp_2_sel == 1) {
						if (seller == 1) {
							if (_kbhit()) {
								key = _getch();
								switch (key) {
								case 'a':
									if (bx >= 14)
										bx--;
									break;
								case 'd':
									if (bx <= 25)
										bx++;
									break;
								}

								if (key == 's') {
									v_b = -4;
									sp_2_sel = 0;
								}
							}
						}
						else {
							if (px >= 7) {
								if (bx > 2)
									bx--;
								if (bx == 2) {
									v_b = -4;
									sp_2_sel = 0;
								}
							}
							else {
								if (px <= 6)
									if (bx < 12)
										bx++;
								if (bx == 12) {
									v_b = -4;
									sp_2_sel = 0;
								}
							}
						}
					}

					if (time_count % 2 == 0 && sp_2_sel != 1) {
						//横(x)方向

						//攪乱の時
						if (sp_kind == 3) {
							if (b_dir == 0) {
								if ((time_count - kakuran_time) % 4 == 0)
									bx -= ran(1, 6);
								else
									bx += ran(1, 6);

								if (bx < 14)
									bx = 14;
								if (bx > 24)
									bx = 24;
							}
							else {
								if ((time_count - kakuran_time) % 4 == 0)
									bx -= ran(1, 6);
								else
									bx += ran(1, 6);

								if (bx < 1)
									bx = 1;
								if (bx > 12)
									bx = 12;
							}
						}
						

						//攪乱以外の時
						if (sp_kind != 3 && sp_kind != 2) {
							switch (b_dir) {
							case 0:
								bx++;
								if (sp_kind == 1)
									bx++;
								break;
							case 1:
								if (sp_kind == 1)
									bx--;
								bx--;
								break;
							}
						}

						//縦(y)方向(落下)
						by_d -= v_b;
						v_b -= 0.5;
						by = by_d;

						//ネットに当たった時
						if ((bx == 14 && (by - v_b) >= 7 && b_dir == 1) || (bx == 12 && ((by - v_b) >= 7 && b_dir == 0)))
							b_dir = (b_dir + 1) % 2;

						//床についたとき
						if (by >= 14) {
							//床貫通しないように
							by = 14;

							//跳ね返る
							v_b *= -1;

							//得点を加算
							if ((bx >= 14 && bx < 25) || bx < 1)
								if(de_pri)
									switch (de_adv) {
									case 0:
										de_adv = 1;
										break;
									case 1:
										de_pri = 0;
										point_p++;
										break;
									case 2:
										de_adv = 0;
										break;
									}
								else
								    point_p++;
							else
								if(de_pri)
									switch (de_adv) {
									case 0:
										de_adv = 2;
										break;
									case 1:
										de_adv = 0;
										break;
									case 2:
										de_pri = 0;
										point_e++;
										break;
									}
								else
							    	point_e++;

							//次のプレイへ
							finish_time = time_count;
							finish = 1;
							play_none = 1;
							surve_right++;
							surve_right %= 2;
							sp_kind = 0;
						}
					}

					//トス
					if ((((toss_p == 1 && (bx > px - 1 && bx < px + 1) && (by < py + 3 && by > py - 5)) || (toss_e == 1 && (bx > ex - 1 && bx < ex + 1) && (by < ey + 3 && by > ey - 5)))) && finish == 0) {
						b_dir += 1;
						b_dir %= 2;
						v_b = 3;
						srand((unsigned int)time(NULL));
						randamu = rand() % 2;
						if (toss_p == 1 && randamu == 0) {
							s_g_e = 1;
							if (sp_max == sp_e)
								sp_do_e = 1;
						}
						toss_p = 0;
						toss_e = 0;
						sp_kind = 0;
					}

					//スパイク
					if ((spaik == 1 && jumping_p == 1 && (bx > px - 1 && bx < px + 1) && (by < py + 3 && by > py - 5)) || (spaik_e == 1 && (bx > ex - 1 && bx < ex + 1) && (by < ey + 3 && by > ey - 5))) {
						//方向の返還
						b_dir += 1;
						b_dir %= 2;

						//速度の変更
						v_b = 0;

						//スペシャルカウント増加
						if (sp_max > sp_p && spaik == 1)
							sp_p++;

						if (sp_max > sp_e && spaik_e == 1)
							sp_e++;

						//速度の変更とスペシャルの使用
						if (sp_do_p != 0 && spaik == 1) {
							sp_p = 0;
							sp_do_p = 0;
							switch (sp_kind_p) {
							case 1:
								v_b = -3;
								sp_kind = 1;
								break;
							case 2:
								bx = 14;
								sp_2_sel = 1;
								seller = 1;
								sp_kind = 2;
								break;
							case 3:
								v_b = 0;
								bx = 14;
								kakuran_time = time_count;
								if (kakuran_time % 2 == 1)
									kakuran_time--;
								sp_kind = 3;
								break;
							}
						}
						else if(sp_do_e == 1 && spaik_e == 1){
							sp_e = 0;
							sp_do_e = 0;
							switch (sp_kind_e) {
							case 1:
								v_b = -3;
								sp_kind = 1;
								break;
							case 2:
								bx = 12;
								sp_2_sel = 1;
								seller = 2;
								sp_kind = 2;
								break;
							case 3:
								v_b = 0;
								bx = 12;
								kakuran_time = time_count;
								if (kakuran_time % 2 == 1)
									kakuran_time--;
								sp_kind = 3;
								break;
							}
						}
						else {
							v_b = 0;
						}

						sp_do_p = 0;
						spaik = 0;
						spaik_e = 0;
					}

					//プレイを次へ(床についてから6カウント分)

					if (play_none == 1) {
						surve = 1;
						if (time_count - finish_time == 6) {
							//勝敗判定
							if (point_p == win_num)
								end = 2;

							if (point_e == win_num)
								end = 3;

							//次のプレイへ
							if ((point_p != win_num && point_e != win_num) || rep == 1)
								system("cls");

							play_none = 0;
							toss_p_print = 0, toss_e_print = 0;
							break;
						}
					}

					//画面消去
					system("cls");

					//ポイント・サーブ権・スペシャルカウントの表示
					printf("\n\n\n\n\n\n\n");
					printf("\t\t\t\t\t\t    ");
					switch (surve_right_p) {
					case 0:
						printf("●\n");
						break;
					case 1:
						printf("                                                   ●\n");
						break;
					}
					printf("\t\t\t\t\t\t    ");
					printf("%s　　        　　     　　 　           　%s\n", name1, name2);
					printf("\t\t\t\t\t\t    ");
					printf("スペシャルカウント\n");
					printf("\t\t\t\t\t\t    ");
					if (sp_max == sp_p) {
						if (sp_do_p == 0)
							printf("!!!MAX!!! ");
						else
							printf("!!!!GO!!!!");
					}
					else {
						for (i = 0; i < 5; i++) {
							if (i < sp_p)
								printf("■");
							else
								printf("  ");
						}
					}
					printf("　　　　     　      　　　      ");
					if (sp_max == sp_e) {
						if (sp_do_e == 0)
							printf("!!!MAX!!! ");
						else
							printf("!!!!GO!!!!");
					}
					else {
						for (j = 0; j < 5; j++) {
							if (j >= sp_e)
								printf("  ");
							else
								printf("■");
						}
					}

					printf("\n");
					printf("\t\t\t\t\t\t    ");
					if (de_pri)
						switch (de_adv) {
						case 0:
							printf("                      デュース\n");
							break;
						case 1:
							printf("Adv.                      :                        %hd\n", point_e);
							break;
						case 2:
							printf("%hd                         :                        Adv.\n", point_p);
							break;
						}
					else
					    printf("%hd                         :                        %hd\n", point_p, point_e);

					//スペシャルスパイクの表示
					switch (sp_kind) {
					case 0:
						printf("\n");
						break;
					case 1:
						printf("\t\t\t\t\t\t                          爆速 -光-\n");
						break;
					case 2:
						printf("\t\t\t\t\t\t                          精密 -落-\n");
						break;
					case 3:
						printf("\t\t\t\t\t\t                          攪乱 -舞-\n");
						break;
					}

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
							else if (x == bx && y == by)
								printf("●");
							else if (x == px && y == py - 3 && toss_p_print == 1)
								printf("TT");
							else if (x == ex && y == ey - 3 && toss_e_print == 1)
								printf("TT");
							else if (x == px && y == py - 3 && spaik_p_print == 1)
								printf("「");
							else if (x == ex && y == ey - 3 && spaik_e_print == 1)
								printf("] ");
							else if (x == ex && y == ey - 2)
								printf("○");
							else if (x == ex && y == ey - 1)
								printf("■");
							else if (x == ex && y == ey)
								printf("ル");
							else if (x == 13 && y >= 7 && y < 15)
								printf("□");
							else if (x > 1 && x < 25 && y == 15)
								printf("□");
							else
								printf("  ");
						}
						printf("\n");
					}

					//座標を表示
					printf("\t\t\t\t\t\t         ");
					printf("(px,py) = (%d, %d)          (ex, ey) = (%d, %d)", px, py, ex, ey);

					//軌跡の代入
					hist_px[time_count] = px, hist_py[time_count] = py;
					hist_ex[time_count] = ex, hist_ey[time_count] = ey;
					hist_bx[time_count] = bx, hist_by[time_count] = by;
					hist_po_p[time_count] = point_p, hist_po_e[time_count] = point_e;
					hist_toss_p[time_count] = toss_p_print, hist_toss_e[time_count] = toss_e_print;
					hist_sp_p[time_count] = sp_p, hist_sp_e[time_count] = sp_e;
					hist_sp_do_p[time_count] = sp_do_p;
					hist_sp_do_e[time_count] = sp_do_e;
					hist_sp_kind[time_count] = sp_kind;
					hist_spaik_p[time_count] = spaik_p_print;
					hist_spaik_e[time_count] = spaik_e_print;
					hist_de_pri[time_count] = de_pri;
					hist_de_adv[time_count] = de_adv;

					//時間を増やす
					time_count++;

					//トスのフラグを下げる
					if (toss_p_print == 1) {
						if (time_count - toss_p_time >= 4) {
							toss_p = 0;
							toss_p_print = 0;
						}
					}
					if (toss_e_print == 1) {
						if (time_count - toss_e_time >= 4) {
							toss_e = 0;
							toss_e_print = 0;
						}
					}

					//スパイクのフラグを下げる
					if (spaik == 1) {
						if (time_count - spaik_time >= 4)
							spaik = 0;
					}

					if (spaik_p_print == 1) {
						if (time_count - spaik_time >= 4) {
							spaik = 0;
							spaik_p_print = 0;
						}
					}
					if (spaik_e_print == 1) {
						if (time_count - spaik_e_time >= 4) {
							spaik_e = 0;
							spaik_e_print = 0;
						}
					}

				}

				//リプレイ
				if (rep == 1) {
					if (time_count - 50 <= 0)
						rep_start = 0;
					else
						rep_start = time_count - 50;
					for (j = rep_start; j < time_count; j++) {

						//表示開始
						printf("\t\t\t\t\t\t    ");

						printf("=======================リプレイ=======================\n");
						//ポイント・サーブ権・スペシャルカウントの表示
						printf("\n\n\n\n\n\n");
						printf("\t\t\t\t\t\t    ");
						switch (surve_right_p) {
						case 0:
							printf("●\n");
							break;
						case 1:
							printf("                                                   ●\n");
							break;
						}
						printf("\t\t\t\t\t\t    ");
						printf("%s　　        　　     　　 　           　%s\n", name1, name2);
						printf("\t\t\t\t\t\t    ");
						printf("スペシャルカウント\n");
						printf("\t\t\t\t\t\t    ");
						if (sp_max == hist_sp_p[j]) {
							if (hist_sp_do_p[j] == 0)
								printf("!!!MAX!!! ");
							else
								printf("!!!!GO!!!!");
						}
						else {
							for (i = 0; i < 5; i++) {
								if (i < hist_sp_p[j])
									printf("■");
								else
									printf("  ");
							}
						}
						printf("　　　　     　      　　　      ");
						if (sp_max == hist_sp_e[j]) {
							if (hist_sp_do_e[j] == 0)
								printf("!!!MAX!!! ");
							else
								printf("!!!!GO!!!!");
						}
						else {
							for (i = 0; i < 5; i++) {
								if (i >= hist_sp_e[j])
									printf("  ");
								else
									printf("■");
							}
						}
						printf("\n");
						printf("\t\t\t\t\t\t    ");
						if (hist_de_pri[j])
							switch (hist_de_adv[j]) {
							case 0:
								printf("                      デュース                      \n");
								break;
							case 1:
								printf("Adv.                      :                        %hd\n", hist_po_e[j]);
								break;
							case 2:
								printf("%hd                         :                        Adv.\n", hist_po_p[j]);
								break;
							}
						else
						    printf("%hd                         :                        %hd\n", hist_po_p[j], hist_po_e[j]);

						//スペシャルスパイクの表示
						switch (hist_sp_kind[j]) {
						case 0:
							printf("\n");
							break;
						case 1:
							printf("\t\t\t\t\t\t                          爆速 -光-\n");
							break;
						case 2:
							printf("\t\t\t\t\t\t                          精密 -落-\n");
							break;
						case 3:
							printf("\t\t\t\t\t\t                          攪乱 -舞-\n");
							break;
						}

						for (y = 0; y <= MAP_Y; y++) {
							printf("\t\t\t\t\t\t    ");
							for (x = 0; x <= MAP_X; x++) {
								if (x == hist_px[j] && y == hist_py[j] - 2)
									printf("▲");
								else if (x == hist_px[j] && y == hist_py[j] - 1)
									printf("■");
								else if (x == hist_px[j] && y == hist_py[j])
									printf("八");
								else if (x == hist_bx[j] && y == hist_by[j])
									printf("●");
								else if (x == hist_px[j] && y == hist_py[j] - 3 && hist_toss_p[j] == 1)
									printf("TT");
								else if (x == hist_ex[j] && y == hist_ey[j] - 3 && hist_toss_e[j] == 1)
									printf("TT");
								else if (x == hist_px[j] && y == hist_py[j] - 3 && hist_spaik_p[j] == 1)
									printf("「");
								else if (x == hist_ex[j] && y == hist_ey[j] - 3 && hist_spaik_e[j] == 1)
									printf("] ");
								else if (x == hist_ex[j] && y == hist_ey[j] - 2)
									printf("○");
								else if (x == hist_ex[j] && y == hist_ey[j] - 1)
									printf("■");
								else if (x == hist_ex[j] && y == hist_ey[j])
									printf("ル");
								else if (x == 13 && y >= 7 && y < 15)
									printf("□");
								else if (x > 1 && x < 25 && y == 15)
									printf("□");
								else
									printf("  ");
							}
							printf("\n");
						}

						//座標を表示
						printf("\t\t\t\t\t\t         ");
						printf("(px,py) = (%d, %d)          (ex, ey) = (%d, %d)", px, py, ex, ey);

						//画面消去
						system("cls");
					}
				}

				//最後の描画
				if (rep == 1 && end != 0) {
					//ポイント・サーブ権・スペシャルカウントの表示
					printf("\n\n\n\n\n\n\n");
					printf("\t\t\t\t\t\t    ");
					switch (surve_right_p) {
					case 0:
						printf("●\n");
						break;
					case 1:
						printf("                                                   ●\n");
						break;
					}
					printf("\t\t\t\t\t\t    ");
					printf("%s　　        　　     　　 　           　%s\n", name1, name2);
					printf("\t\t\t\t\t\t    ");
					printf("スペシャルカウント\n");
					printf("\t\t\t\t\t\t    ");
					if (sp_max == sp_p) {
						if (sp_do_p == 0)
							printf("!!!MAX!!! ");
						else
							printf("!!!!GO!!!!");
					}
					else {
						for (i = 0; i < 5; i++) {
							if (i < sp_p)
								printf("■");
							else
								printf("  ");
						}
					}
					printf("　　　　     　      　　　      ");
					if (sp_max == sp_e) {
						if (sp_do_e == 0)
							printf("!!!MAX!!! ");
						else
							printf("!!!!GO!!!!");
					}
					else {
						for (i = 0; i < 5; i++) {
							if (i >= sp_e)
								printf("  ");
							else
								printf("■");
						}
					}
					printf("\n");
					printf("\t\t\t\t\t\t    ");
					printf("%hd                         :                        %hd\n", point_p, point_e);

					//スペシャルスパイクの表示
					switch (sp_kind) {
					case 0:
						printf("\n");
						break;
					case 1:
						printf("\t\t\t\t\t\t                          爆速 -光-\n");
						break;
					case 2:
						printf("\t\t\t\t\t\t                          精密 -落-\n");
						break;
					case 3:
						printf("\t\t\t\t\t\t                          攪乱 -舞-\n");
						break;
					}

					for (y = 0; y <= MAP_Y; y++) {
						printf("\t\t\t\t\t\t    ");
						for (x = 0; x <= MAP_X; x++) {
							if (x == px && y == py - 2)
								printf("▲");
							else if (x == px && y == py - 1)
								printf("■");
							else if (x == px && y == py)
								printf("八");
							else if (x == bx && y == by)
								printf("●");
							else if (x == px && y == py - 3 && toss_p == 1)
								printf("TT");
							else if (x == ex && y == ey - 3 && toss_e == 1)
								printf("TT");
							else if (x == px && y == py - 3 && spaik == 1)
								printf("「");
							else if (x == ex && y == ey - 2)
								printf("○");
							else if (x == ex && y == ey - 1)
								printf("■");
							else if (x == ex && y == ey)
								printf("ル");
							else if (x == 13 && y >= 7 && y < 15)
								printf("□");
							else if (x > 1 && x < 25 && y == 15)
								printf("□");
							else
								printf("  ");
						}
						printf("\n");
					}

					//座標を表示
					printf("\t\t\t\t\t\t         ");
					printf("(px,py) = (%d, %d)          (ex, ey) = (%d, %d)", px, py, ex, ey);
				}
				printf("\n\n\n");
				switch (end) {
				case 1:
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					printf("\t\t\t\t\t\t                       %s    LOSE   (FALLEN)\n", name1);
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					break;
				case 2:
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					printf("\t\t\t\t\t\t                       %s    WIN   (You got  point!)\n", name1);
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					break;
				case 3:
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					printf("\t\t\t\t\t\t                       %s    WIN   (You got  point!)\n", name2);
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					break;
				case 4:
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					printf("\t\t\t\t\t\t                       %s    LOSE   (FALLEN)\n", name2);
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					break;
				}
			} while (point_p < win_num && point_e < win_num && end == 0);

			Sleep(5000);

			system("cls");

			//続ける or 終了
			while (1) {
				if (_kbhit()) {
					key = _getch();

					switch (key) {
					case 'a':
						con_fin--;
						break;
					case 'd':
						con_fin++;
						break;
					}

					if (key == ENTER)
						break;
				}
				con_fin = (con_fin + 2) % 2;

				switch (con_fin) {
				case 0:
					printf("◎New Game            finish");
					break;
				case 1:
					printf("  New Game          ◎finish");
					break;
				}
				system("cls");
			}

			point_p = 0, point_e = 0;
			sp_p = 0, sp_e = 0;
			toss_p_print = 0;
			toss_e_print = 0;
			end = 0;
			sp_do_p = 0;
		} while (con_fin == 0);
	}while (con_fin == 1);

	printf("See You Next Time!!!!");
	Sleep(10000);

	return 0;
}

int ran(short int x, short int y) {
	short int diff, num;

	//差を求める
	diff = abs(x - y);

    //乱数により値を決定
	srand((unsigned int)time(NULL));
	num = rand() % diff;

	//返したい値に適切になるように
	if (x > y)
		num += y;
	else
		num += x;

	return num;
}