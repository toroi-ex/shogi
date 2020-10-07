#pragma once
#include "ImageIO.h"
#include "color.h"



class binarization {
public:
	struct color** imageData;
	int sizeX, sizeY;
	int t = 0;

	//コンストラクタの宣言
	binarization(RGBImage  image);

	//判別分析法による閾値決定
	int find_t();

	//2値化
	void binary();

	//デストラクタの宣言
	~binarization();

	//RGBImageへ出力
	void output_RGBImage(RGBImage* image_print);

};