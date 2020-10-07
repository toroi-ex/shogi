#include "color.h"
#include "bloat.h"
#include "ImageIO.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;

#define black 0
#define white 255

//コンストラクタ
bloat::bloat(RGBImage image) : size_x(image.sizeX), size_y(image.sizeY)  {

	data = new struct color*[size_y];  //動的確保
	for (int i = 0; i < size_y; i++) {
		data[i] = new struct color[size_x];
	}

	data1 = new struct color*[size_y];  //動的確保
	for (int i = 0; i < size_y; i++) {
		data1[i] = new struct color[size_x];
	}

	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data[y][x].red = image.data[y][x].r;
			data[y][x].green = image.data[y][x].g;
			data[y][x].blue = image.data[y][x].b;

		}
	}

	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {
			data1[y][x].red = data[y][x].red;
			data1[y][x].green = data[y][x].green;
			data1[y][x].blue = data[y][x].blue;
		}
	}

}


void bloat::dilation(int rep) {
	
	for (int i = 0; i < rep; i++) {
		for (int y = 0; y < size_y; y++) {
			for (int x = 0; x < size_x; x++) {
				if (data[y][x].red == white) {
					counter = 0;
					for (int m = -1; m < 2; m++) {
						for (int n = -1; n < 2; n++) {
							p_x = x + n;
							p_y = y + m;
							if (p_x > 0 && p_x < size_x && p_y > 0 && p_y < size_y && data[p_y][p_x].red == black) {
								counter++;
							}
						}
					}
					if (counter > 0) {//閾値
						data1[y][x].red = black;
						data1[y][x].green = black;
						data1[y][x].blue = black;
					}
					/*else {
						data1[y][x].red = white;
						data1[y][x].blue = white;
						data1[y][x].green = white;
					}*/

				}
			}
		}
		for (int y = 0; y < size_y; y++) {
			for (int x = 0; x < size_x; x++) {
				data[y][x].red = data1[y][x].red;
				data[y][x].green = data1[y][x].green;
				data[y][x].blue = data1[y][x].blue;
			}

		}
	}
}

//デストラクタ
bloat::~bloat() {
	for (int i = 0; i < size_y; i++) {
		delete[] data[i];		
		data[i] = 0;
	}
	delete[] data;
	data = 0;

	for (int j = 0; j < size_y; j++) {
		delete[] data1[j];
		data1[j] = 0;
	}
	delete[] data1;
	data1 = 0;
}

// RGBImageへ出力
void bloat::output_RGBImage(RGBImage *rgb_image)
{
	for (int j = 0; j < size_y; j++) {
		for (int i = 0; i < size_x; i++) {
			rgb_image->data[j][i].r = data1[j][i].red;
			rgb_image->data[j][i].g = data1[j][i].green;
			rgb_image->data[j][i].b = data1[j][i].blue;
		}
	}
}