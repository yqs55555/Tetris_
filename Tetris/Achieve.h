#pragma once
#include <iostream>
using namespace std;
class Achieve
{
public:
	Achieve();
	~Achieve();
	void show();//չʾ��óɾ�
	BOOL hasgetachieve(int index);//
	void getnewachive(int index);//������³ɾ�
private:
	string *achievename;
	BOOL getAchieve[20];
};

