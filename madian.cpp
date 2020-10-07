#include "color.h"
#include "median.h"
#include "ImageIO.h"
#include<iostream>

using namespace std;

//コンストラクタ
median::median(RGBImage image) : size_x(image.sizeX), size_y(image.sizeY) {

	data = new struct color*[size_y];
	for (int i = 0; i < size_y; i++) {
		data[i] = new struct color[size_x];
	}
}

int median::median_sort(int sort[9]) {
	int buf;

	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			if (sort[i + 1] < sort[i]) {
				buf = sort[i + 1];
				sort[i + 1] = sort[i];
				sort[i] = buf;
			}
		}
	}
	return sort[4];
}


void median::effect(RGBImage image) {

	int p_x, p_y;
	int count;
	int sort_r[9];
	int sort_g[9];
	int sort_b[9];

	for (int j = 1; j < size_y - 1; j++) {
		for (int i = 1; i < size_x - 1; i++) {

			count = 0;

			for (int m = -1; m < 2; m++) {
				for (int n = -1; n < 2; n++) {
					p_x = i + n;
					p_y = j + m;

					sort_r[count] = image.data[p_y][p_x].r;
					sort_g[count] = image.data[p_y][p_x].g;
					sort_b[count] = image.data[p_y][p_x].b;
					count++;

				}
			}



			data[j][i].red = median_sort(sort_r);
			data[j][i].green = median_sort(sort_g);
			data[j][i].blue = median_sort(sort_b);

		}
	}

}


//デストラクタ
median::~median() {
	for (int i = 0; i < size_y; i++) {
		delete[] data[i];
		data[i] = 0;
	}
	delete[] data;
	data = 0;
}



// RGBImageへ出力
void median::output_RGBImage(RGBImage *image_print)
{
	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			image_print->data[j][i].r = data[j][i].red;
			image_print->data[j][i].g = data[j][i].green;
			image_print->data[j][i].b = data[j][i].blue;
		}
	}
}