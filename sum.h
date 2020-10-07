#pragma once

#include "ImageIO.h"
#include "color.h"

class sum {
public:
	int size_x, size_y;
	int sumgetan;

	struct color **data;

	sum(RGBImage image);

	void sum_number();

	~sum();


};