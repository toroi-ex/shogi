#pragma once
#include "ImageIO.h"
#include "color.h"

class contour {
public:
	int size_x;
	int size_y;

	struct color **data;  //‚Ý‚é‚â‚Â
	struct color **data1; //‚¢‚¶‚é‚â‚Â

	contour(RGBImage image);

	void rinkaku(float amp); //amp‚Í—˜“¾ ‚Ç‚ê‚¾‚¯—ÖŠs‚ð”Z‚­‚·‚é‚©

	void output_RGBImage(RGBImage *image_print);

	~contour();
};