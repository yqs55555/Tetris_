#include "stdafx.h"
#include "Rank.h"


Rank::Rank()
{
	memset(scorePtn0, 0, sizeof(int) * 15);
	memset(scorePtn1, 0, sizeof(int) * 15);
	memset(scorePtn2, 0, sizeof(int) * 15);
	textread();
}


Rank::~Rank()
{
}

void Rank::textread()
{
	//�������ļ�������д������������
}

void Rank::textwrite(string str, int * a)
{
}

void Rank::BubbleSort(int *& p)
{
}

void Rank::swap(int & a, int & b)
{
}

void Rank::insert(int *& a, int n)
{
}

int Rank::caninsert(int * array, int n)
{
	return 0;
}

void Rank::display()
{
	//��ӡ��������
}
