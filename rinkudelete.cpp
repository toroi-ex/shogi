#include "color.h"
#include "rinkakudelete.h"
#include "ImageIO.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<math.h>

#define white 255
#define black 0
#define gray 128

//コンストラクタ
contour2::contour2(RGBImage image) : size_x(image.sizeX), size_y(image.sizeY) {

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
			data[y][x].green = image.data[y][x].g;
			data[y][x].blue = image.data[y][x].b;

		}
	}
	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data1[y][x].red = black;
			data1[y][x].green = black;
			data1[y][x].blue = black;
		}
	}
}

//背景白で文字を黒にしたければ今のまま　背景黒で文字を白にしたければblackとwhiteを入れ替えて


int contour2::obtain_contour(int x_start, int y_start) {
	int x, y;
	int px, py;
	int code;//チェインコード
	int num;//総数
	int i, counter, detect;


	//孤立点のチェック
	counter = 0;
	for (i = 0; i < 8; i++) {
		px = x_start + offset[i][0];
		py = y_start + offset[i][1];
		if (px >= 0 && px < size_x && py >= 0 && py < size_y && data[py][px].red == white) {
			counter++;
		}
	}
	if (counter == 0) { //初期位置は孤立点
		num = 1;
	}
	else { //探索開始
		num = -1;
		x = x_start;
		y = y_start;
		code = 0;
		do {
			detect = 0;//次の点を見つけたら1
			//探索は真ん中からスタートして次は上
			code = code - 3;
			if (code < 0) {
				code = code + 8;
			}
			do {
				px = x + offset[code][0];
				py = y + offset[code][1];
				if (px >= 0 && px < size_x && py >= 0 && py < size_y && data[py][px].red == white) {
					detect = 1;//次の点を検出した
					num++;
					if (num > max) {
						printf("輪郭線の画素数>%d\n", max);
						exit(1);
					}
					chain_code[num] = code;
					x = px;
					y = py;
				}
				code++;
				if (code > 7) {
					code = 0;
				}
			} while (detect == 0);
		} while (x != x_start || y != y_start);//開始点まで
		num = num + 2;//chain_code[]の添え字とのずれを修正
	}
	return (num);
}

//
void contour2::remove_areas(int meter) {//閾値
	int i, num, x, y, px, py;
	int fill,fall;

	/*for (y = 0; y < size_y; y++) {
		for (x = 0; x < size_x; x++) {
			data1[y][x].red = black;
			data1[y][x].green = black;
			data1[y][x].blue = black;
		}
	}*/

	//処理開始
	for (y = 0; y < size_y; y++) {
		for (x = 0; x < size_x; x++) {
			if (data[y][x].red == white) {//開始点
				num = obtain_contour(x, y);//追跡
				if (num > meter) {
					fill = white;				
				}
				else {
					fill = gray;				
				}
				px = x;
				py = y;

				if(data[y][x].green == white){
					data[py][px].red = black;
					data[py][px].green = black;
					data[py][px].blue = black;

					data1[py][px].red = (unsigned char)fill;
					data1[py][px].green = (unsigned char)fill;
					data1[py][px].blue = (unsigned char)fill;
				}

				else if (data[y][x].red == white) {
					data[py][px].red = black;
					data[py][px].green = black;
					data[py][px].blue = black;

					data1[py][px].red = (unsigned char)fill;
					data1[py][px].green = black;
					data1[py][px].blue = black;
				}

				if (num > 1) {
					for (i = 0; i < num - 1; i++) {
						px = px + offset[chain_code[i]][0];
						py = py + offset[chain_code[i]][1];

						if (data[y][x].green == white) {
							data[py][px].red = black;
							data[py][px].green = black;
							data[py][px].blue = black;

							data1[py][px].red = (unsigned char)fill;
							data1[py][px].green = (unsigned char)fill;
							data1[py][px].blue = (unsigned char)fill;
						}

						else if (data[y][x].red == white) {
							data[py][px].red = black;
							data[py][px].green = black;
							data[py][px].blue = black;

							data1[py][px].red = (unsigned char)fill;
							data1[py][px].green = black;
							data1[py][px].blue = black;
						}
					}
				}
			}
		}
	}
	//後処理
	for (y = 0; y < size_y; y++) {
		for (x = 0; x < size_x; x++) {
			if (data1[y][x].red == gray) {
				data1[y][x].red = black;
				data1[y][x].green = black;
				data1[y][x].blue = black;
				for (i = 0; i < 8; i++) {
					px = x + offset[i][0];
					py = y + offset[i][1];
					if (px >= 0 && px < size_x && py >= 0 && py < size_y && data1[py][px].green == white) {
						data1[y][x].red = white;
						data1[y][x].green = white;
						data1[y][x].blue = white;
					}
					else if (px >= 0 && px < size_x && py >= 0 && py < size_y && data1[py][px].red == white) {
						data1[y][x].red = white;
						data1[y][x].green = black;
						data1[y][x].blue = black;
					}
				}
			}
		}
	}
}


//デストラクタ
contour2::~contour2() {
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
void contour2::output_RGBImage(RGBImage *image_print)
{
	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			image_print->data[j][i].r = data1[j][i].red;
			image_print->data[j][i].g = data1[j][i].green;
			image_print->data[j][i].b = data1[j][i].blue;
		}
	}
}