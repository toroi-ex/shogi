#pragma once
#include "ImageIO.h"
#include "color.h"
#include<iostream>

using namespace std;


//メディアンクラス

class median {
public:
	int size_x;
	int size_y;

	struct color **data;


	//コンストラクタ
	median(RGBImage image);

	//デストラクタ
	~median();

	void effect(RGBImage image);

	int median_sort(int sort[9]);


	//RGBImageへ出力
	void output_RGBImage(RGBImage *image_print);

private:

};