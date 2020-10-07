#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "nitika.h"
#include "ImageIO.h"

#define black 0
#define white 255
#define gray 40//閾値

binary::binary(RGBImage image) :size_x(image.sizeX), size_y(image.sizeY) {//2次元配列
	image_data = new struct color *[size_y];
	for (int i = 0; i < size_y; i++) {
		image_data[i] = new struct color[size_x];
	}
	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			if (image.data[j][i].r < gray) {//色の三原色を信じた
				image_data[j][i].red = black;
				image_data[j][i].blue = black;
				image_data[j][i].green = black;
			}
			else {
				image_data[j][i].red = white;
				image_data[j][i].blue = white;
				image_data[j][i].green = white;
			}
		}

	}
}

binary::~binary() {
	for (int i = 0; i < size_y; i++) {
		delete[] image_data[i];
		image_data[i] = 0;
	}
	delete[] image_data;
	image_data = 0;
}

void binary::output_RGBImage(RGBImage *image_print) {
	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			image_print->data[j][i].r = image_data[j][i].red;//RGBImageにさっき求めたデータ配列を格納
			image_print->data[j][i].b = image_data[j][i].blue;//
			image_print->data[j][i].g = image_data[j][i].green;//
		}

	}
}