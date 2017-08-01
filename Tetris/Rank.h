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
	void display(CRankDlg& rDlg);//打印
	void clear();
	void textwrite(const string str, int *a);//写入数据文件
	void BubbleSort(int  *p);//从大至小排列
	void insert(int *a,const int& n);//插入分数
	BOOL caninsert(int *array,const int& n);//判断是否插入
	int scorePtn0[15];//经典模式
	int scorePtn1[15];//残局模式
	int scorePtn2[15];//随机变速模式
private:
	void textread();//读取数据文件
	void swap(int &a, int &b);//交换位置
	void readdata(const string filename,int* score);//score为int指针，存储数据
	void clearrank(const string filename);
};

