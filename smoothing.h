#pragma once
#include "ImageIO.h"
#include "color.h"
#include<iostream>

using namespace std;


//平滑化クラス

class smoothing {
public:
	int size_x;
	int size_y;
	struct color **data;

	//コンストラクタ
	smoothing(RGBImage image);

	//デストラクタ
	~smoothing();

	//RGBImageへ出力
	void output_RGBImage(RGBImage *rgb_image);

};