#pragma once
#include "ImageIO.h"
#include "color.h"

class thinning {
public:
	int size_x;
	int size_y;
	int px;//�ߖT��x���W
	int py;//�ߖT��y���W
	int counter; //���x���ɕω�����������f�̐�
	struct color **data; //�݂���
	struct color **data1; //��������

	thinning(RGBImage image);

	int func_nc8(int *b);

	void thin();

	void output_RGBImage(RGBImage *image_print);

	~thinning();
};