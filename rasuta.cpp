#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "rasuta.h"

#define white 255
#define black 0

rasuta::rasuta(RGBImage image) : size_x(image.sizeX), size_y(image.sizeY) {

	data = new struct color *[size_y];
	for (int i = 0; i < size_y; i++) {
		data[i] = new struct color[size_x];
	}

	data1 = new struct color *[size_y];
	for (int i = 0; i < size_y; i++) {
		data1[i] = new struct color[size_x];
	}

	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data[y][x].red = image.data[y][x].r;
			data[y][x].green = image.data[y][x].g;
			data[y][x].blue = image.data[y][x].b;
		}
	}


	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data1[y][x].red = data[y][x].red;
			data1[y][x].green = data[y][x].green;
			data1[y][x].blue = data[y][x].blue;
		}
	}

}

void rasuta::ras() {
	int x, y;
	int result_x, result_y;
	int result_x1, result_y1;
	int result_x2, result_y2;
	int result_x3, result_y3;
	int out = 0;

	//普通のラスタ走査
	result_x = 0;
	for (y = 0; y < size_y; y++) {
		for (x = 0; x < size_x; x++) {
			if (x > 0 && x < 15) {
				if (data[y][x].red == 0) {
					out = x;
					if (result_x < out) {
						result_x = out;
					}
				}
			}
			else {
				;
			}
		}
	}
	printf("x=%d\n", result_x);

	//縦方向のラスタ走査
	result_y1 = 0;
	out = 0;
	for (x = 0; x < size_x; x++) {
		for (y = 0; y < size_y; y++) {
			if (y>0 && y<30) {
				if (data[y][x].red == 0) {
					out = y;
					if (result_y1 < out) {
						result_y1 = out;
					}
				}
			}
			else {
				;
			}
		}
	}
	printf("y1=%d\n", result_y1);

	//右からラスタ走査
	out = 0;
	result_x2 = size_x - 1;
	for (y = size_y - 1; y > 0; y--) {
		for (x = size_x - 1; x > 0; x--) {
			if (x < size_x && x > size_x - 15) {
				if (data[y][x].red == 0) {
					out = x;
					if (result_x2 > out) {
						result_x2 = out;
					}
				}
				else {
					;
				}
			}


		}
	}
	printf("x2=%d\n", result_x2);

	//下からラスタ走査
	result_y3 = size_y - 1;
	out = 0;
	for (x = size_x - 1; x > 0; x--) {
		for (y = size_y - 1; y > 0; y--) {
			if (y < size_y && y > size_y-25) {
				if (data[y][x].red == 0) {
					out = y;
					if (result_y3 > out) {
						result_y3 = out;
					}
				}
			}
			else {
				;
			}
		}
	}
	printf("y3=%d\n", result_y3);
}

void rasuta::ban() {


	int size_xt = size_xe - size_xs;	//盤のx幅
	int size_yt = size_ye - size_ys;	//盤のy幅

	for (int y = size_ys; y <= size_ye; y++) {
		for (int x = size_xs; x <= size_xe; x++) {
			if (y == size_ys || x == size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.11 + 0.5) + size_ys || x == (int)(size_xt * 0.11 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.22 + 0.5) + size_ys || x == (int)(size_xt * 0.22 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.33 + 0.5) + size_ys || x == (int)(size_xt * 0.33 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.44 + 0.5) + size_ys || x == (int)(size_xt * 0.44 + 0.5) + size_xs){
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.55 + 0.5) + size_ys || x == (int)(size_xt * 0.55 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.66 + 0.5) + size_ys || x == (int)(size_xt * 0.66 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.77 + 0.5) + size_ys || x == (int)(size_xt * 0.77 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.88 + 0.5) + size_ys || x == (int)(size_xt * 0.88 + 0.5) + size_xs){
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == size_ye - 1 || x == size_xe - 1) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else {
				data1[y][x].red = white;
				data1[y][x].green = white;
				data1[y][x].blue = white;
			}
		}
	}
}


//RGBImageへ出力
void rasuta::output_RGBImage(RGBImage* image_print)
{
	//image_print->newImage(size_xe, size_ye);

	for (int i = 0; i < size_ye; i++) {
		for (int j = 0; j < size_xe; j++) {
			image_print->data[i][j].r = data1[i][j].red;
			image_print->data[i][j].g = data1[i][j].green;
			image_print->data[i][j].b = data1[i][j].blue;
		}
	}
}

rasuta::~rasuta() {
	for (int i = 0; i < size_y; i++) {
		delete[] data[i];
		data[i] = 0;
	}
	delete[] data;
	data = 0;
}
