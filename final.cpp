#include "color.h"
#include "final.h"
#include "ImageIO.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define white 255
#define black 0

final::final(RGBImage image, RGBImage image_ras, RGBImage image1, RGBImage image2, RGBImage image3, RGBImage image4, RGBImage image5) : size_x(image.sizeX), size_y(image.sizeY),
size_x_ras(image_ras.sizeX), size_y_ras(image_ras.sizeY), size_x1(image1.sizeX), size_y1(image1.sizeY), size_x2(image2.sizeX), size_y2(image2.sizeY),
size_x3(image3.sizeX), size_y3(image3.sizeY), size_x4(image4.sizeX), size_y4(image4.sizeY), size_x5(image5.sizeX), size_y5(image5.sizeY) {

	data = new struct color*[size_y];  //
	for (int i = 0; i < size_y; i++) {
		data[i] = new struct color[size_x];
	}

	data_kai = new struct color*[size_y];  //白消すやーつと思ったが復元するやつ
	for (int i = 0; i < size_y; i++) {
		data_kai[i] = new struct color[size_x];
	}

	data1 = new struct color*[size_y_ras];  //ラスタ走査用の画像
	for (int i = 0; i < size_y_ras; i++) {
		data1[i] = new struct color[size_x_ras];
	}

	//data_ban = new struct color*[size_ban_y];  //盤出力用の画像
	//for (int i = 0; i < size_ban_y; i++) {
	//	data_ban[i] = new struct color[size_ban_x];
	//}

	templete_data1 = new struct color*[size_y1];  //テンプレート用　歩
	for (int i = 0; i < size_y1; i++) {
		templete_data1[i] = new struct color[size_x1];
	}

	templete_data2 = new struct color*[size_y2];  //テンプレート用　柱
	for (int i = 0; i < size_y2; i++) {
		templete_data2[i] = new struct color[size_x2];
	}

	templete_data3 = new struct color*[size_y3];  //テンプレート用　香
	for (int i = 0; i < size_y3; i++) {
		templete_data3[i] = new struct color[size_x3];
	}

	templete_data4 = new struct color*[size_y4];  //テンプレート用　銀
	for (int i = 0; i < size_y4; i++) {
		templete_data4[i] = new struct color[size_x4];
	}

	templete_data5 = new struct color*[size_y5];  //テンプレート用　金
	for (int i = 0; i < size_y5; i++) {
		templete_data5[i] = new struct color[size_x5];
	}

	//templete_data6 = new struct color*[size_y6];  //テンプレート用　飛車
	//for (int i = 0; i < size_y6; i++) {
	//	templete_data6[i] = new struct color[size_x6];
	//}

	//templete_data7 = new struct color*[size_y7];  //テンプレート用　角
	//for (int i = 0; i < size_y7; i++) {
	//	templete_data7[i] = new struct color[size_x7];
	//}

	//templete_data8 = new struct color*[size_y8];  //テンプレート用　王
	//for (int i = 0; i < size_y8; i++) {
	//	templete_data8[i] = new struct color[size_x8];
	//}

	for (int y = 0; y < size_y; y++) {						//
		for (int x = 0; x < size_x; x++) {
			data[y][x].red = image.data[y][x].r;
			data[y][x].green = image.data[y][x].g;
			data[y][x].blue = image.data[y][x].b;

		}
	}

	for (int y = 0; y < size_y; y++) {						//白消すやーつと思ったが復元するやつ
		for (int x = 0; x < size_x; x++) {
			data_kai[y][x].red = data[y][x].red;
			data_kai[y][x].green = data[y][x].green;
			data_kai[y][x].blue = data[y][x].blue;

		}
	}

	for (int y = 0; y < size_y_ras; y++) {					//ラスタ走査用
		for (int x = 0; x < size_x_ras; x++) {
			data1[y][x].red = image_ras.data[y][x].r;
			data1[y][x].green = image_ras.data[y][x].g;
			data1[y][x].blue = image_ras.data[y][x].b;
		}
	}

	//for (int y = 0; y < size_ban_y; y++) {					//盤用
	//	for (int x = 0; x < size_ban_x; x++) {
	//		data_ban[y][x].red = image_ban.data[y][x].r;
	//		data_ban[y][x].green = image_ban.data[y][x].g;
	//		data_ban[y][x].blue = image_ban.data[y][x].b;
	//	}
	//}

	for (int y = 0; y < size_y1; y++) {							//歩
		for (int x = 0; x < size_x1; x++) {
			templete_data1[y][x].red = image1.data[y][x].r;
			templete_data1[y][x].green = image1.data[y][x].g;
			templete_data1[y][x].blue = image1.data[y][x].b;
		}
	}
	for (int y = 0; y < size_y2; y++) {							//柱
		for (int x = 0; x < size_x2; x++) {
			templete_data2[y][x].red = image2.data[y][x].r;
			templete_data2[y][x].green = image2.data[y][x].g;
			templete_data2[y][x].blue = image2.data[y][x].b;
		}
	}
	for (int y = 0; y < size_y3; y++) {							//香
		for (int x = 0; x < size_x3; x++) {
			templete_data3[y][x].red = image3.data[y][x].r;
			templete_data3[y][x].green = image3.data[y][x].g;
			templete_data3[y][x].blue = image3.data[y][x].b;
		}
	}

	for (int y = 0; y < size_y4; y++) {						//銀
		for (int x = 0; x < size_x4; x++) {
			templete_data4[y][x].red = image4.data[y][x].r;
			templete_data4[y][x].green = image4.data[y][x].g;
			templete_data4[y][x].blue = image4.data[y][x].b;
		}
	}

	for (int y = 0; y < size_y5; y++) {						//金
		for (int x = 0; x < size_x5; x++) {
			templete_data5[y][x].red = image5.data[y][x].r;
			templete_data5[y][x].green = image5.data[y][x].g;
			templete_data5[y][x].blue = image5.data[y][x].b;
		}
	}

	/*for (int y = 0; y < size_y6; y++) {						//飛車
		for (int x = 0; x < size_x6; x++) {
			templete_data6[y][x].red = image6.data[y][x].r;
			templete_data6[y][x].green = image6.data[y][x].g;
			templete_data6[y][x].blue = image6.data[y][x].b;
		}
	}*/

	/*for (int y = 0; y < size_y7; y++) {						//角
		for (int x = 0; x < size_x7; x++) {
			templete_data7[y][x].red = image7.data[y][x].r;
			templete_data7[y][x].green = image7.data[y][x].g;
			templete_data7[y][x].blue = image7.data[y][x].b;
		}
	}*/

	/*for (int y = 0; y < size_y8; y++) {						//王
		for (int x = 0; x < size_x8; x++) {
			templete_data8[y][x].red = image8.data[y][x].r;
			templete_data8[y][x].green = image8.data[y][x].g;
			templete_data8[y][x].blue = image8.data[y][x].b;
		}
	}*/
}

//int final::SSD(int y,int x){
//
//	if (x + size_x1 - 1 < size_x && y + size_y1 - 1 < size_y) {
//		int ssd = 0;
//		for (int k = 0; k < size_y1; k++) {
//			for (int l = 0; l < size_x1; l++) {
//				int tmp = (int)(data[k+y][l+x].red - templete_data1[k][l].red);
//				ssd += tmp*tmp;//++の形にしてabsにするのも一考
//			}
//		}
//		return ssd;
//	}
//	else {
//		printf("size error ssd\n");
//		return 0;
//	}
//}
//
//int final::SSD2(int y, int x) {
//
//	if (x + size_x2 - 1 < size_x && y + size_y2 - 1 < size_y) {
//		int ssd = 0;
//		for (int k = 0; k < size_y2; k++) {
//			for (int l = 0; l < size_x2; l++) {
//				int tmp = (int)(data[k + y][l + x].red - templete_data2[k][l].red);
//				ssd += tmp * tmp;
//			}
//		}
//		return ssd;
//	}
//	else {
//		printf("size error ssd\n");
//		return 0;
//	}
//}
//
//int final::SSD3(int y, int x) {
//
//	if (x + size_x3 - 1 < size_x && y + size_y3 - 1 < size_y) {
//		int ssd = 0;
//		for (int k = 0; k < size_y3; k++) {
//			for (int l = 0; l < size_x3; l++) {
//				int tmp = (int)(data[k + y][l + x].red - templete_data3[k][l].red);
//				ssd += tmp * tmp;
//			}
//		}
//		return ssd;
//	}
//	else {
//		printf("size error ssd\n");
//		return 0;
//	}
//}

//歩
int final::SAD1(int y, int x) {

	if (x + size_x1 - 1 < size_x && y + size_y1 - 1 < size_y) {
		int ssd = 0;
		for (int k = 0; k < size_y1; k++) {
			for (int l = 0; l < size_x1; l++) {
				int tmp = (int)(data[k + y][l + x].red - templete_data1[k][l].red);
				if (tmp < 0) {
					tmp *= -1;
				}
				ssd += tmp;
			}
		}
		return ssd;
	}
	else {
		printf("size error ssd\n");
		return 0;
	}
}
//柱
int final::SAD2(int y, int x) {

	if (x + size_x2 - 1 < size_x && y + size_y2 - 1 < size_y) {
		int ssd = 0;
		for (int k = 0; k < size_y2; k++) {
			for (int l = 0; l < size_x2; l++) {
				int tmp = (int)(data[k + y][l + x].red - templete_data2[k][l].red);
				if (tmp < 0) {
					tmp *= -1;
				}
				ssd += tmp;
			}
		}
		return ssd;
	}
	else {
		printf("size error ssd\n");
		return 0;
	}
}
//香
int final::SAD3(int y, int x) {

	if (x + size_x3 - 1 < size_x && y + size_y3 - 1 < size_y) {
		int ssd = 0;
		for (int k = 0; k < size_y3; k++) {
			for (int l = 0; l < size_x3; l++) {
				int tmp = (int)(data[k + y][l + x].red - templete_data3[k][l].red);
				if (tmp < 0) {
					tmp *= -1;
				}
				ssd += tmp;
			}
		}
		return ssd;
	}
	else {
		printf("size error ssd\n");
		return 0;
	}
}

//銀
int final::SAD4(int y, int x) {

	if (x + size_x4 - 1 < size_x && y + size_y4 - 1 < size_y) {
		int ssd = 0;
		for (int k = 0; k < size_y4; k++) {
			for (int l = 0; l < size_x4; l++) {
				int tmp = (int)(data[k + y][l + x].red - templete_data4[k][l].red);
				if (tmp < 0) {
					tmp *= -1;
				}
				ssd += tmp;
			}
		}
		return ssd;
	}
	else {
		printf("size error ssd\n");
		return 0;
	}
}

//金
int final::SAD5(int y, int x) {

	if (x + size_x5 - 1 < size_x && y + size_y5 - 1 < size_y) {
		int ssd = 0;
		for (int k = 0; k < size_y5; k++) {
			for (int l = 0; l < size_x5; l++) {
				int tmp = (int)(data[k + y][l + x].red - templete_data5[k][l].red);
				if (tmp < 0) {
					tmp *= -1;
				}
				ssd += tmp;
			}
		}
		return ssd;
	}
	else {
		printf("size error ssd\n");
		return 0;
	}
}

//飛車
//int final::SAD6(int y, int x) {
//
//	if (x + size_x6 - 1 < size_x && y + size_y6 - 1 < size_y) {
//		int ssd = 0;
//		for (int k = 0; k < size_y6; k++) {
//			for (int l = 0; l < size_x6; l++) {
//				int tmp = (int)(data[k + y][l + x].red - templete_data6[k][l].red);
//				if (tmp < 0) {
//					tmp *= -1;
//				}
//				ssd += tmp;
//			}
//		}
//		return ssd;
//	}
//	else {
//		printf("size error ssd\n");
//		return 0;
//	}
//}

//角
//int final::SAD7(int y, int x) {
//
//	if (x + size_x7 - 1 < size_x && y + size_y7 - 1 < size_y) {
//		int ssd = 0;
//		for (int k = 0; k < size_y7; k++) {
//			for (int l = 0; l < size_x7; l++) {
//				int tmp = (int)(data[k + y][l + x].red - templete_data7[k][l].red);
//				if (tmp < 0) {
//					tmp *= -1;
//				}
//				ssd += tmp;
//			}
//		}
//		return ssd;
//	}
//	else {
//		printf("size error ssd\n");
//		return 0;
//	}
//}

//王
//int final::SAD8(int y, int x) {
//
//	if (x + size_x8 - 1 < size_x && y + size_y8 - 1 < size_y) {
//		int ssd = 0;
//		for (int k = 0; k < size_y8; k++) {
//			for (int l = 0; l < size_x8; l++) {
//				int tmp = (int)(data[k + y][l + x].red - templete_data8[k][l].red);
//				if (tmp < 0) {
//					tmp *= -1;
//				}
//				ssd += tmp;
//			}
//		}
//		return ssd;
//	}
//	else {
//		printf("size error ssd\n");
//		return 0;
//	}
//}

int final::white_detect(int y, int x, int size_y_tmp, int size_x_tmp) {
	int sum = 0;
	for (int i = y; i < y + size_y_tmp; i++) {
		for (int j = x; j < x + size_x_tmp; j++) {
			if (data[i][j].red == 255) {
				sum++;
			}
		}
	}
	return sum;
}

void final::do_match() {
	int max_x_hu = size_x - size_x1;
	int max_y_hu = size_y - size_y1;
	int max_x_kei = size_x - size_x2;
	int max_y_kei = size_y - size_y2;
	int max_x_kasya = size_x - size_x3;
	int max_y_kasya = size_y - size_y3;
	int max_x_gin = size_x - size_x4;
	int max_y_gin = size_y - size_y4;
	int max_x_kin = size_x - size_x5;
	int max_y_kin = size_y - size_y5;
	/*int max_x_hisya = size_x - size_x6;
	int max_y_hisya = size_y - size_y6;
	int max_x_kaku = size_x - size_x7;
	int max_y_kaku = size_y - size_y7;
	int max_x_ou = size_x - size_x8;
	int max_y_ou = size_y - size_y8;*/

	int result_hu = SAD1(0, 0);
	int result_kei = SAD2(0, 0);
	int result_kasya = SAD3(0, 0);
	int result_gin = SAD4(0, 0);
	int result_kin = SAD5(0, 0);
	//int result_hisya = SAD6(0, 0);
	//int result_kaku = SAD7(0, 0);
	//int result_ou = SAD8(0, 0);

	int result_x_hu = 0, result_y_hu = 0;	//歩のマッチングの座標　動いたあと
	int result_x_kei = 0, result_y_kei = 0;	//柱のマッチングの座標　動いたあと
	int result_x_ka = 0, result_y_ka = 0;	//香のマッチングの座標　動いたあと
	int result_x_gin = 0, result_y_gin = 0;	//銀のマッチング座標　動いたあと
	int result_x_kin = 0, result_y_kin = 0;	//金のマッチング座標　動いたあと
	//int result_x_hisya = 0, result_y_hisya = 0;	//飛車のマッチング座標　動いたあと
	//int result_x_kaku = 0, result_y_kaku = 0;	//角のマッチング座標　動いたあと
	//int result_x_ou = 0, result_y_ou = 0;	//王のマッチング座標　動いたあと
	int i, j;
	int out = 0;
	int white_sum;

	int sift_x = 0, sift_y = 0;
	double sift = 0.0, theta = 0.0;

	result_x = 0, result_y = 0;	//赤消したほう
	result_x1 = 0, result_y1 = 0;	//白消したほう	
	n = 0;	//二回目のマッチングの計算を少なくするため

	for (int y = 0; y < size_y; y++) {										//赤を黒塗り  先に動いたほうを検出
		for (int x = 0; x < size_x; x++) {
			if (data[y][x].red == white && data[y][x].green == black) {
				data[y][x].red = black;
				data[y][x].green = black;
				data[y][x].blue = black;
			}
		}
	}
	//歩
	for (i = 0; i < max_y_hu; i++) {
		for (j = 0; j < max_x_hu; j++) {
			if (white_sum = white_detect(i, j, size_y1, size_x1) > 300) {
				out = (int)SAD1(i, j);
				if (out < 0) {
					printf("error_white_hu\n");
					exit(1);
				}
				if (result_hu > out) {
					result_hu = out;
					result_x_hu = j;
					result_y_hu = i;
				}
			}
		}
	}
	printf("result_hu=%d x=%d y=%d\n", result_hu, result_x_hu, result_y_hu);

	//桂馬
	out = 0;
	white_sum = 0;
	for (i = 0; i < max_y_kei; i++) {
		for (j = 0; j < max_x_kei; j++) {
			if (white_sum = white_detect(i, j, size_y2, size_x2) > 300) {
				out = (int)SAD2(i, j);
				if (out < 0) {
					printf("error_white_kei\n");
					exit(1);
				}
				if (result_kei > out) {
					result_kei = out;
					result_x_kei = j;
					result_y_kei = i;
				}
			}
		}
	}
	printf("result_kei=%d x=%d y=%d\n", result_kei,result_x_kei,result_y_kei);

	//香車
	out = 0;
	white_sum = 0;
	for (i = 0; i < max_y_kasya; i++) {
		for (j = 0; j < max_x_kasya; j++) {
			if (white_sum = white_detect(i, j, size_y3, size_x3) > 300) {
				out = (int)SAD3(i, j);
				if (out < 0) {
					printf("error_white_kasya\n");
					exit(1);
				}
				if (result_kasya > out) {
					result_kasya = out;
					result_x_ka = j;
					result_y_ka = i;
				}
			}
		}
	}
	printf("result_ka=%d x=%d y=%d\n", result_kasya,result_x_ka, result_y_ka);

	//銀
	out = 0;
	white_sum = 0;
	for (i = 0; i < max_y_gin; i++) {
		for (j = 0; j < max_x_gin; j++) {
			if (white_sum = white_detect(i, j, size_y4, size_x4) > 300) {
				out = (int)SAD4(i, j);
				if (out < 0) {
					printf("error_white_gin\n");
					exit(1);
				}
				if (result_gin > out) {
					result_gin = out;
					result_x_gin = j;
					result_y_gin = i;
				}
			}
		}
	}
	printf("result_gin=%d x=%d y=%d\n", result_gin, result_x_gin, result_y_gin);

	//金
	out = 0;
	white_sum = 0;
	for (i = 0; i < max_y_kin; i++) {
		for (j = 0; j < max_x_kin; j++) {
			if (white_sum = white_detect(i, j, size_y5, size_x5) > 300) {
				out = (int)SAD5(i, j);
				if (out < 0) {
					printf("error_white_kin\n");
					exit(1);
				}
				if (result_kin > out) {
					result_kin = out;
					result_x_kin = j;
					result_y_kin = i;
				}
			}
		}
	}
	printf("result_kin=%d x=%d y=%d\n", result_kin, result_x_kin, result_y_kin);

	if (result_hu < result_kasya && result_hu < result_kei && result_hu < result_gin && result_hu < result_kin) {
		n = 1;
		result_x = result_x_hu;
		result_y = result_y_hu;
	}
	else if (result_kei < result_hu && result_kei < result_hu && result_kei < result_gin && result_kei < result_kin) {
		n = 2;
		result_x = result_x_kei;
		result_y = result_y_kei;
	}
	else if (result_kasya < result_hu && result_kasya < result_kei && result_kasya < result_gin && result_kasya < result_kin) {
		n = 3;
		result_x = result_x_ka;
		result_y = result_y_ka;
	}
	else if (result_gin < result_hu && result_gin < result_kei && result_gin < result_kasya && result_gin < result_kin) {
		n = 4;
		result_x = result_x_gin;
		result_y = result_y_gin;
	}
	else if (result_kin < result_hu && result_kin < result_kei && result_kin < result_kasya && result_kin < result_gin) {
		n = 5;
		result_x = result_x_kin;
		result_y = result_y_kin;
	}
	else {
		cout << "マッチングできませんでした" << endl;
	}

	//枠で囲う
	//printf("result=%d x=%d y=%d\n",result_hu,result_x,result_y);
	/*for (int i = result_y; i < result_y+size_y1; i++) {
		for (int j = result_x; j < result_x+size_x1; j++) {
			if (j == result_x || j == result_x + size_x1 || i == result_y || i == result_y + size_y1) {
				data[i][j].red = 255;
				data[i][j].green = 0;
				data[i][j].blue = 0;
			}
		}
	}*/

	//マッチングした座標を黒塗
	/*for (int y = result_y; y <= result_y + size_y1; y++) {
		for (int x = result_x; x <= result_x + size_x1; x++) {
			data[y][x].red = 0;
			data[y][x].green = 0;
			data[y][x].blue = 0;
		}
	}*/
	for (int y = 0; y < size_y; y++) {										//元の状態に戻す
		for (int x = 0; x < size_x; x++) {
			data[y][x].red = data_kai[y][x].red;
			data[y][x].green = data_kai[y][x].green;
			data[y][x].blue = data_kai[y][x].blue;
		}
	}

	for (int y = 0; y < size_y; y++) {										//白を黒塗り  動く前を検出
		for (int x = 0; x < size_x; x++) {
			if (data[y][x].red == white && data[y][x].green == white) {
				data[y][x].red = black;
				data[y][x].green = black;
				data[y][x].blue = black;
			}
		}
	}
	//歩
	if (n == 1) {
		result_hu = (int)SAD1(0, 0);
		out = 0;
		white_sum = 0;
		for (i = 0; i < max_y_hu; i++) {
			for (j = 0; j < max_x_hu; j++) {
				if (white_sum = white_detect(i, j, size_y1, size_x1) > 300) {
					out = (int)SAD1(i, j);
					if (out < 0) {
						printf("error_red_hu\n");
						exit(1);
					}
					if (result_hu > out) {
						result_hu = out;
						result_x1 = j;
						result_y1 = i;
					}
				}
			}
		}
		printf("result_hu=%d x=%d y=%d\n", result_hu, result_x1, result_y1);
	}

	//桂馬
	else if (n == 2) {
		result_kei = SAD2(0, 0);
		out = 0;
		white_sum = 0;
		for (i = 0; i < max_y_kei; i++) {
			for (j = 0; j < max_x_kei; j++) {
				if (white_sum = white_detect(i, j, size_y2, size_x2) > 300) {
					out = (int)SAD2(i, j);
					if (out < 0) {
						printf("error_red_kei\n");
						exit(1);
					}
					if (result_kei > out) {
						result_kei = out;
						result_x1 = j;
						result_y1 = i;
					}
				}
			}
		}
		printf("result_kei=%d x=%d y=%d\n", result_kei, result_x1, result_y1);
	}

	//香車
	else if (n == 3) {
		result_kasya = SAD3(0, 0);
		out = 0;
		white_sum = 0;
		for (i = 0; i < max_y_kasya; i++) {
			for (j = 0; j < max_x_kasya; j++) {
				if (white_sum = white_detect(i, j, size_y3, size_x3) > 300) {
					out = (int)SAD3(i, j);
					if (out < 0) {
						printf("error_red_kasya\n");
						exit(1);
					}
					if (result_kasya > out) {
						result_kasya = out;
						result_x1 = j;
						result_y1 = i;
					}
				}
			}
		}
		printf("result_ka=%d x=%d y=%d\n", result_kasya, result_x1, result_y1);
	}

	//銀
	else if (n == 4) {
		result_gin = SAD4(0, 0);
		out = 0;
		white_sum = 0;
		for (i = 0; i < max_y_gin; i++) {
			for (j = 0; j < max_x_gin; j++) {
				if (white_sum = white_detect(i, j, size_y4, size_x4) > 300) {
					out = (int)SAD4(i, j);
					if (out < 0) {
						printf("error_red_gin\n");
						exit(1);
					}
					if (result_gin > out) {
						result_gin = out;
						result_x1 = j;
						result_y1 = i;
					}
				}
			}
		}
		printf("result_gin=%d x=%d y=%d\n", result_gin, result_x1, result_y1);
	}

	//金
	else if (n == 5) {
		result_kin = SAD5(0, 0);
		out = 0;
		white_sum = 0;
		for (i = 0; i < max_y_kin; i++) {
			for (j = 0; j < max_x_kin; j++) {
				if (white_sum = white_detect(i, j, size_y5, size_x5) > 300) {
					out = (int)SAD5(i, j);
					if (out < 0) {
						printf("error_red_kin\n");
						exit(1);
					}
					if (result_kin > out) {
						result_kin = out;
						result_x1 = j;
						result_y1 = i;
					}
				}
			}
		}
		printf("result_kin=%d x=%d y=%d\n", result_kin, result_x1, result_y1);
	}

	//printf("x_pre=%d y_pre=%d x_aft=%d y_aft=%d\n", result_x1, result_y1, result_x, result_y);

	//角度と距離で答えだすやつ//
	/*sift_x = (result_x - result_x1)*(result_x - result_x1);
	sift_y = (result_y - result_y1)*(result_y - result_y1);
	sift = sqrt(sift_x + sift_y);
	theta = 90.0 - atan(sift_y / sift_x)*180.0 / 3.14;*/

	/*printf("x=%d y=%d sift=%lf theta=%lf\n result=%d result_x=%d result_y=%d result_x1=%d result_y1=%d", sift_x, sift_y, sift, theta, result_hu,
		result_x, result_y, result_x1, result_y1);*/
		/*if (theta < 10) {
			printf("あってます。\n");
		}*/

		/*printf("result=%d x=%d y=%d\n",result_hu,result_x1,result_y1);
		for (int i = 0; i < size_y; i++) {
			for (int j = 0; j < size_x; j++) {
				if (j == result_x1 || j == result_x1 + size_x1 || i == result_y1 || i == result_y1 + size_y1) {
					data[i][j].red = 255;
					data[i][j].green = 0;
					data[i][j].blue = 0;
				}
			}
		}*/
}


//正解判断
void final::answer() {
	int pre_koma = 0;
	int aft_koma = 0;
	int solve = 0;

	mis_size_xs = 0, mis_size_xe = 0, mis_size_ys = 0, mis_size_ye = 0;
	pre_koma_mis = 0;

	pre_koma = specify(result_x1, result_y1);	//前の駒の位置

	mis_size_xs = xs;	//ｘ左
	mis_size_xe = xe;	//ｘ右
	mis_size_ys = ys;	//ｙ上
	mis_size_ye = ye;	//ｙ下

	aft_koma = specify(result_x, result_y);	//後の駒の位置

	solve = pre_koma - aft_koma;

	printf("pre=%d aft=%d pre_koma-aft_koma=%d\n", pre_koma, aft_koma, solve);

	if (n == 1) {
		if (solve == 9) {
			printf("歩の動き合っています。\n");
		}
		else {
			printf("歩の動き間違っています。\n動ける場所を黒で表示するので確認して下さい。\n");
			l = 1;
		}
	}
	else if (n == 2) {
		if (solve == 17 || solve == 19) {
			printf("桂馬の動き合っています。");
		}
		else {
			printf("桂馬の動き間違っています。\n動ける場所を黒で表示するので確認して下さい。\n");
			l = 2;
		}
	}
	else if (n == 3) {
		if (solve == 9 || solve == 18 || solve == 27 || solve == 36 || solve == 45 || solve == 54 || solve == 63 || solve == 72) {
			printf("香車の動き合っています。");
		}
		else {
			printf("香車の動き間違っています。\n動ける場所を黒で表示するので確認して下さい。\n");
			l = 3;
		}
	}
	else if (n == 4) {
		if (solve == 9 || solve == 8 || solve == 10 || solve == -10 || solve == -8) {
			printf("銀の動き合っています。");
		}
		else {
			printf("銀の動き間違っています。\n動ける場所を黒で表示するので確認して下さい。\n");
			l = 4;
		}
	}
	else if (n == 5) {
		if (solve == 1 || solve == 9 || solve == 8 || solve == 10 || solve == -9 || solve == -1) {
			printf("金の動き合っています。");
		}
		else {
			printf("金の動き間違っています。\n動ける場所を黒で表示するので確認して下さい。\n");
			l = 5;
		}
	}
	pre_koma_mis = pre_koma;

}

//ラスタ走査
void final::ras() {
	int x, y;
	int out = 0;
	//rasuta_xs;	左
	//rasuta_ys;	上
	//rasuta_xe;	右
	//rasuta_ye;	下

	//普通のラスタ走査
	rasuta_xs = size_x_ras - 1;
	for (y = 0; y < size_y_ras; y++) {
		for (x = 0; x < size_x_ras; x++) {
			//if (x > 0 && x < 15) {
			if (data1[y][x].red == 0) {
				out = x;
				if (out > 0 && out < size_x_ras) {
					if (rasuta_xs > out) {
						rasuta_xs = out;
					}
				}
			}
			//}
			else {
				;
			}
		}
	}
	rasuta_xs = rasuta_xs + 5;
	printf("x_left=%d\n", rasuta_xs);

	//縦方向のラスタ走査
	rasuta_ys = size_y_ras - 1;
	out = 0;
	for (x = 0; x < size_x_ras; x++) {
		for (y = 0; y < size_y_ras; y++) {
			//if (y > 0 && y < 30) {
			if (data1[y][x].red == 0) {
				out = y;
				if (out > 0 && out < size_y_ras) {
					if (rasuta_ys > out) {
						rasuta_ys = out;
					}
				}
			}
			//}
			else {
				;
			}
		}
	}
	rasuta_ys = rasuta_ys + 5;
	printf("y_on=%d\n", rasuta_ys);

	//右からラスタ走査
	rasuta_xe = 0;
	out = 0;
	for (y = size_y_ras - 1; y > 0; y--) {
		for (x = size_x_ras - 1; x > 0; x--) {
			//if (x < size_x && x > size_x - 15) {
			if (data1[y][x].red == 0) {
				out = x;
				if (out > 0 && out < size_x_ras) {
					if (rasuta_xe < out) {
						rasuta_xe = out;
					}
				}
			}
			else {
				;
			}
			//}


		}
	}
	rasuta_xe = rasuta_xe - 5;
	printf("x_right=%d\n", rasuta_xe);

	//下からラスタ走査
	rasuta_ye = 0;
	out = 0;
	for (x = size_x_ras - 1; x > 0; x--) {
		for (y = size_y_ras - 1; y > 0; y--) {
			//if (y < size_y && y > size_y - 25) {
			if (data1[y][x].red == 0) {
				out = y;
				if (out > 0 && out < size_y_ras) {
					if (rasuta_ye < out) {
						rasuta_ye = out;
					}
				}
			}
			//}
			else {
				;
			}
		}
	}
	rasuta_ye = rasuta_ye - 15;
	printf("y_under=%d\n", rasuta_ye);
}

//駒の位置特定
int final::specify(int point_x, int point_y) {
	int a, b;	//ループ変数

	int size_xs = rasuta_xs;
	int size_xe = rasuta_xe;
	int size_ys = rasuta_ys;
	int size_ye = rasuta_ye;

	int board_x = rasuta_xe - rasuta_xs;	//盤のx幅
	int board_y = rasuta_ye - rasuta_ys;	//盤のy幅

	int point = 81;	//駒の位置

	//yがある値の時にxを見ていく
	for (a = 0; a < 9; a++) {
		if (point_y >= (int)(board_y*0.11*a + 0.5) + size_ys && point_y < (int)(board_y*0.11*(a + 1) + 0.5) + size_ys) {
			for (b = 0; b < 9; b++) {
				if (point_x >= (int)(board_x*0.11*b + 0.5) + size_xs && point_x < (int)(board_x*0.11*(b + 1) + 0.5) + size_xs) {
					point = mas[b + 9 * a];
					ys = (int)(board_y*0.11*a + 0.5) + size_ys;		//y上
					ye = (int)(board_y*0.11*(a + 1) + 0.5) + size_ys;	//y下
					xs = (int)(board_x*0.11*b + 0.5) + size_xs;		//x左
					xe = (int)(board_x*0.11*(b + 1) + 0.5) + size_xs;	//x右
				}
			}
		}
	}

	//全部に当てはまらなければ一番右下
	if (point == 81) {
		point = mas[81];
		ys = (int)(board_y*0.88 + 0.5) + size_ys;		//y上
		ye = size_ye - 1;	//y下
		xs = (int)(board_x*0.88 + 0.5) + size_xs;		//x左
		xe = size_xe - 1;	//x右
	}

	return point;
}

//盤作成
void final::ban() {

	int size_xt = rasuta_xe - rasuta_xs;	//盤のx幅
	int size_yt = rasuta_ye - rasuta_ys;	//盤のy幅

	int size_xs = rasuta_xs;	//x左
	int size_xe = rasuta_xe;	//x右
	int size_ys = rasuta_ys;	//y上
	int size_ye = rasuta_ye;	//y下

	int paint_size_xs = mis_size_xs;	//塗りつぶすx左
	int paint_size_xe = mis_size_xe;	//塗りつぶすx右
	int paint_size_ys = mis_size_ys;	//塗りつぶすy上
	int paint_size_ye = mis_size_ye;	//塗りつぶすy下

	int width_x = paint_size_xe - paint_size_xs;	//xの幅
	int width_y = paint_size_ye - paint_size_ys;	//yの幅

	int point_koma = pre_koma_mis;	//前の駒の位置

	//int mode = 0;

	for (int y = size_ys; y <= size_ye; y++) {
		for (int x = size_xs; x <= size_xe; x++) {
			if (y == size_ys || x == size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.11 + 0.5) + size_ys || x == (int)(size_xt * 0.11 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.22 + 0.5) + size_ys || x == (int)(size_xt * 0.22 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.33 + 0.5) + size_ys || x == (int)(size_xt * 0.33 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.44 + 0.5) + size_ys || x == (int)(size_xt * 0.44 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.55 + 0.5) + size_ys || x == (int)(size_xt * 0.55 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.66 + 0.5) + size_ys || x == (int)(size_xt * 0.66 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.77 + 0.5) + size_ys || x == (int)(size_xt * 0.77 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.88 + 0.5) + size_ys || x == (int)(size_xt * 0.88 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == size_ye - 1 || x == size_xe - 1) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else {
				data1[y][x].red = white;
				data1[y][x].green = white;
				data1[y][x].blue = white;
			}
		}
	}

	//歩が間違っているとき
	if (l == 1) {
		if (point_koma >= 0 && point_koma < 9) {		//歩の位置が一番前のときは進める位置がない
			printf("その位置だと動ける場所ないです。その駒動かすのあきらめてください\n");
		}
		else {
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
	}

	//柱が間違っているとき
	else if (l == 2) {
		if (point_koma >= 0 && point_koma < 18) {		//桂馬が前から一番目二番目のとき
			printf("その位置だと動ける場所ないです。その駒動かすのあきらめてください\n");
		}
		else if (point_koma == 18 || point_koma == 27 || point_koma == 36 || point_koma == 45 || point_koma == 54 || point_koma == 63 || point_koma == 72) {
			for (int y = paint_size_ys - 2 * width_y; y < paint_size_ys - width_y; y++) {		//桂馬が左端のとき
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma == 26 || point_koma == 35 || point_koma == 44 || point_koma == 53 || point_koma == 62 || point_koma == 71 || point_koma == 80) {
			for (int y = paint_size_ys - 2 * width_y; y < paint_size_ys - width_y; y++) {		//桂馬が右端のとき
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}

		}
		else {
			for (int y = paint_size_ys - 2 * width_y; y < paint_size_ys - width_y; y++) {
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - 2 * width_y; y < paint_size_ys - width_y; y++) {
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
	}

	//香が間違っているとき
	else if (l == 3) {
		if (point_koma >= 0 && point_koma < 9) {		//香車の位置が一番前のときは進める位置がない
			printf("その位置だと動ける場所ないです。その駒動かすのあきらめてください\n");
		}
		else {
			for (int k = 1; k < 9; k++) {
				if (point_koma >= 9 * k && point_koma < 9 * (k + 1)) {
					for (int y = paint_size_ys - k * width_y; y < paint_size_ys; y++) {
						for (int x = paint_size_xs; x < paint_size_xe; x++) {
							data1[y][x].red = black;
							data1[y][x].green = black;
							data1[y][x].blue = black;
						}
					}
				}
			}
		}
	}

	//銀が間違っているとき
	else if (l == 4) {
		if (point_koma > 0 && point_koma < 8) {		//銀の位置が一番前のとき　左端と右端を除く
			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//左下
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//右下
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma == 9 || point_koma == 18 || point_koma == 27 || point_koma == 36 || point_koma == 45 || point_koma == 54 || point_koma == 63) {
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//上					//銀の位置が左端のとき　後ろと前を除く
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//右上
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//右下
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma == 17 || point_koma == 26 || point_koma == 35 || point_koma == 44 || point_koma == 53 || point_koma == 62 || point_koma == 71) {
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//左上						//銀が一番右のとき　後ろと前を除く
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//上
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//左下
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma > 72 && point_koma < 80) {					//銀が一番後ろの時　左と右を除く
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//左上
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//上
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//右上
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma == 0) {															//銀が一番左前のとき
			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//右下
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma == 8) {															//銀が一番右前のとき
			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//左下
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma == 72) {										//銀が一番左後ろ
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//上
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//右上
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma == 80) {										//銀が一番右後ろ
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//上
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//左上
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else {
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//左上
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//上
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//右上
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//左下
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//右下
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
	}

	//金が間違っているとき
	else if (l == 5) {
		if (point_koma > 0 && point_koma < 8) {		//金の位置が一番前のとき　左端と右端を除く
			for (int y = paint_size_ys; y < paint_size_ye; y++) {					//左
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}

			for (int y = paint_size_ys; y < paint_size_ye; y++) {					//右
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//下
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma == 9 || point_koma == 18 || point_koma == 27 || point_koma == 36 || point_koma == 45 || point_koma == 54 || point_koma == 63) {
			//金の位置が左端のとき　後ろと前を除く
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//上
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//右上
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys; y < paint_size_ye; y++) {					//右
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//下
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma == 17 || point_koma == 26 || point_koma == 35 || point_koma == 44 || point_koma == 53 || point_koma == 62 || point_koma == 71) {
			//金が一番右のとき　後ろと前を除く
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {		//上
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//左上						
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys; y < paint_size_ye; y++) {					//左
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//下
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma > 72 && point_koma < 80) {					//銀が一番後ろの時　左と右を除く
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {		//上
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//左上						
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//右上
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys; y < paint_size_ye; y++) {					//左
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys; y < paint_size_ye; y++) {					//右
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma == 0) {					//金が一番左前のとき
			for (int y = paint_size_ys; y < paint_size_ye; y++) {					//右
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}

			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//下
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma == 8) {															//金が一番右前のとき

			for (int y = paint_size_ys; y < paint_size_ye; y++) {					//左
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}

			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//下
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma == 72) {										//金が一番左後ろ
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {		//上
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//右上
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys; y < paint_size_ye; y++) {					//右
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else if (point_koma == 80) {										//金が一番右後ろ
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {		//上
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//左上						
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys; y < paint_size_ye; y++) {					//左
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
		else {
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//上
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//左上						
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys - width_y; y < paint_size_ys; y++) {			//右上
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys; y < paint_size_ye; y++) {					//左
				for (int x = paint_size_xs - width_x; x < paint_size_xs; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ys; y < paint_size_ye; y++) {					//右
				for (int x = paint_size_xe; x < paint_size_xe + width_x; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
			for (int y = paint_size_ye; y < paint_size_ye + width_y; y++) {			//下
				for (int x = paint_size_xs; x < paint_size_xe; x++) {
					data1[y][x].red = black;
					data1[y][x].green = black;
					data1[y][x].blue = black;
				}
			}
		}
	}

	//線を引きなおす
	for (int y = size_ys; y <= size_ye; y++) {
		for (int x = size_xs; x <= size_xe; x++) {
			if (y == size_ys || x == size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.11 + 0.5) + size_ys || x == (int)(size_xt * 0.11 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.22 + 0.5) + size_ys || x == (int)(size_xt * 0.22 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.33 + 0.5) + size_ys || x == (int)(size_xt * 0.33 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.44 + 0.5) + size_ys || x == (int)(size_xt * 0.44 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.55 + 0.5) + size_ys || x == (int)(size_xt * 0.55 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.66 + 0.5) + size_ys || x == (int)(size_xt * 0.66 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.77 + 0.5) + size_ys || x == (int)(size_xt * 0.77 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == (int)(size_yt * 0.88 + 0.5) + size_ys || x == (int)(size_xt * 0.88 + 0.5) + size_xs) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
			else if (y == size_ye - 1 || x == size_xe - 1) {
				data1[y][x].red = white;
				data1[y][x].green = black;
				data1[y][x].blue = black;
			}
		}
	}
	//printf("xe=%d xs=%d ye=%d ys=%d widthx=%d widthy=%d\n", paint_size_xe, paint_size_xs, paint_size_ye, paint_size_ys, width_x, width_y);
}

void final::muri() {
	for (int y = 0; y < size_y; y++) {										//白を黒塗り  動く前を検出
		for (int x = 0; x < size_x; x++) {
			if (data[y][x].red == white && data[y][x].green == black) {
				data[y][x].red = black;
				data[y][x].green = black;
				data[y][x].blue = black;
			}
		}
	}
}

void final::sum_number() {

	int sumgetan = 0;

	for (int y = 0; y < size_y5; y++) {
		for (int x = 0; x < size_x5; x++) {
			if (templete_data5[y][x].red == 255) {
				sumgetan++;
			}
		}
	}
	printf("white_sum=%d\n", sumgetan);
}

void final::output_RGBImage(RGBImage *image_print) {

	/*int size_x_ban = rasuta_xe - rasuta_xs;
	int size_y_ban = rasuta_ye - rasuta_ys;*/

	//image_print->newImage(size_x_ban, size_y_ban);

	for (int i = rasuta_ys; i < rasuta_ye + 1; i++) {				//中身
		for (int j = rasuta_xs; j < rasuta_xe + 1; j++) {
			image_print->data[i][j].r = data1[i][j].red;
			image_print->data[i][j].g = data1[i][j].green;
			image_print->data[i][j].b = data1[i][j].blue;
		}
	}

	for (int y = 0; y < rasuta_ys; y++) {							//上の部分を白塗
		for (int x = 0; x < rasuta_xs; x++) {
			image_print->data[y][x].r = white;
			image_print->data[y][x].g = white;
			image_print->data[y][x].b = white;
		}
	}

	for (int y = rasuta_ye; y < size_y_ras; y++) {					//下の部分を白塗り
		for (int x = rasuta_xe; x < size_x_ras; x++) {
			image_print->data[y][x].r = white;
			image_print->data[y][x].g = white;
			image_print->data[y][x].b = white;
		}
	}

	for (int y = rasuta_ys; y < rasuta_ye; y++) {					//左を白塗り
		for (int x = 0; x < rasuta_xs; x++) {
			image_print->data[y][x].r = white;
			image_print->data[y][x].g = white;
			image_print->data[y][x].b = white;
		}
		for (int x = rasuta_xe; x < size_x_ras; x++) {				//右を白塗り
			image_print->data[y][x].r = white;
			image_print->data[y][x].g = white;
			image_print->data[y][x].b = white;
		}
	}
}

final:: ~final() {
	for (int i = 0; i < size_y; i++) {			//
		delete[] data[i];
		data[i] = 0;
	}
	delete[] data;
	data = 0;

	for (int i = 0; i < size_y; i++) {			//白消すやーつと思ったが復元するやつ
		delete[] data_kai[i];
		data_kai[i] = 0;
	}
	delete[] data_kai;
	data_kai = 0;

	for (int i = 0; i < size_y_ras; i++) {		//ラスタ走査用
		delete[] data1[i];
		data1[i] = 0;
	}
	delete[] data1;
	data1 = 0;

	//for (int i = 0; i < size_ban_y; i++) {		//盤用
	//	delete[] data_ban[i];
	//	data_ban[i] = 0;
	//}
	//delete[] data_ban;
	//data_ban = 0;

	for (int j = 0; j < size_y1; j++) {			//歩
		delete[] templete_data1[j];
		templete_data1[j] = 0;
	}
	delete[] templete_data1;
	templete_data1 = 0;

	for (int j = 0; j < size_y2; j++) {			//柱
		delete[] templete_data2[j];
		templete_data2[j] = 0;
	}
	delete[] templete_data2;
	templete_data2 = 0;

	for (int j = 0; j < size_y3; j++) {			//香
		delete[] templete_data3[j];
		templete_data3[j] = 0;
	}
	delete[] templete_data3;
	templete_data3 = 0;

	for (int j = 0; j < size_y4; j++) {		//銀
		delete[] templete_data4[j];
		templete_data4[j] = 0;
	}
	delete[] templete_data4;
	templete_data4 = 0;

	/*for (int j = 0; j < size_y5; j++) {		//金
		delete[] templete_data5[j];
		templete_data5[j] = 0;
	}
	delete[] templete_data5;
	templete_data5 = 0;*/

	/*for (int j = 0; j < size_y6; j++) {		//飛車
		delete[] templete_data6[j];
		templete_data6[j] = 0;
	}
	delete[] templete_data6;
	templete_data6 = 0;*/

	/*for (int j = 0; j < size_y7; j++) {		//角
		delete[] templete_data7[j];
		templete_data7[j] = 0;
	}
	delete[] templete_data7;
	templete_data7 = 0;*/

	/*for (int j = 0; j < size_y8; j++) {		//王
		delete[] templete_data8[j];
		templete_data3[j] = 0;
	}
	delete[] templete_data8;
	templete_data8 = 0;*/

}