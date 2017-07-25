#pragma once
#include <iostream>
using namespace std;
class Achieve
{
public:
	Achieve();
	~Achieve();
	void show();//展示获得成就
	BOOL hasgetachieve(int index);//
	void getnewachive(int index);//获得了新成就
private:
	string *achievename;
	BOOL getAchieve[20];
};

