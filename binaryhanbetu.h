#pragma once
#include "ImageIO.h"
#include "color.h"



class binarization {
public:
	struct color** imageData;
	int sizeX, sizeY;
	int t = 0;

	//�R���X�g���N�^�̐錾
	binarization(RGBImage  image);

	//���ʕ��͖@�ɂ��臒l����
	int find_t();

	//2�l��
	void binary();

	//�f�X�g���N�^�̐錾
	~binarization();

	//RGBImage�֏o��
	void output_RGBImage(RGBImage* image_print);

};