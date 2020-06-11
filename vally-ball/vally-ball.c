
/*-----------1��1�{�[���o�g���Q�[��-----------*/
/*�S��ʃ��[�h����*/
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define ENTER 13

int ran(short int x, short int y);

int main(void) {
	short int px = 4, py = 14;                //�v���C���[�̍��W
	short int ex = 18, ey = 14;               //����̍��W
	short int bx = 0, by = 0;                 //�{�[���̍��W
	short int b_dir = 0;                      //�{�[���̈ړ�����
	short int point_p = 0, point_e = 0;       //�|�C���g
	short int MAP_X = 25, MAP_Y = 25;         //�}�b�v�̍L��
	short int key;                            //���͂��ꂽ�����L��
	short int win_num = 5;                    //�������_
	short int x, y;                           //��ʕ\��
	short int op = 0, op_o = 0, op_opt = 0;   //�I�[�v�j���O�̑I��
	short int com, man;                       //����񂯂�̎�
	short int diff;                           //���s����
	short int p;                              //�ړ�
	short int surve = 1;                      //�T�[�u�p�̃t���O(1���T�[�u�ҋ@)
	short int surve_right = 0;                //�T�[�u��(0�������A1��������)
	short int surve_right_p;                  //�T�[�u��(�\���p)
	short int sp_p = 0, sp_e = 0;             //�X�y�V�����J�E���g
	short int sp_do_p = 0, sp_do_e = 0;       //�X�y�V�������g�����ǂ���
	short int sp_max = 5;                     //�X�y�V�����J�E���g�̍ő�l
	short int sp_kind_p = 1, sp_kind_e = 1;   //�X�y�V�����X�p�C�N�̎��(0 => ���� -��- 1 => ���� -��- 3=> ���� -��-)
	short int sp_kind = 0;                    //�X�y�V�����X�p�C�N�̎��
	short int sp_2_sel = 0;                   //�����̑I��
	short int seller;                         //�����ō��W��I�Ԃق�(1������)
	short int kakuran_time;                   //������ł�����
	short int i, j;                           //for���p
	short int jumping_p = 0;                  //�W�����v�p�̃t���O(1���W�����v��)
	short int jumping_e = 0;                  //�W�����v�p�̃t���O(1���W�����v��)
	short int toss_p = 0, toss_p_print = 0;   //�����̃g�X�p�̃t���O(1���g�X��)
	short int toss_p_time;                    //�����̃g�X��������
	short int toss_e = 0, toss_e_print = 0;   //����̃g�X�p�̃t���O(1���g�X��)
	short int toss_e_time;                    //����̃g�X���ꂽ����
	short int spaik = 0;                      //�X�p�C�N�p�̃t���O(1���X�p�C�N��)
	short int spaik_time;                     //�X�p�C�N��ł�������
	short int spaik_e = 0, spaik_e_time;      //����̃X�p�C�N
	short int spaik_p_print = 0;              //�����̃X�p�C�N�̕\��
	short int spaik_e_print = 0;              //����̃X�p�C�N�̕\��
	short int s_g_e = 0;                      //���肪�X�p�C�N���ɍs��
	short int finish = 0;                     //�I�������(1���I��)
	short int finish_time;                    //���ɂ����Ƃ�
	short int jakka;                          //������キ����
	short int play_none = 0;                  //�v���C�������Ă��邩(1���Â��Ă��Ȃ�)
	short int time_count = 0;                 //���Ԃ̌v��
	short int end = 0;                        //�G���f�B���O�̎�� 
	short int con_fin = 0;                    //�����邩�I��邩(�I���ꍇ�̓X�^�[�g��ʂ�)
	short int rep = 1;                        //���v���C
	short int rep_start;                      //���v���C�̊J�n
	short int han_d = 0, han_n = 0;           //�n���f�̂��炤���Ɠ_��
	short int randamu;                        //������ۑ�����ϐ�
	short int s_d;                            //�T�[�u�̌��ߕ�
	short int s_r;                            //�T�[�u����(�����p)
	short int deuce = 0;                      //�f���[�X(0 =>�@����)
	short int de_pri = 0;                     //�f���[�X�̕\��
	short int de_adv = 0;                     //�f���[�X�ŃA�h�o���e�[�W�������(1 => �v���C��1�@2 => �v���C��2)
 	
	char name1[21] = "���Ȃ�";                //���O
	char name2[21] = "������";                //���O

	int hist_px[1000];                //px�̋O��
	int hist_py[1000];                //py�̋O��
	int hist_ex[1000];                //ex�̋O��
	int hist_ey[1000];                //ey�̋O��
	int hist_bx[1000];                //bx�̋O��
    int hist_by[1000];                //by�̋O��
	int hist_po_p[1000];              //�����̃|�C���g
	int hist_po_e[1000];              //����̃|�C���g
	int hist_toss_p[1000];            //�����̃g�X�̕\���̋L��
	int hist_toss_e[1000];            //����̃g�X�̕\��
	int hist_spaik_p[1000];           //�X�p�C�N�̕\��
	int hist_spaik_e[1000];           //�X�p�C�N�̕\��
	int hist_sp_p[1000];              //�X�y�V�����J�E���g�̋L��(����)
	int hist_sp_do_p[1000];           //�X�y�V�����̎g�p(����)
	int hist_sp_do_e[1000];           //�X�y�V�����̎g�p(����)
	int hist_sp_e[1000];              //�X�y�V�����J�E���g�̋L��(����)
	int hist_sp_kind[1000];           //�X�y�V�����Z�̎��
	int hist_de_pri[1000];            //�f���[�X�̕\��
	int hist_de_adv[1000];            //�f���[�X�̏��

	double v_p = 0, v_b = 0, v_e = 0;   //����
	double px_d, py_d;                  //�v���C���[�̍��W(double�^)
	double ex_d, ey_d;                  //����̍��W(double�^)
	double by_d;                        //�{�[���̍��W(double�^)

	//�����������
	do {
		//�I�[�v�j���O
		do {
			while (1) {
				end = 0;
				printf("-----------1��1�{�[���o�g���Q�[��(�S��ʐ���)-----------\n\n");

				//�I���̕\��
				op_o = 0;

				switch (op) {
				case 0:
					printf("  ��SINGLE    MULTI    OPTION    RULES      END");
					break;
				case 1:
					printf("    SINGLE  ��MULTI    OPTION    RULES      END");
					break;
				case 2:
					printf("    SINGLE    MULTI  ��OPTION    RULES      END");
					break;
				case 3:
					printf("    SINGLE    MULTI    OPTION  ��RULES      END");
					break;
				case 4:
					printf("    SINGLE    MULTI    OPTION    RULES    ��END");
					break;
				}

				//�I���̔��f
				if (_kbhit()) {
					op_o = _getch();
					switch (op_o) {
					case 'a':
						op -= 1;
						break;
					case 'd':
						op += 1;
						break;
					}
				}

				if (op_o == ENTER) {
					system("cls");
					break;
				}
				//�l�̒���
				op = (op + 5) % 5;

				system("cls");
			}

			switch (op) {
			//�ݒ�
			case 2:
				do {
					op_opt = 0;
					while (1) {
						if (_kbhit()) {
							op_o = _getch();
							switch (op_o) {
							case 'w':
								op_opt--;
								break;
							case 's':
								op_opt++;
								break;
							}

							if (op_o == ENTER)
								break;
						}
						op_opt = (op_opt + 7) % 7;

						switch (op_opt) {
						case 0:
							system("cls");
							printf("=====�ݒ�=====\n");
							printf("���v���C����\b\n");
							printf("  �������_\n");
							printf("  �X�y�V����\n");
							printf("  ���v���C\n");
							printf("  �n���f\n");
							printf("  �f���[�X\n");
							printf("  �߂�\n");
							break;
						case 1:
							system("cls");
							printf("=====�ݒ�=====\n");
							printf("  �v���C����\b\n");
							printf("���������_\n");
							printf("  �X�y�V����\n");
							printf("  ���v���C\n");
							printf("  �n���f\n");
							printf("  �f���[�X\n");
							printf("  �߂�\n");
							break;
						case 2:
							system("cls");
							printf("=====�ݒ�=====\n");
							printf("  �v���C����\b\n");
							printf("  �������_\n");
							printf("���X�y�V����\n");
							printf("  ���v���C\n");
							printf("  �n���f\n");
							printf("  �f���[�X\n");
							printf("  �߂�\n");
							break;
						case 3:
							system("cls");
							printf("=====�ݒ�=====\n");
							printf("  �v���C����\b\n");
							printf("  �������_\n");
							printf("  �X�y�V����\n");
							printf("�����v���C\n");
							printf("  �n���f\n");
							printf("  �f���[�X\n");
							printf("  �߂�\n");
							break;
						case 4:
							system("cls");
							printf("=====�ݒ�=====\n");
							printf("  �v���C����\b\n");
							printf("  �������_\n");
							printf("  �X�y�V����\n");
							printf("  ���v���C\n");
							printf("���n���f\n");
							printf("  �f���[�X\n");
							printf("  �߂�\n");
							break;
						case 5:
							system("cls");
							printf("=====�ݒ�=====\n");
							printf("  �v���C����\b\n");
							printf("  �������_\n");
							printf("  �X�y�V����\n");
							printf("  ���v���C\n");
							printf("  �n���f\n");
							printf("���f���[�X\n");
							printf("  �߂�\n");
							break;
						case 6:
							system("cls");
							printf("=====�ݒ�=====\n");
							printf("  �v���C����\b\n");
							printf("  �������_\n");
							printf("  �X�y�V����\n");
							printf("  ���v���C\n");
							printf("  �n���f\n");
							printf("  �f���[�X\n");
							printf("���߂�\n");
							break;
						}
					}

					system("cls");

					printf("=====�ݒ�=====\n");
					switch (op_opt) {
					case 0:
						printf("�v���C����(1)����͂��Ă��������B(10�����ȓ�)\n");
						scanf_s("%s", name1, 11);
						printf("�v���C����(2)����͂��Ă��������B(10�����ȓ�)\n");
						scanf_s("%s", name2, 11);
						break;
					case 1:
						printf("�������_����͂��Ă��������B(���R��)\n");
						do {
							scanf_s("%hd", &win_num);
							if (win_num < 1)
								printf("���R������͂��Ă��������B");
							if (win_num <= han_n)
								printf("�n���f�̓_��(%d)�����������Ă��������B", han_n);
						} while (win_num < 1 || win_num <= han_n);
						break;
					case 2:
						printf("�X�y�V�����J�E���g��MAX����͂��Ă��������B(�ő�6)\n");
						do {
							scanf_s("%hd", &sp_max);
							if (sp_max < 1 || sp_max > 6)
								printf("1�`6�̊Ԃ���͂��Ă��������B\n");
						} while (sp_max < 1 || sp_max > 6);
						printf("�X�y�V�����̎�ނ�I��ł��������B(1 => ���� -��- 2 => ����-��- 3 => ����-��-)\n");
						do {
							printf("�v���C��1>");
							scanf_s("%hd", &sp_kind_p);
							if (sp_kind_p != 1 && sp_kind_p != 2 && sp_kind_p != 3)
								printf("1��2��3����͂��Ă��������B\n");
						} while (sp_kind_p != 1 && sp_kind_p != 2 && sp_kind_p != 3);
						do {
							printf("�v���C��2>");
							scanf_s("%hd", &sp_kind_e);
							if (sp_kind_e != 1 && sp_kind_e != 2 && sp_kind_e != 3)
								printf("1��2��3����͂��Ă��������B\n");
						} while (sp_kind_e != 1 && sp_kind_e != 2 && sp_kind_e != 3);
						break;
					case 3:
						printf("���v���C���܂���?(1 => ����@�@2 => ���Ȃ�)\n");
						do {
							scanf_s("%hd", &rep);
							if (rep != 1 && rep != 2)
								printf("1��2����͂��Ă��������B\n");
						} while (rep != 1 && rep != 2);

						break;
					case 4:
						if (win_num != 1) {
							printf("�n���f�����炤�̂́H(1 => �v���C��1  2 => �v���C��2 3 = > �n���f�Ȃ�)\n");
							do {
								scanf_s("%hd", &han_d);
								if (han_d != 1 && han_d != 2 && han_d != 3)
									printf("1��2��3����͂��Ă��������B\n");
							} while (han_d != 1 && han_d != 2 && han_d != 3);
							if (han_d == 3) {
								han_n = 0;
								break;
							}
							printf("�n���f�̓_������͂��Ă��������B");
							do {
								scanf_s("%hd", &han_n);
								if (han_n < 1 || han_n >= win_num)
									printf("1���珟�����_(%d)�̊Ԃ���͂��Ă�������\n", win_num);
							} while (han_n < 1 || han_n >= win_num);
						}
						else {
							printf("�������_��1�_�̎��̓n���f�����邱�Ƃ��ł��܂���B\n");
							printf("Any key plese...");
							//���͑҂�
							while(1)
								if (_kbhit()) {
									key = _getch(); //�Ӑ}���Ȃ��ϐ��ɑ�������̂�h��
									break;
								}
						}
						break;
					case 5:
						printf("�f���[�X�͂ǂ�����H(1 =>�@���� 2 => �Ȃ�)\n");
						do {
							scanf_s("%hd", &deuce);
							if (deuce != 1 && deuce != 2)
								printf("1��2����͂��Ă��������B\n");
						} while (deuce != 1 && deuce != 2);
						deuce--;
						break;
					}
					system("cls");
				} while (op_opt != 6);
				break;

			//���[������
			case 3:
				while (1) {
					printf("=====���[��=====\n");
					printf("�@�������ɏ������_�ɓ��B���邱�Ƃ���������\n");
					printf("�A�X�p�C�N��ł��ƂŃX�y�V�����J�E���g�𑝂₹��\n");
					printf("�B�X�y�V�����J�E���g���ő吔���߂�ƃX�y�V�����X�p�C�N��ł��Ƃ��ł���\n");
					printf("�C�v���C��1�́A�E�ړ� -> a ���ړ� ->d �W�����v -> w �g�X�A�T�[�u -> s �X�p�C�N�@-> f\n");
					printf("�D�v���C��2�́A�E�ړ� -> k ���ړ� ->; �W�����v -> o �g�X�A�T�[�u -> l �X�p�C�N�@-> j\n");
					printf("�E�R�[�g����͂ݏo���ė�����ƈꔭ����\n");
					printf("�F�V���O�����[�h�ł͑ΐ푊��̓R���s���[�^\n");
					printf("�G�T�[�u���X�p�C�N���邱�Ƃ��\\n");
					printf("Any key plese...\n");

					//���͂��ꂽ�玟��
					while (1) {
						if (_kbhit()) {
							key = _getch;  //�Ӑ}���Ȃ��ϐ��ɑ�������̂�h��
							break;
						}
					}

					break;
				}
			case 4:
				system("cls");
				end = 4;
				break;
			}
		} while (op != 0 && op != 1 && op != 4);

		if (end == 4)
			break;

		do {
			//�T�[�u����
			printf("�T�[�u�͂ǂ����H(1 => %s���T�[�u 2 => %s���T�[�u 3 => %s)\n", name1, name2, (!op)?"����񂯂�Ō��߂�":"�����_���Ō��߂�");

			do {
				scanf_s("%hd", &s_d);
				
				if (s_d != 1 && s_d != 2 && s_d != 3)
					printf("1��2��3����͂��Ă��������B\n");
			} while (s_d != 1 && s_d != 2 && s_d != 3);

			//�����̎��ύX
			srand((unsigned int)time(NULL));

			//�T�[�u���̃Z�b�g
			switch (s_d) {
			case 1:
				surve_right = 0;
				system("cls");
				break;
			case 2:
				surve_right = 1;
				system("cls");
				break;
			case 3:
				if (!op) {
					//��ʏ���
					system("cls");

					//����񂯂�Ō��߂�
					printf("�T�[�o�[���߂���񂯂�!!!\n");

					//�����̎�
					printf("%s�o�����I��ł� (1 => �O�[�@2 => �`���L 3 =>�@�p�[)\n", (op == 0) ? "" : "�v���C��1");
					do {
						scanf_s("%hd", &man);
						man -= 1;
						if (man < 0 || man >= 3)
							printf("1��2��3����͂��Ă��������B\n");
					} while (man < 0 || man >= 3);

					//����̎�
					if (op == 0) {
						do {
							com = rand() % 3;
						} while (com == man);
					}
					else {
						printf("�v���C��2�̏o�����I��ł� (1 => �O�[ 2 => �`���L 3 => �p�[)\n");
						do {
							scanf_s("%hd", &com);
							com -= 1;
							if (com < 0 || com >= 3)
								printf("1��2��3����͂��Ă��������B\n");
						} while (com < 0 || com >= 3);

					}

					//���s����
					diff = (com - man + 3) % 3;

					//��ʏ���
					system("cls");

					//���s�\��
					printf("%s:", name1);
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

					printf("%s:", name2);
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
						printf("%s�̃T�[�u\n", name1);
						surve_right = 0;
						break;
					case 2:
						printf("%s�̃T�[�u\n", name2);
						surve_right = 1;
						break;
					}
				}
				else {
					//�����_���ŃT�[�u������
					srand((unsigned int)time(NULL));
					s_r = rand() % 2;
					if (!s_r)
						surve_right = 0;
					else
						surve_right = 1;

					//��ʏ���
					system("cls");

					//���ʕ\��
					printf("�T�[�u�����I�̌���:%s�̃T�[�u\n", (!surve_right) ? name1:name2);
				}

				//�Q�[���J�n
				printf("Any key plese...");
				while (1) {
					if (_kbhit()) {
						key = _getch(); //�Ӑ}���Ȃ��ϐ��ɑ�������̂�h��
						system("cls");
						break;
					}
				}
				break;
			}

			//�n���f�̓_����ǉ�
			if (han_d == 1)
				point_p = han_n;
			if (han_d == 2)
				point_p = han_n;

			de_pri = 0;
			de_adv = 0;

			do {
				//�f���[�X����
				if (point_p == win_num - 1 && point_e == win_num - 1 && deuce == 0)
					de_pri = 1;

				//�T�[�u

				//���W�����Z�b�g
				px = 5, py = 14;
				ex = 18, ey = 14;

				//�t���O��������
				finish = 0;
				toss_p = 0;
				toss_e = 0;
				spaik = 0;
				end = 0;

				//����߂�
				time_count = 0;

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

				//�\���p�̃T�[�u��
				surve_right_p = surve_right;

				//������(double�^��by)
				by_d = by;

				//�|�C���g�E�T�[�u���E�X�y�V�����J�E���g�̕\��
				printf("\n\n\n");
				printf("\t\t\t\t\t\t    ");
				printf("�T�[�u�ɂ��J�n\n");
				printf("\t\t\t\t\t\t    ");
				switch (surve_right_p) {
				case 0:
					printf("���T�[�u\n");
					break;
				case 1:
					printf("      �@    �@�@�@�@�@�@�@�@�@ �@          �@�T�[�u��\n");
					break;
				}
				printf("\t\t\t\t\t\t    ");
				printf("%s�@      �@�@�@�@�@�@ �@                �@%s\n", name1, name2);
				printf("\t\t\t\t\t\t    ");
				printf("�X�y�V�����J�E���g\n");
				printf("\t\t\t\t\t\t    ");
				if (sp_max == sp_p) {
					if (sp_do_p == 0)
						printf("!!!MAX!!! ");
					else
						printf("!!!!GO!!!!");
				}
				else {
					for (i = 0; i < 5; i++) {
						if (i < sp_p)
							printf("��");
						else
							printf("  ");
					}
				}

				printf("�@�@�@�@�@             �@�@�@    ");
				if (sp_max == sp_e) {
					if (sp_do_e == 0)
						printf("!!!MAX!!! ");
					else
						printf("!!!!GO!!!!");
				}
				else {
					for (j = 0; j < 5; j++) {
						if (j >= sp_e)
							printf("  ");
						else
							printf("��");
					}
				}

				printf("\n");
				printf("\t\t\t\t\t\t    ");
				if (de_pri)
					switch (de_adv) {
					case 0:
						printf("                      �f���[�X\n");
						break;
					case 1:
						printf("Adv.                      :                        %hd\n", point_e);
						break;
					case 2:
						printf("%hd                         :                        Adv.\n", point_p);
						break;
					}
				else
				    printf("%hd                         :                        %hd\n", point_p, point_e);

				printf("\n");

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

				//���W��\��
				printf("\t\t\t\t\t\t         ");
				printf("(px,py) = (%d, %d)          (ex, ey) = (%d, %d)", px, py, ex, ey);

				//�ł܂ő҂�
				if (surve == 1) {
					//�T�[�u��������
					if (!surve_right) {
						while (1) {
							if (_getch() == 's') {
								surve = 0;
								v_b = 3;
								break;
							}
						}
					}
					else
					{
						if (!op) {
							Sleep(1500);
							v_b = 3;
						}
						else {
							if (_getch() == 'l') {
								v_b = 3;
							}
						}
					}
				}

				//����
				while (1) {
					//�f���[�X����
					if (point_p == win_num - 1 && point_e == win_num - 1 && deuce == 0)
						de_pri = 1;

					/*�v���C���[�̈ړ�*/
					//���E�̈ړ��ƃW�����v
					if (sp_2_sel != 1) {
						if (_kbhit()) {
							p = _getch();

							switch (p) {
							case 'd':
								if (px <= 11 && px > 1)
									px++;
								break;
							case 'a':
								if (px >= 1)
									px--;
								break;
							case 's':
								if (toss_p == 0 && b_dir == 1) {
									toss_p = 1;
									toss_p_print = 1;
									toss_p_time = time_count;
								}
								break;
							case 'f':
								if (spaik == 0 && b_dir == 1) {
									spaik = 1;
									spaik_p_print = 1;
									spaik_time = time_count;
								}
								break;
							case 'w':
								if (jumping_p == 0) {
									px_d = px, py_d = py;
									jumping_p = 1;
									v_p = 8;
								}
								break;
							case 'q':
								if (sp_p == sp_max) {
									sp_do_p++;
									sp_do_p %= 2;
								}
								break;
							//��l�v���C�p�̈ړ�
							case 'k':
								if (op == 1)
									if (ex >= 15)
										ex--;
								break;
							case ';':
								if (op == 1)
									if (ex <= 24)
										ex++;
								break;
							case 'l':
								if (op == 1)
									if (toss_e == 0 && b_dir == 0) {
										toss_e = 1;
										toss_e_print = 1;
										toss_e_time = time_count;
									}
								break;
							case 'j':
								if (op == 1)
									if (spaik_e == 0 && b_dir == 0) {
										spaik_e = 1;
										spaik_e_print = 1;
										spaik_e_time = time_count;
									}
								break;
							case 'o':
								if (op == 1)
									if (jumping_e == 0) {
										ex_d = ex, ey_d = ey;
										jumping_e = 1;
										v_e = 8;
									}
								break;
							case 'p':
								if (op == 1)
									if (sp_e == sp_max) {
										sp_do_e++;
										sp_do_e %= 2;
									}
								break;
							}
						}

						//����
						if (jumping_p == 1) {
							py_d -= v_p;
							v_p -= 4;
							py = py_d;
							if (px > 1 && py >= 14) {
								jumping_p = 0;
								py = 14;
								v_p = 0;
							}
						}

						/*�R�[�g�͂ݏo��*/
						//�͂ݏo�����Ƃ�
						if (px < 2) {
							jumping_p = 1;
							py_d = py;
						}

						//��ԉ��ɍs�����畉��
						if (py >= 25) {
							end = 1;
							if(rep == 1)
								system("cls");
							break;
						}


						/*�v���C���[�̈ړ������܂�*/

						/*����̈ړ�*/
						if (!op) { //��l�v���C�̂Ƃ��̂�
							if (time_count % 2) {
								if (s_g_e == 1) {
									//�X�p�C�N���ɍs��
									if (ex != 14)
										ex--;
									if (ex == 14 && bx >= 13 && jumping_e == 0) {
										jumping_e = 1;
										v_e = 8;
										ex_d = ex, ey_d = ey;
									}
								}
								else {
									//�{�[����ǂ�������
									if (bx > 13) {
										if (ex > bx && ex > 14)
											ex--;
										if (ex < bx && ex < 25)
											ex++;
									}
									else {
										if (ex > 18)
											ex--;
										if (ex < 18)
											ex++;
									}
								}

							}
							//�X�p�C�N(����)
							if (jumping_e == 1 && (bx > ex - 1 && bx < ex + 1) && by < ey + 3 && by > ey - 5 && b_dir == 0)
								spaik_e = 1, spaik_e_time = time_count, s_g_e = 0, spaik_e_print = 1;

							//�g�X(����)
							srand((unsigned int)time(NULL));
							jakka = rand() % 6;

							if ((bx > ex - 1 && bx < ex + 1) && by < ey + 3 && by > ey - 5 && b_dir == 0 && jakka != 0 && spaik_e != 1)
								toss_e = 1, toss_e_time = time_count, toss_e_print = 1;
						}

						//����
						if (jumping_e == 1) {
							ey_d -= v_e;
							v_e -= 4;
							ey = ey_d;
							if (ex < 24 && ey >= 14) {
								jumping_e = 0;
								ey = 14;
								v_e = 0;
							}
						}

						/*�R�[�g�͂ݏo��*/
						//�͂ݏo�����Ƃ�
						if (ex > 24) {
							jumping_e = 1;
							ey_d = ey;
						}

						//��ԉ��ɍs�����畉��
						if (ey >= 25) {
							end = 4;
							if(rep == 1)
								system("cls");
							break;
						}

					}
					/*����̈ړ������܂�*/

					/*�{�[���̈ړ�*/
					if (sp_2_sel == 1) {
						if (seller == 1) {
							if (_kbhit()) {
								key = _getch();
								switch (key) {
								case 'a':
									if (bx >= 14)
										bx--;
									break;
								case 'd':
									if (bx <= 25)
										bx++;
									break;
								}

								if (key == 's') {
									v_b = -4;
									sp_2_sel = 0;
								}
							}
						}
						else {
							if (px >= 7) {
								if (bx > 2)
									bx--;
								if (bx == 2) {
									v_b = -4;
									sp_2_sel = 0;
								}
							}
							else {
								if (px <= 6)
									if (bx < 12)
										bx++;
								if (bx == 12) {
									v_b = -4;
									sp_2_sel = 0;
								}
							}
						}
					}

					if (time_count % 2 == 0 && sp_2_sel != 1) {
						//��(x)����

						//�����̎�
						if (sp_kind == 3) {
							if (b_dir == 0) {
								if ((time_count - kakuran_time) % 4 == 0)
									bx -= ran(1, 6);
								else
									bx += ran(1, 6);

								if (bx < 14)
									bx = 14;
								if (bx > 24)
									bx = 24;
							}
							else {
								if ((time_count - kakuran_time) % 4 == 0)
									bx -= ran(1, 6);
								else
									bx += ran(1, 6);

								if (bx < 1)
									bx = 1;
								if (bx > 12)
									bx = 12;
							}
						}
						

						//�����ȊO�̎�
						if (sp_kind != 3 && sp_kind != 2) {
							switch (b_dir) {
							case 0:
								bx++;
								if (sp_kind == 1)
									bx++;
								break;
							case 1:
								if (sp_kind == 1)
									bx--;
								bx--;
								break;
							}
						}

						//�c(y)����(����)
						by_d -= v_b;
						v_b -= 0.5;
						by = by_d;

						//�l�b�g�ɓ���������
						if ((bx == 14 && (by - v_b) >= 7 && b_dir == 1) || (bx == 12 && ((by - v_b) >= 7 && b_dir == 0)))
							b_dir = (b_dir + 1) % 2;

						//���ɂ����Ƃ�
						if (by >= 14) {
							//���ђʂ��Ȃ��悤��
							by = 14;

							//���˕Ԃ�
							v_b *= -1;

							//���_�����Z
							if ((bx >= 14 && bx < 25) || bx < 1)
								if(de_pri)
									switch (de_adv) {
									case 0:
										de_adv = 1;
										break;
									case 1:
										de_pri = 0;
										point_p++;
										break;
									case 2:
										de_adv = 0;
										break;
									}
								else
								    point_p++;
							else
								if(de_pri)
									switch (de_adv) {
									case 0:
										de_adv = 2;
										break;
									case 1:
										de_adv = 0;
										break;
									case 2:
										de_pri = 0;
										point_e++;
										break;
									}
								else
							    	point_e++;

							//���̃v���C��
							finish_time = time_count;
							finish = 1;
							play_none = 1;
							surve_right++;
							surve_right %= 2;
							sp_kind = 0;
						}
					}

					//�g�X
					if ((((toss_p == 1 && (bx > px - 1 && bx < px + 1) && (by < py + 3 && by > py - 5)) || (toss_e == 1 && (bx > ex - 1 && bx < ex + 1) && (by < ey + 3 && by > ey - 5)))) && finish == 0) {
						b_dir += 1;
						b_dir %= 2;
						v_b = 3;
						srand((unsigned int)time(NULL));
						randamu = rand() % 2;
						if (toss_p == 1 && randamu == 0) {
							s_g_e = 1;
							if (sp_max == sp_e)
								sp_do_e = 1;
						}
						toss_p = 0;
						toss_e = 0;
						sp_kind = 0;
					}

					//�X�p�C�N
					if ((spaik == 1 && jumping_p == 1 && (bx > px - 1 && bx < px + 1) && (by < py + 3 && by > py - 5)) || (spaik_e == 1 && (bx > ex - 1 && bx < ex + 1) && (by < ey + 3 && by > ey - 5))) {
						//�����̕Ԋ�
						b_dir += 1;
						b_dir %= 2;

						//���x�̕ύX
						v_b = 0;

						//�X�y�V�����J�E���g����
						if (sp_max > sp_p && spaik == 1)
							sp_p++;

						if (sp_max > sp_e && spaik_e == 1)
							sp_e++;

						//���x�̕ύX�ƃX�y�V�����̎g�p
						if (sp_do_p != 0 && spaik == 1) {
							sp_p = 0;
							sp_do_p = 0;
							switch (sp_kind_p) {
							case 1:
								v_b = -3;
								sp_kind = 1;
								break;
							case 2:
								bx = 14;
								sp_2_sel = 1;
								seller = 1;
								sp_kind = 2;
								break;
							case 3:
								v_b = 0;
								bx = 14;
								kakuran_time = time_count;
								if (kakuran_time % 2 == 1)
									kakuran_time--;
								sp_kind = 3;
								break;
							}
						}
						else if(sp_do_e == 1 && spaik_e == 1){
							sp_e = 0;
							sp_do_e = 0;
							switch (sp_kind_e) {
							case 1:
								v_b = -3;
								sp_kind = 1;
								break;
							case 2:
								bx = 12;
								sp_2_sel = 1;
								seller = 2;
								sp_kind = 2;
								break;
							case 3:
								v_b = 0;
								bx = 12;
								kakuran_time = time_count;
								if (kakuran_time % 2 == 1)
									kakuran_time--;
								sp_kind = 3;
								break;
							}
						}
						else {
							v_b = 0;
						}

						sp_do_p = 0;
						spaik = 0;
						spaik_e = 0;
					}

					//�v���C������(���ɂ��Ă���6�J�E���g��)

					if (play_none == 1) {
						surve = 1;
						if (time_count - finish_time == 6) {
							//���s����
							if (point_p == win_num)
								end = 2;

							if (point_e == win_num)
								end = 3;

							//���̃v���C��
							if ((point_p != win_num && point_e != win_num) || rep == 1)
								system("cls");

							play_none = 0;
							toss_p_print = 0, toss_e_print = 0;
							break;
						}
					}

					//��ʏ���
					system("cls");

					//�|�C���g�E�T�[�u���E�X�y�V�����J�E���g�̕\��
					printf("\n\n\n\n\n\n\n");
					printf("\t\t\t\t\t\t    ");
					switch (surve_right_p) {
					case 0:
						printf("��\n");
						break;
					case 1:
						printf("                                                   ��\n");
						break;
					}
					printf("\t\t\t\t\t\t    ");
					printf("%s�@�@        �@�@     �@�@ �@           �@%s\n", name1, name2);
					printf("\t\t\t\t\t\t    ");
					printf("�X�y�V�����J�E���g\n");
					printf("\t\t\t\t\t\t    ");
					if (sp_max == sp_p) {
						if (sp_do_p == 0)
							printf("!!!MAX!!! ");
						else
							printf("!!!!GO!!!!");
					}
					else {
						for (i = 0; i < 5; i++) {
							if (i < sp_p)
								printf("��");
							else
								printf("  ");
						}
					}
					printf("�@�@�@�@     �@      �@�@�@      ");
					if (sp_max == sp_e) {
						if (sp_do_e == 0)
							printf("!!!MAX!!! ");
						else
							printf("!!!!GO!!!!");
					}
					else {
						for (j = 0; j < 5; j++) {
							if (j >= sp_e)
								printf("  ");
							else
								printf("��");
						}
					}

					printf("\n");
					printf("\t\t\t\t\t\t    ");
					if (de_pri)
						switch (de_adv) {
						case 0:
							printf("                      �f���[�X\n");
							break;
						case 1:
							printf("Adv.                      :                        %hd\n", point_e);
							break;
						case 2:
							printf("%hd                         :                        Adv.\n", point_p);
							break;
						}
					else
					    printf("%hd                         :                        %hd\n", point_p, point_e);

					//�X�y�V�����X�p�C�N�̕\��
					switch (sp_kind) {
					case 0:
						printf("\n");
						break;
					case 1:
						printf("\t\t\t\t\t\t                          ���� -��-\n");
						break;
					case 2:
						printf("\t\t\t\t\t\t                          ���� -��-\n");
						break;
					case 3:
						printf("\t\t\t\t\t\t                          ���� -��-\n");
						break;
					}

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
							else if (x == bx && y == by)
								printf("��");
							else if (x == px && y == py - 3 && toss_p_print == 1)
								printf("TT");
							else if (x == ex && y == ey - 3 && toss_e_print == 1)
								printf("TT");
							else if (x == px && y == py - 3 && spaik_p_print == 1)
								printf("�u");
							else if (x == ex && y == ey - 3 && spaik_e_print == 1)
								printf("] ");
							else if (x == ex && y == ey - 2)
								printf("��");
							else if (x == ex && y == ey - 1)
								printf("��");
							else if (x == ex && y == ey)
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

					//���W��\��
					printf("\t\t\t\t\t\t         ");
					printf("(px,py) = (%d, %d)          (ex, ey) = (%d, %d)", px, py, ex, ey);

					//�O�Ղ̑��
					hist_px[time_count] = px, hist_py[time_count] = py;
					hist_ex[time_count] = ex, hist_ey[time_count] = ey;
					hist_bx[time_count] = bx, hist_by[time_count] = by;
					hist_po_p[time_count] = point_p, hist_po_e[time_count] = point_e;
					hist_toss_p[time_count] = toss_p_print, hist_toss_e[time_count] = toss_e_print;
					hist_sp_p[time_count] = sp_p, hist_sp_e[time_count] = sp_e;
					hist_sp_do_p[time_count] = sp_do_p;
					hist_sp_do_e[time_count] = sp_do_e;
					hist_sp_kind[time_count] = sp_kind;
					hist_spaik_p[time_count] = spaik_p_print;
					hist_spaik_e[time_count] = spaik_e_print;
					hist_de_pri[time_count] = de_pri;
					hist_de_adv[time_count] = de_adv;

					//���Ԃ𑝂₷
					time_count++;

					//�g�X�̃t���O��������
					if (toss_p_print == 1) {
						if (time_count - toss_p_time >= 4) {
							toss_p = 0;
							toss_p_print = 0;
						}
					}
					if (toss_e_print == 1) {
						if (time_count - toss_e_time >= 4) {
							toss_e = 0;
							toss_e_print = 0;
						}
					}

					//�X�p�C�N�̃t���O��������
					if (spaik == 1) {
						if (time_count - spaik_time >= 4)
							spaik = 0;
					}

					if (spaik_p_print == 1) {
						if (time_count - spaik_time >= 4) {
							spaik = 0;
							spaik_p_print = 0;
						}
					}
					if (spaik_e_print == 1) {
						if (time_count - spaik_e_time >= 4) {
							spaik_e = 0;
							spaik_e_print = 0;
						}
					}

				}

				//���v���C
				if (rep == 1) {
					if (time_count - 50 <= 0)
						rep_start = 0;
					else
						rep_start = time_count - 50;
					for (j = rep_start; j < time_count; j++) {

						//�\���J�n
						printf("\t\t\t\t\t\t    ");

						printf("=======================���v���C=======================\n");
						//�|�C���g�E�T�[�u���E�X�y�V�����J�E���g�̕\��
						printf("\n\n\n\n\n\n");
						printf("\t\t\t\t\t\t    ");
						switch (surve_right_p) {
						case 0:
							printf("��\n");
							break;
						case 1:
							printf("                                                   ��\n");
							break;
						}
						printf("\t\t\t\t\t\t    ");
						printf("%s�@�@        �@�@     �@�@ �@           �@%s\n", name1, name2);
						printf("\t\t\t\t\t\t    ");
						printf("�X�y�V�����J�E���g\n");
						printf("\t\t\t\t\t\t    ");
						if (sp_max == hist_sp_p[j]) {
							if (hist_sp_do_p[j] == 0)
								printf("!!!MAX!!! ");
							else
								printf("!!!!GO!!!!");
						}
						else {
							for (i = 0; i < 5; i++) {
								if (i < hist_sp_p[j])
									printf("��");
								else
									printf("  ");
							}
						}
						printf("�@�@�@�@     �@      �@�@�@      ");
						if (sp_max == hist_sp_e[j]) {
							if (hist_sp_do_e[j] == 0)
								printf("!!!MAX!!! ");
							else
								printf("!!!!GO!!!!");
						}
						else {
							for (i = 0; i < 5; i++) {
								if (i >= hist_sp_e[j])
									printf("  ");
								else
									printf("��");
							}
						}
						printf("\n");
						printf("\t\t\t\t\t\t    ");
						if (hist_de_pri[j])
							switch (hist_de_adv[j]) {
							case 0:
								printf("                      �f���[�X                      \n");
								break;
							case 1:
								printf("Adv.                      :                        %hd\n", hist_po_e[j]);
								break;
							case 2:
								printf("%hd                         :                        Adv.\n", hist_po_p[j]);
								break;
							}
						else
						    printf("%hd                         :                        %hd\n", hist_po_p[j], hist_po_e[j]);

						//�X�y�V�����X�p�C�N�̕\��
						switch (hist_sp_kind[j]) {
						case 0:
							printf("\n");
							break;
						case 1:
							printf("\t\t\t\t\t\t                          ���� -��-\n");
							break;
						case 2:
							printf("\t\t\t\t\t\t                          ���� -��-\n");
							break;
						case 3:
							printf("\t\t\t\t\t\t                          ���� -��-\n");
							break;
						}

						for (y = 0; y <= MAP_Y; y++) {
							printf("\t\t\t\t\t\t    ");
							for (x = 0; x <= MAP_X; x++) {
								if (x == hist_px[j] && y == hist_py[j] - 2)
									printf("��");
								else if (x == hist_px[j] && y == hist_py[j] - 1)
									printf("��");
								else if (x == hist_px[j] && y == hist_py[j])
									printf("��");
								else if (x == hist_bx[j] && y == hist_by[j])
									printf("��");
								else if (x == hist_px[j] && y == hist_py[j] - 3 && hist_toss_p[j] == 1)
									printf("TT");
								else if (x == hist_ex[j] && y == hist_ey[j] - 3 && hist_toss_e[j] == 1)
									printf("TT");
								else if (x == hist_px[j] && y == hist_py[j] - 3 && hist_spaik_p[j] == 1)
									printf("�u");
								else if (x == hist_ex[j] && y == hist_ey[j] - 3 && hist_spaik_e[j] == 1)
									printf("] ");
								else if (x == hist_ex[j] && y == hist_ey[j] - 2)
									printf("��");
								else if (x == hist_ex[j] && y == hist_ey[j] - 1)
									printf("��");
								else if (x == hist_ex[j] && y == hist_ey[j])
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

						//���W��\��
						printf("\t\t\t\t\t\t         ");
						printf("(px,py) = (%d, %d)          (ex, ey) = (%d, %d)", px, py, ex, ey);

						//��ʏ���
						system("cls");
					}
				}

				//�Ō�̕`��
				if (rep == 1 && end != 0) {
					//�|�C���g�E�T�[�u���E�X�y�V�����J�E���g�̕\��
					printf("\n\n\n\n\n\n\n");
					printf("\t\t\t\t\t\t    ");
					switch (surve_right_p) {
					case 0:
						printf("��\n");
						break;
					case 1:
						printf("                                                   ��\n");
						break;
					}
					printf("\t\t\t\t\t\t    ");
					printf("%s�@�@        �@�@     �@�@ �@           �@%s\n", name1, name2);
					printf("\t\t\t\t\t\t    ");
					printf("�X�y�V�����J�E���g\n");
					printf("\t\t\t\t\t\t    ");
					if (sp_max == sp_p) {
						if (sp_do_p == 0)
							printf("!!!MAX!!! ");
						else
							printf("!!!!GO!!!!");
					}
					else {
						for (i = 0; i < 5; i++) {
							if (i < sp_p)
								printf("��");
							else
								printf("  ");
						}
					}
					printf("�@�@�@�@     �@      �@�@�@      ");
					if (sp_max == sp_e) {
						if (sp_do_e == 0)
							printf("!!!MAX!!! ");
						else
							printf("!!!!GO!!!!");
					}
					else {
						for (i = 0; i < 5; i++) {
							if (i >= sp_e)
								printf("  ");
							else
								printf("��");
						}
					}
					printf("\n");
					printf("\t\t\t\t\t\t    ");
					printf("%hd                         :                        %hd\n", point_p, point_e);

					//�X�y�V�����X�p�C�N�̕\��
					switch (sp_kind) {
					case 0:
						printf("\n");
						break;
					case 1:
						printf("\t\t\t\t\t\t                          ���� -��-\n");
						break;
					case 2:
						printf("\t\t\t\t\t\t                          ���� -��-\n");
						break;
					case 3:
						printf("\t\t\t\t\t\t                          ���� -��-\n");
						break;
					}

					for (y = 0; y <= MAP_Y; y++) {
						printf("\t\t\t\t\t\t    ");
						for (x = 0; x <= MAP_X; x++) {
							if (x == px && y == py - 2)
								printf("��");
							else if (x == px && y == py - 1)
								printf("��");
							else if (x == px && y == py)
								printf("��");
							else if (x == bx && y == by)
								printf("��");
							else if (x == px && y == py - 3 && toss_p == 1)
								printf("TT");
							else if (x == ex && y == ey - 3 && toss_e == 1)
								printf("TT");
							else if (x == px && y == py - 3 && spaik == 1)
								printf("�u");
							else if (x == ex && y == ey - 2)
								printf("��");
							else if (x == ex && y == ey - 1)
								printf("��");
							else if (x == ex && y == ey)
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

					//���W��\��
					printf("\t\t\t\t\t\t         ");
					printf("(px,py) = (%d, %d)          (ex, ey) = (%d, %d)", px, py, ex, ey);
				}
				printf("\n\n\n");
				switch (end) {
				case 1:
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					printf("\t\t\t\t\t\t                       %s    LOSE   (FALLEN)\n", name1);
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					break;
				case 2:
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					printf("\t\t\t\t\t\t                       %s    WIN   (You got  point!)\n", name1);
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					break;
				case 3:
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					printf("\t\t\t\t\t\t                       %s    WIN   (You got  point!)\n", name2);
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					break;
				case 4:
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					printf("\t\t\t\t\t\t                       %s    LOSE   (FALLEN)\n", name2);
					printf("\t\t\t\t\t\t    *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
					break;
				}
			} while (point_p < win_num && point_e < win_num && end == 0);

			Sleep(5000);

			system("cls");

			//������ or �I��
			while (1) {
				if (_kbhit()) {
					key = _getch();

					switch (key) {
					case 'a':
						con_fin--;
						break;
					case 'd':
						con_fin++;
						break;
					}

					if (key == ENTER)
						break;
				}
				con_fin = (con_fin + 2) % 2;

				switch (con_fin) {
				case 0:
					printf("��New Game            finish");
					break;
				case 1:
					printf("  New Game          ��finish");
					break;
				}
				system("cls");
			}

			point_p = 0, point_e = 0;
			sp_p = 0, sp_e = 0;
			toss_p_print = 0;
			toss_e_print = 0;
			end = 0;
			sp_do_p = 0;
		} while (con_fin == 0);
	}while (con_fin == 1);

	printf("See You Next Time!!!!");
	Sleep(10000);

	return 0;
}

int ran(short int x, short int y) {
	short int diff, num;

	//�������߂�
	diff = abs(x - y);

    //�����ɂ��l������
	srand((unsigned int)time(NULL));
	num = rand() % diff;

	//�Ԃ������l�ɓK�؂ɂȂ�悤��
	if (x > y)
		num += y;
	else
		num += x;

	return num;
}