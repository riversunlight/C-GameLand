#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "ranking.h"
#define ENTER 13

void rule(void) {
	int key = 0;
	system("cls");
	printf("============================RULE===========================\n");
	printf("1.�����Ă���ʕ�������ē��_�Q�b�g!���_�������̂�����̂Œ���!\n");
	printf("2,�݂���(�Z) 10�_ �����S(��) 20�_  �p�C�i�b�v��(��)30�_ �X�C�J(��) 40�_\n");
	printf("3,�ŃL�m�R(��) -10�_ ���e(x) -40�_\n");
	printf("4.a�ō��ړ��Ad�ŉE�ړ�  �[����[�փ��[�v�\(�t�ɂ��Â炢��������܂���)\n");
	printf("Any key plese...\n");
	while (1) {
		if (_kbhit()) {
			key = _getch();
			system("cls");
			break;
		}
	}
}

int item_easy(void) {
	int key;
	int flag = 1;
	int op = 0;
	while (flag) {
		printf("===�A�C�e���̏o�₷��===\n");
		printf("%s�o�₷��\n", (op == 0)? "��" : "  ");
		printf("%s����\n", (op == 1) ? "��" : "  ");
		printf("%s�o�ɂ���\n", (op == 2) ? "��" : "  ");
		system("cls");
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case 'w':
				op--;
				break;
			case 's':
				op++;
				break;
			case ENTER:
				flag = 0;
				break;
			}
			op = (op + 3) % 3;
		}
	}

	return 100 + op;
}

int option(void) {
	int key;
	int flag = 1;
	int num = 1;
	int op = 0;
	while (flag) {
		printf("=====OPTION=====\n");
		printf("%s�A�C�e���̏o�₷��\n", (op == 0) ? "��" : "  ");
		printf("%s�߂�\n", (op == 1) ? "��" : "  ");
		system("cls");
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case 'w':
				op--;
				break;
			case 's':
				op++;
				break;
			case ENTER:
				flag = 0;
				break;
			}
			op = (op + 2) % 2;
		}
	}

	switch (op) {
	case 0:
		num = item_easy();
		break;
	}

	return num;
}

int opening(int cho) {
	int flag = 1;
	int op = 0;
	int key;
	int num = 0;

	if (cho == 1) {
		flag = 0;
		op = 1;
	}

	do {
		while (flag) {
			system("cls");
			printf("==========�ʕ��W�߃Q�[��==========\n");
			printf("%sSTART\n", (op == 0) ? "        ��" : "          ");
			printf("%sOPTION\n", (op == 1) ? "        ��" : "          ");
			printf("%sRANKING\n", (op == 2) ? "        ��" : "          ");
			printf("%sRULE\n", (op == 3) ? "        ��" : "          ");
			printf("%sEND\n", (op == 4) ? "        ��" : "          ");
			if (_kbhit()) {
				key = _getch();
				switch (key) {
				case 'w':
				case '8':
					op--;
					break;
				case 's':
				case '2':
					op++;
					break;
				case ENTER:
					flag = 0;
					break;
				}
				op = (op + 5) % 5;
			}
		}
		system("cls");
		switch (op) {
		case 1:
			num = option();
			flag = 1;
			break;
		case 2:
			rank_show();
			flag = 1;
			break;
		case 3:
			rule();
			flag = 1;
			break;
		case 4:
			num = -1;
			break;
		}
	} while (op == 2 || op == 3);

	return num;
}

int ending(int op, int rank) {
	int flag = 1;
	int key;
	while (1) {
			printf("RANK IN: %d RANK", rank + 1);
			for (int j = 4; j > rank; j--)
				printf("!");
			printf("\n");

		printf("%snew game\n", (op == 0) ? "��" : "  ");
		printf("%send\n", (op == 1) ? "��" : "  ");
		system("cls");
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case 'w':
				op--;
				break;
			case 's':
				op++;
				break;
			case ENTER:
				flag = 0;
				break;
			}
			op = (op + 2) % 2;
			if (flag == 0)
				break;
		}
	}
	return op;
}

void end_sen(void){
	printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
	printf("                     !!!!!�I��!!!!!\n");
	printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
	Sleep(5000);
}