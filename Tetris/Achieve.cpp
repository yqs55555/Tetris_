#include "stdafx.h"
#include "Achieve.h"
#include <fstream>


Achieve::Achieve()
{
	achievename = new string[18]{ "��һͰ�𣨵õ�100�����ϣ�","����Ѿ����õ�500�����ϣ�","С�гɾͣ��õ�1000�����ϣ�" ,
		"��ӭ������߾��磨��һ�ε����Ѷ�9����" ,"���������9�����Ѷ�����ȥ10�У�" ,"���Ѿ����˿ɵ��ˣ���9�����Ѷ�����ȥ30�У�"
		,"�����������õ�233�֣�" ,"6�÷��𣨵õ�666�֣�" ,"��զ��������(�õ�6666�֣�",
		"�������˲�!��һ��δ����������" ,"First Blood����һ��������" ,"double kill���������У�"
		,"triple kill���������У�","quadruple kill���������У�","re:���㿪ʼ�Ķ���˹���飨��������10�Σ�","��ս�Űܣ��Ű���ս����������50�Σ�"
		,"սʤ���������ˣ���������100�Σ�","���Ѿ����ˣ���һ��������" };
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
				��ӡachievename[i];
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
	for (int i = 0; !file.eof();i++)//�Ƿ��ļ���β
	{
		int tmp;
		file >> tmp;
		if (tmp == 1)
			getAchieve[i];
	}
	file.close();
}
