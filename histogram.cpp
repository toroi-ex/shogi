#include "color.h"
#include "histogram.h"
#include "ImageIO.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>

#define black 0
#define white 255

//�R���X�g���N�^
histogram::histogram(RGBImage image) : size_x(image.sizeX), size_y(image.sizeY) {

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
			data1[y][x].red = white;
			data1[y][x].green = white;
			data1[y][x].blue = white;

		}
	}
}

void histogram::make_histogram() {
	int i, x, y;

	//������
	for (i = 0; i < 256; i++) {
		hist[i] = 0;
	}
	//���X�^����
	for (y = 0; y < size_y; y++) {
		for (x = 0; x < size_x; x++) {
			hist[data[y][x].red]++; //�����̒l���P����
		}
	}
}

void histogram::make_image(int h) {
	//����256�Œ�@�c��h�Ō��߂�
	int i, x, y;
	long int max; // �ŕp�l
	int height; //�e�K���̕p�x�̍���
	//�摜�̏c�E���̒l
	size_x1 = 256;
	size_y1 = h;
	max = 0;
	for (i = 0; i < 256; i++) {
		if (hist[i] > max) {
			max = hist[i];
		}
	}
	//�c��h�ɐ��K��
	for (x = 0; x < size_x1; x++) {
		height = (int)(h / (double)max*hist[x]);
		if (height > h) {
			height = h;
		}
		for (y = 0; y < h; y++) {
			if (y < height) {
				data1[h - 1 - y][x].red = black;
				data1[h - 1 - y][x].green = black;
				data1[h - 1 - y][x].blue = black;
			}
			/*else {
				data1[h - 1 - y][x].red = white;
				data1[h - 1 - y][x].green = white;
				data1[h - 1 - y][x].blue = white;
			}*/
		}
	}
}

void histogram::do_make(int h) {
	make_histogram();
	make_image(h);
}

// RGBImage�֏o��
void histogram::output_RGBImage(RGBImage *image_print)
{
	image_print->newImage(size_x1,size_y1);

	for (int j = 0; j < size_y1; j++) {
		for (int i = 0; i < size_x1; i++) {
			image_print->data[j][i].r = data1[j][i].red;
			image_print->data[j][i].g = data1[j][i].green;
			image_print->data[j][i].b = data1[j][i].blue;
		}
	}
}

//�f�X�g���N�^
histogram::~histogram() {
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

