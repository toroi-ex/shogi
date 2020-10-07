#pragma once
#include "ImageIO.h"
#include "color.h"

class thinning {
public:
	int size_x;
	int size_y;
	int px;//近傍のx座標
	int py;//近傍もy座標
	int counter; //ラベルに変化が生じた画素の数
	struct color **data; //みるやつ
	struct color **data1; //いじるやつ

	thinning(RGBImage image);

	int func_nc8(int *b);

	void thin();

	void output_RGBImage(RGBImage *image_print);

	~thinning();
};