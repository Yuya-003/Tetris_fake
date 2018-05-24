#pragma once
#include <GL/glut.h>

#define BLOCK_SPACE_X 10//ブロックを置くことのできるスペース
#define BLOCK_SPACE_Y 20
#define BLOCK_SIZE 30//ブロックのサイズ
#define WORLDX (BLOCK_SPACE_X+2)//配列の大きさ
#define WORLDY (BLOCK_SPACE_Y+5)
#define WX (BLOCK_SPACE_X+2)//表示されるブロック数
#define WY (BLOCK_SPACE_Y+1)
#define WINDOWX (WX * BLOCK_SIZE + 100 + 200)//ウィンドウサイズ
#define WINDOWY (WY * BLOCK_SIZE + 50)
#define Pos_x(x) (GLdouble)(-1.0 + (2.0 / WINDOWX) * (x))//x座標変換マクロ
#define Pos_y(y) (GLdouble)(1.0 - (2.0 / WINDOWY) * (y))//y座標変換マクロ

typedef struct {
	int x, y;//x,y座標
	int type;//ブロックの種類
	int dir;//向き

			/* typeについて
			1:■■■■	2:■■	3:  ■		4:■		5:    ■		6:■■		7:  ■■
						  ■■	  ■■■	  ■■■	  ■■■		    ■■	  ■■
			dirが増えると時計回りに回転させる。
			*/
}block;

typedef struct {
	GLbyte *bits;
	GLint width, height;
}bitmap;

extern char str1[10];
extern char str2[10];
extern char str3[10];
extern char WorldMap[WORLDY][WORLDX];
extern int minoflag[8];
extern int nextmino[7];
extern int keypush;
extern int keypush_sp;
extern int appear;
extern int gameflag;
extern int level;
extern int del_line;
extern int del_line_sum;
extern int score;
extern int stock;
extern int stockflag;
extern int move;
extern int count;
extern int func_time;
extern int choices;
extern block mino;
extern block mino_shadow;
extern bitmap bmp_pause;
extern bitmap bmp_over;
extern bitmap bmp_red;
extern bitmap bmp_green;
extern bitmap bmp_blue;
extern bitmap bmp_lightblue;
extern bitmap bmp_yellow;
extern bitmap bmp_violet;
extern bitmap bmp_orange;
extern bitmap bmp_wall;

void Init(void);
void Display(void);
void InitMap(char world[WORLDY][WORLDX]);
void Changeblock(block, int );
void ChangeShadow(void);
void MoveTo(int, int, int);
void Keyboard(unsigned char, int, int);
void KeyUp(unsigned char, int, int);
void KeyUp_sp(int, int, int);
void Timer1(int);
void Drop(void);
void DrawString(const char*, void*, float, float);
void Load_bmp(bitmap*, const char*);
void Print_bmp(bitmap, int, int);
