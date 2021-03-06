#pragma once
#include "ImageIO.h"
#include "color.h"

class contour {
public:
	int size_x;
	int size_y;

	struct color **data;  //みるやつ
	struct color **data1; //いじるやつ

	contour(RGBImage image);

	void rinkaku(float amp); //ampは利得 どれだけ輪郭を濃くするか

	void output_RGBImage(RGBImage *image_print);

	~contour();
};