#include <GL/glut.h>
#include "declaration.h"

//一般キー関数
void Keyboard(unsigned char key, int x, int y) {
	int i, tmp;

	if (gameflag == 1) {
		switch (key) {
			//右回転
		case 'f':
		case 'F':
			if (appear == 0 && keypush == 0) {
				keypush = 1;
				switch (mino.type) {
				case 1:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0 && WorldMap[mino.y + 2][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.x++;
							mino.dir = 1;
							move = 1;
						}
						
						break;

					case 1:
						if (WorldMap[mino.y + 1][mino.x - 2] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.y++;
							mino.dir = 2;
							move = 1;
						}
						
						break;

					case   2:
						if (WorldMap[mino.y - 2][mino.x - 1] <= 0 && WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							Changeblock(mino, 0);
							mino.x--;
							mino.dir = 3;
							move = 1;
						}
						
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y - 1][mino.x + 2] <= 0) {
							Changeblock(mino, 0);
							mino.y--;
							mino.dir = 0;
							move = 1;
						}
						
						break;
					}
					break;

				case 2:
					move = 1;
					break;

				case 3:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y + 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 1;
							move = 1;
						}
						
						break;

					case 1:
						if (WorldMap[mino.y][mino.x - 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 2;
							move = 1;
						}
						
						break;

					case 2:
						if (WorldMap[mino.y - 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 3;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 0;
							move = 1;
						}
						
						break;
					}
					break;

				case 4:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 1;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 2;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 3;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 0;
							move = 1;
						}
						break;
					}
					break;

				case 5:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 1;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 2;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 3;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y - 1][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 0;
							move = 1;
						}
						break;
					}
					break;

				case 6:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 1;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 2;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 3;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 0;
							move = 1;
						}
						break;
					}
					break;

				case 7:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 1;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 2;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 3;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y - 1][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 0;
							move = 1;
						}
						break;
					}
					break;
				}
			}
			break;

			//左回転
		case 'd':
		case 'D':
			if (appear == 0 && keypush == 0) {
				keypush = 1;
				switch (mino.type) {
				case 1:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 2][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.y++;
							mino.dir = 3;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y][mino.x - 2] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.x--;
							mino.dir = 0;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y - 2][mino.x] <= 0 && WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.y--;
							mino.dir = 1;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 2] <= 0) {
							Changeblock(mino, 0);
							mino.x++;
							mino.dir = 2;
							move = 1;
						}
						break;
					}
					break;

				case 2:
					break;

				case 3:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y + 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 3;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y][mino.x - 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 0;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y - 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 1;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 2;
							move = 1;
						}
						break;
					}
					break;

				case 4:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 3;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 0;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 1;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 2;
							move = 1;
						}
						break;
					}
					break;

				case 5:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 3;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 0;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 1;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 2;
							move = 1;
						}
						break;
					}
					break;

				case 6:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 3;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y - 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 0;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 1;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y + 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 2;
							move = 1;
						}
						break;
					}
					break;

				case 7:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 3;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 0;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 1;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							Changeblock(mino, 0);
							mino.dir = 2;
							move = 1;
						}
						break;
					}
					break;
				}
			}
			break;


		case ' ':
			if (stockflag == 0 && appear == 0) {//ストック未使用かつ出現中
				Changeblock(mino, 0);
				if (stock == 0) {//ストック無し(初期状態)
					stock = mino.type;
					mino.type = nextmino[0];
					for (i = 0;i < 6;++i) {
						nextmino[i] = nextmino[i + 1];
					}
					while (minoflag[tmp = rand() % 7 + 1] == 1);
					nextmino[6] = tmp;
					minoflag[tmp] = 1;
					minoflag[0]++;//一度出現した種類をカウント
					if (minoflag[0] == 7) {//7種類すべて一度ずつ出したら0にする
						for (i = 0;i < 8;++i) {
							minoflag[i] = 0;
						}
					}
				}
				else {//すでにストックあり
					tmp = stock;
					stock = mino.type;
					mino.type = tmp;
				}
				//位置決め
				mino.dir = 0;
				mino.x = (WORLDX / 2) - 1;
				mino.y = 3;
				Changeblock(mino, mino.type);
				stockflag = 1;
			}
			break;
		}

		ChangeShadow();
		Changeblock(mino, mino.type);
	}
	else if (gameflag == 0) {
		switch (key) {
		case 0x000d://エンターキー
			if (choices == 0) {//上の選択肢(YES)の時
				Init();
				glutTimerFunc(1, Timer1, 0);
			}
			else if (choices == 1) {//下の選択肢(NO)の時
				exit(0);
			}
			break;
		}
	}

	switch (key) {
	case 'p':
	case 'P':
		if (keypush == 0) {
			keypush = 1;
			if (gameflag == 1) {
				gameflag = -1;
			}
			else if (gameflag == -1) {
				gameflag = 1;
				glutTimerFunc(1, Timer1, 0);
			}
		}
		break;
	}

	glutPostRedisplay();

}

void KeyUp(unsigned char key, int x, int y) {
	switch (key) {
	case 'f':
	case 'F':
	case 'd':
	case 'D':
	case 'p':
	case 'P':
		keypush = 0;
		break;
	}
}

