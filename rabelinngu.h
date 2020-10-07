#pragma once

#include "ImageIO.h"
#include "color.h"

class labeling {
public:
	int size_x;
	int size_y;
	struct color **image_data;//画像データ 原画像
	struct color **data; //いじるやつ

	int **label_data;//ラベルづけされたデータ
	int **label_second;
	int label;//ラベル番号
	int look_up_table[5000];
	int count = 1;//背景が0のため
	int cnt = 0;
	labeling(RGBImage image);//コンストラクタ

	void modify(int num1, int num2);//ラベルの番号を詰める

	int search_4neighbors(int x, int y);//4近傍走査 ラベルの最大値を返す

	int labeling_kai();//探索して値を返していく方法

	int rabeling(); //ラベリング

	void recognition(int area1,double rat);

	void output_RGBImage(RGBImage *image_print);//出力

	~labeling();//デストラクタ


};