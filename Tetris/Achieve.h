#pragma once
#include <iostream>
using namespace std;
class Achieve
{
public:
	Achieve();
	~Achieve();
	void display();//չʾ��óɾ�
	BOOL hasgetachieve(int index);//
	void getnewachive(int index);//������³ɾ�
	CString *achievename;
private:
	BOOL getAchieve[20];
	void InitAchieve();
};

