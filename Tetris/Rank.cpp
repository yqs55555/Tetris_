#include <fstream>
#include<iostream>
using namespace std;
int* textread(string str);
void textwrite(string str, int *a);
void BubbleSort(int  *&p);//从大至小排列
void swap(int &a, int &b);
void rank(string str, int n);
void insert(int *&a, int n);
int caninsert(int *array, int n);
void arrayinsert(int *&a, int n, int position);

void rank(string str, int n)
{
	int *array = textread(str);
	BubbleSort(array);
	insert(array, n);
	textwrite(str, array);


}

int* textread(string str)
{
	fstream file;
	file.open(str, ios::in);
	if (!file)
		cout << "file not founded" << endl;
	int a[100];
	int pos = 0;
	while (!file.eof())//是否到文件结尾
	{
		file >> a[pos];
		pos++;
		if (pos >= 100)
			break;
	}
	file.close();
	for (int i = 0; i<pos; i++)
		cout << a[i] << endl;
	return a;
}
void insert(int *&a, int n)
{
	BubbleSort(a);
	if (caninsert(a, n))
	{
		int position = caninsert(a, n) + 1;
		arrayinsert(a, n, position);
	}
}
void BubbleSort(int  *&p)
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
void swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
int caninsert(int *array, int n)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (n <= array[i] && n >= array[i + 1]);
		return i;

	}
	return -1;
}
void arrayinsert(int *&a, int n, int position)
{
	for (int i = 10; i >position; i--)
	{
		a[i] = a[i - 1];
	}
	a[position] = n;

}
void textwrite(string str, int *a)
{
	fstream fs;
	fs.open(str, ios_base::out);
	for (int i = 0; i<10; i++)
		fs << a[i] << ' ';
	fs << a[9];
	fs.close();
}





