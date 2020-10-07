#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "sabunn.h"
#include "ImageIO.h"

#define max 128
#define white 255
#define black 0

//�R���X�g���N�^
sabun::sabun(RGBImage image, RGBImage image1) :size_x(image.sizeX), size_y(image.sizeY) , size_x1(image1.sizeX) , size_y1(image1.sizeY){

	image_data = new struct color *[size_y];  //���I�m��
	for (int i = 0; i < size_y; i++) {//
		image_data[i] = new struct color[size_x];//
	}
	
	data = new struct color *[size_y];
	for (int i = 0; i < size_y; i++) {
		data[i] = new struct color[size_x];
	}

	data1 = new struct color *[size_y1];
	for (int i = 0; i < size_y1; i++) {
		data1[i] = new struct color[size_x1];
	}

	if ((size_x != size_x1) || (size_y != size_y1)) {  //�G���[�`�F�b�N
		printf("error\n");
	}

	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data[y][x].red = image.data[y][x].r;
			data[y][x].green = image.data[y][x].g;
			data[y][x].blue = image.data[y][x].b;
		}
	}

	for (int y = 0; y < size_y1; y++) {
		for (int x = 0; x < size_x1; x++) {
			data1[y][x].red = image1.data[y][x].r;
			data1[y][x].green = image1.data[y][x].g;
			data1[y][x].blue = image1.data[y][x].b;
		}
	}
}

void sabun::sab() {

	for (int j = 0; j < size_y; j++) {
		for (int k = 0; k < size_x; k++) {
			image_data[j][k].red = data[j][k].red - data1[j][k].red;	//�����摜�쐬
			image_data[j][k].blue = data[j][k].blue - data1[j][k].blue;
			image_data[j][k].green = data[j][k].green - data1[j][k].green;
			if (image_data[j][k].red > 40 && image_data[j][k].red < 70) { //�O���[�]�� ���������� 10<�K���} >30	30<�t�K���}>70
				image_data[j][k].red = white;
				image_data[j][k].green = white;
				image_data[j][k].blue = white;
			}
			//else if (image_data[j][k].red > -80 && image_data[j][k].red < -30) { //���]�O���[ ����������
			//	image_data[j][k].red = black;
			//	image_data[j][k].green = black;
			//	image_data[j][k].blue = black;
			//}
			//else if (image_data[j][k].red > 180 && image_data[j][k].red < 210) { //�����O �A���_�[�t���[���Ė߂��Ă��� 220<�K���}>250	190<�t�K���}>220
			//	image_data[j][k].red = white;
			//	image_data[j][k].green = black;
			//	image_data[j][k].blue = black;
			//}
			//else if (image_data[j][k].red < -180 && image_data[j][k].red > -210) { //�����O
			//	image_data[j][k].red = white;
			//	image_data[j][k].green = black;
			//	image_data[j][k].blue = black;
			//}
			else {
				image_data[j][k].red = black;
				image_data[j][k].green = black;
				image_data[j][k].blue = black;
			}
		}
	}

	
}
//�f�X�g���N�^
sabun::~sabun() {
	for (int i = 0; i < size_y; i++) {
		delete[] image_data[i];
		image_data[i] = 0;
	}
	delete[] image_data;
	image_data = 0;

	for (int i = 0; i < size_y; i++) {
		delete[] data[i];
		data[i] = 0;
	}
	delete[] data;
	data = 0;

	for (int i = 0; i < size_y1; i++) {
		delete[] data1[i];
		data1[i] = 0;
	}
	delete[] data;
	data = 0;
}

//�摜���o��
void sabun :: output_RGBImage(RGBImage *image_print) {
	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			image_print->data[j][i].r = image_data[j][i].red;//RGBImage�ɂ��������߂��f�[�^�z����i�[
			image_print->data[j][i].b = image_data[j][i].blue;//
			image_print->data[j][i].g = image_data[j][i].green;//
		}

	}
	
}