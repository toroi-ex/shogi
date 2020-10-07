#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "ImageIO.h"
#include "gray.h"
#include <math.h>

#define R 1.25

//コンストラクタ
gray::gray(RGBImage image) : size_x(image.sizeX), size_y(image.sizeY)
{
	image_data = new struct color*[size_y];
	for (int i = 0; i < size_y; i++) {									  // ダブルポインタによる二次元配列の動的確保		
		image_data[i] = new struct color[size_x];
	}

	data = new struct color*[size_y];
	for (int i = 0; i < size_y; i++) {									  // ダブルポインタによる二次元配列の動的確保		
		data[i] = new struct color[size_x];
	}

	data1 = new struct color *[size_y];
	for (int i = 0; i < size_y; i++) {
		data1[i] = new struct color[size_x];
	}

	//ガンマ補正
	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
			data[i][j].red = (unsigned char)(255.0*pow(image.data[i][j].r/255.0,1/R));
			data[i][j].green = (unsigned char)(255.0*pow(image.data[i][j].g/255.0, 1/R));
			data[i][j].blue = (unsigned char)(255.0*pow(image.data[i][j].b/255.0, 1/R));
		}
	}

	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
			image_data[i][j].red = (unsigned char)(data[i][j].red * 0.3 + data[i][j].green *0.59 + data[i][j].blue * 0.11);
			image_data[i][j].green = (unsigned char)(data[i][j].red * 0.3 + data[i][j].green *0.59 + data[i][j].blue * 0.11);
			image_data[i][j].blue = (unsigned char)(data[i][j].red * 0.3 + data[i][j].green *0.59 + data[i][j].blue * 0.11);
		}
	}

	/*for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
			image_data[i][j].red = (unsigned char)(image.data[i][j].r * 0.3 + image.data[i][j].g *0.59 + image.data[i][j].b * 0.11);
			image_data[i][j].green = (unsigned char)(image.data[i][j].r * 0.3 + image.data[i][j].g *0.59 + image.data[i][j].b * 0.11);
			image_data[i][j].blue = (unsigned char)(image.data[i][j].r * 0.3 + image.data[i][j].g *0.59 + image.data[i][j].b * 0.11);
		}
	}*/

}
//逆ガンマ補正
void gray::gray_image() {

	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
			data1[i][j].red = (unsigned char)(255.0*pow(image_data[i][j].red / 255.0, R));
			data1[i][j].green = (unsigned char)(255.0*pow(image_data[i][j].green / 255.0, R));
			data1[i][j].blue = (unsigned char)(255.0*pow(image_data[i][j].blue / 255.0, R));
		}
	}
}

//デストラクタ
gray::~gray()
{
	for (int i = 0; i < size_y; i++) {
		delete[] image_data[i];
		image_data[i] = 0;
	}
	delete[] image_data;
	image_data = 0;

	for (int i = 0; i < size_y; i++) {
		delete[] data[i];
		data[i] = 0;
	}
	delete[] data;
	data = 0;

	for (int i = 0; i < size_y; i++) {
		delete[] data1[i];
		data1[i] = 0;
	}
	delete[] data1;
	data1 = 0;
}

//RGBImageへ出力
void gray::output_RGBImage(RGBImage* image_print)
{
	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
			image_print->data[i][j].r = image_data[i][j].red;
			image_print->data[i][j].g = image_data[i][j].green;
			image_print->data[i][j].b = image_data[i][j].blue;
		}
	}

	/*for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
			image_print->data[i][j].r = data1[i][j].red;
			image_print->data[i][j].g = data1[i][j].green;
			image_print->data[i][j].b = data1[i][j].blue;
		}
	}*/
}