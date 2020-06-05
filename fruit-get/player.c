#define SIZE 15

int player_move(int cx, int key) {
	//キー入力による移動
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

	//ワープ
	cx = (cx + SIZE) % SIZE;

	return cx;
}