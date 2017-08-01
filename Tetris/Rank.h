#pragma once
#include<iostream>
#include "AchieveDlg.h"
#include "RankDlg.h"
using namespace std;

class Rank
{
public:
	Rank();
	~Rank();
	void display(CRankDlg& rDlg);//��ӡ
	void clear();
	void textwrite(const string str, int *a);//д�������ļ�
	void BubbleSort(int  *p);//�Ӵ���С����
	void insert(int *a,const int& n);//�������
	BOOL caninsert(int *array,const int& n);//�ж��Ƿ����
	int scorePtn0[15];//����ģʽ
	int scorePtn1[15];//�о�ģʽ
	int scorePtn2[15];//�������ģʽ
private:
	void textread();//��ȡ�����ļ�
	void swap(int &a, int &b);//����λ��
	void readdata(const string filename,int* score);//scoreΪintָ�룬�洢����
	void clearrank(const string filename);
};

