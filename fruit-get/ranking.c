#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define RANK_NUM 5
int score[RANK_NUM] = { 0 };

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
	FILE* fp;
	errno_t error;
	
	for (i = 0; i < RANK_NUM; i++)
		if (score[i] < point) {
			for (int j = 4; j > i; j--)
				score[j] = score[j - 1];
			score[i] = point;
			break;
		}

	error = fopen_s(&fp, "data.txt", "w");
	if (error != 0) {
		printf("data.txtファイルをオープンできませんでした\n");
	}
	else {
		for (int i = 0; i < RANK_NUM; i++)
		    fprintf(fp, "%d\n", score[i]);
	}


	return i;
}

int rank_read() {
	FILE* fp;
	errno_t error;
	error = fopen_s(&fp, "data.txt", "r");

	if (error != 0) {
		printf("data.txtファイルをオープンできませんでした\n");
		printf("ない場合は新しく作成し、点数を5つ縦に書いてください\n");
		return 1;
	}

	for (int i = 0; i < RANK_NUM; i++)
		fscanf_s(fp, "%d", &score[i]);

	fclose(fp);
	return 0;
}