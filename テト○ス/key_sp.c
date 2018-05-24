#include <GL/glut.h>
#include "declaration.h"

//特殊キー関数
void MoveTo(int key, int x, int y) {

	if (gameflag == 1) {
		switch (key) {
		case GLUT_KEY_LEFT:
			if (appear == 0) {
				Changeblock(mino, 0);
				switch (mino.type) {
				case 1:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y][mino.x - 2] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0 && WorldMap[mino.y + 2][mino.x - 1] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y][mino.x - 3] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 2][mino.x - 1] <= 0 && WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							mino.x--;
							move = 1;
						}
						break;
					}
					break;

				case 2:
					if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0) {
						mino.x--;
						move = 1;
					}
					break;

				case 3:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 2] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y][mino.x - 2] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 2] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							mino.x--;
							move = 1;
						}
						break;
					}
					break;

				case 4:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x - 2] <= 0 && WorldMap[mino.y][mino.x - 2] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y][mino.x - 2] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x - 2] <= 0) {
							mino.x--;
							move = 1;
						}
						break;
					}
					break;

				case 5:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y][mino.x - 2] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y][mino.x - 2] <= 0 && WorldMap[mino.y + 1][mino.x - 2] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x - 2] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							mino.x--;
							move = 1;
						}
						break;
					}
					break;

				case 6:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x - 2] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y][mino.x - 2] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 2] <= 0 && WorldMap[mino.y + 1][mino.x - 2] <= 0) {
							mino.x--;
							move = 1;
						}
						break;
					}
					break;

				case 7:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 2] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x - 1] <= 0 && WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y][mino.x - 1] <= 0 && WorldMap[mino.y + 1][mino.x - 2] <= 0) {
							mino.x--;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x - 2] <= 0 && WorldMap[mino.y][mino.x - 2] <= 0 && WorldMap[mino.y + 1][mino.x - 1] <= 0) {
							mino.x--;
							move = 1;
						}
						break;
					}
					break;
				}
			}
			break;

		case GLUT_KEY_RIGHT:
			if (appear == 0) {
				Changeblock(mino, 0);
				switch (mino.type) {
				case 1:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y][mino.x + 3] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0 && WorldMap[mino.y + 2][mino.x + 1] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y][mino.x + 2] <= 0) {
							mino.x++;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 2][mino.x + 1] <= 0 && WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							mino.x++;
							move = 1;
						}
						break;
					}
					break;

				case 2:
					if (WorldMap[mino.y - 1][mino.x + 2] <= 0 && WorldMap[mino.y][mino.x + 2] <= 0) {
						mino.x++;
						move = 1;
					}
					break;

				case 3:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 2] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 2] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y][mino.x + 2] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							mino.x++;
							move = 1;
						}
						break;
					}
					break;

				case 4:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y][mino.x + 2] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x + 2] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y][mino.x + 2] <= 0 && WorldMap[mino.y + 1][mino.x + 2] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							mino.x++;
							move = 1;
						}
						break;
					}
					break;

				case 5:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x + 2] <= 0 && WorldMap[mino.y][mino.x + 2] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 2] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y][mino.x + 2] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							mino.x++;
							move = 1;
						}
						break;
					}
					break;

				case 6:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 2] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x + 2] <= 0 && WorldMap[mino.y][mino.x + 2] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 2] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x] <= 0) {
							mino.x++;
							move = 1;
						}
						break;
					}
					break;

				case 7:
					switch (mino.dir) {
					case 0:
						if (WorldMap[mino.y - 1][mino.x + 2] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 1:
						if (WorldMap[mino.y - 1][mino.x + 1] <= 0 && WorldMap[mino.y][mino.x + 2] <= 0 && WorldMap[mino.y + 1][mino.x + 2] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 2:
						if (WorldMap[mino.y][mino.x + 2] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							mino.x++;
							move = 1;
						}
						break;

					case 3:
						if (WorldMap[mino.y - 1][mino.x] <= 0 && WorldMap[mino.y][mino.x + 1] <= 0 && WorldMap[mino.y + 1][mino.x + 1] <= 0) {
							mino.x++;
							move = 1;
						}
						break;
					}
					break;
				}
			}
			break;

		case GLUT_KEY_UP:
			if (appear == 0 && keypush_sp == 0) {
				keypush_sp = 1;
				count = func_time;

				Changeblock(mino, 0);
				appear = 1;
				mino = mino_shadow;
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
			break;

		case GLUT_KEY_DOWN:
			if (appear == 0) {
				Changeblock(mino, 0);
				move = 0;

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
			}
			break;
		}

		ChangeShadow();
		Changeblock(mino, mino.type);
	}
	else if (gameflag == 0) {
		switch (key) {
		case GLUT_KEY_UP:
			choices = 0;
			break;

		case GLUT_KEY_DOWN:
			choices = 1;
			break;
		}
	}

	switch (key) {
	case GLUT_KEY_END:
		exit(0);
		break;
	}

	glutPostRedisplay();
}

void KeyUp_sp(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		keypush_sp = 0;
		break;
	}
}

