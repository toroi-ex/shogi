#pragma once
#include "ImageIO.h"
#include "color.h"

class contour {
public:
	int size_x;
	int size_y;

	struct color **data;  //�݂���
	struct color **data1; //��������

	contour(RGBImage image);

	void rinkaku(float amp); //amp�͗��� �ǂꂾ���֊s��Z�����邩

	void output_RGBImage(RGBImage *image_print);

	~contour();
};