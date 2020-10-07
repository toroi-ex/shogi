#pragma once
#include "ImageIO.h"
#include "color.h"

class final2 {
public:
	int size_x;		//原画像サイズ
	int size_y;		//原画像サイズ
	int size_x1, size_y1;	//歩　テンプレート用の画像サイズ
	int size_x2, size_y2;	//柱　テンプレート用の画像サイズ
	int size_x3, size_y3;	//香　テンプレート用の画像サイズ
	int size_x4, size_y4;	//銀　テンプレート用の画像サイズ
	int size_x5, size_y5;	//金　テンプレート用の画像サイズ
	int size_x6, size_y6;	//飛車　テンプレート用の画像サイズ
	int size_x7, size_y7;	//角　テンプレート用の画像サイズ
	int size_x8, size_y8;	//王　テンプレート用の画像サイズ
	int size_ban_x, size_ban_y;	//盤

	int result_x, result_y;	//マッチングの結果 動く
	int result_x1, result_y1;	//動く後
	int n;						//２回目のマッチングの計算少なく　＋駒の区別

	struct color **data; //原画像 前の画像
	struct color **data_kai;	//原画像 後の画像
	struct color **data_op;		//作業するように格納するやつ
	//struct color **templete_data; //計算する用のやつ
	struct color **templete_data1; //歩テンプレート
	struct color **templete_data2; //柱テンプレート
	struct color **templete_data3; //香テンプレート
	struct color **templete_data4; //銀テンプレート
	struct color **templete_data5; //金テンプレート
	struct color **templete_data6; //飛車テンプレート
	struct color **templete_data7; //角テンプレート
	struct color **templete_data8; //王テンプレート

	int mas[81] = { 0, 1, 2, 3, 4, 5, 6, 7, 8,
					 9,10,11,12,13,14,15,16,17,
					18,19,20,21,22,23,24,25,26,
					27,28,29,30,31,32,33,34,35,
					36,37,38,39,40,41,42,43,44,
					45,46,47,48,49,50,51,52,53,
					54,55,56,57,58,59,60,61,62,
					63,64,65,66,67,68,69,70,71,
					72,73,74,75,76,77,78,79,80 };	//盤の位置

	final2(RGBImage image, RGBImage image_kai,RGBImage image_ras, RGBImage image1, RGBImage image2, RGBImage image3, RGBImage image4, RGBImage image5);

	//int SSD(int y,int x);

	//int SSD2(int y, int x);

	//int SSD3(int y, int x);

	int SAD1(int y, int x);	//歩

	int SAD2(int y, int x);	//柱

	int SAD3(int y, int x);	//香

	int SAD4(int y, int x);	//銀

	int SAD5(int y, int x);	//金

	int SAD6(int y, int x);	//飛車

	int SAD7(int y, int x);	//角

	int SAD8(int y, int x);	//王

	int specify(int point_x, int point_y);		//どこにあるか特定

	int white_detect(int y, int x, int size_y_tmp, int size_x_tmp);

	void do_match();	//マッチング

	void answer();	//あってるか判断

	int rasuta_xs;	//ラスタ走査して得られたx座標の一番左
	int rasuta_ys;	//ラスタ走査して得られたx座標の一番上
	int rasuta_xe;	//ラスタ走査して得られたx座標の一番右
	int rasuta_ye;	//ラスタ走査して得られたx座標の一番下
	//int board_size_x;	//盤のxサイズ
	//int board_size_y;	//盤のyサイズ

	struct color **data1;		//ラスタ走査用のやつ
	//struct color **data_ban;	//盤の画像を出力するやつ
	int size_x_ras;
	int size_y_ras;

	int l = 0;	//間違っているときに移動できる画像を表示するための変数
	int pre_koma_mis;	//間違っているときの駒の位置を記録して表示するのに使うやつ
	int xs, xe, ys, ye;	//１次的に保持するやつ
	int mis_size_xs;	//最終形態
	int mis_size_xe;	//最終形態
	int mis_size_ys;	//最終形態
	int mis_size_ye;	//最終形態

	void ras();	//ラスタ走査

	void ban(); //盤の画像を出力

	void sum_number();

	void output_RGBImage(RGBImage *image_print);

	~final2();

};