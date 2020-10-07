#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "shrink.h"
#include "color.h"
#include "ImageIO.h"

#define black 0
#define white 255

//コンストラクタ
shrink::shrink(RGBImage image) :size_x(image.sizeX), size_y(image.sizeY) {
	data = new struct color*[size_y];
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

void shrink :: erosion(int rep) {

	for (int i = 0; i < rep; i++) {
		for (int y = 0; y < size_y; y++) {
			for (int x = 0; x < size_x; x++) {
				if (data[y][x].red == black) {
					counter = 0;
					for (int m = -1; m < 2; m++) {
						for (int n = -1; n < 2; n++) {
							p_x = x + n;
							p_y = y + m;
							if (p_x > 0 && p_x < size_x && p_y>0 && p_y < size_y && data[p_y][p_x].red == white) {
								counter++;
							}
						}
					}
					if (counter > 0) {
						data1[y][x].red = white;
						data1[y][x].blue = white;
						data1[y][x].green = white;
					}
					/*else {
						data1[y][x].red = black;
						data1[y][x].blue = black;
						data1[y][x].green = black;
					}*/

				}
			}
		}
		for (int y = 0; y < size_y; y++) {
			for (int x = 0; x < size_x; x++) {
				data[y][x].red = data1[y][x].red;
				data[y][x].blue = data1[y][x].blue;
				data[y][x].green = data1[y][x].green;
			}

		}
	}
}
	/*
	int sum = 0;

	for (int m = 0; m < rep; m++) {

		for (int j = 0; j < size_y; j++) {

			for (int i = 0; i < size_x; i++) {

				if (j == 0 && !(i == 0)) { //上端
					for (int k = 1; k < 3; k++) {
						for (int l = 0; l < 3; l++) {

							sum = 0;
							sum += image.data[j + k - 1][i + l - 1].r;

							if (sum > 1) {
								data[j][i].red = 255;
								data[j][i].green = 255;
								data[j][i].blue = 255;
							}
							else  {
								data[j][i].red = 0;
								data[j][i].green = 0;
								data[j][i].blue = 0;
							}

						}
					}

				}
				else if ((j == 0) && (i == 0)) { //左上端
					for (int k = 1; k < 3; k++) {
						for (int l = 1; l < 3; l++) {
							sum = 0;
							sum += image.data[j + k - 1][i + l - 1].r;

							if (sum > 1) {
								data[j][i].red = 255;
								data[j][i].green = 255;
								data[j][i].blue = 255;
							}
							else  {
								data[j][i].red = 0;
								data[j][i].green = 0;
								data[j][i].blue = 0;
							}

						}
					}

				}
				else if ((j == size_y - 1) && (i == 0)) { //左下端
					for (int k = 0; k < 2; k++) {
						for (int l = 1; l < 3; l++) {
							sum = 0;
							sum += image.data[j + k - 1][i + l - 1].r;

							if (sum > 1) {
								data[j][i].red = 255;
								data[j][i].green = 255;
								data[j][i].blue = 255;
							}
							else  {
								data[j][i].red = 0;
								data[j][i].green = 0;
								data[j][i].blue = 0;
							}
						}
					}


				}
				else if ((j == size_y - 1) && (i == size_x - 1)) { //右下端
					for (int k = 0; k < 2; k++) {
						for (int l = 0; l < 2; l++) {
							sum = 0;
							sum += image.data[j + k - 1][i + l - 1].r;

							if (sum > 1) {
								data[j][i].red = 255;
								data[j][i].green = 255;
								data[j][i].blue = 255;
							}
							else  {
								data[j][i].red = 0;
								data[j][i].green = 0;
								data[j][i].blue = 0;
							}
						}
					}

				}
				else if ((j == 0) && (i == size_x - 1)) { //右上端
					for (int k = 1; k < 3; k++) {
						for (int l = 0; l < 2; l++) {
							sum = 0;
							sum += image.data[j + k - 1][i + l - 1].r;

							if (sum > 1) {
								data[j][i].red = 255;
								data[j][i].green = 255;
								data[j][i].blue = 255;
							}
							else  {
								data[j][i].red = 0;
								data[j][i].green = 0;
								data[j][i].blue = 0;
							}

						}
					}

				}
				else if (!(j == 0) && (i == 0)) { //左端
					for (int k = 0; k < 3; k++) {
						for (int l = 1; l < 3; l++) {
							sum = 0;
							sum += image.data[j + k - 1][i + l - 1].r;

							if (sum > 1) {
								data[j][i].red = 255;
								data[j][i].green = 255;
								data[j][i].blue = 255;
							}
							else  {
								data[j][i].red = 0;
								data[j][i].green = 0;
								data[j][i].blue = 0;
							}
						}
					}

				}
				else if (!(j == 0) && (i == size_x - 1)) { //右端
					for (int k = 0; k < 3; k++) {
						for (int l = 0; l < 2; l++) {
							sum = 0;
							sum += image.data[j + k - 1][i + l - 1].r;

							if (sum > 1) {
								data[j][i].red = 255;
								data[j][i].green = 255;
								data[j][i].blue = 255;
							}
							else  {
								data[j][i].red = 0;
								data[j][i].green = 0;
								data[j][i].blue = 0;
							}
						}
					}

				}
				else if ((j == (size_y - 1)) && !(i == 0)) { //下端
					for (int k = 0; k < 2; k++) {
						for (int l = 0; l < 3; l++) {
							sum = 0;
							sum += image.data[j + k - 1][i + l - 1].r;

							if (sum > 1) {
								data[j][i].red = 255;
								data[j][i].green = 255;
								data[j][i].blue = 255;
							}
							else  {
								data[j][i].red = 0;
								data[j][i].green = 0;
								data[j][i].blue = 0;
							}
						}
					}

				}
				else {    //上記以外
					for (int k = 0; k < 3; k++) {
						for (int l = 0; l < 3; l++) {
							sum = 0;
							sum += image.data[j + k - 1][i + l - 1].r;

							if (sum > 1) {
								data[j][i].red = 255;
								data[j][i].green = 255;
								data[j][i].blue = 255;
							}
							else  {
								data[j][i].red = 0;
								data[j][i].green = 0;
								data[j][i].blue = 0;
							}
						}
					}

				}

			}
		}
	}
}
*/

//デストラクタ
shrink::~shrink() {
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

void shrink::output_RGBImage(RGBImage *image_print) {
	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			image_print->data[j][i].r = data1[j][i].red;//RGBImageにさっき求めたデータ配列を格納
			image_print->data[j][i].b = data1[j][i].blue;//
			image_print->data[j][i].g = data1[j][i].green;//
		}

	}
}





