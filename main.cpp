#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "ImageIO.h"
#include "sabunn.h"
#include "nitika.h"
#include "color.h"
#include "rabelinngu.h"
#include "gray.h"
#include "shrink.h"
#include "bloat.h"
#include "sobel.h"
#include "smoothing.h"
#include "binaryhanbetu.h"
#include "thinning.h"
#include "rinkaku.h"
#include "rinkakudelete.h"
#include "median.h"
#include "matching.h"
#include "histogram.h"
#include "rasuta.h"
#include "final2.h"

using namespace std;

int main(void)
{
	//struct color color;
	RGBImage image, image1, image2, image3, image4, image5, image6, image7, image8, image9, image10, image11, image12, image13, image14; // 画像を保持するための変数
	RGBImage image15, image16, image17, image18, image19, image20, image21, image22, image23, image24,image25;  //テンプレート用の画像
	//color_image color_image(image6);                     
	BitmapReader bmpReader;										// Bitmapファイルを読み込むための変数

	//string inputFilename = "C:\\Users\\toui\\Desktop\\crin_final\\gray_hu_kei_ka_hu_true.bmp";	// ２値化
	//string inputFilename1 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\rinkaku_delete_gin_t.bmp";				//ラベリング
	//string inputFilename2 = "C:\\Users\\toui\\Desktop\\clanguage\\sobel.bmp";						//ソーベル
	//string inputFilename3 = "C:\\Users\\toui\\Desktop\\clanguage\\nitika_koma.bmp";				//膨張
	//string inputFilename4 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\shrink_koma.bmp";				//収縮
	//string inputFilename5 = "C:\\Users\\toui\\Desktop\\crin_final++\\ban_ori.bmp";				//グレイ
	//string inputFilename6 = "C:\\Users\\toui\\Desktop\\clanguage\\gray_rena.bmp";					//平滑化
	//string inputFilename7 = "C:\\Users\\toui\\Desktop\\clanguage\\bloat.bmp";						//細線化
	//string inputFilename8 = "C:\\Users\\toui\\Desktop\\clanguage\\pyama_thinning2.bmp";			//境界線追跡
	//string inputFilename9 = "C:\\Users\\toui\\Desktop\\crin_final\\sabun_kei_true.bmp";			//境界線追跡除去
	//string inputFilename10 = "C:\\Users\\toui\\Desktop\\clanguage\\nitika.bmp";					//メディアんフィルタ
	//string inputFilename11 = "C:\\Users\\toui\\Desktop\\clanguage\\gray_rena.bmp";				//ヒストグラム
	//string inputFilename12 = "C:\\Users\\toui\\Desktop\\crin_final\\gray_hu_kei_ka_ori.bmp";		//差分
	//string inputFilename13 = "C:\\Users\\toui\\Desktop\\crin_final\\gray_hu_kei_ka_ka_true.bmp";	//差分
	//string inputFilename14 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\nitika_ban.bmp";			//ラスタ走査
	//string inputFilename15 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\rinkaku_delete_hu_t.bmp";	//テンプレート
	//string inputFilename16 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\hu_tmp_kai.bmp";			//歩　テンプレート
	//string inputFilename17 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\kei_tmp_kai.bmp";			//柱　テンプレート用の画像
	//string inputFilename18 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\ka_tmp_kai.bmp";			//香　テンプレート用の画像
	//string inputFilename19 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\gin_tmp_kai.bmp";			//銀　テンプレート用の画像
	//string inputFilename20 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\kin_tmp_kai.bmp";			//金　テンプレート用の画像
	//string inputFilename24 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\ban_present.bmp";			//盤を表示したいやつ
	//string inputFilename21 = "C:\\Users\\toui\\Desktop\\clanguage\\nitika_koma_hisya.bmp";		//飛車　テンプレート用の画像
	//string inputFilename22 = "C:\\Users\\toui\\Desktop\\clanguage\\nitika_koma_kasya.bmp";		//角　テンプレート用の画像
	//string inputFilename23 = "C:\\Users\\toui\\Desktop\\clanguage\\nitika_koma_kasya.bmp";		//王　テンプレート用の画像

	//bmpReader.read(inputFilename, &image);     //２値化
	//bmpReader.read(inputFilename1, &image1);   //ラベリング
	//bmpReader.read(inputFilename2, &image2);   //
	//bmpReader.read(inputFilename3, &image3);   //膨張　収縮
	//bmpReader.read(inputFilename4, &image4);     //収縮
	//bmpReader.read(inputFilename5, &image5);   //グレイ
	//bmpReader.read(inputFilename6, &image6);   //平滑化
	//bmpReader.read(inputFilename7, &image7);     //細線化
	//bmpReader.read(inputFilename8, &image8);     //境界線追跡
	//bmpReader.read(inputFilename9, &image9);     //境界線追跡除去
	//bmpReader.read(inputFilename10, &image10);  //メディアンフィルタ
	//bmpReader.read(inputFilename11, &image11);  //ヒストグラム
	//bmpReader.read(inputFilename12, &image12);	//差分
	//bmpReader.read(inputFilename13, &image13);	//差分
	//bmpReader.read(inputFilename14, &image14);	//ラスタ
	//bmpReader.read(inputFilename15, &image15);	//テンプレートマッチング
	//bmpReader.read(inputFilename16, &image16);	//歩　テンプレート
	//bmpReader.read(inputFilename17, &image17);	//柱　テンプレート
	//bmpReader.read(inputFilename18, &image18);	//香　テンプレート
	//bmpReader.read(inputFilename19, &image19);	//銀　テンプレート
	//bmpReader.read(inputFilename20, &image20);	//金　テンプレート
	//bmpReader.read(inputFilename24, &image24);	//盤
	//bmpReader.read(inputFilename21, &image21);	//飛車　テンプレート
	//bmpReader.read(inputFilename22, &image22);	//角　テンプレート
	//bmpReader.read(inputFilename23, &image23);	//王　テンプレート

	BitmapWriter bmpWriter;                 // Bitmapファイルを書き込むための変数

	//２値化
	//string inputFilename = "C:\\Users\\toui\\Desktop\\crin_final_kai\\zoku\\gray_gin_m3.bmp";	// ２値化
	//bmpReader.read(inputFilename, &image);     //２値化
	//binary binary(image);
	//binary.output_RGBImage(&image);
	//string outputfilename = "C:\\Users\\toui\\Desktop\\crin_final_kai\\zoku\\nitika_gin.bmp";
	//bmpWriter.write(outputfilename, &image);	

	//判別分析法
	/*binarization binarization(image3);
	binarization.find_t();
	binarization.binary();
	binarization.output_RGBImage(&image3);
	string outputfilename7 = "hanbetu.bmp";
	bmpWriter.write(outputfilename7, &image3);*/

	//ラベリング
	//labeling labeling(image1);
	////labeling.rabeling();
	//labeling.recognition(1000,0.8);
	//labeling.output_RGBImage(&image1);
	//string outputfilename2 = "c:\\users\\toui\\desktop\\crin_final_kai\\labeling_h.bmp";
	//bmpWriter.write(outputfilename2, &image1);

	//グレースケール
	//string inputFilename5 = "C:\\Users\\toui\\Desktop\\crin_final++\\zoku\\ban_ori.bmp";  //グレイ
	//bmpReader.read(inputFilename5, &image5);   //グレイ
	//gray gray(image5);
	//gray.gray_image();
	//gray.output_RGBImage(&image5);
	//string outputFilename5 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\zoku\\gray_ban_ori_g.bmp";
	//bmpWriter.write(outputFilename5, &image5);

	//膨張
	/*bloat bloat(image4);
	bloat.dilation(2);
	bloat.output_RGBImage(&image4);
	string outputFilename3 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\shrink_koma_b.bmp";
	bmpWriter.write(outputFilename3, &image4);*/

	//収縮
	/*shrink shrink(image4);
	shrink.erosion(1);
	shrink.output_RGBImage(&image4);
	string outputFilename4 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\shrink_koma.bmp";
	bmpWriter.write(outputFilename4, &image4);*/

	//そーベル
	//sobel_image sobel_image(image1);
	//sobel_image.output_RGBImage(&image1);

	//平滑化
	/*smoothing smoothing(image6);
	smoothing.output_RGBImage(&image6);
	string outputFilename6 = "C:\\Users\\toui\\Desktop\\clanguage\\smoothing.bmp";
	bmpWriter.write(outputFilename6, &image6);*/

	//細線化
	/*thinning thinning(image7);
	thinning.thin();
	thinning.output_RGBImage(&image7);
	string outputFilename7 = "C:\\Users\\toui\\Desktop\\clanguage\\thinning_koma.bmp";
	bmpWriter.write(outputFilename7, &image7);*/

	//境界線追跡
	/*contour contour(image8);
	contour.rinkaku(2.5);
	contour.output_RGBImage(&image8);
	string outputFilename8 = "C:\\Users\\toui\\Desktop\\clanguage\\rinkaku_p.bmp";
	bmpWriter.write(outputFilename8, &image8);*/

	//境界線追跡除去
	//string inputFilename9 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\sabun_gin_m2.bmp";
	//bmpReader.read(inputFilename9, &image9);     
	//contour2 contour2(image9);
	//contour2.remove_areas(100);	//歩170 桂15 香120 　　3つの時　歩170 柱70 香100  2回目にとった写真 歩170 柱100 香100 銀100 金100
	//contour2.output_RGBImage(&image9);
	//string outputFilename9 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\rinkaku_delete_ginM2.bmp";
	//bmpWriter.write(outputFilename9, &image9);

	//メディアンフィルタ
	/*median median(image10);
	median.effect(image10);
	median.output_RGBImage(&image10);
	string outputFilename10 = "C:\\Users\\toui\\Desktop\\clanguage\\median.bmp";
	bmpWriter.write(outputFilename10, &image10);*/

	//ヒストグラム
	//histogram histogram(image11);
	///*histogram.make_histogram();
	//histogram.make_image();*/
	//histogram.do_make(256);
	//histogram.output_RGBImage(&image11);
	//string outputFilename11 = "C:\\Users\\toui\\Desktop\\clanguage\\histogram.bmp";
	//bmpWriter.write(outputFilename11, &image11);

	//差分  色を変える範囲は適宜求めるしかないか
	//string inputFilename12 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\zoku\\gray_kin_m1.bmp";	//差分
	//string inputFilename13 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\zoku\\gray_ban_hu_m.bmp";	//差分
	//bmpReader.read(inputFilename12, &image12);	//差分
	//bmpReader.read(inputFilename13, &image13);	//差分
	//sabun sabun(image12, image13);
	//sabun.sab();
	//sabun.output_RGBImage(&image12);
	///*string outputFilename12 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\sabun_kin_m1.bmp";
	//bmpWriter.write(outputFilename12, &image12);*/

	////string inputFilename9 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\sabun_gin_m2.bmp";
	////bmpReader.read(inputFilename9, &image9);     
	//contour2 contour2(image12);
	//contour2.remove_areas(100);	//歩170 桂15 香120 　　3つの時　歩170 柱70 香100  2回目にとった写真 歩170 柱100 香100 銀100 金100
	//contour2.output_RGBImage(&image12);
	//string outputFilename9 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\zoku\\sabun\\rinkaku_delete_ban_hu_m.bmp";
	//bmpWriter.write(outputFilename9, &image12);

	//ラスタ
	/*rasuta rasuta(image14);
	rasuta.ras();
	rasuta.ban();
	rasuta.output_RGBImage(&image14);
	string outputFilename13 = "C:\\Users\\toui\\Desktop\\crin_final\\rasuta_ban.bmp";
	bmpWriter.write(outputFilename13, &image14);*/

	//テンプレートマッチング
	/*matching matching(image11,image12,image13,image14);
	matching.do_match();
	matching.output_RGBImage(&image11);
	string outputFilename14 = "C:\\Users\\toui\\Desktop\\crin_final\\hu_mis_tmp.bmp";
	bmpWriter.write(outputFilename14, &image14);*/

	//テンプレートからまとめた
	//string inputFilename14 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\nitika_ban.bmp";			//ラスタ走査
	//string inputFilename15 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\sabun\\rinkaku_delete_gin_ori_ban.bmp";	//テンプレート
 //   string inputFilename25 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\sabun\\rinkaku_delete_gin_ban.bmp";
	//string inputFilename16 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\hu_tmp_2.bmp";			//歩　テンプレート
	//string inputFilename17 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\kei_tmp_2.bmp";			//柱　テンプレート用の画像
	//string inputFilename18 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\ka_tmp_2.bmp";			//香　テンプレート用の画像
	//string inputFilename19 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\gin_tmp_2.bmp";			//銀　テンプレート用の画像
	//string inputFilename20 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\kin_tmp_kai.bmp";			//金　テンプレート用の画像
	////string inputFilename24 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\ban_present.bmp";			//盤を表示したいやつ

	//bmpReader.read(inputFilename14, &image14);	//ラスタ
	//bmpReader.read(inputFilename15, &image15);	//テンプレートマッチング
	//bmpReader.read(inputFilename25, &image25);
	//bmpReader.read(inputFilename16, &image16);	//歩　テンプレート
	//bmpReader.read(inputFilename17, &image17);	//柱　テンプレート
	//bmpReader.read(inputFilename18, &image18);	//香　テンプレート
	//bmpReader.read(inputFilename19, &image19);	//銀　テンプレート
	//bmpReader.read(inputFilename20, &image20);	//金　テンプレート
	////bmpReader.read(inputFilename24, &image24);	//盤

	//final final(image15, image14, image16, image17, image18, image19, image20);
	////final.sum_number();
	//final.ras();
	//final.do_match();
	//final.answer();
	//final.ban();
	////final.muri();
	//final.output_RGBImage(&image14);
	//string outputFilename15 = "C:\\Users\\toui\\Desktop\\crin_real_final\\sabun\\correct_gin_ban.bmp";
	//bmpWriter.write(outputFilename15, &image14);

	//final2 final2(image15, image25, image14, image16, image17, image18, image19, image20);
	////final.sum_number();
	//final2.ras();
	//final2.do_match();
	//final2.answer();
	//final2.ban();
	////final.muri();
	//final2.output_RGBImage(&image14);
	//string outputFilename15 = "C:\\Users\\toui\\Desktop\\crin_real_final\\sabun\\correct_gin_ban.bmp";
	//bmpWriter.write(outputFilename15, &image14);

	//RGBType pixelValue;											// ピクセル値を保持するための変数
	//pixelValue = image.data[20][10];							// X : 10, Y : 20の位置のピクセル値(RGBType型)を取り出す

	//image.data[10][20].setElement(255, 100, 0);					// X : 20, Y : 10の位置のピクセル値にr : 255, g : 100, b : 0をセット

	return 0;
}