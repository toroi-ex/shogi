#include "color.h"
#include "matching.h"
#include "ImageIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
matching::matching(RGBImage image, RGBImage image1,RGBImage image2,RGBImage image3) :size_x(image.sizeX), size_y(image.sizeY), size_x1(image1.sizeX), size_y1(image1.sizeY) 
, size_x2(image2.sizeX), size_y2(image2.sizeY), size_x3(image3.sizeX), size_y3(image3.sizeY){

	data = new struct color*[size_y];  //動的確保
	for (int i = 0; i < size_y; i++) {
		data[i] = new struct color[size_x];
	}

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

	//templete_data4 = new struct color*[size_y4];  //テンプレート用　銀
	//for (int i = 0; i < size_y4; i++) {
	//	templete_data4[i] = new struct color[size_x4];
	//}

	//templete_data5 = new struct color*[size_y5];  //テンプレート用　金
	//for (int i = 0; i < size_y5; i++) {
	//	templete_data5[i] = new struct color[size_x5];
	//}

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

	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data[y][x].red = image.data[y][x].r;
			data[y][x].green = image.data[y][x].g;
			data[y][x].blue = image.data[y][x].b;

		}
	}

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

	/*for (int y = 0; y < size_y4; y++) {						//銀
		for (int x = 0; x < size_x4; x++) {
			templete_data4[y][x].red = image4.data[y][x].r;
			templete_data4[y][x].green = image4.data[y][x].g;
			templete_data4[y][x].blue = image4.data[y][x].b;
		}
	}*/

	/*for (int y = 0; y < size_y5; y++) {						//金
		for (int x = 0; x < size_x5; x++) {
			templete_data5[y][x].red = image5.data[y][x].r;
			templete_data5[y][x].green = image5.data[y][x].g;
			templete_data5[y][x].blue = image5.data[y][x].b;
		}
	}*/

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

//int matching::SSD(int y,int x){
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
//int matching::SSD2(int y, int x) {
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
//int matching::SSD3(int y, int x) {
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
int matching::SAD1(int y, int x) {

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
int matching::SAD2(int y, int x) {

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
int matching::SAD3(int y, int x) {

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
//int matching::SAD4(int y, int x) {
//
//	if (x + size_x4 - 1 < size_x && y + size_y4 - 1 < size_y) {
//		int ssd = 0;
//		for (int k = 0; k < size_y4; k++) {
//			for (int l = 0; l < size_x4; l++) {
//				int tmp = (int)(data[k + y][l + x].red - templete_data4[k][l].red);
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

//金
//int matching::SAD5(int y, int x) {
//
//	if (x + size_x5 - 1 < size_x && y + size_y5 - 1 < size_y) {
//		int ssd = 0;
//		for (int k = 0; k < size_y5; k++) {
//			for (int l = 0; l < size_x5; l++) {
//				int tmp = (int)(data[k + y][l + x].red - templete_data5[k][l].red);
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

//飛車
//int matching::SAD6(int y, int x) {
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
//int matching::SAD7(int y, int x) {
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
//int matching::SAD8(int y, int x) {
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

void matching::do_match() {
	int max_x_hu = size_x - size_x1;
	int max_y_hu = size_y - size_y1;
	int max_x_kei = size_x - size_x2;
	int max_y_kei = size_y - size_y2;
	int max_x_kasya = size_x - size_x3;
	int max_y_kasya = size_y - size_y3;
	/*int max_x_gin = size_x - size_x4;
	int max_y_gin = size_y - size_y4;
	int max_x_kin = size_x - size_x5;
	int max_y_kin = size_y - size_y5;
	int max_x_hisya = size_x - size_x6;
	int max_y_hisya = size_y - size_y6;
	int max_x_kaku = size_x - size_x7;
	int max_y_kaku = size_y - size_y7;
	int max_x_ou = size_x - size_x8;
	int max_y_ou = size_y - size_y8;*/

	int result_hu = SAD1(0, 0);
	//int result_kei = SAD2(0, 0);
	//int result_kasya = SAD3(0, 0);
	//int result_gin = SAD4(0, 0);
	//int result_kin = SAD5(0, 0);
	//int result_hisya = SAD6(0, 0);
	//int result_kaku = SAD7(0, 0);
	//int result_ou = SAD8(0, 0);

	int result_x1 = 0, result_y1 = 0;
	int i, j;
	int out=0;
	int sift_x = 0, sift_y = 0;
	double sift=0.0, theta = 0.0;

	result_x = 0, result_y = 0;

	for (i = 0; i < max_y_hu; i++) {
		for (j = 0; j < max_x_hu; j++) {
			out = (int)SAD1(i, j);
			if (out < 0) {
				printf("error\n");
				exit(1);
			}
			if (result_hu > out) {
				result_hu = out;
				result_x = j;
				result_y = i;
			}
		}
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
	for (int y = result_y; y <= result_y + size_y1; y++) {
		for (int x = result_x; x <= result_x + size_x1; x++) {
			data[y][x].red = 0;
			data[y][x].green = 0;
			data[y][x].blue = 0;
		}
	}

	result_hu = SAD1(0, 0);
	out = 0;
	for (i = 0; i < max_y_hu; i++) {
		for (j = 0; j < max_x_hu; j++) {
			out = (int)SAD1(i, j);
			if (out < 0) {
				printf("error\n");
				exit(1);
			}
			if (result_hu > out) {
				result_hu = out;
				result_x1 = j;
				result_y1 = i;
			}
		}
	}
	//枠で囲う
	for (int i = result_y1; i < result_y1 + size_y1; i++) {
		for (int j = result_x1; j < result_x1 + size_x1; j++) {
			if (j == result_x1 || j == result_x1 + size_x1 || i == result_y1 || i == result_y1 + size_y1) {
				data[i][j].red = 0;
				data[i][j].green = 0;
				data[i][j].blue = 255;
			}
		}
	}

	sift_x = (result_x - result_x1)*(result_x-result_x1);
	sift_y = (result_y - result_y1)*(result_y-result_y1);
	sift = sqrt(sift_x + sift_y);
	theta = 90.0 - atan(sift_y / sift_x)*180.0/3.14;

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

void matching::ras() {
	int x, y;
	int result_x, result_y;
	int result_x1, result_y1;
	int result_x2, result_y2;
	int result_x3, result_y3;
	int init = 0;

	//普通のラスタ走査
	for (y = 0; y < size_y; y++) {
		for (x = 0; x < size_x; x++) {
			if (init == 0) {
				if (data[y][x].red == 0) {
					result_x = x;
					result_y = y;
					if (result_x < 20) {
						init = 1;
					}
				}

			}
			else {
				;
			}
		}
	}
	printf("x=%d y=%d\n", result_x, result_y);

	//縦方向のラスタ走査
	init = 0;
	for (x = 0; x < size_x; x++) {
		for (y = 0; y < size_y; y++) {
			if (init == 0) {
				if (data[y][x].red == 0) {
					result_x1 = x;
					result_y1 = y;
					if (result_y1 < 40) {
						init = 1;
					}
				}
			}
			else {
				;
			}
		}
	}
	printf("x1=%d y1=%d\n", result_x1, result_y1);

	//右からラスタ走査
	init = 0;
	for (y = size_y - 1; y > 0; y--) {
		for (x = size_x - 1; x > 0; x--) {
			if (init == 0) {
				if (data[y][x].red == 0) {
					result_x2 = x;
					result_y2 = y;
					if (result_x2 > size_x - 20) {
						init = 1;
					}
				}
			}
			else {
				;
			}
		}
	}
	printf("x2=%d y2=%d\n", result_x2, result_y2);

	//下からラスタ走査
	init = 0;
	for (x = size_x - 1; x > 0; x--) {
		for (y = size_y - 1; y > 0; y--) {
			if (init == 0) {
				if (data[y][x].red == 0) {
					result_x3 = x;
					result_y3 = y;
					if (result_y3 > size_y - 40) {
						init = 1;
					}
				}
			}
			else {
				;
			}
		}
	}
	printf("x3=%d y3=%d\n", result_x3, result_y3);
}
void matching::specify() {

}

void matching::output_RGBImage(RGBImage *image_print) {
	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
			image_print->data[i][j].r = data[i][j].red;
			image_print->data[i][j].g = data[i][j].green;
			image_print->data[i][j].b = data[i][j].blue;
		}
	}
}

matching:: ~matching() {
	for (int i = 0; i < size_y; i++) {
		delete[] data[i];
		data[i] = 0;
	}
	delete[] data;
	data = 0;

	for (int j = 0; j < size_y1; j++) {
		delete[] templete_data1[j];
		templete_data1[j] = 0;
	}
	delete[] templete_data1;
	templete_data1 = 0;

	for (int j = 0; j < size_y2; j++) {
		delete[] templete_data2[j];
		templete_data2[j] = 0;
	}
	delete[] templete_data2;
	templete_data2 = 0;

	for (int j = 0; j < size_y3; j++) {
		delete[] templete_data3[j];
		templete_data3[j] = 0;
	}
	delete[] templete_data3;
	templete_data3 = 0;

}

