#include "binaryhanbetu.h"
#include "color.h"
#include "ImageIO.h"

#include <iostream>


//コンストラクタ
binarization::binarization(RGBImage image) : sizeX(image.sizeX), sizeY(image.sizeY)
{
	imageData = new struct color*[sizeY];
	for (int i = 0; i < sizeY; i++) {									  // ダブルポインタによる二次元配列の動的確保		
		imageData[i] = new struct color[sizeX];
	}

	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			imageData[i][j].red = image.data[i][j].r;
			imageData[i][j].green = image.data[i][j].g;
			imageData[i][j].blue = image.data[i][j].b;
		}
	}
}

int binarization::find_t() {

	double sb2_max = 0;
	for (int t_num = 0; t_num < 255; t_num++) {
		double sb2 = 0;
		double w0 = 0, w1 = 0, m0 = 0, m1 = 0;
		int class0 = 0, sum0 = 0, ave0 = 0;
		int class1 = 0, sum1 = 0, ave1 = 0;

		for (int i = 0; i < sizeY; i++) {
			for (int j = 0; j < sizeX; j++) {
				if (imageData[i][j].red < t_num) {
					sum0 = sum0 + imageData[i][j].red;
					class0++;
				}
				else {
					sum1 = sum1 + imageData[i][j].red;
					class1++;
				}
			}
		}

		w0 = class0 / (double)65025;
		w1 = class1 / (double)65025;

		if (class0 == 0) {
			m0 = 0;
		}
		else {
			m0 = sum0 / class0;
		}
		if (class1 == 0) {
			m1 = 0;
		}
		else {
			m1 = sum1 / class1;
		}
		sb2 = w0 * w1 * (m0 - m1) * (m0 - m1);
		if (sb2 > sb2_max) {
			sb2_max = sb2;
			t = t_num;
		}
	}

	return t;
}

void binarization::binary()
{
	for (int i = 0; i < sizeY; i++) {
		for (int j = 1; j < sizeX; j++) {
			if (imageData[i][j].red < t) {      //閾値判断
				imageData[i][j].red = 0;     //     
				imageData[i][j].green = 0;   //黒にする
				imageData[i][j].blue = 0;    //
			}
			else {
				imageData[i][j].red = 255;     //     
				imageData[i][j].green = 255;   //白にする
				imageData[i][j].blue = 255;    //
			}
		}
	}
}

//デストラクタ
binarization::~binarization()
{
	for (int i = 0; i < sizeY; i++) {
		delete[] imageData[i];
		imageData[i] = 0;
	}
	delete[] imageData;
	imageData = 0;
}

//RGBImageへ出力
void binarization::output_RGBImage(RGBImage* image_print)
{
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			image_print->data[i][j].r = imageData[i][j].red;
			image_print->data[i][j].g = imageData[i][j].green;
			image_print->data[i][j].b = imageData[i][j].blue;
		}
	}
}