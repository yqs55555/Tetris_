#include "stdafx.h"
#include "Rank.h"
#include <fstream>
#include "TetrisDlg.h"
#include "AchieveDlg.h"
#include "Tetris.h"
#include "TetrisDlg.h"
#include "AchieveDlg.h"
#include "afxdialogex.h"
#include "ChooseDlg.h"
#include "GameDlg.h"
#include "Game.h"


Rank::Rank()
{
	memset(scorePtn0, 0, sizeof(int) * 15);
	memset(scorePtn1, 0, sizeof(int) * 15);
	memset(scorePtn2, 0, sizeof(int) * 15);
	textread();//��ȡ�����ļ�
	BubbleSort(scorePtn0);//����
	BubbleSort(scorePtn1);
	BubbleSort(scorePtn2);
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

void Rank::textwrite(const string str, int *score)
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

void Rank::readdata(const string filename, int* score)
{
	fstream file;
	file.open(filename, ios::in);
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


void Rank::display(CRankDlg& cDlg)
{
	CString res;
	for (int i = 0; i < 10; i++)
	{
		CString test;
		test.Format(_T("%d"), scorePtn0[i]);
		res = res + test + '\n';
	}
	SetDlgItemText(cDlg,IDC_STATIC_PATTERN0, res);//����ģʽ

	res = "";//��������
	for (int i = 0; i < 10; i++)
	{
		CString test;
		test.Format(_T("%d"), scorePtn1[i]);
		res = res + test + '\n';
	}
	SetDlgItemText(cDlg, IDC_STATIC_PATTERN1, res);//�о�ģʽ

	res = "";//��������
	for (int i = 0; i < 10; i++)
	{
		CString test;
		test.Format(_T("%d"), scorePtn2[i]);
		res = res + test + '\n';
	}
	SetDlgItemText(cDlg, IDC_STATIC_PATTERN2, res);//�������ģʽ
}
void Rank::clear()
{
	clearrank("dataPtn0.txt");
	clearrank("dataPtn1.txt");
	clearrank("dataPtn2.txt");

}
void Rank::clearrank(const string filename)
{
	memset(scorePtn0, 0, sizeof(int) * 15);
	memset(scorePtn1, 0, sizeof(int) * 15);
	memset(scorePtn2, 0, sizeof(int) * 15);
	fstream fs;
	fs.open(filename, ios_base::out);
	fs << "";
	fs.close();
}

