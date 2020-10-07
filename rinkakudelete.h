#pragma once
#include "ImageIO.h"
#include "color.h"

#define max 50000 //��f�̍ő�l

class contour2 {
public:
	int size_x;
	int size_y;

	struct color **data;
	struct color **data1;

	int chain_code[max]; //�`�F�C���R�[�h
	int offset[8][2] = { {1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1} }; //�ߖT��f�Ƃ̋���

	contour2(RGBImage image);

	int obtain_contour(int x_start, int y_start);//�֊s���Ɋ܂܂��_�̑�����Ԃ�

	void remove_areas(int meter); // ���͒����w�肵���l��菬���������菜

	void output_RGBImage(RGBImage *image_print);

	~contour2();
};