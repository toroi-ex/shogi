#pragma once
#include "ImageIO.h"
#include "color.h"

class gray {
public:
	int size_x;
	int size_y;
	struct color **image_data;
	struct color **data;
	struct color **data1;

	//コンストラクタ
	gray(RGBImage image);

	void gray_image();

	//RGBImageへ出力
	void output_RGBImage(RGBImage *image_print);

	//デストラクタ
	~gray();
};