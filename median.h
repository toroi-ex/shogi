#pragma once
#include "ImageIO.h"
#include "color.h"
#include<iostream>

using namespace std;


//���f�B�A���N���X

class median {
public:
	int size_x;
	int size_y;

	struct color **data;


	//�R���X�g���N�^
	median(RGBImage image);

	//�f�X�g���N�^
	~median();

	void effect(RGBImage image);

	int median_sort(int sort[9]);


	//RGBImage�֏o��
	void output_RGBImage(RGBImage *image_print);

private:

};