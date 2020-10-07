#include "color.h"
#include "sobel.h"
#include "ImageIO.h"
#include<iostream>
#include<math.h>

using namespace std;


//コンストラクタ
sobel_image::sobel_image(RGBImage image) : size_x(image.sizeX), size_y(image.sizeY) {

	data = new struct color*[size_y];
	for (int i = 0; i < size_y; i++) {
		data[i] = new struct color[size_x];
	}

	int sobel_x[9] =
	{
		-1, 0, 1,
		-2, 0, 2,
		-1, 0, 1
	};

	int sobel_y[9] =
	{
		1, 2, 1,
		0, 0, 0,
		-1, -2, -1
	};



	for (int j = 0; j < size_y; j++) {

		for (int i = 0; i < size_x; i++) {

			int xr = 0, xg = 0, xb = 0, yr = 0, yg = 0, yb = 0;

			if (j == 0 && !(i == 0)) { //上端
				for (int k = 1; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						xr += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						xg += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						xb += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;

						yr += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						yg += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						yb += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;
					}
				}

				data[j][i].red = (int)sqrt(pow(xr, 2) + pow(yr, 2));
				data[j][i].green = (int)sqrt(pow(xg, 2) + pow(yg, 2));
				data[j][i].blue = (int)sqrt(pow(xb, 2) + pow(yb, 2));

			}
			else if ((j == 0) && (i == 0)) { //左上端
				for (int k = 1; k < 3; k++) {
					for (int l = 1; l < 3; l++) {
						xr += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						xg += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						xb += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;

						yr += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						yg += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						yb += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;
					}
				}

				data[j][i].red = (int)sqrt(pow(xr, 2) + pow(yr, 2));
				data[j][i].green = (int)sqrt(pow(xg, 2) + pow(yg, 2));
				data[j][i].blue = (int)sqrt(pow(xb, 2) + pow(yb, 2));

			}
			else if ((j == size_y - 1) && (i == 0)) { //左下端
				for (int k = 0; k < 2; k++) {
					for (int l = 1; l < 3; l++) {
						xr += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						xg += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						xb += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;

						yr += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						yg += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						yb += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;
					}
				}

				data[j][i].red = (int)sqrt(pow(xr, 2) + pow(yr, 2));
				data[j][i].green = (int)sqrt(pow(xg, 2) + pow(yg, 2));
				data[j][i].blue = (int)sqrt(pow(xb, 2) + pow(yb, 2));

			}
			else if ((j == size_y - 1) && (i == size_x - 1)) { //右下端
				for (int k = 0; k < 2; k++) {
					for (int l = 0; l < 2; l++) {
						xr += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						xg += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						xb += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;

						yr += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						yg += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						yb += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;
					}
				}
				data[j][i].red = (int)sqrt(pow(xr, 2) + pow(yr, 2));
				data[j][i].green = (int)sqrt(pow(xg, 2) + pow(yg, 2));
				data[j][i].blue = (int)sqrt(pow(xb, 2) + pow(yb, 2));

			}
			else if ((j == 0) && (i == size_x - 1)) { //右上端
				for (int k = 1; k < 3; k++) {
					for (int l = 0; l < 2; l++) {
						xr += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						xg += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						xb += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;

						yr += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						yg += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						yb += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;
					}
				}
				data[j][i].red = (int)sqrt(pow(xr, 2) + pow(yr, 2));
				data[j][i].green = (int)sqrt(pow(xg, 2) + pow(yg, 2));
				data[j][i].blue = (int)sqrt(pow(xb, 2) + pow(yb, 2));

			}
			else if (!(j == 0) && (i == 0)) { //左端
				for (int k = 0; k < 3; k++) {
					for (int l = 1; l < 3; l++) {
						xr += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						xg += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						xb += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;

						yr += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						yg += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						yb += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;
					}
				}

				data[j][i].red = (int)sqrt(pow(xr, 2) + pow(yr, 2));
				data[j][i].green = (int)sqrt(pow(xg, 2) + pow(yg, 2));
				data[j][i].blue = (int)sqrt(pow(xb, 2) + pow(yb, 2));

			}
			else if (!(j == 0) && (i == size_x - 1)) { //右端
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 2; l++) {
						xr += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						xg += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						xb += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;

						yr += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						yg += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						yb += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;
					}
				}
				data[j][i].red = (int)sqrt(pow(xr, 2) + pow(yr, 2));
				data[j][i].green = (int)sqrt(pow(xg, 2) + pow(yg, 2));
				data[j][i].blue = (int)sqrt(pow(xb, 2) + pow(yb, 2));

			}
			else if ((j == (size_y - 1)) && !(i == 0)) { //下端
				for (int k = 0; k < 2; k++) {
					for (int l = 0; l < 3; l++) {
						xr += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						xg += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						xb += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;

						yr += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						yg += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						yb += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;
					}
				}

				data[j][i].red = (int)sqrt(pow(xr, 2) + pow(yr, 2));
				data[j][i].green = (int)sqrt(pow(xg, 2) + pow(yg, 2));
				data[j][i].blue = (int)sqrt(pow(xb, 2) + pow(yb, 2));
			}
			else {
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						xr += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						xg += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						xb += sobel_x[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;

						yr += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].r;
						yg += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].g;
						yb += sobel_y[k * 3 + l] * image.data[j + k - 1][i + l - 1].b;
					}
				}

				data[j][i].red = (int)sqrt(pow(xr, 2) + pow(yr, 2));
				data[j][i].green = (int)sqrt(pow(xg, 2) + pow(yg, 2));
				data[j][i].blue = (int)sqrt(pow(xb, 2) + pow(yb, 2));
			}

		}
	}
}

//デストラクタ
sobel_image::~sobel_image() {
	for (int i = 0; i < size_y; i++) {
		delete[] data[i];
		data[i] = 0;
	}
	delete[] data;
	data = 0;
}

// RGBImageへ出力
void sobel_image::output_RGBImage(RGBImage *image_print)
{
	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			image_print->data[j][i].r = data[j][i].red;
			image_print->data[j][i].g = data[j][i].green;
			image_print->data[j][i].b = data[j][i].blue;
		}
	}
}