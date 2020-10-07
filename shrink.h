#pragma once
#include "color.h"
#include "ImageIO.h"

class shrink {
public:
	int size_x;
	int size_y;
	int counter; //近傍の図形画素数
	int p_x, p_y; //近傍の座標
	struct color **data;	//みるやつ
	struct color **data1;	//いじるやつ
	
	//コンストラクタ
	shrink(RGBImage image);

	//収縮
	void erosion(int rep);

	//出力
	void output_RGBImage(RGBImage *image_print);

	//デストラクタ
	~shrink();
};