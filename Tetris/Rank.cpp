#include "stdafx.h"
#include "Rank.h"
#include"fstream"


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
	string filenamePtn0 = "dataPtn0.txt";
	readdata(filenamePtn0, scorePtn0);
	string filenamePtn1 = "dataPtn1.txt";
	readdata(filenamePtn1, scorePtn1);
	string filenamePtn2 = "dataPtn2.txt";
	readdata(filenamePtn2, scorePtn2);


	
}

void Rank::textwrite(string str, int * a)
{
}

void Rank::BubbleSort(int *p)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
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

void Rank::insert(int *a, int n)
{
	{
		BubbleSort(a);
		if (caninsert(a, n))
		{
			int position = caninsert(a, n) + 1;
			for (int i = 10; i >position; i--)
			{
				a[i] = a[i - 1];
			}
			    a[position] = n;
		}
	}
}

int Rank::caninsert(int * array, int n)
{
	return 0;
}

void Rank::readdata(string filename, int* score)
{
	fstream file;
	file.open(filename, ios::in);
	if (!file)
		cout << "file not founded" << endl;
	int pos = 0;
	while (!file.eof())//�Ƿ��ļ���β
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
	MessageBox(nullptr, res, L"����", MB_OK);
}
