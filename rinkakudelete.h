#pragma once
#include "ImageIO.h"
#include "color.h"

#define max 50000 //画素の最大値

class contour2 {
public:
	int size_x;
	int size_y;

	struct color **data;
	struct color **data1;

	int chain_code[max]; //チェインコード
	int offset[8][2] = { {1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1} }; //近傍画素との距離

	contour2(RGBImage image);

	int obtain_contour(int x_start, int y_start);//輪郭線に含まれる点の総数を返す

	void remove_areas(int meter); // 周囲長が指定した値より小さいやつを取り除

	void output_RGBImage(RGBImage *image_print);

	~contour2();
};