//j1902 ������l�@�t�x�݉ۑ�

/*-----------1��1�{�[���o�g���Q�[��-----------*/
/*�S��ʃ��[�h����*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define ENTER 13

int main(void) {
	int px = 5, py = 14;                //�v���C���[�̍��W
	int ex = 18, ey = 14;               //����̍��W
	int bx = 0,by = 0;                  //�{�[���̍��W
	int b_dir = 0;                      //�{�[���̈ړ�����
	int point_p = 0, point_e = 0;       //�|�C���g
	int MAP_X = 25, MAP_Y = 25;         //�}�b�v�̍L��
	int x, y;                           //��ʕ\��
	int op = 0, op_o = 0;               //�I�[�v�j���O�̑I��
	int com, man;                       //����񂯂�̎�
	int diff;                           //���s����
	int p;                              //�ړ�
	int surve = 1;                      //�T�[�u�p�̃t���O(1���T�[�u�ҋ@)
	int surve_right = 0;                //�T�[�u��(0�������A1��������)
	int sp_p = 0, sp_e = 0;             //�X�y�V�����J�E���g
	int i, j;                           //�X�y�V�����J�E���g�̕\��
	int jumping = 0;                    //�W�����v�p�̃t���O(1���W�����v��)
	int toss = 0;                       //�g�X�p�̃t���O(1���g�X��)
	int toss_time;                      //�g�X���ꂽ����
	int finish_time;                    //���ɂ����Ƃ�
	int play_none = 0;                  //�v���C�������Ă��邩(1���Â��Ă��Ȃ�)
	int time_count = 0;                 //���Ԃ̌v��
	int end = 0;                        //�G���f�B���O�̎�� 

	int hist_px[100000];                //px�̋O��
	int hist_py[100000];                //py�̋O��
	int hist_bx[100000];                //bx�̋O��
	int hist_by[100000];                //by�̋O��

	double v_p = 0, v_b = 0;             //����
	double px_d, py_d;                  //�v���C���[�̍��W(double�^)
	double by_d;                        //�{�[���̍��W(double�^)

    //�I�[�v�j���O
	do {
		while (1) {
			printf("-----------1��1�{�[���o�g���Q�[��-----------\n\n");

			//�I���̕\��
			op_o = 0;
			switch (op) {
			case 0:
				printf("  ��START    OPTION    RULES");
				break;
			case 1:
				printf("    START  ��OPTION    RULES");
				break;
			case 2:
				printf("    START    OPTION  ��RULES");
				break;
			}

			//�I���̔��f
			if (_kbhit()) {
				op_o = _getch();
				switch (op_o) {
				case 'a':
					op -= 1;
					break;
				case 'f':
					op += 1;
					break;
				}
			}

			if (op_o == ENTER) {
				system("cls");
				break;
			}
			//�l�̒���
			op = (op + 3) % 3;

			system("cls");
		}
		switch (op) {
		//�ݒ�
		case 1:
			while (1) {
				printf("=====�ݒ�=====\n");
				printf("�������_\n");
				printf("�X�y�V�����J�E���g(�ő�6)\n");
				printf("���v���C\n");
				printf("�n���f\n");
				system("cls");
				if (_kbhit()) {
					system("cls");
					break;
				}
			}
			break;
		//���[������
		case 2:
			while (1) {
				printf("=====���[��=====\n");
				printf("�@�������ɏ������_�ɓ��B���邱�Ƃ���������\n");
				printf("�A�X�p�C�N��ł��ƂŃX�y�V�����J�E���g�𑝂₹��\n");
				printf("�B�X�y�V�����J�E���g���ő吔���߂�ƃX�y�V�����X�p�C�N��ł��Ƃ��ł���\n");
				printf("�C�ړ���A�܂���4(��)��F�܂���6(�E)�A�W�����v�̓X�y�[�X�A�g�X��J�܂���5�A�X�p�C�N�ƃT�[�u�̓G���^�[\n");
				printf("�D�R�[�g����͂ݏo���ė�����ƈꔭ����\n");
				printf("Any key plese...(�G���^�[�ȊO)\n");
				system("cls");
				if (_kbhit()) {
					system("cls");
					break;
				}
			}
		}
	} while (op != 0);

	//�T�[�u����
	//�����̎�	
	printf("�T�[�o�[���߂���񂯂�!!!\n");
	printf("�o�����I��ł� (1 => �O�[�@2 => �`���L 3 =>�@�p�[)\n");
	do {
		scanf_s("%d", &man);
		man -= 1;
		if (man < 0 || man >= 3)
			printf("1��2��3����͂��Ă��������B\n");
	} while (man < 0 || man >= 3);

	//����̎�
	do {
		com = rand() % 3;
	} while (com == man);

	//���s����
	diff = (com - man + 3) % 3;

	system("cls");

	//���s�\��
	printf("���Ȃ�:");
	switch (man) {
	case 0:
		printf("�O�[\t");
		break;
	case 1:
		printf("�`���L\t");
		break;
	case 2:
		printf("�p�[\t");
		break;
	}

	printf("������:");
	switch (com) {
	case 0:
		printf("�O�[\t");
		break;
	case 1:
		printf("�`���L\t");
		break;
	case 2:
		printf("�p�[\t");
		break;
	}

	switch (diff) {
	case 1:
		printf("���Ȃ��̃T�[�u\n");
		surve_right = 0;
		break;
	case 2:
		printf("����̃T�[�u\n");
		surve_right = 1;
		break;
	}

	//�Q�[���J�n
	printf("Any key plese...(�G���^�[�ȊO)");
	while (1) {
		if (_kbhit()) {
			system("cls");
			break;
		}
	}

	do {
		//�T�[�u

		//�T�[�u���̃Z�b�g
		switch (surve_right % 2) {
		case 0:
			b_dir = 0;
			bx = px;
			by = py - 3;
			break;
		case 1:
			b_dir = 1;
			bx = ex;
			by = ey - 3;
			break;
		}

		//������(double�^��by)
		by_d = by;

		//�|�C���g�E�T�[�u���E�X�y�V�����J�E���g�̕\��
		printf("\n\n\n");
		printf("\t\t\t\t\t\t    ");
		switch (surve_right) {
		case 0:
			printf("���T�[�u\n");
			break;
		case 1: 
			printf("�@�@�@�@�@�@�@�@�@�@ �@          �@�T�[�u��\n");
			break;
		}
		printf("\t\t\t\t\t\t    ");
		printf("�T�[�u�ɂ��J�n\n");
		printf("\t\t\t\t\t\t    ");
		printf("���Ȃ��@�@�@�@�@�@�@�@�@�@ �@          �@������\n");
		printf("\t\t\t\t\t\t    ");
		printf("�X�y�V�����J�E���g\n");
		printf("\t\t\t\t\t\t    ");
		for (i = 0; i < 5; i++) {
			if (i < sp_p)
				printf("��");
			else
				printf("  ");
		}
		printf("�@�@�@�@�@            �@�@�@");
		for (j = 0; j < 5; j++) {
			if (j >= sp_e)
				printf("  ");
			else
				printf("��");
		}
		printf("\n");
		printf("\t\t\t\t\t\t    ");
		printf("%d                    :                       %d\n", point_p, point_e);

		//�R�[�g�̕\��
		for (y = 0; y <= MAP_Y; y++) {
			printf("\t\t\t\t\t\t    ");
			for (x = 0; x <= MAP_X; x++) {
				if (x == px && y == py - 2)
					printf("��");
				else if (x == px && y == py - 1)
					printf("��");
				else if (x == px && y == py)
					printf("��");
				else if (x == ex && y == ey - 2)
					printf("��");
				else if (x == ex && y == ey - 1)
					printf("��");
				else if (x == ex && y == ey)
					printf("��");
				else if (x == bx && y == by)
					printf("��");
				else if (x == 13 && y >= 7 && y < 15)
					printf("��");
				else if (x > 1 && x < 25 && y == 15)
					printf("��");
				else
					printf("  ");
			}
			printf("\n");
		}

		//�ł܂ő҂�
		if (surve == 1) {
			//�T�[�u��������
			if (!surve_right) {
				while (1) {
					if (_getch() == ENTER) {
						surve = 0;
						v_b = 3;
						break;
					}
				}
			}
			//�T�[�u��������
			else{
				Sleep(1500);
				v_b = 3;
			}
		}

		//����
		while (1) {
			/*�v���C���[�̈ړ�*/
			//���E�̈ړ��ƃW�����v
			if (_kbhit()) {
				p = _getch();
				printf("%d", p);

				switch (p) {
				case 'f':
				case '6':
					if (px <= 11)
						px++;
					break;
				case 'a':
				case '4':
					if (px >= 1)
						px--;
					break;
				case '5':
				case 'j':
					if (toss == 0) {
						toss = 1;
						toss_time = time_count;
					}
					break;
				case ' ':
					if (jumping == 0) {
						px_d = px, py_d = py;
						jumping = 1;
						v_p = 5;
					}
					break;
				}
			}

			//����
			if (jumping == 1) {
				py_d -= v_p;
				v_p -= 3;
				py = py_d;
				if (px > 1 && py >= 14) {
					jumping = 0;
					py = 14;
					v_p = 0;
				}
			}

			/*�R�[�g�͂ݏo��*/
			//�͂ݏo�����Ƃ�
			if (px < 2) {
				jumping = 1;
				py_d = py;
			}

			//��ԉ��ɍs�����畉��
			if (py >= 25) {
				end = 1;
				break;
			}

			/*�v���C���[�̈ړ������܂�*/

			/*�{�[���̈ړ�*/
			if (time_count % 2) {
				//��(x)����
				switch (b_dir) {
				case 0:
					bx++;
					break;
				case 1:
					bx--;
					break;
				}

				//�c(y)����(����)
				by_d -= v_b;
				v_b -= 0.5;
				by = by_d;
		        
				//���ɂ����Ƃ�
				if (by >= 14) {
					//���ђʂ��Ȃ��悤��
					by = 14;
					//���˕Ԃ�
					v_b *= -1;
					//���_�����Z
					if (b_dir == 0)
						point_p++;
					else
						point_e++;
					//���̃v���C��
					finish_time = time_count;
					play_none = 1;
					surve_right++;
					surve_right %= 2;
				}

			}

			//�g�X
			if (toss == 1)
				printf("%d%d  %d%d", px, bx, py, by);
			if (toss == 1 && (toss_time || toss_time + 1 || toss_time + 2) == time_count && bx == (px || px - 1 || px + 1) && by == (py - 4 || py - 5 || py - 6)){
				b_dir += 1;
				b_dir %= 2;
				v_b = 3;
			}

			//�v���C������(���ɂ��Ă���6�J�E���g��)
			if (play_none == 1) {
				surve = 1;
				if (time_count - finish_time == 6) {
					//���s����
					if (point_p == 5)
						end = 2;

					if (point_e == 5)
						end = 3;
					
					//���̃v���C��
					if(point_p != 5 && point_e != 5)
					  system("cls");

					play_none = 0;
					break;
				}
			}

			//��ʏ���
			system("cls");

			//�|�C���g�E�T�[�u���E�X�y�V�����J�E���g�̕\��
			printf("\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t    ");
			printf("���Ȃ��@�@�@�@�@�@�@�@     �@�@ �@     �@������\n");
			printf("\t\t\t\t\t\t    ");
			printf("�X�y�V�����J�E���g\n");
			printf("\t\t\t\t\t\t    ");
			for (i = 0; i < 5; i++) {
				if (i < sp_p)
					printf("��");
				else
					printf("  ");
			}
			printf("�@�@�@�@     �@      �@�@�@");
			for (j = 0; j < 5; j++) {
				if (j >= sp_e)
					printf("  ");
				else
					printf("��");
			}
			printf("\n");
			printf("\t\t\t\t\t\t    ");
			printf("%d                    :                       %d\n", point_p, point_e);

			//�R�[�g�̕\��
			for (y = 0; y <= MAP_Y; y++) {
				printf("\t\t\t\t\t\t    ");
				for (x = 0; x <= MAP_X; x++) {
					if (x == px && y == py - 2)
						printf("��");
					else if (x == px && y == py - 1)
						printf("��");
					else if (x == px && y == py)
						printf("��");
					else if (x == px && y == py -3 && toss == 1)
						printf("TT");
					else if (x == ex && y == ey - 2)
						printf("��");
					else if (x == ex && y == ey - 1)
						printf("��");
					else if (x == ex && y == ey)
						printf("��");
					else if (x == bx && y == by)
						printf("��");
					else if (x == 13 && y >= 7 && y < 15)
						printf("��");
					else if (x > 1 && x < 25 && y == 15)
						printf("��");
					else
						printf("  ");
				}
				printf("\n");
			}

			//���Ԃ𑝂₷
			time_count++;

			//��Ղ̑��
			hist_px[time_count] = px, hist_py[time_count] = py;
			hist_bx[time_count] = bx, hist_py[time_count] = by;

			//�g�X�̃t���O��������
			if (toss == 1){
				if(time_count - toss_time >= 4)
				    toss = 0;
			}
		}
		printf("\n\n\n");
		switch (end) {
		case 1:
			printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
			printf("\t\t\t\t\t\t                       YOU    LOSE   (FALLEN)\n");
			printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
			break;
		case 2:
			printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
			printf("\t\t\t\t\t\t                       YOU    WIN   (You got 5 point!)\n");
			printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
			break;
		case 3:
			printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
			printf("\t\t\t\t\t\t                       YOU    LOSE   (You lost 5 point...)\n");
			printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
			break;;
		}
	} while (point_p < 5 && point_e < 5 && end == 0);

	Sleep(10000);

    return 0;
}