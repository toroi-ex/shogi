#pragma once

#include "ImageIO.h"

//�J���[�摜�̃s�N�Z����\������\����
struct color {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

class color_image {
public:
	   struct color **image_data;//2�����z���\��
	   int size_x;
	   int size_y; 
	   
	   color_image(RGBImage image);//�R���X�g���N�^
	   ~color_image();//�f�X�g���N�^

	//void set_size_x(int index_size_x);//�Z�b�^

	//void set_size_y(int index_size_y);//�Z�b�^

	//int get_size_x();//�Q�b�^

	//int get_size_y();//�Q�b�^

	   int set_pixsel( struct color *value, int index_x, int index_y);//�s�N�Z���̒l���Z�b�g

	   void get_pixsel( int index_x, int index_y);//�s�N�Z�����擾

	   void set_color(struct color *pixsel, unsigned char red_val, unsigned char green_val, unsigned char blue_val);//�F�̒l���Z�b�g

};

//void set_color(struct color *pixsel, unsigned char blue_val, unsigned char green_val, unsigned char red_val);//�F�̒l���Z�b�g