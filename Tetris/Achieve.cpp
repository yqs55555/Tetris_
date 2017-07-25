#include "stdafx.h"
#include "Achieve.h"
#include <fstream>


Achieve::Achieve()
{
	achievename = new string[18]{ "第一桶金（得到100分以上）","渐入佳境（得到500分以上）","小有成就（得到1000分以上）" ,
		"欢迎来到最高境界（第一次到达难度9级）" ,"神的领域（在9级的难度下消去10行）" ,"你已经无人可挡了（在9级的难度下消去30行）"
		,"哈哈哈哈（得到233分）" ,"6得飞起（得到666分）" ,"你咋不上天呢(得到6666分）",
		"你真是人才!（一行未消就死亡）" ,"First Blood（第一次消除）" ,"double kill（连消两行）"
		,"triple kill（连消三行）","quadruple kill（连消四行）","re:从零开始的俄罗斯方块（死亡超过10次）","屡战屡败，屡败屡战（死亡超过50次）"
		,"战胜地狱的男人（死亡超过100次）","你已经死了（第一次死亡）" };
	InitAchieve();
}


Achieve::~Achieve()
{
}

void Achieve::display()
{
	/*
	for(int i=0;i<20;i++)
		{
			if(hasgetachieve)
			{
				打印achievename[i];
			}
		}
	
	*/
}

BOOL Achieve::hasgetachieve(int index)
{
	return getAchieve[index];
}

void Achieve::getnewachive(int index)
{
	getAchieve[index] = TRUE;
}

void Achieve::InitAchieve()
{
	fstream file;
	file.open("dataAchieve.txt", ios::in);
	int pos = 0;
	for (int i = 0; !file.eof();i++)//是否到文件结尾
	{
		int tmp;
		file >> tmp;
		if (tmp == 1)
			getAchieve[i];
	}
	file.close();
}
