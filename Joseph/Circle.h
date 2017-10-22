#pragma once
#include "Person.h"

class CCircle
{
public:
	CCircle();
	CCircle(int headCount, int start, int gap);
	~CCircle();
private:
	int headCount;	//������
	int start;	//��ʼλ��
	int gap;	//���

public:
	CPerson* persons;  //�볡��Ա
	int* roll;	 // //��������,�㵥Ԫ����

private:
	void Bulid();   //����Լɪ��
public:
	bool JudgeHeadCount();  //�ж��������Ƿ�����߼�
	bool JudgeStart();   //�ж���ʼλ���Ƿ�����߼�
	bool JudgeGap();     //�жϼ���Ƿ�����߼�
	void Run();     //ִ��Լɪ�򻷹����ҵ���������
};

