#include <GL/glut.h>
#include "declaration.h"

//ブロックを出現,落下,消去する関数
void Drop(void) {
	int i, j, k, rnd;

	if (gameflag == 1) {
		if (appear == 1) {//出現or消去
			del_line = 0;
			for (i = WORLDY - 2;i > 3;i--) {
				j = 1;
				while ((j < WORLDX - 1) && (WorldMap[i][j] > 0)) {//ブロックがあれば端にずらしていく
					j++;
				}
				if (j == WORLDX - 1) {//端まで探索されていたら消す
					del_line++;
					del_line_sum++;
					appear = -1;
					mino.type = 0;
					count = func_time - 100;
					for (j = 1;j < WORLDX - 1;j++) {
						WorldMap[i][j] = 0;
					}
				}
			}
			score += del_line*del_line;

			if (del_line == 0) {//消していないなら
				mino.type = nextmino[0];
				for (i = 0;i < 6;++i) {
					nextmino[i] = nextmino[i + 1];
				}
				while (minoflag[(rnd = rand() % 7 + 1)] == 1);
				nextmino[6] = rnd;
				mino.x = (WORLDX / 2) - 1;
				mino.y = 3;
				mino.dir = 0;
				mino_shadow = mino;
				appear = 0;//出現中(0)にする
				stockflag = 0;//ストック可能にする
				minoflag[rnd] = 1;
				minoflag[0]++;//一度出現した種類の数をカウント
				if (minoflag[0] == 7) {//7種類すべて一度ずつ出したらリセットする
					for (i = 0;i < 8;++i) {
						minoflag[i] = 0;
					}
				}

				switch (mino.type) {
				case 1:
					if (WorldMap[mino.y][mino.x - 1] != 0 || WorldMap[mino.y][mino.x] != 0 || WorldMap[mino.y][mino.x + 1] != 0 || WorldMap[mino.y][mino.x + 2] != 0) {
						gameflag = 0;
					}
					break;

				case 2:
					if (WorldMap[mino.y - 1][mino.x] != 0 || WorldMap[mino.y - 1][mino.x + 1] != 0 || WorldMap[mino.y][mino.x] != 0 || WorldMap[mino.y][mino.x + 1] != 0) {
						gameflag = 0;
					}
					break;

				case 3:
					if (WorldMap[mino.y - 1][mino.x] != 0 || WorldMap[mino.y][mino.x - 1] != 0 || WorldMap[mino.y][mino.x] != 0 || WorldMap[mino.y][mino.x + 1] != 0) {
						gameflag = 0;
					}
					break;

				case 4:
					if (WorldMap[mino.y - 1][mino.x - 1] != 0 || WorldMap[mino.y][mino.x - 1] != 0 || WorldMap[mino.y][mino.x] != 0 || WorldMap[mino.y][mino.x + 1] != 0) {
						gameflag = 0;
					}
					break;

				case 5:
					if (WorldMap[mino.y - 1][mino.x + 1] != 0 || WorldMap[mino.y][mino.x - 1] != 0 || WorldMap[mino.y][mino.x] != 0 || WorldMap[mino.y][mino.x + 1] != 0) {
						gameflag = 0;
					}
					break;

				case 6:
					if (WorldMap[mino.y - 1][mino.x - 1] != 0 || WorldMap[mino.y - 1][mino.x] != 0 || WorldMap[mino.y][mino.x] != 0 || WorldMap[mino.y][mino.x + 1] != 0) {
						gameflag = 0;
					}
					break;

				case 7:
					if (WorldMap[mino.y - 1][mino.x] != 0 || WorldMap[mino.y - 1][mino.x + 1] != 0 || WorldMap[mino.y][mino.x - 1] != 0 || WorldMap[mino.y][mino.x] != 0) {
						gameflag = 0;
					}
					break;
				}
			}

		}
		else if (appear == -1) {//消去後なら空いたところを詰める
			for (i = WORLDY - 2;i > 0;i--) {
				j = 1;
				while (j < WORLDX - 1 && WorldMap[i][j] <= 0) {//ブロックがないか端まで見ていく
					j++;
				}
				if (j == WORLDX - 1) {//i行目にブロックがなかったら
					k = i;
					do {
						k--;
						j = 1;
						while (j < WORLDX - 1 && WorldMap[k][j] <= 0) {
							j++;
						}
					} while (j == WORLDX - 1 && k >= 0);

					if (k >= 0) {
						for (j = 1;j < WORLDX - 1;j++) {
							WorldMap[i][j] = WorldMap[k][j];
							WorldMap[k][j] = 0;
						}
					}
				}
			}
			appear = 1;
			count = func_time - 100;


		}
		else if (appear == 0) {//出現中(0)だったら落とす
			Changeblock(mino, 0);

			switch (mino.type) {
			case 1:
				switch (mino.dir) {
				case 0:
					if (WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 2] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0 || WorldMap[mino.y + 1][mino.x + 2] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 1:
					if (WorldMap[mino.y + 3][mino.x] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 3][mino.x] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 2:
					if (WorldMap[mino.y + 1][mino.x - 2] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x - 2] > 0 || WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 3:
					if (WorldMap[mino.y + 2][mino.x] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
					}
					break;
				}
				break;

			case 2:
				if (WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
					mino.y++;
					move = 1;
					if (WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
						count = func_time - 500;
					}
				}
				break;

			case 3:
				switch (mino.dir) {
				case 0:
					if (WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 1:
					if (WorldMap[mino.y + 1][mino.x + 1] <= 0 && WorldMap[mino.y + 2][mino.x] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x + 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 2:
					if (WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 2][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 3:
					if (WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 2][mino.x] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
					}
					break;
				}
				break;

			case 4:
				switch (mino.dir) {
				case 0:
					if (WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 1:
					if (WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 2][mino.x] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y][mino.x + 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 2:
					if (WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0 && WorldMap[mino.y + 2][mino.x + 1] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0 || WorldMap[mino.y + 2][mino.x + 1] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 3:
					if (WorldMap[mino.y + 2][mino.x - 1] <= 0 && WorldMap[mino.y + 2][mino.x] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 2][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
					}
					break;
				}
				break;

			case 5:
				switch (mino.dir) {
				case 0:
					if (WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 1:
					if (WorldMap[mino.y + 2][mino.x] <= 0 && WorldMap[mino.y + 2][mino.x + 1] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 2][mino.x] > 0 || WorldMap[mino.y + 2][mino.x + 1] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 2:
					if (WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0 && WorldMap[mino.y + 2][mino.x - 1] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0 || WorldMap[mino.y + 2][mino.x - 1] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 3:
					if (WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 2][mino.x] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
					}
					break;
				}
				break;

			case 6:
				switch (mino.dir) {
				case 0:
					if (WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 1:
					if (WorldMap[mino.y + 1][mino.x + 1] <= 0 && WorldMap[mino.y + 2][mino.x] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x + 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 2:
					if (WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 2][mino.x] <= 0 && WorldMap[mino.y + 2][mino.x + 1] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0 || WorldMap[mino.y + 2][mino.x + 1] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 3:
					if (WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 2][mino.x - 1] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 2][mino.x - 1] > 0) {
							count = func_time - 500;
						}
					}
					break;
				}
				break;

			case 7:
				switch (mino.dir) {
				case 0:
					if (WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y][mino.x + 1] > 0 || WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 1:
					if (WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 2][mino.x + 1] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 2][mino.x + 1] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 2:
					if (WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 2][mino.x - 1] <= 0 && WorldMap[mino.y + 2][mino.x] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 2][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
					}
					break;

				case 3:
					if (WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 2][mino.x] <= 0) {
						mino.y++;
						move = 1;
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
					}
					break;
				}
				break;
			}

			/*if (move == 1) {//動いた後で下にブロックがあったら一時的に時間を変更
				switch (mino.type) {
				case 1:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0 || WorldMap[mino.y + 1][mino.x + 2] > 0) {
							count = func_time - 500;
						}
						break;

					case 1:
						if (WorldMap[mino.y + 3][mino.x] > 0) {
							count = func_time - 500;
						}
						break;

					case 2:
						if (WorldMap[mino.y + 1][mino.x - 2] > 0 || WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
							count = func_time - 500;
						}
						break;

					case 3:
						if (WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
						break;
					}
					break;

				case 2:
					if (WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
						count = func_time - 500;
					}
					break;

				case 3:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
							count = func_time - 500;
						}
						break;

					case 1:
						if (WorldMap[mino.y + 1][mino.x + 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
						break;

					case 2:
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
							count = func_time - 500;
						}
						break;

					case 3:
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
						break;
					}
					break;

				case 4:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
							count = func_time - 500;
						}
						break;

					case 1:
						if (WorldMap[mino.y][mino.x + 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
						break;

					case 2:
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0 || WorldMap[mino.y + 2][mino.x + 1] > 0) {
							count = func_time - 500;
						}
						break;

					case 3:
						if (WorldMap[mino.y + 2][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
						break;
					}
					break;

				case 5:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
							count = func_time - 500;
						}
						break;

					case 1:
						if (WorldMap[mino.y + 2][mino.x] > 0 || WorldMap[mino.y + 2][mino.x + 1] > 0) {
							count = func_time - 500;
						}
						break;

					case 2:
						if (WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0 || WorldMap[mino.y + 2][mino.x - 1] > 0) {
							count = func_time - 500;
						}
						break;

					case 3:
						if (WorldMap[mino.y][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
						break;
					}
					break;

				case 6:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 1][mino.x + 1] > 0) {
							count = func_time - 500;
						}
						break;

					case 1:
						if (WorldMap[mino.y + 1][mino.x + 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
						break;

					case 2:
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0 || WorldMap[mino.y + 2][mino.x + 1] > 0) {
							count = func_time - 500;
						}
						break;

					case 3:
						if (WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 2][mino.x - 1] > 0) {
							count = func_time - 500;
						}
						break;
					}
					break;

				case 7:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y][mino.x + 1] > 0 || WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 1][mino.x] > 0) {
							count = func_time - 500;
						}
						break;

					case 1:
						if (WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 2][mino.x + 1] > 0) {
							count = func_time - 500;
						}
						break;

					case 2:
						if (WorldMap[mino.y + 1][mino.x] > 0 || WorldMap[mino.y + 2][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
						break;

					case 3:
						if (WorldMap[mino.y + 1][mino.x - 1] > 0 || WorldMap[mino.y + 2][mino.x] > 0) {
							count = func_time - 500;
						}
						break;
					}
					break;
				}
			}
			else */if (move == 0) {//動きがなかったら固定
				appear = 1;
				switch (mino.type) {
				case 1:
					switch (mino.dir) {
					case 0:
						if (mino.y <= 3) {
							gameflag = 0;
						}
						break;

					case 1:
						if (mino.y + 2 <= 3) {
							gameflag = 0;
						}
						break;

					case 2:
						if (mino.y <= 3) {
							gameflag = 0;
						}
						break;

					case 3:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;
					}
					break;

				case 2:
					if (mino.y <= 3) {
						gameflag = 0;
					}
					break;

				case 3:
					switch (mino.dir) {
					case 0:
						if (mino.y <= 3) {
							gameflag = 0;
						}
						break;

					case 1:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;

					case 2:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;

					case 3:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;
					}
					break;

				case 4:
					switch (mino.dir) {
					case 0:
						if (mino.y <= 3) {
							gameflag = 0;
						}
						break;

					case 1:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;

					case 2:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;

					case 3:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;
					}
					break;

				case 5:
					switch (mino.dir) {
					case 0:
						if (mino.y <= 3) {
							gameflag = 0;
						}
						break;

					case 1:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;

					case 2:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;

					case 3:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;
					}
					break;

				case 6:
					switch (mino.dir) {
					case 0:
						if (mino.y <= 3) {
							gameflag = 0;
						}
						break;

					case 1:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;

					case 2:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;

					case 3:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;
					}
					break;

				case 7:
					switch (mino.dir) {
					case 0:
						if (mino.y <= 3) {
							gameflag = 0;
						}
						break;

					case 1:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;

					case 2:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;

					case 3:
						if (mino.y + 1 <= 3) {
							gameflag = 0;
						}
						break;
					}
					break;
				}

			}
			move = 0;

		}

		ChangeShadow();
		Changeblock(mino, mino.type);
	}

	glutPostRedisplay();
}

