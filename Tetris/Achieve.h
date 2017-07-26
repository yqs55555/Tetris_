#pragma once
#include <iostream>
using namespace std;
class Achieve
{
public:
	Achieve();
	~Achieve();
	void display();//展示获得成就
	BOOL hasgetachieve(int index);//
	void getnewachive(int index);//获得了新成就
	CString *achievename;
private:
	BOOL getAchieve[20];
	void InitAchieve();
};

