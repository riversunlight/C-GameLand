/*�V���[�e�B���O�Q�[��*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include"calc.h"
#include"oprate.h"
#define SIZE 15

int main() {
	int cx = 14, cy = 14;
	int ex = 0, ey = 0;
	int myLife = 3;
	int enemyLife = 10;
	int win_flag = 0;
	int cnt = 0;
	int flag = 0;
	int next = 0;

	while(1) {
		/*�n�܂�O�̏���*/
		srand((unsigned int)time(NULL));
		next = 0;
		win_flag = 0;
		myLife = 3;
		enemyLife = 10;
		cx = 14, cy = 14;
		ex = 0; ey = 0;
		init_0();

		/*�I�[�v�j���O*/
		flag = opening();
		if (flag == 1)
			break;

		/*���C�����[�v*/
		while (1) {
			//���@�̈ړ�
			if (_kbhit()) {
				int key = _getch();
				if (key == 'a' || key == 'd')
					cx = move(cx, key, SIZE);
				else if (key == ' ')
					bullet_gene(0, cx);
			}

			//�G�@�̈ړ�
			ex = enemy_move(ex, SIZE);
			if (cnt % 3 == 0)
				bullet_gene(1, ex);

			//�e�̈ړ�
			bullet_move();

			//���C�t�_�E��
			myLife = isHit(0, myLife, cx);
			enemyLife = isHit(1, enemyLife, ex);

			//��ʍX�V
			update(cx, cy, ex, ey, myLife, enemyLife, SIZE);

			//���S����
			if (myLife == 0) {
				win_flag = 2;
				break;
			}
			else if (enemyLife == 0) {
				win_flag = 1;
				break;
			}

			//�^�[���J�E���g����
			cnt++;
		}

		ending(win_flag);
		Sleep(5000);

		next = new_game();
		if (next == 1)
			break;
	}

	system("cls");
	printf("See You Next Time!!\n");

	return 0;
}