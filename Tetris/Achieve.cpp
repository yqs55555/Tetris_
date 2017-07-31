#include "stdafx.h"
#include "Achieve.h"
#include <fstream>


Achieve::Achieve()
{
	achievename = new CString[18]{ L"第一桶金（得到100分以上）",L"渐入佳境（得到500分以上）",L"小有成就（得到1000分以上）" ,
		L"欢迎来到最高境界（第一次到达难度9级）" ,L"神的领域（在9级的难度下消去10行）" ,L"你已经无人可挡了（在9级的难度下消去30行）"
		,L"哈哈哈哈（得到233分）" ,L"6得飞起（得到666分）" ,L"你咋不上天呢(得到6666分）",
		L"你真是人才!（一行未消就死亡）" ,L"First Blood（第一次消除）" ,L"double kill（连消两行）"
		,L"triple kill（连消三行）",L"quadruple kill（连消四行）",L"re:从零开始的俄罗斯方块（死亡超过10次）",L"屡战屡败，屡败屡战（死亡超过50次）"
		,L"战胜地狱的男人（死亡超过100次）",L"你已经死了（第一次死亡）" };
	InitAchieve();
}


Achieve::~Achieve()
{
	delete achievename;
}

void Achieve::display()
{
	InitAchieve();
	CString stringAchieve(L"已获得的成就：\n");
	int count = 0;
	for(int i=0;i<18;i++)
		{
			if(hasgetachieve(i))
			{
				stringAchieve = stringAchieve + achievename[i] + ';' + '\t';
				count++;
				if (count % 2 == 0)
					stringAchieve += '\n';
			}
		}
	MessageBox(nullptr, stringAchieve, L"成就", MB_OK);
}

BOOL Achieve::hasgetachieve(int index)
{
	return getAchieve[index];
}

void Achieve::getnewachive(int index)
{
	getAchieve[index] = TRUE;
	fstream fs;
	fs.open("dataAchieve.txt", ios_base::out);
	for (int i = 0; i<17; i++)
		fs << getAchieve[i] << ' ';
	fs << getAchieve[17];
	fs.close();
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
			getAchieve[i] = TRUE;
	}
	file.close();
}
