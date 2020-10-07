#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "ImageIO.h"
#include "sabunn.h"
#include "nitika.h"
#include "color.h"
#include "rabelinngu.h"
#include "gray.h"
#include "shrink.h"
#include "bloat.h"
#include "sobel.h"
#include "smoothing.h"
#include "binaryhanbetu.h"
#include "thinning.h"
#include "rinkaku.h"
#include "rinkakudelete.h"
#include "median.h"
#include "matching.h"
#include "histogram.h"
#include "rasuta.h"
#include "final2.h"

using namespace std;

int main(void)
{
	//struct color color;
	RGBImage image, image1, image2, image3, image4, image5, image6, image7, image8, image9, image10, image11, image12, image13, image14; // �摜��ێ����邽�߂̕ϐ�
	RGBImage image15, image16, image17, image18, image19, image20, image21, image22, image23, image24,image25;  //�e���v���[�g�p�̉摜
	//color_image color_image(image6);                     
	BitmapReader bmpReader;										// Bitmap�t�@�C����ǂݍ��ނ��߂̕ϐ�

	//string inputFilename = "C:\\Users\\toui\\Desktop\\crin_final\\gray_hu_kei_ka_hu_true.bmp";	// �Q�l��
	//string inputFilename1 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\rinkaku_delete_gin_t.bmp";				//���x�����O
	//string inputFilename2 = "C:\\Users\\toui\\Desktop\\clanguage\\sobel.bmp";						//�\�[�x��
	//string inputFilename3 = "C:\\Users\\toui\\Desktop\\clanguage\\nitika_koma.bmp";				//�c��
	//string inputFilename4 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\shrink_koma.bmp";				//���k
	//string inputFilename5 = "C:\\Users\\toui\\Desktop\\crin_final++\\ban_ori.bmp";				//�O���C
	//string inputFilename6 = "C:\\Users\\toui\\Desktop\\clanguage\\gray_rena.bmp";					//������
	//string inputFilename7 = "C:\\Users\\toui\\Desktop\\clanguage\\bloat.bmp";						//�א���
	//string inputFilename8 = "C:\\Users\\toui\\Desktop\\clanguage\\pyama_thinning2.bmp";			//���E���ǐ�
	//string inputFilename9 = "C:\\Users\\toui\\Desktop\\crin_final\\sabun_kei_true.bmp";			//���E���ǐՏ���
	//string inputFilename10 = "C:\\Users\\toui\\Desktop\\clanguage\\nitika.bmp";					//���f�B�A��t�B���^
	//string inputFilename11 = "C:\\Users\\toui\\Desktop\\clanguage\\gray_rena.bmp";				//�q�X�g�O����
	//string inputFilename12 = "C:\\Users\\toui\\Desktop\\crin_final\\gray_hu_kei_ka_ori.bmp";		//����
	//string inputFilename13 = "C:\\Users\\toui\\Desktop\\crin_final\\gray_hu_kei_ka_ka_true.bmp";	//����
	//string inputFilename14 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\nitika_ban.bmp";			//���X�^����
	//string inputFilename15 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\rinkaku_delete_hu_t.bmp";	//�e���v���[�g
	//string inputFilename16 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\hu_tmp_kai.bmp";			//���@�e���v���[�g
	//string inputFilename17 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\kei_tmp_kai.bmp";			//���@�e���v���[�g�p�̉摜
	//string inputFilename18 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\ka_tmp_kai.bmp";			//���@�e���v���[�g�p�̉摜
	//string inputFilename19 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\gin_tmp_kai.bmp";			//��@�e���v���[�g�p�̉摜
	//string inputFilename20 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\kin_tmp_kai.bmp";			//���@�e���v���[�g�p�̉摜
	//string inputFilename24 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\ban_present.bmp";			//�Ղ�\�����������
	//string inputFilename21 = "C:\\Users\\toui\\Desktop\\clanguage\\nitika_koma_hisya.bmp";		//��ԁ@�e���v���[�g�p�̉摜
	//string inputFilename22 = "C:\\Users\\toui\\Desktop\\clanguage\\nitika_koma_kasya.bmp";		//�p�@�e���v���[�g�p�̉摜
	//string inputFilename23 = "C:\\Users\\toui\\Desktop\\clanguage\\nitika_koma_kasya.bmp";		//���@�e���v���[�g�p�̉摜

	//bmpReader.read(inputFilename, &image);     //�Q�l��
	//bmpReader.read(inputFilename1, &image1);   //���x�����O
	//bmpReader.read(inputFilename2, &image2);   //
	//bmpReader.read(inputFilename3, &image3);   //�c���@���k
	//bmpReader.read(inputFilename4, &image4);     //���k
	//bmpReader.read(inputFilename5, &image5);   //�O���C
	//bmpReader.read(inputFilename6, &image6);   //������
	//bmpReader.read(inputFilename7, &image7);     //�א���
	//bmpReader.read(inputFilename8, &image8);     //���E���ǐ�
	//bmpReader.read(inputFilename9, &image9);     //���E���ǐՏ���
	//bmpReader.read(inputFilename10, &image10);  //���f�B�A���t�B���^
	//bmpReader.read(inputFilename11, &image11);  //�q�X�g�O����
	//bmpReader.read(inputFilename12, &image12);	//����
	//bmpReader.read(inputFilename13, &image13);	//����
	//bmpReader.read(inputFilename14, &image14);	//���X�^
	//bmpReader.read(inputFilename15, &image15);	//�e���v���[�g�}�b�`���O
	//bmpReader.read(inputFilename16, &image16);	//���@�e���v���[�g
	//bmpReader.read(inputFilename17, &image17);	//���@�e���v���[�g
	//bmpReader.read(inputFilename18, &image18);	//���@�e���v���[�g
	//bmpReader.read(inputFilename19, &image19);	//��@�e���v���[�g
	//bmpReader.read(inputFilename20, &image20);	//���@�e���v���[�g
	//bmpReader.read(inputFilename24, &image24);	//��
	//bmpReader.read(inputFilename21, &image21);	//��ԁ@�e���v���[�g
	//bmpReader.read(inputFilename22, &image22);	//�p�@�e���v���[�g
	//bmpReader.read(inputFilename23, &image23);	//���@�e���v���[�g

	BitmapWriter bmpWriter;                 // Bitmap�t�@�C�����������ނ��߂̕ϐ�

	//�Q�l��
	//string inputFilename = "C:\\Users\\toui\\Desktop\\crin_final_kai\\zoku\\gray_gin_m3.bmp";	// �Q�l��
	//bmpReader.read(inputFilename, &image);     //�Q�l��
	//binary binary(image);
	//binary.output_RGBImage(&image);
	//string outputfilename = "C:\\Users\\toui\\Desktop\\crin_final_kai\\zoku\\nitika_gin.bmp";
	//bmpWriter.write(outputfilename, &image);	

	//���ʕ��͖@
	/*binarization binarization(image3);
	binarization.find_t();
	binarization.binary();
	binarization.output_RGBImage(&image3);
	string outputfilename7 = "hanbetu.bmp";
	bmpWriter.write(outputfilename7, &image3);*/

	//���x�����O
	//labeling labeling(image1);
	////labeling.rabeling();
	//labeling.recognition(1000,0.8);
	//labeling.output_RGBImage(&image1);
	//string outputfilename2 = "c:\\users\\toui\\desktop\\crin_final_kai\\labeling_h.bmp";
	//bmpWriter.write(outputfilename2, &image1);

	//�O���[�X�P�[��
	//string inputFilename5 = "C:\\Users\\toui\\Desktop\\crin_final++\\zoku\\ban_ori.bmp";  //�O���C
	//bmpReader.read(inputFilename5, &image5);   //�O���C
	//gray gray(image5);
	//gray.gray_image();
	//gray.output_RGBImage(&image5);
	//string outputFilename5 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\zoku\\gray_ban_ori_g.bmp";
	//bmpWriter.write(outputFilename5, &image5);

	//�c��
	/*bloat bloat(image4);
	bloat.dilation(2);
	bloat.output_RGBImage(&image4);
	string outputFilename3 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\shrink_koma_b.bmp";
	bmpWriter.write(outputFilename3, &image4);*/

	//���k
	/*shrink shrink(image4);
	shrink.erosion(1);
	shrink.output_RGBImage(&image4);
	string outputFilename4 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\shrink_koma.bmp";
	bmpWriter.write(outputFilename4, &image4);*/

	//���[�x��
	//sobel_image sobel_image(image1);
	//sobel_image.output_RGBImage(&image1);

	//������
	/*smoothing smoothing(image6);
	smoothing.output_RGBImage(&image6);
	string outputFilename6 = "C:\\Users\\toui\\Desktop\\clanguage\\smoothing.bmp";
	bmpWriter.write(outputFilename6, &image6);*/

	//�א���
	/*thinning thinning(image7);
	thinning.thin();
	thinning.output_RGBImage(&image7);
	string outputFilename7 = "C:\\Users\\toui\\Desktop\\clanguage\\thinning_koma.bmp";
	bmpWriter.write(outputFilename7, &image7);*/

	//���E���ǐ�
	/*contour contour(image8);
	contour.rinkaku(2.5);
	contour.output_RGBImage(&image8);
	string outputFilename8 = "C:\\Users\\toui\\Desktop\\clanguage\\rinkaku_p.bmp";
	bmpWriter.write(outputFilename8, &image8);*/

	//���E���ǐՏ���
	//string inputFilename9 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\sabun_gin_m2.bmp";
	//bmpReader.read(inputFilename9, &image9);     
	//contour2 contour2(image9);
	//contour2.remove_areas(100);	//��170 �j15 ��120 �@�@3�̎��@��170 ��70 ��100  2��ڂɂƂ����ʐ^ ��170 ��100 ��100 ��100 ��100
	//contour2.output_RGBImage(&image9);
	//string outputFilename9 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\rinkaku_delete_ginM2.bmp";
	//bmpWriter.write(outputFilename9, &image9);

	//���f�B�A���t�B���^
	/*median median(image10);
	median.effect(image10);
	median.output_RGBImage(&image10);
	string outputFilename10 = "C:\\Users\\toui\\Desktop\\clanguage\\median.bmp";
	bmpWriter.write(outputFilename10, &image10);*/

	//�q�X�g�O����
	//histogram histogram(image11);
	///*histogram.make_histogram();
	//histogram.make_image();*/
	//histogram.do_make(256);
	//histogram.output_RGBImage(&image11);
	//string outputFilename11 = "C:\\Users\\toui\\Desktop\\clanguage\\histogram.bmp";
	//bmpWriter.write(outputFilename11, &image11);

	//����  �F��ς���͈͓͂K�X���߂邵���Ȃ���
	//string inputFilename12 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\zoku\\gray_kin_m1.bmp";	//����
	//string inputFilename13 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\zoku\\gray_ban_hu_m.bmp";	//����
	//bmpReader.read(inputFilename12, &image12);	//����
	//bmpReader.read(inputFilename13, &image13);	//����
	//sabun sabun(image12, image13);
	//sabun.sab();
	//sabun.output_RGBImage(&image12);
	///*string outputFilename12 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\sabun_kin_m1.bmp";
	//bmpWriter.write(outputFilename12, &image12);*/

	////string inputFilename9 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\sabun_gin_m2.bmp";
	////bmpReader.read(inputFilename9, &image9);     
	//contour2 contour2(image12);
	//contour2.remove_areas(100);	//��170 �j15 ��120 �@�@3�̎��@��170 ��70 ��100  2��ڂɂƂ����ʐ^ ��170 ��100 ��100 ��100 ��100
	//contour2.output_RGBImage(&image12);
	//string outputFilename9 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\zoku\\sabun\\rinkaku_delete_ban_hu_m.bmp";
	//bmpWriter.write(outputFilename9, &image12);

	//���X�^
	/*rasuta rasuta(image14);
	rasuta.ras();
	rasuta.ban();
	rasuta.output_RGBImage(&image14);
	string outputFilename13 = "C:\\Users\\toui\\Desktop\\crin_final\\rasuta_ban.bmp";
	bmpWriter.write(outputFilename13, &image14);*/

	//�e���v���[�g�}�b�`���O
	/*matching matching(image11,image12,image13,image14);
	matching.do_match();
	matching.output_RGBImage(&image11);
	string outputFilename14 = "C:\\Users\\toui\\Desktop\\crin_final\\hu_mis_tmp.bmp";
	bmpWriter.write(outputFilename14, &image14);*/

	//�e���v���[�g����܂Ƃ߂�
	//string inputFilename14 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\nitika_ban.bmp";			//���X�^����
	//string inputFilename15 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\sabun\\rinkaku_delete_gin_ori_ban.bmp";	//�e���v���[�g
 //   string inputFilename25 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\sabun\\rinkaku_delete_gin_ban.bmp";
	//string inputFilename16 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\hu_tmp_2.bmp";			//���@�e���v���[�g
	//string inputFilename17 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\kei_tmp_2.bmp";			//���@�e���v���[�g�p�̉摜
	//string inputFilename18 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\ka_tmp_2.bmp";			//���@�e���v���[�g�p�̉摜
	//string inputFilename19 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\gin_tmp_2.bmp";			//��@�e���v���[�g�p�̉摜
	//string inputFilename20 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\kin_tmp_kai.bmp";			//���@�e���v���[�g�p�̉摜
	////string inputFilename24 = "C:\\Users\\toui\\Desktop\\crin_final_kai\\ban_present.bmp";			//�Ղ�\�����������

	//bmpReader.read(inputFilename14, &image14);	//���X�^
	//bmpReader.read(inputFilename15, &image15);	//�e���v���[�g�}�b�`���O
	//bmpReader.read(inputFilename25, &image25);
	//bmpReader.read(inputFilename16, &image16);	//���@�e���v���[�g
	//bmpReader.read(inputFilename17, &image17);	//���@�e���v���[�g
	//bmpReader.read(inputFilename18, &image18);	//���@�e���v���[�g
	//bmpReader.read(inputFilename19, &image19);	//��@�e���v���[�g
	//bmpReader.read(inputFilename20, &image20);	//���@�e���v���[�g
	////bmpReader.read(inputFilename24, &image24);	//��

	//final final(image15, image14, image16, image17, image18, image19, image20);
	////final.sum_number();
	//final.ras();
	//final.do_match();
	//final.answer();
	//final.ban();
	////final.muri();
	//final.output_RGBImage(&image14);
	//string outputFilename15 = "C:\\Users\\toui\\Desktop\\crin_real_final\\sabun\\correct_gin_ban.bmp";
	//bmpWriter.write(outputFilename15, &image14);

	//final2 final2(image15, image25, image14, image16, image17, image18, image19, image20);
	////final.sum_number();
	//final2.ras();
	//final2.do_match();
	//final2.answer();
	//final2.ban();
	////final.muri();
	//final2.output_RGBImage(&image14);
	//string outputFilename15 = "C:\\Users\\toui\\Desktop\\crin_real_final\\sabun\\correct_gin_ban.bmp";
	//bmpWriter.write(outputFilename15, &image14);

	//RGBType pixelValue;											// �s�N�Z���l��ێ����邽�߂̕ϐ�
	//pixelValue = image.data[20][10];							// X : 10, Y : 20�̈ʒu�̃s�N�Z���l(RGBType�^)�����o��

	//image.data[10][20].setElement(255, 100, 0);					// X : 20, Y : 10�̈ʒu�̃s�N�Z���l��r : 255, g : 100, b : 0���Z�b�g

	return 0;
}