#pragma once
#include "ImageIO.h"
#include "color.h"



class matching {
public:
	int size_x;		//���摜�T�C�Y
	int size_y;		//���摜�T�C�Y
	int size_x1, size_y1;	//���@�e���v���[�g�p�̉摜�T�C�Y
	int size_x2, size_y2;	//���@�e���v���[�g�p�̉摜�T�C�Y
	int size_x3, size_y3;	//���@�e���v���[�g�p�̉摜�T�C�Y
	int size_x4, size_y4;	//��@�e���v���[�g�p�̉摜�T�C�Y
	int size_x5, size_y5;	//���@�e���v���[�g�p�̉摜�T�C�Y
	int size_x6, size_y6;	//��ԁ@�e���v���[�g�p�̉摜�T�C�Y
	int size_x7, size_y7;	//�p�@�e���v���[�g�p�̉摜�T�C�Y
	int size_x8, size_y8;	//���@�e���v���[�g�p�̉摜�T�C�Y

	int result_x;	//�}�b�`���O�̌���
	int result_y;

	struct color **data; //���摜
	//struct color **templete_data; //�v�Z����p�̂��
	struct color **templete_data1; //���e���v���[�g
	struct color **templete_data2; //���e���v���[�g
	struct color **templete_data3; //���e���v���[�g
	struct color **templete_data4; //��e���v���[�g
	struct color **templete_data5; //���e���v���[�g
	struct color **templete_data6; //��ԃe���v���[�g
	struct color **templete_data7; //�p�e���v���[�g
	struct color **templete_data8; //���e���v���[�g
	
	int mas[81] = { 0,1,2,3,4,5,6,7,8,
			 9,10,11,12,13,14,15,16,17,
			 18,19,20,21,22,23,24,25,26,
			 27,28,29,30,31,32,33,34,35,
			 36,37,38,39,40,41,42,43,44,
			 45,46,47,48,49,50,51,52,53,
			 54,55,56,57,58,59,60,61,62,
			 63,64,65,66,67,68,69,70,71,
			 72,73,74,75,76,77,78,79,80, };	//�Ղ̈ʒu

	matching(RGBImage image,RGBImage image1,RGBImage image2,RGBImage image3);

	//int SSD(int y,int x);

	//int SSD2(int y, int x);

	//int SSD3(int y, int x);

	int SAD1(int y, int x);	//��

	int SAD2(int y, int x);	//��

	int SAD3(int y, int x);	//��

	int SAD4(int y, int x);	//��

	int SAD5(int y, int x);	//��

	int SAD6(int y, int x);	//���

	int SAD7(int y, int x);	//�p

	int SAD8(int y, int x);	//��

	void do_match();	//�}�b�`���O

	void specify();		//�ǂ��ɂ��邩����

	void output_RGBImage(RGBImage *image_print);

	int rasuta_xs;	//���X�^�������ē���ꂽx���W�̈�ԍ�
	int rasuta_ys;	//���X�^�������ē���ꂽx���W�̈�ԏ�
	int rasuta_xe;	//���X�^�������ē���ꂽx���W�̈�ԉE
	int rasuta_ye;	//���X�^�������ē���ꂽx���W�̈�ԉ�
	int board_size_x;	//�Ղ�x�T�C�Y
	int board_size_y;	//�Ղ�y�T�C�Y

	void ras();	//���X�^����

	~matching();

};