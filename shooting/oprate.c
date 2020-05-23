#include<stdlib.h>
#include<time.h>

int myBullet[10][2];
int enemyBullet[10][2];
static int my_num = 0;
static int enemy_num = 0;

int move(int place, int s, int size) {
	//keyによる操作
	if (s == 'a')
		place--;
	else if (s == 'd')
		place++;

	//ワープ処理
	place = (place + size) % size;
	return place;
}

int enemy_move(int place, int size) {
	//乱数による操作
	int r = rand() % 3;
	if (r == 0)
		place++;
	else if (r == 1)
		place--;

	//ワープ処理
	place = (place + size) % size;
	return place;
}

void bullet_gene(int player, int x) {
	if (player == 0) {
		if (my_num < 10) {
			myBullet[my_num][0] = x;
			myBullet[my_num++][1] = 13;
		}
	}
	else {
		if (enemy_num < 10) {
			enemyBullet[enemy_num][0] = x;
			enemyBullet[enemy_num++][1] = 1;
		}
	}
	return;
}

void bullet_move() {
	for (int i = 0; i < my_num; i++) {
		myBullet[i][1]--;
		if (myBullet[i][1] == -1) {
			for (int j = i; j < my_num; j++) {
				myBullet[j][0] = myBullet[j + 1][0];
				myBullet[j][1] = myBullet[j + 1][1];
			}
			my_num--;
			i--;
		}
	}
	for (int i = 0; i < enemy_num; i++) {
		enemyBullet[i][1]++;
		if (enemyBullet[i][1] == 15) {
			for (int j = i; j < enemy_num; j++) {
				enemyBullet[j][0] = enemyBullet[j + 1][0];
				enemyBullet[j][1] = enemyBullet[j + 1][1];
			}
			enemy_num--;
			i--;
		}
	}
	return;
}

int isBullet(int x, int y) {
	for (int i = 0; i < my_num; i++) {
		if (myBullet[i][0] == x && myBullet[i][1] == y)
			return 1;
	}
	for (int i = 0; i < enemy_num; i++) {
		if (enemyBullet[i][0] == x && enemyBullet[i][1] == y)
			return 1;
	}

	return 0;
}

int isHit(int player, int life, int x) {
	if (player == 0) {
		for (int i = 0; i < enemy_num; i++) {
			if (x == enemyBullet[i][0] && enemyBullet[i][1] == 14) {
				return life - 1;
			}
		}
	}
	else {
		for (int i = 0; i < my_num; i++) {
			if (x == myBullet[i][0] && myBullet[i][1] == 0) {
				return life - 1;
			}
		}
	}
	return life;
}

void init_0() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			myBullet[i][j] = 0;
			enemyBullet[i][j] = 0;
		}
	}
	return;
}