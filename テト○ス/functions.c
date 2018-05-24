#include <GL/glut.h>
#include "declaration.h"
#include <stdio.h>

//文字列描画関数
void DrawString(const char *str, void *font, float x, float y) {
	glRasterPos2f(x, y);
	while (*str) {
		glutBitmapCharacter(font, *str);
		++str;
	}
}

//ビットマップ読み込み関数
void Load_bmp(bitmap *bmp, const char *filename) {
	FILE *stream;
	unsigned long offbits, size_image;

	/*if ((stream = fopen(filename, "rb")) == NULL) {
		exit(EXIT_FAILURE);
	}*/
	if (fopen_s(&stream, filename, "rb")) {
		exit(EXIT_FAILURE);
	}
	fseek(stream, 0x0a, SEEK_SET);
	fread(&offbits, 4, 1, stream);
	fseek(stream, 0x12, SEEK_SET);
	fread(&bmp->width, 4, 1, stream);
	fread(&bmp->height, 4, 1, stream);
	fseek(stream, 0x22, SEEK_SET);
	fread(&size_image, 4, 1, stream);
	bmp->bits = malloc(size_image);
	fseek(stream, offbits, SEEK_SET);
	fread(bmp->bits, 1, size_image, stream);
	fclose(stream);
}

//ビットマップ表示関数 座標の基準は左上(x,y=-1で中央)
void Print_bmp(bitmap bmp, int x, int y) {
	if (x == -1) {
		x = WINDOWX / 2 - bmp.width / 2;
	}
	if (y == -1) {
		y = WINDOWY / 2 - bmp.height / 2;
	}
	glRasterPos2d(Pos_x(x), Pos_y(y + bmp.height));
	glDrawPixels(bmp.width, bmp.height, GL_BGR_EXT, GL_UNSIGNED_BYTE, bmp.bits);
}
