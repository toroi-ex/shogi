#pragma once
#include "ImageIO.h"
#include "color.h"

//�\�[�x���N���X

class sobel_image {
public:
	int size_x;
	int size_y;
	struct color **data;

	//�R���X�g���N�^
	sobel_image(RGBImage image);

	//RGBImage�֏o��
	void output_RGBImage(RGBImage *image_print);

	//�f�X�g���N�^
	~sobel_image();

};