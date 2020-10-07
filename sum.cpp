#include "sum.h"
#include "ImageIO.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

sum::sum(RGBImage image) :size_x(image.sizeX), size_y(image.sizeY) {

	data = new struct color *[size_y];
	for (int i = 0; i < size_y; i++) {
		data[i] = new struct color[size_x];
	}

	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data[y][x].red = image.data[y][x].r;
			data[y][x].green = image.data[y][x].g;
			data[y][x].blue = image.data[y][x].b;
		}
	}
}

void sum::sum_number() {

	sumgetan = 0;

	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			if (data[y][x].red == 255) {
				sumgetan++;
			}
		}
	}
	printf("white_sum=%d\n", sumgetan);
}

sum::~sum() {

	for (int i = 0; i < size_y; i++) {
		delete[] data[i];
		data[i] = 0;
	}
	delete[] data;
	data = 0;

}