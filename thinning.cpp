#include "color.h"
#include "thinning.h"
#include "ImageIO.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define black 0
#define white 255
#define gray 128

thinning::thinning(RGBImage image) :size_x(image.sizeX), size_y(image.sizeY) {
	data = new struct color*[size_y];  //���I�m��
	for (int i = 0; i < size_y; i++) {
		data[i] = new struct color[size_x];
	}

	data1 = new struct color*[size_y];  //���I�m��
	for (int i = 0; i < size_y; i++) {
		data1[i] = new struct color[size_x];
	}

	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data[y][x].red = image.data[y][x].r;
			data[y][x].blue = image.data[y][x].b;
			data[y][x].green = image.data[y][x].g;

		}
	}

	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data1[y][x].red = image.data[y][x].r;
			data1[y][x].blue = image.data[y][x].b;
			data1[y][x].green = image.data[y][x].g;
		}
	}
}

//���ډ�f�̘A���x�����߂�
int thinning::func_nc8(int *b) {
	int n_odd[4] = { 1,3,5,7 }; //��̋ߖT�ԍ�
	int i;
	int j;
	int sum;
	int d[10];
	for (i = 0; i <= 9; i++) {
		j = i;
		if (i == 9) {
			j = 1;
		}
		if (abs(*(b + j)) == 1) {
			d[i] = 1;
		}
		else {
			d[i] = 0;
		}
	}
	sum = 0;
	for (i = 0; i < 4; i++) {
		j = n_odd[i];
		sum = sum + d[j] - d[j] * d[j + 1] * d[j + 2];
	}
	return (sum);
}

void thinning::thin() {
	int offset[9][2] = { {0,0},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1} }; //�ߖT�̉摜�̋���
	int n_odd[4] = { 1,3,5,7 };//�ߖT�ԍ�
	int b[9];  //�������܂�9�ߖT�̒l
	int condition[6]; //���� =1�̂Ƃ�����
	int i;
	int x;
	int y;
	int copy;
	int sum;
	int path=1;//�摜�̑����

	do {
		printf("path:%d\n", path);
		counter = 0;
		for (y = 0; y < size_y; y++) {
			for (x = 0; x < size_x; x++) {
				for (i = 0; i < 9; i++) {
					b[i] = 0;
					px = x + offset[i][0]; //�ߖT��f�̈ʒu
					py = y + offset[i][1]; //
					if (px >= 0 && px < size_x && py >= 0 && py < size_y) {
						if (data1[py][px].red == black) {
							b[i] = 1;
						}
						else if (data1[py][px].red == gray) {
							b[i] = -1;
						}
					}
				}
				for (i = 0; i < 6; i++) {
					condition[i] = 0;
				}
				//�}�`�̉�f�ł���
				if (b[0] == 1) {
					condition[0] = 1;
				}
				//���E�_�ł���
				sum = 0;
				for (i = 0; i < 4; i++) {
					sum = sum + 1 - abs(b[n_odd[i]]);
				}
				if (sum >= 1) {
					condition[1] = 1;
				}
				//�[�_���c��
				sum = 0;
				for (i = 1; i <= 8; i++) {
					sum = sum + abs(b[i]);
				}
				if (sum >= 2) {
					condition[2] = 1;
				}
				//�Ǘ��_��ۑ�
				sum = 0;
				for (i = 1; i <= 8; i++) {
					if (b[i] == 1) {
						sum++;
					}
				}
				if (sum >= 1) {
					condition[3] = 1;
				}
				//�A������ۑ�
				if (func_nc8(b) == 1) {
					condition[4] = 1;
				}
				//����2�̐����̕Б�����
				sum = 0;
				for (i = 1; i <= 8; i++) {
					if (b[i] != -1) {
						sum++;
					}
					else {
						copy = b[i];
						b[i] = 0;
						if (func_nc8(b) == 1) {
							sum++;
						}
						b[i] = copy;
					}
				}
				if (sum == 8) {
					condition[5] = 1;
				}
				//�ŏI����
				if (condition[0] && condition[1] && condition[2] && condition[3] && condition[4] && condition[5]) {
					data1[y][x].red = gray;
					data1[y][x].blue = gray;
					data1[y][x].green = gray;
					counter++;
				}

			}
		}
		if (counter != 0) {
			for (y = 0; y < size_y; y++) {
				for (x = 0; x < size_x; x++) {
					if (data1[y][x].red == gray) {
						data1[y][x].red = white;
						data1[y][x].blue = white;
						data1[y][x].green = white;
					}
				}
			}
		}
		path++;
	} while (counter != 0);
}

thinning::~thinning() {
	for (int i = 0; i < size_y; i++) {
		delete[] data[i];
		data[i] = 0;
	}
	delete[] data;
	data = 0;

	for (int j = 0; j < size_y; j++) {
		delete[] data1[j];
		data1[j] = 0;
	}
	delete[] data1;
	data1 = 0;
}

// RGBImage�֏o��
void thinning::output_RGBImage(RGBImage *image_print)
{
	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			image_print->data[j][i].r = data1[j][i].red;
			image_print->data[j][i].g = data1[j][i].green;
			image_print->data[j][i].b = data1[j][i].blue;
		}
	}
}