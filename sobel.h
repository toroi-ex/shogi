#pragma once
#include "ImageIO.h"
#include "color.h"

//ソーベルクラス

class sobel_image {
public:
	int size_x;
	int size_y;
	struct color **data;

	//コンストラクタ
	sobel_image(RGBImage image);

	//RGBImageへ出力
	void output_RGBImage(RGBImage *image_print);

	//デストラクタ
	~sobel_image();

};