#pragma once
#include "color.h"
#include "ImageIO.h"

class sabun {
public:
	int size_x;//画像サイズ
	int size_y;//

	int size_x1;
	int size_y1;

	struct color **image_data;
	struct color **data;
	struct color **data1;

	sabun(RGBImage image, RGBImage image1);//コンストラクタ

	void sab();

	void output_RGBImage(RGBImage *image_print);

	~sabun();
};