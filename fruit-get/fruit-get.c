/*�ʕ��W�߃Q�[��*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "fruit.h"
#include "player.h"
#include "oprate.h"

int main(void) {
	int cx = 8, cy = 14;
	int key;
	int score = 0;
	int op = 0;
	int flag = 0;
	int e_o_s = 0;

	/*�I�[�v�j���O*/
	opening();
	/*�I�[�v�j���O�����܂�*/

	//���C�����[�v
	while (1) {
		score = 0;
		flag = 0;
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
				//�ʕ��̈ړ�
				fruit_move();

				//�擾���̉��_
				score = fruit_get(score, cx);
				
				/*�ʕ�����*/
				fruit_gene();
				/*�ʕ����������܂�*/
			}

			/*�L�����N�^�̈ړ�*/
			//�L�����N�^�̑���
			if (_kbhit()) {
				key = _getch();
				switch (key) {
				case 'a':
				case '4':
				case 'd':
				case '6':
					cx = player_move(cx, key);
					break;
				case 27:
					flag = 1;
					break;
				}
			}

			//esc�L�[�ɂ��I��
			if (flag == 1)
				break;
			/*�ړ������܂�*/

			/*�\��*/
			//�v���C���
			system("cls");
			
			show(cx, cy, score);
			/*�\�������܂�*/
		}

		end_sen();

		flag = 1;

		//���s���I����
		system("cls");
		op = 0;
		
		op = ending(op);
		if (op == 1)
			break;

		fruit_reset();
	}

	printf("See you next time!!!!!!\n");
	Sleep(6000);
	return 0;
}