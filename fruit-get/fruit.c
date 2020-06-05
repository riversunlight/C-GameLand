#define SIZE 15
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kudamono[SIZE][SIZE] = { 0 };

enum fruit {
	EMPTY,     //(ãÛîí)
	ORANGE,    //ÅZ
	APPLE,     //Åú
	PAINAPPLE, //Å°
	W_MERON,   //Åô
	BOM,       //Å~
	P_KINOKO   //Å¢
};

//â ï®ÇÃç¿ïWÇÇ–Ç∆Ç¬Ç√Ç¬â∫Ç∞ÇÈ
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

void fruit_gene(void) {
	int r;
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
}

void show(int cx, int cy, int score) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			if (i == cy && j == cx)
				printf("Åù");
			else
				switch (kudamono[j][i]) {
				case EMPTY:
					printf("  ");
					break;
				case ORANGE:
					printf("ÅZ");
					break;
				case APPLE:
					printf("Åú");
					break;
				case PAINAPPLE:
					printf("Å°");
					break;
				case W_MERON:
					printf("Åô");
					break;
				case BOM:
					printf("Å~");
					break;
				case P_KINOKO:
					printf("Å¢");
					break;
				}
		printf("\n");
	}

	//ìæì_ÇÃï\é¶
	printf("SCORE: %5d\n", score);
}

void fruit_reset(void) {
	for (int i = 0; i < SIZE; i++)
		memset(kudamono[i], EMPTY, sizeof(kudamono[i]));
}