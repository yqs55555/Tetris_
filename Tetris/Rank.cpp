#include "stdafx.h"
#include "Rank.h"
#include <fstream>


Rank::Rank()
{
	memset(scorePtn0, 0, sizeof(int) * 15);
	memset(scorePtn1, 0, sizeof(int) * 15);
	memset(scorePtn2, 0, sizeof(int) * 15);
	textread();
	BubbleSort(scorePtn0);
	BubbleSort(scorePtn1);
	BubbleSort(scorePtn2);
}


Rank::~Rank()
{
}

void Rank::textread()
{
	//将数据文件的数据写入三个数组中
	string filenamePtn0 = "dataPtn0.txt";
	readdata(filenamePtn0, scorePtn0);
	string filenamePtn1 = "dataPtn1.txt";
	readdata(filenamePtn1, scorePtn1);
	string filenamePtn2 = "dataPtn2.txt";
	readdata(filenamePtn2, scorePtn2); 
}

void Rank::textwrite(string str, int *score)
{
	fstream fs;
	fs.open(str, ios_base::out);
	for (int i = 0; i<10; i++)
		fs << score[i] << ' ';
	fs << score[9];
	fs.close();
}

void Rank::BubbleSort(int *p)
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11 - i - 1; j++)
		{
			if (p[j] < p[j + 1])
			{
				swap(p[j], p[j + 1]);
			}
		}
	}
}


void Rank::swap(int & a, int & b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void Rank::insert(int *score, int n)
{
	score[10] = n;
	BubbleSort(score);
}

BOOL Rank::caninsert(int * array, int n)
{
	for (int i = 0; i < 10; i++)
	{
		if (n > array[i])
		{
			return TRUE;
		}
	}
	return FALSE;
		
}

void Rank::readdata(string filename, int* score)
{
	fstream file;
	file.open(filename, ios::in);
	int pos = 0;
	while (!file.eof())//是否到文件结尾
	{
		file >> score[pos];
		pos++;
		if (pos >= 100)
			break;
	}
	file.close();
}


void Rank::display()
{
	CString res;
	for (int i = 0; i < 10; i++)
	{
		CString test;
		test.Format(_T("%d"), scorePtn0[i]);
		res = res + test + '\n';
	}
	MessageBox(nullptr, res, L"分数", MB_OK);
}
void Rank::clear()
{
	clearrank("dataPtn0.txt");
	clearrank("dataPtn1.txt");
	clearrank("dataPtn2.txt");

}
void Rank::clearrank(string filename)
{
	fstream fs;
	fs.open(filename, ios_base::out);
	fs << "";
	fs.close();
}

