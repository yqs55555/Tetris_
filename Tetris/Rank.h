#pragma once
#include<iostream>
using namespace std;

class Rank
{
public:
	Rank();
	~Rank();
	void display();//打印
	void clear();
private:
	void textread();//读取数据文件
	void textwrite(string str, int *a);//写入数据文件
	void BubbleSort(int  *p);//从大至小排列
	void swap(int &a, int &b);//交换位置
	void insert(int *a, int n);//插入分数
	int caninsert(int *array, int n);//判断是否插入
	int scorePtn0[15];//经典模式
	int scorePtn1[15];//残局模式
	int scorePtn2[15];//随机变速模式
	void readdata(string filename,int* score);
	void clearrank(string filename);

};

