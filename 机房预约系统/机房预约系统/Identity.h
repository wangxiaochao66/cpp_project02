#pragma once
#include<iostream>

using namespace std;

//��ݳ������
class Identity
{
public:

	//�����˵�  ���麯��
	//���������д����Ĵ��麯���������޷�ʵ��������
	virtual void operMenu() = 0;

	//�û���
	string m_Name;
	//����
	string m_Pwd;
};