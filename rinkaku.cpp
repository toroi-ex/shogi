#include "color.h"
#include "rinkaku.h"
#include "ImageIO.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<math.h>

#define white 255
#define black 0

//コンストラクタ
contour::contour(RGBImage image) : size_x(image.sizeX), size_y(image.sizeY) {

	data = new struct color*[size_y];  //動的確保
	for (int i = 0; i < size_y; i++) {
		data[i] = new struct color[size_x];
	}

	data1 = new struct color*[size_y];  //動的確保
	for (int i = 0; i < size_y; i++) {
		data1[i] = new struct color[size_x];
	}

	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data[y][x].red = image.data[y][x].r;
			data[y][x].blue = image.data[y][x].b;
			data[y][x].green = image.data[y][x].g;

		}
	}

	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data1[y][x].red = data[y][x].red;
			data1[y][x].blue = data[y][x].blue;
			data1[y][x].green = data[y][x].green;
		}
	}

}


void contour::rinkaku(float amp) {
	int    d0, d1, d2, d3, d4, d5, d6, d7, d8;
	int    i, j, k, max, dat;
	int    m[8];
	float    z;

	for (i = 1; i < size_y - 1; i++) {
		for (j = 1; j < size_x - 1; j++) {
			d0 = data[i - 1][j - 1].red;
			d1 = data[i - 1][j].red;
			d2 = data[i - 1][j + 1].red;
			d3 = data[i][j - 1].red;
			d4 = data[i][j].red;
			d5 = data[i][j + 1].red;
			d6 = data[i + 1][j - 1].red;
			d7 = data[i + 1][j].red;
			d8 = data[i + 1][j + 1].red;
			m[0] = d0 + d1 + d2 + d3 - 2 * d4 + d5 - d6 - d7 - d8;
			m[1] = d0 + d1 + d2 + d3 - 2 * d4 - d5 + d6 - d7 - d8;
			m[2] = d0 + d1 - d2 + d3 - 2 * d4 - d5 + d6 + d7 - d8;
			m[3] = d0 - d1 - d2 + d3 - 2 * d4 - d5 + d6 + d7 + d8;
			m[4] = -d0 - d1 - d2 + d3 - 2 * d4 + d5 + d6 + d7 + d8;
			m[5] = -d0 - d1 + d2 - d3 - 2 * d4 + d5 + d6 + d7 + d8;
			m[6] = -d0 + d1 + d2 - d3 - 2 * d4 + d5 - d6 + d7 + d8;
			m[7] = d0 + d1 + d2 - d3 - 2 * d4 + d5 - d6 - d7 + d8;
			max = 0;
			for (k = 0; k < 8; k++) {
				if (max < m[k])
				{
					max = m[k];
				}
			}
			z = amp*(float)(max);
			dat = (int)(z);
			if (dat > 255) {
				dat = black;//whiteで輪郭白　blackで輪郭黒
				data1[i][j].red = (char)dat;
				data1[i][j].blue = (char)dat;
				data1[i][j].green = (char)dat;
			}
			//背景が白で輪郭を黒にしたいとき
			else {
				dat = white;
				data1[i][j].red = (char)dat;
				data1[i][j].blue = (char)dat;
				data1[i][j].green = (char)dat;
			}
			//背景が黒で輪郭を白にしたいとき
			//data1[i][j].red = (char)dat;
			//data1[i][j].blue = (char)dat;
			//data1[i][j].green = (char)dat;
		}
	}
}


//デストラクタ
contour::~contour() {
	for (int i = 0; i < size_y; i++) {
		delete[] data[i];
		data[i] = 0;
	}
	delete[] data;
	data = 0;

	for (int j = 0; j < size_y; j++) {
		delete[] data1[j];
		data1[j] = 0;
	}
	delete[] data1;
	data1 = 0;
}

// RGBImageへ出力
void contour::output_RGBImage(RGBImage *image_print)
{
	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			image_print->data[j][i].r = data1[j][i].red;
			image_print->data[j][i].g = data1[j][i].green;
			image_print->data[j][i].b = data1[j][i].blue;
		}
	}
}