#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ImageIO.h"
#include "color.h"

using namespace std;

void color_image::set_color(struct color *pixsel, unsigned char red_val, unsigned char green_val, unsigned char blue_val) {//RGB�̒l���Z�b�g
	pixsel->red = red_val;
	pixsel->green = green_val;
	pixsel->blue = blue_val;

}
//�ʒu���Z�b�g
int color_image::set_pixsel( struct color*value, int index_x, int index_y) {//�͈̓`�F�b�N�@�G���[����

	if ((this->size_x < index_x || index_x < 0) || (this->size_y < index_y || index_y < 0)) {
		cout << "�͈͊Ԉ���Ă邼�΂����[\n";
		return 0;
	}
	else {
		size_x = index_x;
		size_y = index_y;
		this->image_data[this->size_y][this->size_x] = *value;//���X�^�����݂����Ȋ����@[y0,y1,y2,y3�E�E�E]y�̐���x�̕�
		return 1;
	}
}
//�l���擾 �\��
void color_image::get_pixsel( int index_x, int index_y) {

	if ((this->size_x < index_x || index_x < 0) || (this->size_y < index_y || index_y < 0)) {
		cout << "�͈͊Ԉ���Ă邼�΂����[\n";

	}
	else {
		size_x = index_x;
		size_y = index_y;
		unsigned char red = this->image_data[this->size_y][this->size_x].red;
		unsigned char green = this->image_data[this->size_y][this->size_x].green;
		unsigned char blue = this->image_data[this->size_y][this->size_x].blue;

		//printf("\tR : %hhu   \tG : %hhu   \tB : %hhu  \n", red, green, blue);//RGb�̒l��\��

	}
}

color_image::color_image(RGBImage image) : size_x(image.sizeX), size_y(image.sizeY) {
	int i;
	image_data = new struct color*[size_y];        //2�����z��̓��I�m��
	for (i = 0; i < size_y; i++) {
		image_data[i] = new struct color[size_x];
	}
}

//�f�X�g���N�^
color_image::~color_image() {
	int i;
	for (i = 0; i < size_y; i++) {
		delete[] image_data[i];
		image_data[i] = 0;
	}
	delete[] image_data;
	image_data = 0;
}

//size_x�̃Z�b�^
/*void color_image::set_size_x(int index_size_x) {
	if (index_size_x > 0 && index_size_x < 255) {
		size_x = index_size_x;
	}
	else {
		printf("�ԈႢ\n");
	}
}
//size_y�̃Z�b�^
void color_image1::set_size_y(int index_size_y) {
	if (index_size_y > 0 && index_size_y < 255) {
		size_y = index_size_y;
	}
	else {
		printf("�ԈႢn");
	}
}

//size_x�̃Q�b�^
int color_image::get_size_x() {
	return this->size_x;
}

//size_y�̃Q�b�^
int color_image::get_size_y() {
	return this->size_y;
}*/



