#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "rabelinngu.h"
#include "ImageIO.h"

#define a_b 128
#define b_c 255
#define c_d 0

labeling::labeling(RGBImage image) :size_x(image.sizeX), size_y(image.sizeY) {

	image_data = new struct color *[size_y];        //画像データの確保
	for (int i = 0; i < size_y; i++) {              //
		image_data[i] = new struct color[size_x];   //
	}

	data = new struct color *[size_y];        //
	for (int i = 0; i < size_y; i++) {              //
		data[i] = new struct color[size_x];   //
	}

	label_data = new int  *[size_y];        //ラベルづけされたデータの確保
	for (int i = 0; i < size_y; i++) {              //
		label_data[i] = new int[size_x];   //
	}

	label_second = new int  *[size_y];        //ラベルづけされたデータの確保
	for (int i = 0; i < size_y; i++) {              //
		label_second[i] = new int[size_x];   //
	}

	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			image_data[y][x].red = image.data[y][x].r;
			image_data[y][x].green = image.data[y][x].g;
			image_data[y][x].blue = image.data[y][x].b;
		}
	}

	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data[y][x].red = image_data[y][x].red;
			data[y][x].green = image_data[y][x].green;
			data[y][x].blue = image_data[y][x].blue;
		}
	}
}

void labeling::modify(int num1, int num2) {
	for (int y = 0; y < size_y; y++){
		for (int x = 0; x < size_x; x++) {
			if (label_data[y][x] == num1) {
				label_data[y][x] = num2;
			}
		}
	}
}

int labeling::search_4neighbors(int y, int x) {
	int max = 0;
	if (y - 1 >= 0 && label_data[y-1][x]>max) {  //上
		max = label_data[y - 1][x];
	}
	if (x - 1 >= 0 && label_data[y][x - 1] > max) {  //左
		max = label_data[y][x - 1];
	}
	if (y + 1 < size_y&&label_data[y + 1][x] > max) {  //下
		max = label_data[y + 1][x];
	}
	if (x + 1 < size_x&&label_data[y][x + 1] > max) {  //右
		max = label_data[y][x + 1];
	}
	return max;
}

int labeling::labeling_kai() {
	int x, y, num;
	int count = 0; //ら別の最大値
	int new_count;

	//初期化
	for (y = 0; y < size_y; y++) {
		for (x = 0; x < size_x; x++) {
			label_data[y][x]=0;
		}
	}
	//スキャン
	for (y = 0; y < size_y; y++) {
		for (x = 0; x < size_x; x++) {
			if (image_data[y][x].red == 0 && label_data[y][x] == 0) {
				num = search_4neighbors(y, x);
				if (num ==0) {  //新しい孤立領域
					label_data[y][x] = ++count;
				}
				else {
					label_data[y][x] = num;
				}
			}
		}
	}
	//ラベルを整形
	if (count > 0) {
		//重複の削除
		for (y = 0; y < size_y; y++) {
			for (x = 0; x < size_x; x++) {
				if (label_data[y][x] != 0) {
					num = search_4neighbors(y, x);
					if (num > label_data[y][x]) { //numを全部変更
						modify(num, label_data[y][x]);
					}
				}
			}
		}

		//番号を詰める
		new_count = 0;
		for (y = 0; y < size_y; y++) {
			for (x = 0; x < size_x; x++) {
				if (label_data[y][x] > new_count) {
					new_count++;
					modify(label_data[y][x], new_count);
				}
			}
		}
		return new_count;  //最終的なラベルの最大値
	}
	else{ //孤立領域なし
		return 0;
	}
}

int labeling::rabeling() {
	int new_count;

	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			if ((image_data[j][i].red == 0) && (image_data[j][i].green == 0) && (image_data[j][i].blue == 0)) {

				if (j == 0 && i == 0) {
					label_data[j][i] = count;                                //走査開始画素
					look_up_table[count] = count;
					count++;
				}

				else if (j == 0 && i != 0) {                                //最上端
					if (label_data[j][i - 1] != 0) {                             //左画素がラベル済み
						label_data[j][i] = label_data[0][i - 1];
					}
					else {
						label_data[j][i] = count;                                //ラベルを追加
						look_up_table[count] = count;
						count++;
					}
				}
				else if (j == size_y) {                                    //最下端
					if (label_data[j - 1][i] != 0) {                             //上がラベル済み
						label_data[j][i] = label_data[j - 1][i];
					}
					else {
						label_data[size_y][i] = count;                          //ラベルを追加
						look_up_table[count] = count;
						count++;
					}
				}
				else if (j != 0 && i == 0) {                               //１番左端
					if (label_data[j - 1][i] != 0) {
						label_data[j][i] = label_data[j - 1][i];
					}
					else {
						label_data[j][i] = count;                          //ラベルを追加
						look_up_table[count] = count;
						count++;
					}
				}


				else {                                                      //その他の画素

					if (label_data[j][i - 1] != 0 && label_data[j - 1][i] == 0) {          //左がラベル済み上が未ラベル
						label_data[j][i] = label_data[j][i - 1];
					}
					else if (label_data[j][i - 1] == 0 && label_data[j - 1][i] != 0) {        //左が未ラベル上がラベル済み
						label_data[j][i] = label_data[j - 1][i];
					}
					else if (label_data[j][i - 1] != 0 && label_data[j - 1][i] != 0) {        //上、左ラベル済み
						if (label_data[j][i - 1] < label_data[j - 1][i]) {                    //左画素が上画素よりも小さい
							label_data[j][i] = label_data[j][i - 1];                          //左画素を代入
							look_up_table[label_data[j - 1][i]] = look_up_table[label_data[j][i - 1]]; //ルックアップテーブル更新
						}
						else {                                                      //上画素が左画素よりも小さい
							label_data[j][i] = label_data[j - 1][i];                          //上画素を代入
							look_up_table[label_data[j][i - 1]] = look_up_table[label_data[j - 1][i]];
						}
					}
					else {
						label_data[j][i] = count;                                        //その他の画素　左と上以外　新しいラベル
						look_up_table[count] = count;                                    //ルックアップテーブルニ登録
						count++;
					}
				}
			}
			else {                                                          //0-画素
				label_data[j][i] = 0;
			}
		}
	}
	if (count > 0) {
		for (int k = count; k > 0; k--) {                      //ラベルを更新
			for (int j = 0; j < size_y; j++) {
				for (int i = 0; i < size_x; i++) {
					if (label_data[j][i] == k) {
						label_data[j][i] = look_up_table[k];
					}
				}
			}
		}
	
		
		//値を詰める
		new_count = 0;
		for (int y = 0; y < size_y; y++) {
			for (int x = 0; x < size_x; x++) {
				if (label_data[y][x] > new_count) {
					new_count++;
					modify(label_data[y][x], new_count);
				}
			}
		}
		return new_count;//最終的なラベルの最大値
	}
	else {
		return 0;
	}
	
	/*for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			if (label_data[j][i] != 0) {
				switch (label_data[j][i] % 3) {
				case 0:
					image_data[j][i].red = 255;
					image_data[j][i].green = 0;
					image_data[j][i].blue = 0;
					break;

				case 1:
					image_data[j][i].red = 0;
					image_data[j][i].green = 0;
					image_data[j][i].blue = 255;
					break;

				case 2:
					image_data[j][i].red = 0;
					image_data[j][i].green = 255;
					image_data[j][i].blue = 0;
					break;
				default:
					image_data[j][i].red = 255;
					image_data[j][i].green = 0;
					image_data[j][i].blue = 0;
					break;
				}

			}
			else {
				image_data[j][i].red = 255;
				image_data[j][i].blue = 255;
				image_data[j][i].green = 255;
			}
		}
	}*/
}

void labeling::recognition(int area1,double rat) {
	int i, num, x, y, h, w;
	int area, x_min, y_min, x_max, y_max;
	double ratio;

	num = labeling_kai(); //４近傍で探す
	//num = rabeling(); //ルックアップテーブル
	//面積・外接四角刑充填率で分類
	for (i = 1; i <= num; i++) {
		area = 0;
		x_max = 0;
		y_max = 0;
		x_min = size_x;
		y_min = size_y;
		for (y = 0; y < size_y; y++) {
			for (x = 0; x < size_x; x++) {
				if (label_data[y][x] == i) {
					area++;
					if (x < x_min) {
						x_min = x;
					}
					if (x > x_max) {
						x_max = x;
					}
					if (y < y_min) {
						y_min = y;
					}
					if (y > y_max) {
						y_max = y;
					}
				}
			}
		}
		w = x_max - x_min;
		if (w == 0) {
			w = 1;
		}
		h = y_max - y_min;
		if (h == 0) {
			h = 1;
		}

		ratio = (double)area / w / h; 

		for (y = 0; y < size_y; y++) {
			for (x = 0; x < size_x; x++) {
				if (label_data[y][x] == i) {
					if (ratio <= rat) {
						data[y][x].red = c_d;
						data[y][x].green = c_d;
						data[y][x].blue = c_d;
					}
					if (area <= area1) {
						data[y][x].red = b_c;
						data[y][x].green = b_c;
						data[y][x].blue = b_c;
					}
					else {
						data[y][x].red = c_d;
						data[y][x].green = c_d;
						data[y][x].blue = c_d;
					}
				}
			}
		}
	}
}
labeling::~labeling() {
	for (int i = 0; i < size_y; i++) {
		delete[] image_data[i];
		image_data[i] = 0;
	}
	delete[] image_data;
	image_data = 0;

	for (int i = 0; i < size_y; i++) {
		delete[] label_data[i];
		label_data[i] = 0;
	}
	delete[] label_data;
	label_data = 0;
}


void labeling::output_RGBImage(RGBImage *image_print) {
	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			image_print->data[j][i].r = data[j][i].red;//RGBImageにさっき求めたデータ配列を格納
			image_print->data[j][i].g = data[j][i].green;//
			image_print->data[j][i].b = data[j][i].blue;//
		}
	}
}


