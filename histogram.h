#pragma once
#include "color.h"
#include "ImageIO.h"


class histogram {
public:
	int size_x;
	int size_y;
	long hist[256];//ヒストグラム用のデータ配列
	int size_x1; //ヒストグラム画像の横幅
	int size_y1; //ヒストグラム画像の立幅

	struct color **data;
	struct color **data1;//ヒストグラム用のやつ

	histogram(RGBImage image);

	void make_histogram();//ヒストグラム作成

	void make_image(int h);//画像に起こす

	void do_make(int h);

	void output_RGBImage(RGBImage *image_print);

	~histogram();

};