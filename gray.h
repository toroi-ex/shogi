#pragma once
#include "ImageIO.h"
#include "color.h"

class gray {
public:
	int size_x;
	int size_y;
	struct color **image_data;
	struct color **data;
	struct color **data1;

	//�R���X�g���N�^
	gray(RGBImage image);

	void gray_image();

	//RGBImage�֏o��
	void output_RGBImage(RGBImage *image_print);

	//�f�X�g���N�^
	~gray();
};