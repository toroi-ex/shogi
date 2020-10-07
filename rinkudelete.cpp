#include "color.h"
#include "rinkakudelete.h"
#include "ImageIO.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<math.h>

#define white 255
#define black 0
#define gray 128

//�R���X�g���N�^
contour2::contour2(RGBImage image) : size_x(image.sizeX), size_y(image.sizeY) {

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
			data[y][x].green = image.data[y][x].g;
			data[y][x].blue = image.data[y][x].b;

		}
	}
	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data1[y][x].red = black;
			data1[y][x].green = black;
			data1[y][x].blue = black;
		}
	}
}

//�w�i���ŕ��������ɂ�������΍��̂܂܁@�w�i���ŕ����𔒂ɂ��������black��white�����ւ���


int contour2::obtain_contour(int x_start, int y_start) {
	int x, y;
	int px, py;
	int code;//�`�F�C���R�[�h
	int num;//����
	int i, counter, detect;


	//�Ǘ��_�̃`�F�b�N
	counter = 0;
	for (i = 0; i < 8; i++) {
		px = x_start + offset[i][0];
		py = y_start + offset[i][1];
		if (px >= 0 && px < size_x && py >= 0 && py < size_y && data[py][px].red == white) {
			counter++;
		}
	}
	if (counter == 0) { //�����ʒu�͌Ǘ��_
		num = 1;
	}
	else { //�T���J�n
		num = -1;
		x = x_start;
		y = y_start;
		code = 0;
		do {
			detect = 0;//���̓_����������1
			//�T���͐^�񒆂���X�^�[�g���Ď��͏�
			code = code - 3;
			if (code < 0) {
				code = code + 8;
			}
			do {
				px = x + offset[code][0];
				py = y + offset[code][1];
				if (px >= 0 && px < size_x && py >= 0 && py < size_y && data[py][px].red == white) {
					detect = 1;//���̓_�����o����
					num++;
					if (num > max) {
						printf("�֊s���̉�f��>%d\n", max);
						exit(1);
					}
					chain_code[num] = code;
					x = px;
					y = py;
				}
				code++;
				if (code > 7) {
					code = 0;
				}
			} while (detect == 0);
		} while (x != x_start || y != y_start);//�J�n�_�܂�
		num = num + 2;//chain_code[]�̓Y�����Ƃ̂�����C��
	}
	return (num);
}

//
void contour2::remove_areas(int meter) {//臒l
	int i, num, x, y, px, py;
	int fill,fall;

	/*for (y = 0; y < size_y; y++) {
		for (x = 0; x < size_x; x++) {
			data1[y][x].red = black;
			data1[y][x].green = black;
			data1[y][x].blue = black;
		}
	}*/

	//�����J�n
	for (y = 0; y < size_y; y++) {
		for (x = 0; x < size_x; x++) {
			if (data[y][x].red == white) {//�J�n�_
				num = obtain_contour(x, y);//�ǐ�
				if (num > meter) {
					fill = white;				
				}
				else {
					fill = gray;				
				}
				px = x;
				py = y;

				if(data[y][x].green == white){
					data[py][px].red = black;
					data[py][px].green = black;
					data[py][px].blue = black;

					data1[py][px].red = (unsigned char)fill;
					data1[py][px].green = (unsigned char)fill;
					data1[py][px].blue = (unsigned char)fill;
				}

				else if (data[y][x].red == white) {
					data[py][px].red = black;
					data[py][px].green = black;
					data[py][px].blue = black;

					data1[py][px].red = (unsigned char)fill;
					data1[py][px].green = black;
					data1[py][px].blue = black;
				}

				if (num > 1) {
					for (i = 0; i < num - 1; i++) {
						px = px + offset[chain_code[i]][0];
						py = py + offset[chain_code[i]][1];

						if (data[y][x].green == white) {
							data[py][px].red = black;
							data[py][px].green = black;
							data[py][px].blue = black;

							data1[py][px].red = (unsigned char)fill;
							data1[py][px].green = (unsigned char)fill;
							data1[py][px].blue = (unsigned char)fill;
						}

						else if (data[y][x].red == white) {
							data[py][px].red = black;
							data[py][px].green = black;
							data[py][px].blue = black;

							data1[py][px].red = (unsigned char)fill;
							data1[py][px].green = black;
							data1[py][px].blue = black;
						}
					}
				}
			}
		}
	}
	//�㏈��
	for (y = 0; y < size_y; y++) {
		for (x = 0; x < size_x; x++) {
			if (data1[y][x].red == gray) {
				data1[y][x].red = black;
				data1[y][x].green = black;
				data1[y][x].blue = black;
				for (i = 0; i < 8; i++) {
					px = x + offset[i][0];
					py = y + offset[i][1];
					if (px >= 0 && px < size_x && py >= 0 && py < size_y && data1[py][px].green == white) {
						data1[y][x].red = white;
						data1[y][x].green = white;
						data1[y][x].blue = white;
					}
					else if (px >= 0 && px < size_x && py >= 0 && py < size_y && data1[py][px].red == white) {
						data1[y][x].red = white;
						data1[y][x].green = black;
						data1[y][x].blue = black;
					}
				}
			}
		}
	}
}


//�f�X�g���N�^
contour2::~contour2() {
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
void contour2::output_RGBImage(RGBImage *image_print)
{
	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			image_print->data[j][i].r = data1[j][i].red;
			image_print->data[j][i].g = data1[j][i].green;
			image_print->data[j][i].b = data1[j][i].blue;
		}
	}
}