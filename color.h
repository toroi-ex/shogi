#pragma once

#include "ImageIO.h"

//カラー画像のピクセルを表現する構造体
struct color {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

class color_image {
public:
	   struct color **image_data;//2次元配列を表現
	   int size_x;
	   int size_y; 
	   
	   color_image(RGBImage image);//コンストラクタ
	   ~color_image();//デストラクタ

	//void set_size_x(int index_size_x);//セッタ

	//void set_size_y(int index_size_y);//セッタ

	//int get_size_x();//ゲッタ

	//int get_size_y();//ゲッタ

	   int set_pixsel( struct color *value, int index_x, int index_y);//ピクセルの値をセット

	   void get_pixsel( int index_x, int index_y);//ピクセルを取得

	   void set_color(struct color *pixsel, unsigned char red_val, unsigned char green_val, unsigned char blue_val);//色の値をセット

};

//void set_color(struct color *pixsel, unsigned char blue_val, unsigned char green_val, unsigned char red_val);//色の値をセット