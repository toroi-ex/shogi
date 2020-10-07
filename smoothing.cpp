#include "color.h"
#include "smoothing.h"
#include "ImageIO.h"
#include <iostream>
#include <math.h>

using namespace std;


//コンストラクタ
smoothing::smoothing(RGBImage image) : size_x(image.sizeX), size_y(image.sizeY) {

	data = new struct color*[size_y];
	for (int i = 0; i < size_y; i++) {
		data[i] = new struct color[size_x];
	}

	//double smoothing[9] =
	//{
	//	0.111, 0.111, 0.111,
	//	0.111, 0.111, 0.111,
	//	0.111, 0.111, 0.111
	//};

	double smoothing[9] =
	{
		1,1, 1,
		1, -8, 1,
		1, 1, 1
	};

	for (int j = 0; j < size_y; j++) {

		for (int i = 0; i < size_x; i++) {

			if (j == 0 && !(i == 0)) { //上端
				for (int k = 1; k < 3; k++) {
					for (int l = 0; l < 3; l++) {

						data[j][i].red += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].r);
						data[j][i].green += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].g);
						data[j][i].blue += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].b);
					}
				}

			}
			else if ((j == 0) && (i == 0)) { //左上端
				for (int k = 1; k < 3; k++) {
					for (int l = 1; l < 3; l++) {

						data[j][i].red += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].r);
						data[j][i].green += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].g);
						data[j][i].blue += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].b);
					}
				}

			}
			else if ((j == size_y - 1) && (i == 0)) { //左下端
				for (int k = 0; k < 2; k++) {
					for (int l = 1; l < 3; l++) {
						data[j][i].red += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].r);
						data[j][i].green += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].g);
						data[j][i].blue += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].b);
					}
				}


			}
			else if ((j == size_y - 1) && (i == size_x - 1)) { //右下端
				for (int k = 0; k < 2; k++) {
					for (int l = 0; l < 2; l++) {
						data[j][i].red += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].r);
						data[j][i].green += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].g);
						data[j][i].blue += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].b);
					}
				}

			}
			else if ((j == 0) && (i == size_x - 1)) { //右上端
				for (int k = 1; k < 3; k++) {
					for (int l = 0; l < 2; l++) {
						data[j][i].red += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].r);
						data[j][i].green += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].g);
						data[j][i].blue += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].b);
					}
				}

			}
			else if (!(j == 0) && (i == 0)) { //左端
				for (int k = 0; k < 3; k++) {
					for (int l = 1; l < 3; l++) {
						data[j][i].red += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].r);
						data[j][i].green += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].g);
						data[j][i].blue += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].b);
					}
				}

			}
			else if (!(j == 0) && (i == size_x - 1)) { //右端
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 2; l++) {
						data[j][i].red += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].r);
						data[j][i].green += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].g);
						data[j][i].blue += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].b);
					}
				}

			}
			else if ((j == (size_y - 1)) && !(i == 0)) { //下端
				for (int k = 0; k < 2; k++) {
					for (int l = 0; l < 3; l++) {
						data[j][i].red += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].r);
						data[j][i].green += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].g);
						data[j][i].blue += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].b);
					}
				}

			}
			else {
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						data[j][i].red += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].r);
						data[j][i].green += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].g);
						data[j][i].blue += (int)(smoothing[k * 3 + l] * image.data[j + k - 1][i + l - 1].b);
					}
				}

			}

		}
	}
}

//デストラクタ
smoothing::~smoothing() {
	for (int i = 0; i < size_y; i++) {
		delete[] data[i];
		data[i] = 0;
	}
	delete[] data;
	data = 0;
}

// RGBImageへ出力
void smoothing::output_RGBImage(RGBImage *rgb_image)
{
	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			rgb_image->data[j][i].r = data[j][i].red;
			rgb_image->data[j][i].g = data[j][i].green;
			rgb_image->data[j][i].b = data[j][i].blue;
		}
	}
}