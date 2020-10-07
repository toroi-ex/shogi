#pragma once
#include "color.h"
#include "ImageIO.h"


class histogram {
public:
	int size_x;
	int size_y;
	long hist[256];//�q�X�g�O�����p�̃f�[�^�z��
	int size_x1; //�q�X�g�O�����摜�̉���
	int size_y1; //�q�X�g�O�����摜�̗���

	struct color **data;
	struct color **data1;//�q�X�g�O�����p�̂��

	histogram(RGBImage image);

	void make_histogram();//�q�X�g�O�����쐬

	void make_image(int h);//�摜�ɋN����

	void do_make(int h);

	void output_RGBImage(RGBImage *image_print);

	~histogram();

};