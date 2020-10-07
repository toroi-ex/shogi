#pragma once
#include "color.h"
#include "ImageIO.h"


class rasuta {
public:
	int size_x;
	int size_y;

	int size_xs = 14;
	int size_xe = 946;
	int size_ys = 29;
	int size_ye = 1123;

	struct color **data;	//‚Ý‚é‚â‚Â
	struct color **data1;	//‚¢‚¶‚é‚â‚Â

	rasuta(RGBImage image);

	void ras();

	void ban();

	void output_RGBImage(RGBImage *image_print);

	~rasuta();

};