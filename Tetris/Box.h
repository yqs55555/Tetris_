#pragma once
class Box
{
public:
	Box(int type);
	~Box();
	int _data[4][4];
private:
	void Make_1();//---
	void Make_2();//[ ]
	void Make_3();// p
	void Make_4();// q
	void Make_5();// Z
	void Make_6();// op_z
	void Make_7();//_|_
};
