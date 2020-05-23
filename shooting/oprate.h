#pragma once
#include<stdio.h>

int move(int place, int s, int size);
int enemy_move(int place, int size);
void bullet_gene(int player, int x);
void bullet_move();
int isBullet(int x, int y);
int isHit(int player, int life, int x);
void init_0();