#pragma once
#include<iostream>

using namespace std;

//身份抽象基类
class Identity
{
public:

	//操作菜单  纯虚函数
	//子类必须重写父类的纯虚函数，否则无法实例化对象
	virtual void operMenu() = 0;

	//用户名
	string m_Name;
	//密码
	string m_Pwd;
};