#pragma once
#include "color.h"
#include "ImageIO.h"

class shrink {
public:
	int size_x;
	int size_y;
	int counter; //�ߖT�̐}�`��f��
	int p_x, p_y; //�ߖT�̍��W
	struct color **data;	//�݂���
	struct color **data1;	//��������
	
	//�R���X�g���N�^
	shrink(RGBImage image);

	//���k
	void erosion(int rep);

	//�o��
	void output_RGBImage(RGBImage *image_print);

	//�f�X�g���N�^
	~shrink();
};