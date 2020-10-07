#pragma once

#include "ImageIO.h"
#include "color.h"

class labeling {
public:
	int size_x;
	int size_y;
	struct color **image_data;//�摜�f�[�^ ���摜
	struct color **data; //��������

	int **label_data;//���x���Â����ꂽ�f�[�^
	int **label_second;
	int label;//���x���ԍ�
	int look_up_table[5000];
	int count = 1;//�w�i��0�̂���
	int cnt = 0;
	labeling(RGBImage image);//�R���X�g���N�^

	void modify(int num1, int num2);//���x���̔ԍ����l�߂�

	int search_4neighbors(int x, int y);//4�ߖT���� ���x���̍ő�l��Ԃ�

	int labeling_kai();//�T�����Ēl��Ԃ��Ă������@

	int rabeling(); //���x�����O

	void recognition(int area1,double rat);

	void output_RGBImage(RGBImage *image_print);//�o��

	~labeling();//�f�X�g���N�^


};