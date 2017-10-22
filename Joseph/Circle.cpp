#include "stdafx.h"
#include "Circle.h"
#include "Person.h"

CCircle::CCircle()
{
}
//���캯�����Ա�����ʼ��
CCircle::CCircle(int headCount, int start, int gap)
{
	this->headCount = headCount;
	this->start = start;
	this->gap = gap;
	this->persons = new CPerson[this->headCount + 1];
	this->roll = new int[this->headCount + 1];	
}

CCircle::~CCircle()
{
}
//����Լɪ��,��pHand��������
void CCircle::Bulid()
{
	for (int i = 1; i < this->headCount; i++)
	{
		persons[i].pHand = &persons[i + 1];
		persons[i].personNum = i;
	}
	persons[this->headCount].pHand = &persons[1];
	persons[this->headCount].personNum = this->headCount;
}
//�Ա����Ƿ�����߼����ж�
bool CCircle::JudgeHeadCount()
{
	if (this->headCount > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CCircle::JudgeStart()
{
	if (this->start <= this->headCount && this->start > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CCircle::JudgeGap()
{
	if (this->gap > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CCircle::Run()
{
	Bulid();
	CPerson* p = &persons[1];
	for (int i = 2; i <= this->start; i++)
	{//������ʼλ��
		p = p->pHand;
	}
	CPerson* q = p;  
	int cut = 1;   //������
	while (this->headCount)
	{
		for (int i = 2; i <= this->gap; i++)
		{//��gap(���)���λ��
			q = p;
			p = p->pHand;
		}//��¼���
		this->roll[cut] = p->personNum;
		q->pHand = p->pHand;  //���˳���
		p = p->pHand;
		q = p;
		cut++;
		this->headCount--;
	}
}