#pragma once
#include "color.h"
#include "ImageIO.h"

class binary {
public:
	int size_x;
	int size_y;
	struct color **image_data;

	binary(RGBImage image);
	
	void output_RGBImage(RGBImage *image_print);

	~binary();
};