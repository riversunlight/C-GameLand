/*�ʕ��W�߃Q�[��*/

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 15
#define ENTER 13
#define ESC 27

enum fruit {
	EMPTY,     //(��)
	ORANGE,    //�Z
	APPLE,     //��
	PAINAPPLE, //��
	W_MERON,   //��
	BOM,       //�~
	P_KINOKO   //��
};

int main() {
	int cx = 8, cy = 14;
	int key;
	int r;
	int score = 0;
	int op = 0;
	int kudamono[SIZE][SIZE] = { 0 };
	int flag = 1;

	/*�I�[�v�j���O*/
	do {
		while (flag) {
			printf("==========�ʕ��W�߃Q�[��==========\n");
			printf("%sSTART\n", (op == 1) ? "          " : "        ��");
			printf("%sRULE\n", (op == 0)?"          " : "        ��");
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
				case 13:
					flag = 0;
					break;
				}
				op = (op + 2) % 2;
			}
			system("cls");
		}
		switch (op) {
		case 1:
			//���[���\��
			printf("1.�����Ă���ʕ�������ē��_�Q�b�g!���_�������̂�����̂Œ���!\n");
			printf("2,�݂���(�Z) 10�_ �����S(��) 20�_  �p�C�i�b�v��(��)30�_ �X�C�J(��) 40�_\n");
			printf("3,�ŃL�m�R(��) -10�_ ���e(x) -40�_\n");
			printf("4.a�ō��ړ��Ad�ŉE�ړ�  �[����[�փ��[�v�\(�t�ɂ��Â炢��������܂���)\n");
			while (1) {
				if (_kbhit()) {
					key = _getch();
					flag = 1;
					system("cls");
					break;
				}
			}
			break;
		}
	} while (op);
	/*�I�[�v�j���O�����܂�*/

	//���C�����[�v
	while (1) {
		score = 0;
		//�J�E���g�_�E��
		for (int i = 3; i > 0; i--) {
			printf("�J�n�܂�%d", i);
			Sleep(1000);
			system("cls");
		}
		printf("�X�^�[�g!!!!!");
		Sleep(1000);
		system("cls");
		srand(time(NULL));

		for (int cnt = 0; cnt < 1000; cnt++) {

			//�ʕ��֘A
			if (cnt % 3 == 0) {
				/*�ʕ��̈ړ�*/
				//�ЂƂÂ�����
				for (int i = 0; i < SIZE; i++)
					for (int j = SIZE - 1; j > 0; j--) {
						kudamono[i][j] = kudamono[i][j - 1];
						kudamono[i][j - 1] = EMPTY;
					}
				/*�ʕ��̈ړ������܂�*/

				/*�擾���̉��_*/
				for (int i = 0; i < SIZE; i++) {
					if (kudamono[i][14] != EMPTY && cx == i)
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
				/*�擾���̉��_�����܂�*/

				/*�ʕ�����*/
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
				/*�ʕ����������܂�*/
			}

			/*�L�����N�^�̈ړ�*/
			//�L�����N�^�̑���
			if (_kbhit()) {
				key = _getch();
				switch (key) {
				case 'a':
				case '4':
					cx--;
					break;
				case 'd':
				case '6':
					cx++;
					break;
				case ESC:
					flag = 1;
					break;
				}
			}
			//���[�v
			cx = (cx + SIZE) % SIZE;

			//esc�L�[�ɂ��I��
			if (flag == 1)
				break;
			/*�ړ������܂�*/

			/*�\��*/
			//�v���C���
			system("cls");
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++)
					if (i == cy && j == cx)
						printf("��");
					else
						switch (kudamono[j][i]) {
						case EMPTY:
							printf("  ");
							break;
						case ORANGE:
							printf("�Z");
							break;
						case APPLE:
							printf("��");
							break;
						case PAINAPPLE:
							printf("��");
							break;
						case W_MERON:
							printf("��");
							break;
						case BOM:
							printf("�~");
							break;
						case P_KINOKO:
							printf("��");
							break;
						}
				printf("\n");
			}

			//���_�̕\��
			printf("SCORE: %5d\n", score);
			/*�\�������܂�*/
		}

		printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
		printf("                     !!!!!�I��!!!!!\n");
		printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
		flag = 1;
		Sleep(5000);

		//���s���I����
		system("cls");
		op = 0;
		while (1) {
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

		if (op == 1)
			break;

		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				kudamono[i][j] = EMPTY;
	}

	printf("See you next time!!!!!!\n");
	Sleep(6000);
	return 0;
}