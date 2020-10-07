#pragma once
#include "ImageIO.h"
#include "color.h"



//膨張クラス

class bloat {
public:
	int size_x;
	int size_y;
	//int size_x1;
	//int size_y1;
	
	int counter; //近傍の図形画素数
	int p_x, p_y; //近傍の座標
	struct color **data;	//みるやつ
	struct color **data1;	//いじるやつ

	//コンストラクタ
	bloat(RGBImage image);

	//膨張
	void dilation(int rep);


	//RGBImageへ出力
	void output_RGBImage(RGBImage *rgb_image);

	//デストラクタ
	~bloat();

};