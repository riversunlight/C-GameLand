/*�ʕ��W�߃Q�[��*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "fruit.h"
#include "player.h"
#include "oprate.h"
#include "ranking.h"

int main(void) {
	int cx = 8, cy = 14;
	int key;
	int score = 0;
	int op = 0;
	int rank;
	int flag = 0;
	int e_o_s = 1;
	int open;
	int op_flag = 0;

	//�X�R�A�̓ǂݍ���
	rank_read();

	/*���ׂẴ��[�v*/
	do {
		flag = 0;
		/*�I�[�v�j���O*/
		do {
			int num;
			open = opening(op_flag);
			if (open == -1) {//END�L�[�ɂ��I��
				flag = 1;
				break;
			}
			op_flag = 0;
			num = open / 100;
			switch (num) {
			case 1:
				e_o_s = open % 100;
				op_flag = 1;
				break;
			}
		} while (open != 0);
		/*�I�[�v�j���O�����܂�*/

		//END�L�[�ɂ��I��
		if (flag == 1)
			break;

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
					fruit_gene(e_o_s);
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

			/*�Q�[���I����̏���*/
			fruit_reset();

			end_sen();

			flag = 1;

			//���s���I����
			system("cls");
			op = 0;
			
			//�����L���O�̍X�V
			rank = ranking_update(score);
			op = ending(op, rank);
			if (op == 1)
				break;

		}
	} while (1);

	printf("See you next time!!!!!!\n");
	Sleep(6000);
	return 0;
}