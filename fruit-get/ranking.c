#include<stdio.h>
#include<conio.h>
#include<windows.h>
int score[5] = { 0 };

void rank_show(){
	while (1) {
		system("cls");
		printf("=====RANKING=====\n");
		for (int i = 0; i < 5; i++)
			printf("%d: %5d\n", i + 1, score[i]);
		printf("Any key plese...\n");
		if (_kbhit()) {
			int key = _getch();
			break;
		}
	}
	return;
}

int ranking_update(int point) {
	int i;
	for (i = 0; i < 5; i++)
		if (score[i] < point) {
			for (int j = 4; j > i; j--)
				score[j] = score[j - 1];
			score[i] = point;
			break;
		}
		    
	return i;
}