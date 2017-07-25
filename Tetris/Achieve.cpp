#include "stdafx.h"
#include "Achieve.h"


Achieve::Achieve()
{
	achievename = new string[20]{ "第一桶金（得到100分以上）","渐入佳境（得到500分以上）","小有成就（得到1000分以上）" ,
		"欢迎来到最高境界（第一次到达难度9级）" ,"神的领域（在9级的难度下消去10行）" ,"你已经无人可挡了（在9级的难度下消去30行）"
		,"哈哈哈哈（得到233分）" ,"玩得挺6（得到66分）" ,"6得飞起（得到666分）" ,"你咋不上天呢(得到6666分）",
		"你真是人才!（一行未消就死亡）" ,"你真快!（3秒内结束游戏）" ,"First Blood（第一次消除）" ,"double kill（连消两行）"
		,"triple kill（连消三行）","quadruple kill（连消四行）","re:从零开始的俄罗斯方块（死亡超过10次）","屡战屡败，屡败屡战（死亡超过50次）"
		,"战胜地狱的男人（死亡超过100次）","你已经死了（第一次死亡）" };
}


Achieve::~Achieve()
{
}

void Achieve::show()
{
}

BOOL Achieve::hasgetachieve(int index)
{
	return TRUE;
}

void Achieve::getnewachive(int index)
{
}
