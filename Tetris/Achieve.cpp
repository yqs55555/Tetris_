#include "stdafx.h"
#include "Achieve.h"
#include <fstream>


Achieve::Achieve()
{
	achievename = new CString[18]{ L"��һͰ�𣨵õ�100�����ϣ�",L"����Ѿ����õ�500�����ϣ�",L"С�гɾͣ��õ�1000�����ϣ�" ,
		L"��ӭ������߾��磨��һ�ε����Ѷ�9����" ,L"���������9�����Ѷ�����ȥ10�У�" ,L"���Ѿ����˿ɵ��ˣ���9�����Ѷ�����ȥ30�У�"
		,L"�����������õ�233�֣�" ,L"6�÷��𣨵õ�666�֣�" ,L"��զ��������(�õ�6666�֣�",
		L"�������˲�!��һ��δ����������" ,L"First Blood����һ��������" ,L"double kill���������У�"
		,L"triple kill���������У�",L"quadruple kill���������У�",L"re:���㿪ʼ�Ķ���˹���飨��������10�Σ�",L"��ս�Űܣ��Ű���ս����������50�Σ�"
		,L"սʤ���������ˣ���������100�Σ�",L"���Ѿ����ˣ���һ��������" };
	InitAchieve();
}


Achieve::~Achieve()
{
	delete achievename;
}

void Achieve::display()
{
	InitAchieve();
	CString stringAchieve(L"�ѻ�õĳɾͣ�\n");
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
	MessageBox(nullptr, stringAchieve, L"�ɾ�", MB_OK);
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
	for (int i = 0; !file.eof();i++)//�Ƿ��ļ���β
	{
		int tmp;
		file >> tmp;
		if (tmp == 1)
			getAchieve[i] = TRUE;
	}
	file.close();
}
