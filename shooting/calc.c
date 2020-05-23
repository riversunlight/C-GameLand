#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include"oprate.h"

#define ENTER 13

void update(int cx, int cy, int ex, int ey, int myLife, int enemyLife, int size) {
	//��ʏ���
	system("cls");

	//�v���C���
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j == cx && i == cy)
				printf("��");
			else if (j == ex && i == ey)
				printf("��");
			else if (isBullet(j, i))
				printf("��");
			else
				printf("  ");
		}
		printf("\n");
	}

	//���C�t
	printf("MyLife:");
	for (int i = 0; i < myLife; i++)
		printf("��");
	printf("\n");
	printf("EnemyLife:");
	for (int i = 0; i < enemyLife; i++)
		printf("��");
	printf("\n");

	return;
}

void ending(int flag) {
	switch (flag) {
	case 1:
		printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
		printf("!!!!!!!!YOU WIN!!!!!!!!!!!!!!\n");
		printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
		break;
	case 2:
		printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
		printf("        YOU LOSE...          \n");
		printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
		break;
	}
	return;
}

int opening() {
	int op = 0;
	int flag = 0;

	do {
		while (1) {
			//�J�[�\���ړ�
			if (_kbhit()) {
				int op_o = _getch();
				switch (op_o) {
				case 'w':
					op--;
					break;
				case 's':
					op++;
					break;
				case ENTER:
					flag = 1;
					break;
				}
				op = (op + 3) % 3;
			}

			if (flag == 1) {
				flag = 0;
				break;
			}

			//��ʕ\��
			printf("==========�V���[�e�B���O�Q�[��==========\n");
			printf("%sSTART\n", (op == 0) ? "��" : "  ");
			printf("%sRULE\n", (op == 1) ? "��" : "  ");
			printf("%sEND\n", (op == 2) ? "��" : "  ");

			//��ʏ���
			system("cls");
		}

		switch (op) {
		case 1:
			do {
				printf("=====���[��=====\n");
				printf("1.�e���o���āA������U�����A����̃��C�t���Ȃ����Ώ���\n");
				printf("2.A�ō��ړ��AD�ŉE�ړ��A�X�y�[�X�L�[�Œe���o����\n");
				printf("Any Key Plese...\n");
				system("cls");

				if (_kbhit()) {
					flag = 1;
					int key = _getch();
					break;
				}
			} while (flag == 0);
			flag = 0;
			break;
		case 2:
			return 1;
		}
	} while (op == 1);
	return 0;
}

int new_game() {
	int op = 0;
	while (1) {
		printf("%sNEW GAME\n", (op == 0) ? "��" : "  ");
		printf("%sEND\n", (op == 1) ? "��" : "  ");
		system("cls");
		if (_kbhit()) {
			int key = _getch();
			switch (key) {
			case 'w':
				op--;
				break;
			case 's':
				op++;
				break;
			case ENTER:
				return op;
			}
		}
	}
}