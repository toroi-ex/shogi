#pragma once
#include "ImageIO.h"
#include "color.h"



//�c���N���X

class bloat {
public:
	int size_x;
	int size_y;
	//int size_x1;
	//int size_y1;
	
	int counter; //�ߖT�̐}�`��f��
	int p_x, p_y; //�ߖT�̍��W
	struct color **data;	//�݂���
	struct color **data1;	//��������

	//�R���X�g���N�^
	bloat(RGBImage image);

	//�c��
	void dilation(int rep);


	//RGBImage�֏o��
	void output_RGBImage(RGBImage *rgb_image);

	//�f�X�g���N�^
	~bloat();

};