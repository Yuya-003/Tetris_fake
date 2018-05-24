#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "declaration.h"

char str1[10];
char str2[10];
char str3[10];
char WorldMap[WORLDY][WORLDX];
int minoflag[8];
int nextmino[7];
int keypush = 0;
int keypush_sp = 0;
int appear;
int gameflag;
int level;
int del_line;
int del_line_sum;
int score;
int stock;
int stockflag;
int move;
int count;
int func_time;
int choices;
block mino;
block mino_shadow;
bitmap bmp_pause;
bitmap bmp_over;
bitmap bmp_red;
bitmap bmp_green;
bitmap bmp_blue;
bitmap bmp_lightblue;
bitmap bmp_yellow;
bitmap bmp_violet;
bitmap bmp_orange;
bitmap bmp_wall;

int main(int argc, char *argv[]) {	

	//画像の読み込み
	Load_bmp(&bmp_pause, "./picture/pause.bmp");//ポーズ
	Load_bmp(&bmp_over, "./picture/gameover.bmp");//ゲームオーバー
	Load_bmp(&bmp_red, "./picture/red_mino.bmp");//赤ブロック
	Load_bmp(&bmp_green, "./picture/green_mino.bmp");//緑ブロック
	Load_bmp(&bmp_blue, "./picture/blue_mino.bmp");//青ブロック
	Load_bmp(&bmp_lightblue, "./picture/lightblue_mino.bmp");//水色ブロック
	Load_bmp(&bmp_yellow, "./picture/yellow_mino.bmp");//黄色ブロック
	Load_bmp(&bmp_violet, "./picture/violet_mino.bmp");//紫ブロック
	Load_bmp(&bmp_orange, "./picture/orange_mino.bmp");//オレンジブロック
	Load_bmp(&bmp_wall, "./picture/wall.bmp");//壁ブロック

	srand((unsigned)time(NULL));
	Init();

	glutInit(&argc, argv);
	glutInitWindowPosition(200, 5);
	glutInitWindowSize(WINDOWX, WINDOWY);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("Hogehoge");
	glutSpecialFunc(MoveTo);
	glutKeyboardFunc(Keyboard);
	glutKeyboardUpFunc(KeyUp);
	glutSpecialUpFunc(KeyUp_sp);
	glutDisplayFunc(Display);

	glutTimerFunc(1, Timer1, 0);

	glutMainLoop();

	return 0;
}

//各種初期化関数
void Init(void) {
	int i, j, rnd;

	appear = 1;
	gameflag = 1;
	level = 1;
	del_line_sum = 0;
	score = 0;
	stock = 0;
	stockflag = 0;
	count = 0;
	func_time = 760;
	mino.type = 0;
	mino.dir = 0;
	mino.x = 0;
	mino.y = 0;
	move = 1;
	choices = 0;
	mino_shadow = mino;
	InitMap(WorldMap);
	for(i = 0;i < 8;++i){
		minoflag[i] = 0;
	}
	
	for (i = 0;i < 7;++i) {
		while (minoflag[rnd = rand() % 7 + 1] == 1);
		nextmino[i] = rnd;
		minoflag[rnd] = 1;
		minoflag[0]++;//一度出現した種類をカウント
		if (minoflag[0] == 7) {//7種類すべて一度ずつ出したら0にする
			for (j = 0;j < 8;++j) {
				minoflag[j] = 0;
			}
		}
	}
}

//マップ初期化関数
void InitMap(char world[WORLDY][WORLDX]) {
	int i, j;
	for (i = 0;i < WORLDY;i++) {
		for (j = 0;j < WORLDX;j++) {
			if (j == 0 || j == WORLDX - 1 || i == WORLDY - 1) {//壁
				world[i][j] = 11;
			}
			else {
				world[i][j] = 0;
			}
		}
	}
}

//ウィンドウ描画関数
void Display(void) {
	int i, j;
	int x[4], y[4];
	glClear(GL_COLOR_BUFFER_BIT);

	if (gameflag == 1) {
		for (i = 0;i < WY;++i) {//iがy座標,jがx座標
			for (j = 0;j < WX;++j) {
				switch (WorldMap[i + 4][j]) {
				case -1:
					glColor3ub(100, 50, 50);//影

					//ブロックの表示
					glBegin(GL_QUADS);
					glVertex2d(Pos_x(150 + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE*i));
					glVertex2d(Pos_x(150 + BLOCK_SIZE + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE*i));
					glVertex2d(Pos_x(150 + BLOCK_SIZE + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE + BLOCK_SIZE*i));
					glVertex2d(Pos_x(150 + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE + BLOCK_SIZE*i));
					glEnd();
					////枠の表示
					//glColor3ub(100, 100, 100);
					//glBegin(GL_LINE_LOOP);
					//glVertex2d(Pos_x(150 + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE*i));
					//glVertex2d(Pos_x(150 + BLOCK_SIZE + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE*i));
					//glVertex2d(Pos_x(150 + BLOCK_SIZE + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE + BLOCK_SIZE*i));
					//glVertex2d(Pos_x(150 + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE + BLOCK_SIZE*i));
					//glEnd();
					break;
				case 0:
					glColor3ub(0, 0, 40);//暗い青

					 //ブロックの表示
					glBegin(GL_QUADS);
					glVertex2d(Pos_x(150 + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE*i));
					glVertex2d(Pos_x(150 + BLOCK_SIZE + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE*i));
					glVertex2d(Pos_x(150 + BLOCK_SIZE + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE + BLOCK_SIZE*i));
					glVertex2d(Pos_x(150 + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE + BLOCK_SIZE*i));
					glEnd();
					////枠の表示
					//glColor3ub(100, 100, 100);
					//glBegin(GL_LINE_LOOP);
					//glVertex2d(Pos_x(150 + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE*i));
					//glVertex2d(Pos_x(150 + BLOCK_SIZE + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE*i));
					//glVertex2d(Pos_x(150 + BLOCK_SIZE + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE + BLOCK_SIZE*i));
					//glVertex2d(Pos_x(150 + BLOCK_SIZE*j), Pos_y(25 + BLOCK_SIZE + BLOCK_SIZE*i));
					//glEnd();
					break;
				case 11:
					Print_bmp(bmp_wall, 150 + BLOCK_SIZE*j, 25 + BLOCK_SIZE*i);
					//glColor3ub(153, 153, 153);//灰色
					break;
				case 1:
					Print_bmp(bmp_lightblue, 150 + BLOCK_SIZE*j, 25 + BLOCK_SIZE*i);
					//glColor3ub(0, 255, 255);//水色
					break;
				case 2:
					Print_bmp(bmp_yellow, 150 + BLOCK_SIZE*j, 25 + BLOCK_SIZE*i);
					//glColor3ub(255, 255, 50);//黄色っぽい
					break;
				case 3:
					Print_bmp(bmp_violet, 150 + BLOCK_SIZE*j, 25 + BLOCK_SIZE*i);
					//glColor3ub(180, 75, 255);//紫色っぽい
					break;
				case 4:
					Print_bmp(bmp_blue, 150 + BLOCK_SIZE*j, 25 + BLOCK_SIZE*i);
					//glColor3ub(0, 0, 255);//青
					break;
				case 5:
					Print_bmp(bmp_orange, 150 + BLOCK_SIZE*j, 25 + BLOCK_SIZE*i);
					//glColor3ub(255, 128, 0);//オレンジっぽい
					break;
				case 6:
					Print_bmp(bmp_red, 150 + BLOCK_SIZE*j, 25 + BLOCK_SIZE*i);
					//glColor3ub(255, 0, 0);//赤
					break;
				case 7:
					Print_bmp(bmp_green, 150 + BLOCK_SIZE*j, 25 + BLOCK_SIZE*i);
					//glColor3ub(0, 255, 0);//緑
					break;
				}


			}
		}

		//待機中ブロックの描画
		glColor3ub(200, 200, 255);
		DrawString("NEXT", GLUT_BITMAP_TIMES_ROMAN_24, (float)Pos_x(WINDOWX-103), (float)Pos_y(40));
		glColor3ub(0, 65, 80);
		glBegin(GL_QUADS);//上の枠内を塗りつぶす
		glVertex2d(Pos_x(WINDOWX - 120), Pos_y(50));
		glVertex2d(Pos_x(WINDOWX - 20), Pos_y(50));
		glVertex2d(Pos_x(WINDOWX - 20), Pos_y(150));
		glVertex2d(Pos_x(WINDOWX - 120), Pos_y(150));
		glEnd();
		glColor3ub(0, 30, 35);
		glBegin(GL_QUADS);//下の枠内を塗りつぶす
		glVertex2d(Pos_x(WINDOWX - 100), Pos_y(150));
		glVertex2d(Pos_x(WINDOWX - 20), Pos_y(150));
		glVertex2d(Pos_x(WINDOWX - 20), Pos_y(150 + 80 * 6));
		glVertex2d(Pos_x(WINDOWX - 100), Pos_y(150 + 80 * 6));
		glEnd();
		glColor3ub(100, 100, 100);
		glLineWidth(2.0);
		glBegin(GL_LINE_LOOP);//上の枠を描画
		glVertex2d(Pos_x(WINDOWX - 120), Pos_y(50));
		glVertex2d(Pos_x(WINDOWX - 20), Pos_y(50));
		glVertex2d(Pos_x(WINDOWX - 20), Pos_y(150));
		glVertex2d(Pos_x(WINDOWX - 120), Pos_y(150));
		glEnd();
		glLineWidth(1.0);
		glBegin(GL_LINE_LOOP);//下の枠を描画
		glVertex2d(Pos_x(WINDOWX - 100), Pos_y(150));
		glVertex2d(Pos_x(WINDOWX - 20), Pos_y(150));
		glVertex2d(Pos_x(WINDOWX - 20), Pos_y(150 + 80 * 6));
		glVertex2d(Pos_x(WINDOWX - 100), Pos_y(150 + 80 * 6));
		glEnd();
		glBegin(GL_LINES);
		for (i = 1;i <= 5;++i) {
			glVertex2d(Pos_x(WINDOWX - 100), Pos_y(150 + 80 * i));
			glVertex2d(Pos_x(WINDOWX - 20), Pos_y(150 + 80 * i));
		}
		glEnd();
		for (i = 0;i < 7;++i) {
			switch (nextmino[i]) {
			case 1:
				x[0] = -4, y[0] = -1;
				x[1] = -2, y[1] = -1;
				x[2] = 0, y[2] = -1;
				x[3] = 2, y[3] = -1;
				glColor3ub(0, 255, 255);//水色
				break;

			case 2:
				x[0] = -2, y[0] = -2;
				x[1] = 0, y[1] = -2;
				x[2] = -2, y[2] = 0;
				x[3] = 0, y[3] = 0;
				glColor3ub(255, 255, 50);//黄色っぽい
				break;

			case 3:
				x[0] = -1, y[0] = -2;
				x[1] = -3, y[1] = 0;
				x[2] = -1, y[2] = 0;
				x[3] = 1, y[3] = 0;
				glColor3ub(180, 75, 255);//紫色っぽい
				break;

			case 4:
				x[0] = -3, y[0] = -2;
				x[1] = -3, y[1] = 0;
				x[2] = -1, y[2] = 0;
				x[3] = 1, y[3] = 0;
				glColor3ub(0, 0, 255);//青
				break;

			case 5:
				x[0] = 1, y[0] = -2;
				x[1] = -3, y[1] = 0;
				x[2] = -1, y[2] = 0;
				x[3] = 1, y[3] = 0;
				glColor3ub(255, 128, 0);//オレンジっぽい
				break;

			case 6:
				x[0] = -3, y[0] = -2;
				x[1] = -1, y[1] = -2;
				x[2] = -1, y[2] = 0;
				x[3] = 1, y[3] = 0;
				glColor3ub(255, 0, 0);//赤
				break;

			case 7:
				x[0] = -1, y[0] = -2;
				x[1] = 1, y[1] = -2;
				x[2] = -3, y[2] = 0;
				x[3] = -1, y[3] = 0;
				glColor3ub(0, 255, 0);//緑
				break;
			}
			if (i == 0) {//一番上の四角の時
				for (j = 0;j < 4;++j) {
					//ブロックの描画
					glBegin(GL_QUADS);
					glVertex2d(Pos_x(WINDOWX - 70 + 10 * x[j]), Pos_y(100 + 10 * y[j]));
					glVertex2d(Pos_x(WINDOWX - 70 + 10 * x[j] + 20), Pos_y(100 + 10 * y[j]));
					glVertex2d(Pos_x(WINDOWX - 70 + 10 * x[j] + 20), Pos_y(100 + 10 * y[j] + 20));
					glVertex2d(Pos_x(WINDOWX - 70 + 10 * x[j]), Pos_y(100 + 10 * y[j] + 20));
					glEnd();
				}
				for (j = 0;j < 4;++j) {
					glColor3ub(100, 100, 100);
					glBegin(GL_LINE_LOOP);
					glVertex2d(Pos_x(WINDOWX - 70 + 10 * x[j]), Pos_y(100 + 10 * y[j]));
					glVertex2d(Pos_x(WINDOWX - 70 + 10 * x[j] + 20), Pos_y(100 + 10 * y[j]));
					glVertex2d(Pos_x(WINDOWX - 70 + 10 * x[j] + 20), Pos_y(100 + 10 * y[j] + 20));
					glVertex2d(Pos_x(WINDOWX - 70 + 10 * x[j]), Pos_y(100 + 10 * y[j] + 20));
					glEnd();
				}
			}
			else {//2番目以降の四角の時
				for (j = 0;j < 4;++j) {
					//ブロックの描画
					glBegin(GL_QUADS);
					glVertex2d(Pos_x(WINDOWX - 60 + 9 * x[j]), Pos_y(190 + 80 * (i - 1) + 9 * y[j]));
					glVertex2d(Pos_x(WINDOWX - 60 + 9 * x[j] + 18), Pos_y(190 + 80 * (i - 1) + 9 * y[j]));
					glVertex2d(Pos_x(WINDOWX - 60 + 9 * x[j] + 18), Pos_y(190 + 80 * (i - 1) + 9 * y[j] + 18));
					glVertex2d(Pos_x(WINDOWX - 60 + 9 * x[j]), Pos_y(190 + 80 * (i - 1) + 9 * y[j] + 18));
					glEnd();
				}
				for (j = 0;j < 4;++j) {
					glColor3ub(100, 100, 100);
					glBegin(GL_LINE_LOOP);
					glVertex2d(Pos_x(WINDOWX - 60 + 9 * x[j]), Pos_y(190 + 80 * (i - 1) + 9 * y[j]));
					glVertex2d(Pos_x(WINDOWX - 60 + 9 * x[j] + 18), Pos_y(190 + 80 * (i - 1) + 9 * y[j]));
					glVertex2d(Pos_x(WINDOWX - 60 + 9 * x[j] + 18), Pos_y(190 + 80 * (i - 1) + 9 * y[j] + 18));
					glVertex2d(Pos_x(WINDOWX - 60 + 9 * x[j]), Pos_y(190 + 80 * (i - 1) + 9 * y[j] + 18));
					glEnd();
				}
			}
		}

		//ホールドの描画
		glColor3ub(200, 255, 200);
		DrawString("HOLD", GLUT_BITMAP_TIMES_ROMAN_24, (float)Pos_x(37), (float)Pos_y(40));
		glColor3ub(0, 50, 35);
		glBegin(GL_QUADS);//枠内を塗りつぶす
		glVertex2d(Pos_x(20), Pos_y(50));
		glVertex2d(Pos_x(120), Pos_y(50));
		glVertex2d(Pos_x(120), Pos_y(150));
		glVertex2d(Pos_x(20), Pos_y(150));
		glEnd();
		glColor3ub(100, 100, 100);
		glLineWidth(2.0);
		glBegin(GL_LINE_LOOP);//枠の描画
		glVertex2d(Pos_x(20), Pos_y(50));
		glVertex2d(Pos_x(120), Pos_y(50));
		glVertex2d(Pos_x(120), Pos_y(150));
		glVertex2d(Pos_x(20), Pos_y(150));
		glEnd();
		glLineWidth(1.0);

		switch (stock) {
		case 1:
			x[0] = -4, y[0] = -1;
			x[1] = -2, y[1] = -1;
			x[2] = 0, y[2] = -1;
			x[3] = 2, y[3] = -1;
			glColor3ub(0, 255, 255);//水色
			break;

		case 2:
			x[0] = -2, y[0] = -2;
			x[1] = 0, y[1] = -2;
			x[2] = -2, y[2] = 0;
			x[3] = 0, y[3] = 0;
			glColor3ub(255, 255, 50);//黄色っぽい
			break;

		case 3:
			x[0] = -1, y[0] = -2;
			x[1] = -3, y[1] = 0;
			x[2] = -1, y[2] = 0;
			x[3] = 1, y[3] = 0;
			glColor3ub(180, 75, 255);//紫色っぽい
			break;

		case 4:
			x[0] = -3, y[0] = -2;
			x[1] = -3, y[1] = 0;
			x[2] = -1, y[2] = 0;
			x[3] = 1, y[3] = 0;
			glColor3ub(0, 0, 255);//青
			break;

		case 5:
			x[0] = 1, y[0] = -2;
			x[1] = -3, y[1] = 0;
			x[2] = -1, y[2] = 0;
			x[3] = 1, y[3] = 0;
			glColor3ub(255, 128, 0);//オレンジっぽい
			break;

		case 6:
			x[0] = -3, y[0] = -2;
			x[1] = -1, y[1] = -2;
			x[2] = -1, y[2] = 0;
			x[3] = 1, y[3] = 0;
			glColor3ub(255, 0, 0);//赤
			break;

		case 7:
			x[0] = -1, y[0] = -2;
			x[1] = 1, y[1] = -2;
			x[2] = -3, y[2] = 0;
			x[3] = -1, y[3] = 0;
			glColor3ub(0, 255, 0);//緑
			break;
		}

		if (stock != 0) {
			for (i = 0;i < 4;++i) {
				//ブロックの描画
				glBegin(GL_QUADS);
				glVertex2d(Pos_x(70 + 10 * x[i]), Pos_y(100 + 10 * y[i]));
				glVertex2d(Pos_x(70 + 10 * x[i] + 20), Pos_y(100 + 10 * y[i]));
				glVertex2d(Pos_x(70 + 10 * x[i] + 20), Pos_y(100 + 10 * y[i] + 20));
				glVertex2d(Pos_x(70 + 10 * x[i]), Pos_y(100 + 10 * y[i] + 20));
				glEnd();
			}
			for (i = 0;i < 4;++i) {
				glColor3ub(100, 100, 100);
				glBegin(GL_LINE_LOOP);
				glVertex2d(Pos_x(70 + 10 * x[i]), Pos_y(100 + 10 * y[i]));
				glVertex2d(Pos_x(70 + 10 * x[i] + 20), Pos_y(100 + 10 * y[i]));
				glVertex2d(Pos_x(70 + 10 * x[i] + 20), Pos_y(100 + 10 * y[i] + 20));
				glVertex2d(Pos_x(70 + 10 * x[i]), Pos_y(100 + 10 * y[i] + 20));
				glEnd();
			}
		}

		//スコア等の表示
		sprintf_s(str1, 10, "%d", level);
		sprintf_s(str2, 10, "%d", del_line_sum);
		sprintf_s(str3, 10, "%d", score);
		/*sprintf(str1, "%d", level);
		sprintf(str2, "%d", del_line_sum);
		sprintf(str3, "%d", score);*/
		glColor3ub(255, 255, 255);
		DrawString("LEVEL", GLUT_BITMAP_TIMES_ROMAN_24, (float)Pos_x(30), (float)Pos_y(220));
		DrawString(str1, GLUT_BITMAP_TIMES_ROMAN_24, (float)Pos_x(55), (float)Pos_y(245));
		DrawString("LINE", GLUT_BITMAP_TIMES_ROMAN_24, (float)Pos_x(35), (float)Pos_y(300));
		DrawString(str2, GLUT_BITMAP_TIMES_ROMAN_24, (float)Pos_x(55), (float)Pos_y(325));
		DrawString("SCORE", GLUT_BITMAP_TIMES_ROMAN_24, (float)Pos_x(30), (float)Pos_y(380));
		DrawString(str3, GLUT_BITMAP_TIMES_ROMAN_24, (float)Pos_x(55), (float)Pos_y(405));

	}
	else if (gameflag == -1) {//ポーズ中
		glClear(GL_COLOR_BUFFER_BIT);
		Print_bmp(bmp_pause, -1, -1);
	}
	else if (gameflag == 0) {//ゲームオーバー
		glClear(GL_COLOR_BUFFER_BIT);
		Print_bmp(bmp_over, -1, (WINDOWY / 2 - bmp_over.height - 50));
				
		glColor3ub(0, 255, 0);
		DrawString("COUNTINUE?", GLUT_BITMAP_TIMES_ROMAN_24, (float)Pos_x(WINDOWX / 2 - 75), (float)Pos_y(WINDOWY / 2));
		DrawString("YES", GLUT_BITMAP_TIMES_ROMAN_24, (float)Pos_x(WINDOWX / 2 + 10), (float)Pos_y(WINDOWY / 2 + 35));
		DrawString("NO", GLUT_BITMAP_TIMES_ROMAN_24, (float)Pos_x(WINDOWX / 2 + 12), (float)Pos_y(WINDOWY / 2 + 70));
		if (choices == 0) {
			DrawString("->", GLUT_BITMAP_TIMES_ROMAN_24, (float)Pos_x(WINDOWX / 2 -20), (float)Pos_y(WINDOWY / 2 + 35));
		}
		else if (choices == 1) {
			DrawString("->", GLUT_BITMAP_TIMES_ROMAN_24, (float)Pos_x(WINDOWX / 2 -20), (float)Pos_y(WINDOWY / 2 + 70));
		}
	}

	glutSwapBuffers();
}

//ブロック変更関数
void Changeblock(block mino, int color) {
	switch (mino.type) {
	case 1:
		switch (mino.dir) {
		case 0:
			WorldMap[mino.y][mino.x - 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y][mino.x + 1] = color;
			WorldMap[mino.y][mino.x + 2] = color;
			break;

		case 1:
			WorldMap[mino.y - 1][mino.x] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y + 1][mino.x] = color;
			WorldMap[mino.y + 2][mino.x] = color;
			break;

		case 2:
			WorldMap[mino.y][mino.x - 2] = color;
			WorldMap[mino.y][mino.x - 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y][mino.x + 1] = color;
			break;

		case 3:
			WorldMap[mino.y - 2][mino.x] = color;
			WorldMap[mino.y - 1][mino.x] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y + 1][mino.x] = color;
			break;
		}
		break;

	case 2:
		WorldMap[mino.y - 1][mino.x] = color;
		WorldMap[mino.y - 1][mino.x + 1] = color;
		WorldMap[mino.y][mino.x] = color;
		WorldMap[mino.y][mino.x + 1] = color;
		break;

	case 3:
		switch (mino.dir) {
		case 0:
			WorldMap[mino.y - 1][mino.x] = color;
			WorldMap[mino.y][mino.x - 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y][mino.x + 1] = color;
			break;

		case 1:
			WorldMap[mino.y - 1][mino.x] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y][mino.x + 1] = color;
			WorldMap[mino.y + 1][mino.x] = color;
			break;

		case 2:
			WorldMap[mino.y][mino.x - 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y][mino.x + 1] = color;
			WorldMap[mino.y + 1][mino.x] = color;
			break;

		case 3:
			WorldMap[mino.y - 1][mino.x] = color;
			WorldMap[mino.y][mino.x - 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y + 1][mino.x] = color;
			break;
		}
		break;

	case 4:
		switch (mino.dir) {
		case 0:
			WorldMap[mino.y - 1][mino.x - 1] = color;
			WorldMap[mino.y][mino.x - 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y][mino.x + 1] = color;
			break;

		case 1:
			WorldMap[mino.y - 1][mino.x] = color;
			WorldMap[mino.y - 1][mino.x + 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y + 1][mino.x] = color;
			break;

		case 2:
			WorldMap[mino.y][mino.x - 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y][mino.x + 1] = color;
			WorldMap[mino.y + 1][mino.x + 1] = color;
			break;

		case 3:
			WorldMap[mino.y - 1][mino.x] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y + 1][mino.x - 1] = color;
			WorldMap[mino.y + 1][mino.x] = color;
			break;
		}
		break;

	case 5:
		switch (mino.dir) {
		case 0:
			WorldMap[mino.y - 1][mino.x + 1] = color;
			WorldMap[mino.y][mino.x - 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y][mino.x + 1] = color;
			break;

		case 1:
			WorldMap[mino.y - 1][mino.x] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y + 1][mino.x] = color;
			WorldMap[mino.y + 1][mino.x + 1] = color;
			break;

		case 2:
			WorldMap[mino.y][mino.x - 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y][mino.x + 1] = color;
			WorldMap[mino.y + 1][mino.x - 1] = color;
			break;

		case 3:
			WorldMap[mino.y - 1][mino.x - 1] = color;
			WorldMap[mino.y - 1][mino.x] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y + 1][mino.x] = color;
			break;
		}
		break;

	case 6:
		switch (mino.dir) {
		case 0:
			WorldMap[mino.y - 1][mino.x - 1] = color;
			WorldMap[mino.y - 1][mino.x] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y][mino.x + 1] = color;
			break;

		case 1:
			WorldMap[mino.y - 1][mino.x + 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y][mino.x + 1] = color;
			WorldMap[mino.y + 1][mino.x] = color;
			break;

		case 2:
			WorldMap[mino.y][mino.x - 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y + 1][mino.x] = color;
			WorldMap[mino.y + 1][mino.x + 1] = color;
			break;

		case 3:
			WorldMap[mino.y - 1][mino.x] = color;
			WorldMap[mino.y][mino.x - 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y + 1][mino.x - 1] = color;
			break;
		}
		break;

	case 7:
		switch (mino.dir) {
		case 0:
			WorldMap[mino.y - 1][mino.x] = color;
			WorldMap[mino.y - 1][mino.x + 1] = color;
			WorldMap[mino.y][mino.x - 1] = color;
			WorldMap[mino.y][mino.x] = color;
			break;

		case 1:
			WorldMap[mino.y - 1][mino.x] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y][mino.x + 1] = color;
			WorldMap[mino.y + 1][mino.x + 1] = color;
			break;

		case 2:
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y][mino.x + 1] = color;
			WorldMap[mino.y + 1][mino.x - 1] = color;
			WorldMap[mino.y + 1][mino.x] = color;
			break;

		case 3:
			WorldMap[mino.y - 1][mino.x - 1] = color;
			WorldMap[mino.y][mino.x - 1] = color;
			WorldMap[mino.y][mino.x] = color;
			WorldMap[mino.y + 1][mino.x] = color;
			break;
		}
		break;
	}
}

//ブロックの影を更新する関数
void ChangeShadow() {
	int i;

	if (mino.type != 0) {

		Changeblock(mino_shadow, 0);
		mino_shadow = mino;
		switch (mino_shadow.type) {
		case 1:
			switch (mino_shadow.dir) {
			case 0:
				i = mino_shadow.y + 1;
				while (WorldMap[i][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i][mino_shadow.x + 1] <= 0 && WorldMap[i][mino_shadow.x + 2] <= 0) {
					i++;
				}
				mino_shadow.y = i - 1;
				break;

			case 1:
				i = mino_shadow.y + 3;
				while (WorldMap[i][mino_shadow.x] <= 0) {
					i++;
				}
				mino_shadow.y = i - 3;
				break;

			case 2:
				i = mino_shadow.y + 1;
				while (WorldMap[i][mino_shadow.x - 2] <= 0 && WorldMap[i][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 1;
				break;

			case 3:
				i = mino_shadow.y + 2;
				while (WorldMap[i][mino_shadow.x] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;
			}
			break;

		case 2:
			i = mino_shadow.y + 1;
			while (WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i][mino_shadow.x + 1] <= 0) {
				i++;
			}
			mino_shadow.y = i - 1;
			break;

		case 3:
			switch (mino_shadow.dir) {
			case 0:
				i = mino_shadow.y + 1;
				while (WorldMap[i][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 1;
				break;

			case 1:
				i = mino_shadow.y + 2;
				while (WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i - 1][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;

			case 2:
				i = mino_shadow.y + 2;
				while (WorldMap[i - 1][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i - 1][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;

			case 3:
				i = mino_shadow.y + 2;
				while (WorldMap[i - 1][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;
			}
			break;

		case 4:
			switch (mino_shadow.dir) {
			case 0:
				i = mino_shadow.y + 1;
				while (WorldMap[i][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 1;
				break;

			case 1:
				i = mino_shadow.y + 2;
				while (WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i - 2][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;

			case 2:
				i = mino_shadow.y + 2;
				while (WorldMap[i - 1][mino_shadow.x - 1] <= 0 && WorldMap[i - 1][mino_shadow.x] <= 0 && WorldMap[i][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;

			case 3:
				i = mino_shadow.y + 2;
				while (WorldMap[i][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;
			}
			break;

		case 5:
			switch (mino_shadow.dir) {
			case 0:
				i = mino_shadow.y + 1;
				while (WorldMap[i][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 1;
				break;

			case 1:
				i = mino_shadow.y + 2;
				while (WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;

			case 2:
				i = mino_shadow.y + 2;
				while (WorldMap[i][mino_shadow.x - 1] <= 0 && WorldMap[i - 1][mino_shadow.x] <= 0 && WorldMap[i - 1][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;

			case 3:
				i = mino_shadow.y + 2;
				while (WorldMap[i - 2][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;
			}
			break;

		case 6:
			switch (mino_shadow.dir) {
			case 0:
				i = mino_shadow.y + 1;
				while (WorldMap[i - 1][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 1;
				break;

			case 1:
				i = mino_shadow.y + 2;
				while (WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i - 1][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;

			case 2:
				i = mino_shadow.y + 2;
				while (WorldMap[i - 1][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;

			case 3:
				i = mino_shadow.y + 2;
				while (WorldMap[i][mino_shadow.x - 1] <= 0 && WorldMap[i - 1][mino_shadow.x] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;
			}
			break;

		case 7:
			switch (mino_shadow.dir) {
			case 0:
				i = mino_shadow.y + 1;
				while (WorldMap[i][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i - 1][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 1;
				break;

			case 1:
				i = mino_shadow.y + 2;
				while (WorldMap[i - 1][mino_shadow.x] <= 0 && WorldMap[i][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;

			case 2:
				i = mino_shadow.y + 2;
				while (WorldMap[i][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0 && WorldMap[i - 1][mino_shadow.x + 1] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;

			case 3:
				i = mino_shadow.y + 2;
				while (WorldMap[i - 1][mino_shadow.x - 1] <= 0 && WorldMap[i][mino_shadow.x] <= 0) {
					i++;
				}
				mino_shadow.y = i - 2;
				break;
			}
			break;
		}

		Changeblock(mino_shadow, -1);
	}
}

//glutTimerFuncdで実行させる関数
void Timer1(int value) {
	if (gameflag == 1) {
		count++;
		
		if (count >= func_time) {
			count = 0;
			Drop();
		}
		if ((del_line_sum >= 10 * level) && (func_time - 40 >= 0)) {
			level++;
			func_time -= 40;
		}
		
		glutTimerFunc(1, Timer1, value);
	}
}
