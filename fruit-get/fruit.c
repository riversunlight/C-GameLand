#define SIZE 15
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kudamono[SIZE][SIZE] = { 0 };

enum fruit {
	EMPTY,     //(空白)
	ORANGE,    //〇
	APPLE,     //●
	PAINAPPLE, //■
	W_MERON,   //☆
	BOM,       //×
	P_KINOKO   //△
};

//果物の座標をひとつづつ下げる
void fruit_move(void) {
	for (int i = 0; i < SIZE; i++)
		for (int j = SIZE - 1; j > 0; j--) {
			kudamono[i][j] = kudamono[i][j - 1];
			kudamono[i][j - 1] = EMPTY;
		}
}

int fruit_get(int score, int x) {
	for (int i = 0; i < SIZE; i++) {
		if (kudamono[i][14] != EMPTY && x == i)
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
	return score;
}

void fruit_gene(int e_o_s) {
	int r;
	int gene_div = 1000;

	//確率変更
	switch (e_o_s) {
	case 0:
		gene_div = 500;
		break;
	case 2:
		gene_div = 1500;
		break;
	}

	//生成
	for (int i = 0; i < SIZE; i++) {
		r = rand() % gene_div;
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
}

void show(int cx, int cy, int score) {
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
}

void fruit_reset(void) {
	for (int i = 0; i < SIZE; i++)
		memset(kudamono[i], EMPTY, sizeof(kudamono[i]));
}