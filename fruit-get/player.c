#define SIZE 15

int player_move(int cx, int key) {
	//�L�[���͂ɂ��ړ�
	switch (key) {
	case 'a':
	case '4':
		cx--;
		break;
	case 'd':
	case '6':
		cx++;
		break;
	}

	//���[�v
	cx = (cx + SIZE) % SIZE;

	return cx;
}