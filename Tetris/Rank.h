#pragma once
#include<iostream>
using namespace std;

class Rank
{
public:
	Rank();
	~Rank();
	void display();//��ӡ
	void clear();
private:
	void textread();//��ȡ�����ļ�
	void textwrite(string str, int *a);//д�������ļ�
	void BubbleSort(int  *p);//�Ӵ���С����
	void swap(int &a, int &b);//����λ��
	void insert(int *a, int n);//�������
	int caninsert(int *array, int n);//�ж��Ƿ����
	int scorePtn0[15];//����ģʽ
	int scorePtn1[15];//�о�ģʽ
	int scorePtn2[15];//�������ģʽ
	void readdata(string filename,int* score);
	void clearrank(string filename);

};

