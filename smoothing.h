#pragma once
#include "ImageIO.h"
#include "color.h"
#include<iostream>

using namespace std;


//�������N���X

class smoothing {
public:
	int size_x;
	int size_y;
	struct color **data;

	//�R���X�g���N�^
	smoothing(RGBImage image);

	//�f�X�g���N�^
	~smoothing();

	//RGBImage�֏o��
	void output_RGBImage(RGBImage *rgb_image);

};